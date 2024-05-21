#ifndef CPP2_S21_CONTAINERS_SRC_ARRAY_
#define CPP2_S21_CONTAINERS_SRC_ARRAY_

#include <cstddef>
#include <initializer_list>
#include <iostream>

namespace s21 {
template <class T, std::size_t N>
class array {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  using size_type = size_t;
  array();
  array(std::initializer_list<value_type> const &items);
  array(const array &v);
  array(array &&v);
  array &operator=(array &&v);
  ~array() = default;
  // Element access
  reference operator[](size_type pos);
  reference at(size_type pos);
  const_reference front() const;
  const_reference back() const;
  T *data() noexcept;
  // iterators
  iterator begin() noexcept;
  iterator end() noexcept;
  // capacity
  bool empty() noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  // modifiers
  void swap(array &other) noexcept;
  void fill(const_reference value);

 private:
  value_type data_[N];
  size_type size_;
};
}  // namespace s21

#include "s21_array.tpp"
#endif  // CPP2_S21_CONTAINERS_SRC_ARRAY_