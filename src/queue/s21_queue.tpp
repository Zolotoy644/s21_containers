#include "s21_queue.h"

namespace s21 {
template <typename T>
queue<T>::queue() : list() {}

template <typename T>
queue<T>::queue(const std::initializer_list<value_type> &items) : list(items) {}

template <typename T>
queue<T>::queue(queue<T> &&q) {
  list.swap(q.list);
  q.list.clear();
}

template <typename T>
queue<T>::queue(const queue<T> &q) : list(q.list) {}

template <typename T>
queue<T>::~queue() {
  list.clear();
}

template <typename T>
queue<T> &queue<T>::operator=(queue<T> &&q) {
  list.swap(q.list);
  q.list.clear();
  return *this;
}

template <typename T>
typename queue<T>::const_reference queue<T>::front() {
  return list.front();
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() {
  return list.back();
}

template <typename T>
bool queue<T>::empty() {
  return list.empty();
}

template <typename T>
typename queue<T>::size_type queue<T>::size() {
  return list.size();
}

template <typename T>
void queue<T>::push(const_reference value) {
  list.push_back(value);
}

template <typename T>
void queue<T>::pop() {
  if (!empty()) {
    list.pop_front();
  } else {
    throw std::out_of_range("Error: empty queue!");
  }
}

template <typename T>
void queue<T>::swap(queue<T> &other) {
  list.swap(other.list);
}

template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args &&...args) {
  list.insert_many_back(args...);
}

}  // namespace s21
