#ifndef CPP2_S21_CONTAINERS_SRC_MAP_
#define CPP2_S21_CONTAINERS_SRC_MAP_

#include <memory>

#include "../BinaryTree/tree.h"

namespace s21 {
template <class Key, class T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;

  struct Comparator {
    static bool Equality(value_type node_value, Key value) {
      return node_value.first == value;
    }
    static bool NotEquality(value_type node_value, Key value) {
      return node_value.first != value;
    }
    static bool Equality(value_type node_value, value_type value) {
      return node_value.first == value.first;
    }
    static bool NotEquality(value_type node_value, value_type value) {
      return node_value.first != value.first;
    }
    static bool Less(value_type node_value, Key value) {
      return value < node_value.first;
    }
  };

  using size_type = size_t;
  using iterator = typename BinaryTree<Key, value_type, Comparator>::iterator;
  using const_iterator =
      typename BinaryTree<Key, value_type, Comparator>::const_iterator;
  map() : tree_() {}
  map(std::initializer_list<value_type> const &items) {
    for (auto element : items) {
      tree_.Insert(element);
    }
  }
  map(const map &m) : tree_(m.tree_) {}
  map(map &&m) : tree_(std::move(m.tree_)) {}
  ~map() {}
  map &operator=(map &&m) {
    tree_ = std::move(m.tree_);
    return *this;
  }
  // Element access
  T &at(const Key &key) { return OperatorHelper(key, true); }
  T &operator[](const Key &key) { return OperatorHelper(key, false); };
  // iterators
  iterator begin() const noexcept { return tree_.begin(); }
  iterator end() const noexcept { return tree_.end(); }
  // Capacity
  bool empty() const noexcept { return tree_.empty(); }
  size_type size() const noexcept { return tree_.size(); }
  size_type max_size() const noexcept { return tree_.max_size(); }
  // Modifiers
  void clear() noexcept { tree_.clear(); }
  std::pair<iterator, bool> insert(const value_type &value) {
    return tree_.InsertBool(value);
  }
  std::pair<iterator, bool> insert_or_assign(const Key &key, const T &obj) {
    std::pair<Key, T> obj_transform = {key, obj};
    return tree_.InsertOrAssign(obj_transform);
  }
  void erase(iterator pos) { tree_.erase(pos); }
  void swap(map &other) { tree_.swap(other.tree_); }
  void merge(map &other) { tree_.merge(other.tree_); }
  // Lookup
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
  BinaryTree<Key, value_type, Comparator> tree_;
  T &OperatorHelper(const Key &key, bool at_or_brackets) {
    bool isFind = false;
    static T value = 0;
    iterator it = tree_.begin();
    for (; it != tree_.end(); it++) {
      if (it.getCurrent()->data.first == key) {
        value = it.getCurrent()->data.second;
        isFind = true;
      }
    }
    if (!isFind && at_or_brackets) {
      throw std::out_of_range("Container does not have an element");
    }
    return value;
  }
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_SRC_MAP_