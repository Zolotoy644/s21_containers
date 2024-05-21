#ifndef CPP2_S21_CONTAINERS_SRC_VECTOR_
#define CPP2_S21_CONTAINERS_SRC_VECTOR_

#include <cstddef>
#include <initializer_list>
#include <iostream>

// const T&
namespace s21 {
template <class T>
class vector {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = value_type *;
  using const_iterator = const value_type *;
  using size_type = size_t;
  vector() noexcept;
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(vector &&v);
  vector &operator=(vector &&v);
  ~vector();
  // modifiers
  void clear() noexcept;
  iterator insert(iterator pos, const_reference value);
  iterator erase(iterator pos);
  void push_back(const_reference value);
  void pop_back() noexcept;
  void swap(vector &other) noexcept;
  // Element access
  reference operator[](size_type pos) const;
  reference at(size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  T *data() const noexcept;
  // iterators
  iterator begin() const noexcept;
  iterator end() const noexcept;
  // capacity
  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;
  void reserve(size_type size);
  size_type capacity() const noexcept;
  void shrink_to_fit();
  // bonus
  template <typename... Args>
  iterator insert_many(iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  iterator data_;
  size_type size_;
  size_type capacity_;
  void CreateVector(size_type n);
};
}  // namespace s21

#include "s21_vector.tpp"

#endif  // CPP2_S21_CONTAINERS_SRC_VECTOR_