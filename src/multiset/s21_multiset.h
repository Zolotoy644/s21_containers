#ifndef CPP2_S21_CONTAINERS_SRC_MULTISET_
#define CPP2_S21_CONTAINERS_SRC_MULTISET_

#include "../BinaryTree/tree.h"

namespace s21 {
template <class Key>
class multiset {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

  struct Comparator {
    static bool Equality(value_type node_value, Key value) {
      return node_value == value;
    }
    static bool NotEquality(value_type node_value, Key value) {
      return node_value != value;
    }
    static bool Less(value_type node_value, Key value) {
      return value < node_value;
    }
  };

  using iterator = typename BinaryTree<Key, Key, Comparator>::iterator;
  using const_iterator =
      typename BinaryTree<Key, Key, Comparator>::const_iterator;
  multiset() : tree_(){};
  multiset(std::initializer_list<value_type> const &items) {
    for (auto element : items) {
      tree_.Insert(element, true);
    }
  }
  multiset(const multiset &ms) : tree_(ms.tree_){};
  multiset(multiset &&ms) : tree_(std::move(ms.tree_)){};
  ~multiset(){};
  multiset &operator=(multiset &&ms) {
    tree_ = std::move(ms.tree_);
    return *this;
  }
  // iterators
  iterator begin() const noexcept { return tree_.begin(); }
  iterator end() const noexcept { return tree_.end(); };
  // capacity
  bool empty() const noexcept { return tree_.empty(); };
  size_type size() const noexcept { return tree_.size(); };
  size_type max_size() const noexcept { return tree_.max_size(); }
  // modifiers
  void clear() noexcept { tree_.clear(); };
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree_.InsertBool(value, true);
  }
  void erase(iterator pos) { tree_.erase(pos); }
  void swap(multiset &other) { tree_.swap(other.tree_); };
  void merge(multiset &other) { tree_.merge(other.tree_); };
  // lookup
  size_type count(const Key &key) {
    size_type counter = 0;
    tree_.counter(tree_, counter, key);
    return counter;
  }
  iterator find(const Key &key) { return tree_.FindNum(key); }
  bool contains(const Key &key) {
    iterator node = tree_.FindNum(key);
    iterator null;
    return node != null;
  }

  iterator lower_bound(const Key &key) {
    return tree_.FindNumByIter(key, true);
  }
  iterator upper_bound(const Key &key) {
    return tree_.FindNumByIter(key, false, true);
  }
  std::pair<iterator, iterator> equal_range(const Key &key) {
    std::pair<iterator, iterator> result = {lower_bound(key), upper_bound(key)};
    return result;
  }

  template <typename... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> vec;
    for (const auto &arg : {args...}) {
      vec.push_back(insert(arg));
    }
    return vec;
  }

 private:
  BinaryTree<Key, Key, Comparator> tree_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_MULTISET_