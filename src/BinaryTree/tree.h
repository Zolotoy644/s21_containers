#ifndef CPP2_S21_CONTAINERS_SRC_BINARYTREE_
#define CPP2_S21_CONTAINERS_SRC_BINARYTREE_

#include <iostream>
#include <type_traits>

namespace s21 {

template <typename Key, typename T, typename Comparator>
class BinaryTree {
 public:
  class Node;
  class BinaryTreeIterator;
  class BinaryTreeConstIterator;
  using key_type = Key;
  using value_type = T;
  using reference = T &;
  using const_reference = const value_type &;
  using iterator = BinaryTree<Key, T, Comparator>::BinaryTreeIterator;
  using const_iterator =
      BinaryTree<Key, T, Comparator>::BinaryTreeConstIterator;
  using size_type = std::size_t;

  class Node {
   public:
    Node *left;
    Node *right;
    Node *parent;
    value_type data;
    Node() {
      left = nullptr;
      right = nullptr;
      parent = nullptr;
    }
    explicit Node(const value_type &data = value_type{}, Node *left = nullptr,
                  Node *right = nullptr, Node *parent = nullptr)
        : left(left), right(right), parent(parent), data(data) {}
  };

  class BinaryTreeIterator {
   public:
    BinaryTreeIterator() : current(nullptr) {}
    explicit BinaryTreeIterator(Node *current) : current(current) {}
    BinaryTreeIterator &operator++() {
      if (current) {
        if (current->right) {
          current = current->right;
          while (current->left) current = current->left;
        } else {
          while (current->parent && current->data >= current->parent->data) {
            current = current->parent;
          }
          current = current->parent;
        }
      }
      return *this;
    }
    BinaryTreeIterator &operator--() {
      if (current) {
        if (current->left) {
          current = current->left;
          while (current->right) current = current->right;
        } else {
          while (current->parent && current->data < current->parent->data) {
            current = current->parent;
          }
          current = current->parent;
        }
      }
      return *this;
    }
    BinaryTreeIterator operator++(int) {
      iterator it(*this);
      ++(*this);
      return it;
    }
    BinaryTreeIterator operator--(int) {
      iterator it(*this);
      --(*this);
      return it;
    }
    bool operator==(const BinaryTreeIterator &other) const {
      return current == other.current;
    }
    bool operator!=(const BinaryTreeIterator &other) const {
      return current != other.current;
    }
    reference operator*() const {
      if (!current) {
        throw std::invalid_argument("wrong argument");
      }
      return current->data;
    }
    Node *getCurrent() { return current; }

   private:
    Node *current{nullptr};
  };

  class BinaryTreeConstIterator : public BinaryTreeIterator {
   public:
    BinaryTreeConstIterator();
    explicit BinaryTreeConstIterator(Node *current);
    BinaryTreeConstIterator(const BinaryTreeIterator &it);

    BinaryTreeConstIterator &operator++();
    BinaryTreeConstIterator &operator--();
    BinaryTreeConstIterator operator++(int);
    BinaryTreeConstIterator operator--(int);
    bool operator==(const BinaryTreeConstIterator &other) const;
    bool operator!=(const BinaryTreeConstIterator &other) const;
    const_reference operator*() const;

   private:
    BinaryTreeIterator it;
  };

  BinaryTree() : root(nullptr) {}
  // BinaryTree(std::initializer_list<value_type> const &items);  // ?
  BinaryTree(const BinaryTree<Key, T, Comparator> &s) {
    root = new Node(s.root->data);
    root->parent = nullptr;
    CopyTree(root, s.root);
  }
  BinaryTree(BinaryTree &&s) { swap(s); }
  // destructor
  ~BinaryTree() {
    if (root != nullptr) {
      clear();
    }
  }
  // overload operator
  BinaryTree &operator=(BinaryTree &&s) {
    clear();
    swap(s);
    return *this;
  }

  // Tree Iterators
  iterator begin() const noexcept {
    Node *tmp = root;
    while (tmp->left) {
      tmp = tmp->left;
    }
    return iterator(tmp);
  }
  iterator end() const noexcept {
    Node *tmp = root;
    while (tmp->right) {
      tmp = tmp->right;
    }
    return iterator(tmp->right);
  }

  // Tree Capacity
  bool empty() const noexcept { return (!root); }
  size_type size() const noexcept {
    size_type counter = 0;
    if (root) {
      for (auto it = begin(); it != end(); ++it) {
        ++counter;
      }
    }
    return counter;
  }

  size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
  }
  // Tree Modifiers
  void clear() noexcept { ClearTree(root); }

  void Insert(value_type value, bool duplicate = false) {
    Insert(root, value, duplicate);
  }

