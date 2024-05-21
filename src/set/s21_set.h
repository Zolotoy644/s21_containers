#ifndef CPP2_S21_CONTAINERS_SRC_SET_
#define CPP2_S21_CONTAINERS_SRC_SET_

#include "../BinaryTree/tree.h"

namespace s21 {
template <class Key>
class set {
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
  set() : tree_() {}
  set(std::initializer_list<value_type> const &items) {
    for (auto element : items) {
      tree_.Insert(element);
    }
  }
  set(const set &s) : tree_(s.tree_){};
  set(set &&s) : tree_(std::move(s.tree_)){};
  ~set() {}
  set &operator=(set &&s) {
    tree_ = std::move(s.tree_);
    return *this;
  }
  iterator begin() const noexcept { return tree_.begin(); }
  iterator end() const noexcept { return tree_.end(); };
  bool empty() const noexcept { return tree_.empty(); };
  size_type size() const noexcept { return tree_.size(); };
  size_type max_size() const noexcept { return tree_.max_size(); }
  void clear() noexcept { tree_.clear(); };
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree_.InsertBool(value);
  }
  void erase(iterator pos) { tree_.erase(pos); }
  void swap(set &other) { tree_.swap(other.tree_); };
  void merge(set &other) { tree_.merge(other.tree_); };
  iterator find(const Key &key) { return tree_.FindNum(key); }
  bool contains(const Key &key) {
    iterator node = tree_.FindNum(key);
    iterator null;
    return node != null;
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

#endif  // CPP2_S21_CONTAINERS_SRC_SET_