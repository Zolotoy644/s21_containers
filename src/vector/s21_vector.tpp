#include "s21_vector.h"

namespace s21 {

// constructors and destructor
template <class value_type>
vector<value_type>::vector() noexcept
    : data_(nullptr), size_(0), capacity_(0) {}

template <class value_type>
vector<value_type>::vector(size_type n) : size_(n), capacity_(n) {
  CreateVector(n);
}

template <class value_type>
vector<value_type>::vector(std::initializer_list<value_type> const& items) {
  size_ = capacity_ = items.size();
  CreateVector(size_);
  std::copy(items.begin(), items.end(), data_);
}

template <class value_type>
vector<value_type>::vector(const vector& v) {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = new value_type[v.size_];
  for (size_t i = 0; i < size_; ++i) {
    data_[i] = v.data_[i];
  }
}

template <class value_type>
vector<value_type>::vector(vector&& v) {
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = v.data_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
}

template <class value_type>
vector<value_type>& vector<value_type>::operator=(vector&& v) {
  delete[] data_;
  size_ = v.size_;
  capacity_ = v.capacity_;
  data_ = v.data_;
  v.size_ = 0;
  v.capacity_ = 0;
  v.data_ = nullptr;
  return *this;
}

template <class value_type>
vector<value_type>::~vector() {
  delete[] data_;
  size_ = capacity_ = 0;
  data_ = nullptr;
}

// methods
template <class value_type>
void vector<value_type>::CreateVector(size_type n) {
  if (n > 0) {
    data_ = new value_type[n]();
  } else {
    throw std::out_of_range("Invalid size vector");
  }
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::begin()
    const noexcept {
  return data_;
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::end() const noexcept {
  return data_ + size_;
}

template <class value_type>
bool vector<value_type>::empty() const noexcept {
  return begin() == end();
}

template <class value_type>
size_t vector<value_type>::size() const noexcept {
  return size_;
}

template <class value_type>
typename vector<value_type>::size_type vector<value_type>::max_size()
    const noexcept {
  return std::numeric_limits<size_type>::max() / sizeof(size_type);
}

template <class value_type>
size_t vector<value_type>::capacity() const noexcept {
  return capacity_;
}

template <class value_type>
void vector<value_type>::shrink_to_fit() {
  if (capacity_ > size_) {
    capacity_ = size_;
  }
}

template <class value_type>
void vector<value_type>::reserve(size_type size) {
  if (size > max_size()) {
    throw std::length_error("Cannot allocate space for capacity");
  }
  if (size > capacity_) {
    value_type* buff = new value_type[size];
    for (size_t i = 0; i < size_; i++) {
      buff[i] = data_[i];
    }
    delete[] data_;
    data_ = buff;
    capacity_ = size;
  }
}

template <class value_type>
value_type& vector<value_type>::operator[](size_type pos) const {
  return data_[pos];
}

template <class value_type>
value_type& vector<value_type>::at(size_type pos) const {
  if (pos > size()) {
    throw std::out_of_range("Number out of range container");
  }
  return data_[pos];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::front() const {
  return data_[0];
}

template <class value_type>
typename vector<value_type>::const_reference vector<value_type>::back() const {
  return data_[size_ - 1];
}

template <class value_type>
typename vector<value_type>::iterator vector<value_type>::data()
    const noexcept {
  return data_;
}

// modifiers
template <class value_type>
void vector<value_type>::clear() noexcept {
  size_ = 0;
}

template <class value_type>
value_type* vector<value_type>::insert(iterator pos, const_reference value) {
  if (pos < begin() || pos > end() - 1) {
    throw std::out_of_range("Pointer located behind border vector");
  }
  size_type position = pos - data_;
  size_type start_position = pos - data_;
  value_type temp;
  temp = *pos;
  if (size_ + 1 >= capacity_) {
    reserve(capacity_ * 2);
  }
  size_++;
  value_type temp2;
  data_[position] = value;
  iterator res = data_ + position;
  for (; position != size(); ++position) {
    if (position == start_position) {
      continue;
    } else {
      temp2 = data_[position];
      data_[position] = temp;
      temp = temp2;
    }
  }
  return res;
}

template <class value_type>
value_type* vector<value_type>::erase(iterator pos) {
  if (pos < begin() || pos > end() - 1) {
    throw std::out_of_range("Pointer located behind border vector");
  }
  if (pos == end() - 1) {
    --size_;
    return pos;
  } else {
    size_type position = pos - data_;
    data_[position] = *(pos + 1);
    --size_;
    return pos + 1;
  }
}

template <class value_type>
void vector<value_type>::push_back(const_reference value) {
  if (size_ == capacity_ && size_ != 0) {
    reserve(capacity_ * 2);
  } else if (size_ == 0) {
    CreateVector(1);
    capacity_++;
  }
  data_[size_++] = value;
}
template <class value_type>
void vector<value_type>::pop_back() noexcept {
  size_--;
}

template <class value_type>
void vector<value_type>::swap(vector& other) noexcept {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename value_type>
template <typename... Args>
void vector<value_type>::insert_many_back(Args&&... args) {
  std::initializer_list<value_type> items{args...};
  for (auto val : items) {
    push_back(val);
  }
}

template <typename value_type>
template <typename... Args>
typename vector<value_type>::iterator vector<value_type>::insert_many(
    iterator pos, Args&&... args) {
  std::initializer_list<value_type> items{args...};
  iterator iter = pos;
  iterator result;
  for (auto val : items) {
    result = insert(iter, val);
    iter = end() - 1;
  }
  return result;
}

}  // namespace s21