  void Insert(Node *node, value_type value, bool duplicate = false) {
    if (root == nullptr) {
      root = new Node(value);
      root->parent = nullptr;
      return;
    }
    if (value < node->data) {
      if (node->left == nullptr) {
        node->left = new Node(value);
        node->left->parent = node;
      } else {
        Insert(node->left, value);
      }
    } else if (value > node->data || duplicate) {
      if (node->right == nullptr) {
        node->right = new Node(value);
        node->right->parent = node;
      } else {
        Insert(node->right, value);
      }
    }
  }

  std::pair<iterator, bool> InsertOrAssign(const T &obj) {
    std::pair<iterator, bool> result;
    iterator null;
    if (FindNumByIter(obj) == null) {
      Insert(obj);
      iterator node = FindNumByIter(obj);
      result.first = node;
      result.second = true;
    } else {
      iterator node = FindNumByIter(obj);
      node.getCurrent()->data.second = obj.second;
      result.first = node;
      result.second = false;
    }
    return result;
  }

  std::pair<iterator, bool> InsertBool(const value_type &value,
                                       bool duplicate = false) {
    std::pair<iterator, bool> result;
    size_type begin_size = size();
    Insert(value, duplicate);
    if (size() == begin_size) {
      iterator node = FindNumByIter(value);
      result.first = node;
      result.second = false;
    } else {
      iterator node = FindNumByIter(value);
      result.first = node;
      result.second = true;
    }
    return result;
  }

  void erase(iterator pos) {
    if (pos.getCurrent() == nullptr || size() == 0)
      throw std::invalid_argument("wrong argument");
    root = delete_node(root, *pos);
  }

  Node *delete_node(Node *node, value_type value) {
    Node *tmp = nullptr;
    if (node != nullptr) {
      if (value < node->data)
        node->left = delete_node(node->left, value);
      else if (value > node->data)
        node->right = delete_node(node->right, value);
      else if (node->left != nullptr && node->right != nullptr) {
        tmp = node;
        node = minimum(node->right);
        node->left = tmp->left;
        node->right = tmp->right;
        node->parent = tmp->parent;
        // node->data = minimum(node->right)->data;
        // node->right = delete_node(node->right, node->data);
      } else if (node->left != nullptr) {
        tmp = node;
        node = node->left;
        node->parent = tmp->parent;
      } else if (node->right != nullptr) {
        tmp = node;
        node = node->right;
        node->parent = tmp->parent;
      } else {
        tmp = node;
        node = nullptr;
      }
      if (tmp != nullptr) {
        delete (tmp);
      }
    }
    return node;
  }

  Node *minimum(Node *node) {
    Node *tmp = node;
    if (tmp != nullptr) {
      while (tmp->left) {
        tmp = tmp->left;
      }
    }
    return tmp;
  }

  void swap(BinaryTree &other) { std::swap(root, other.root); }
  void merge(BinaryTree &other) {
    for (iterator it = other.begin(); it != other.end(); ++it) {
      Insert(*it);
    }
  }

  iterator FindNum(const Key &key) { return iterator(FindNumByKey(root, key)); }

  iterator FindNumByIter(value_type value, bool lower = false,
                         bool upper = false) {
    iterator node = begin();
    if (!lower && !upper) {
      return iterator(FindNumByValue(root, value));
    } else if (lower) {
      while (value > node.getCurrent()->data) {
        node++;
      }
    } else if (upper) {
      while (node.getCurrent()->data <= value) {
        node++;
      }
    }
    return node;
  }

  Node *FindNumByKey(Node *node, Key value) {
    if (Comparator::Equality(node->data, value) || node == nullptr) {
      return node;
    }
    while (Comparator::NotEquality(node->data, value) && node != nullptr) {
      if (Comparator::Less(node->data, value)) {
        node = node->left;
      } else {
        node = node->right;
      }
      if (node == nullptr) {
        break;
      }
    }
    return node;
  }

  Node *FindNumByValue(Node *node, value_type value) {
    if (Comparator::Equality(node->data, value) || node == nullptr) {
      return node;
    }
    while (Comparator::NotEquality(node->data, value) && node != nullptr) {
      if (value < node->data) {
        node = node->left;
      } else {
        node = node->right;
      }
      if (node == nullptr) {
        break;
      }
    }
    return node;
  }

  void CopyTree(Node *node, Node *node_copy) {
    if (node_copy->left != nullptr) {
      node->left = new Node(node_copy->left->data);
      node->left->parent = node;
      CopyTree(node->left, node_copy->left);
    }
    if (node_copy->right != nullptr) {
      node->right = new Node(node_copy->right->data);
      node->right->parent = node;
      CopyTree(node->right, node_copy->right);
    }
  }

  void ClearTree(Node *node) {
    if (node->left != nullptr) {
      ClearTree(node->left);
      delete node->left;
      node->left = nullptr;
    }
    if (node->right != nullptr) {
      ClearTree(node->right);
      delete node->right;
      node->right = nullptr;
    }
    if (root->left == nullptr && root->right == nullptr) {
      delete root;
      root = nullptr;
    }
  }

 private:
  Node *root{nullptr};
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_BINARYTREE_
