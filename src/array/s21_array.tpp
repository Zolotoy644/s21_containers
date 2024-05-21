#include "s21_array.h"

namespace s21 {
// constructors and destructors
template <class value_type, std::size_t N>
array<value_type, N>::array() : size_(N) {}

template <class value_type, std::size_t N>
array<value_type, N>::array(std::initializer_list<value_type> const& items) {
  size_ = N;
  std::copy(items.begin(), items.end(), data_);
}

template <class value_type, std::size_t N>
array<value_type, N>::array(const array& v) {
  size_ = v.size_;
  for (size_type i = 0; i < v.size(); ++i) {
    data_[i] = v.data_[i];
  }
}

template <class value_type, std::size_t N>
array<value_type, N>::array(array&& v) {
  size_ = v.size_;
  for (size_type i = 0; i < v.size(); ++i) {
    data_[i] = std::move(v.data_[i]);
  }
  v.size_ = 0;
}

template <class value_type, std::size_t N>
array<value_type, N>& array<value_type, N>::operator=(array&& v) {
  size_ = v.size_;
  for (size_type i = 0; i < v.size(); ++i) {
    data_[i] = std::move(v.data_[i]);
  }
  v.size_ = 0;
  return *this;
}

template <class value_type, std::size_t N>
value_type& array<value_type, N>::operator[](size_type pos) {
  return data_[pos];
}

template <class value_type, std::size_t N>
value_type& array<value_type, N>::at(size_type pos) {
  if (pos > size()) {
    throw std::out_of_range("Number out of range container");
  }
  return data_[pos];
}

template <class value_type, std::size_t N>
typename array<value_type, N>::const_reference array<value_type, N>::front()
    const {
  return data_[0];
}

template <class value_type, std::size_t N>
typename array<value_type, N>::const_reference array<value_type, N>::back()
    const {
  return data_[size_ - 1];
}

template <class value_type, std::size_t N>
value_type* array<value_type, N>::data() noexcept {
  return data_;
}

template <class value_type, std::size_t N>
typename array<value_type, N>::iterator array<value_type, N>::begin() noexcept {
  if (size() == 0) {
    return end();
  }
  return data_;
}

template <class value_type, std::size_t N>
typename array<value_type, N>::iterator array<value_type, N>::end() noexcept {
  return data_ + size_;
}

template <class value_type, std::size_t N>
bool array<value_type, N>::empty() noexcept {
  return begin() == end();
}

template <class value_type, std::size_t N>
typename array<value_type, N>::size_type array<value_type, N>::max_size()
    const noexcept {
  return N;
}

template <class value_type, std::size_t N>
void array<value_type, N>::swap(array& other) noexcept {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
}

template <class value_type, std::size_t N>
void array<value_type, N>::fill(const_reference value) {
  for (auto it = begin(); it != end(); ++it) {
    *it = value;
  }
}

template <class value_type, std::size_t N>
size_t array<value_type, N>::size() const noexcept {
  return size_;
}

}  // namespace s21