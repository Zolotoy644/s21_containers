#include "s21_stack.h"

namespace s21 {
template <typename T>
stack<T>::Node::Node() {
  prev = nullptr;
}

template <typename T>
stack<T>::Node::Node(value_type value) : Node() {
  this->value = value;
}

template <typename T>
stack<T>::stack() : head(nullptr), stack_size(0) {}

template <typename T>
stack<T>::stack(std::initializer_list<value_type> const &items)
    : head(nullptr), stack_size(0) {
  for (auto val : items) {
    push(val);
  }
}

template <typename T>
stack<T>::stack(const stack &s) : stack() {
  stack<T> tmp;
  for (Node *node = s.head; node != NULL; node = node->prev) {
    tmp.push(node->value);
  }
  for (Node *node = tmp.head; node != NULL; node = node->prev) {
    push(node->value);
  }
  tmp.remove_stack();
}

template <typename T>
stack<T>::stack(stack &&s) : stack() {
  swap(s);
}

template <typename T>
stack<T>::~stack() {
  remove_stack();
}

template <typename T>
stack<T> &stack<T>::operator=(stack<T> &&s) {
  remove_stack();
  head = s.head;
  stack_size = s.stack_size;
  s.head = nullptr;
  s.stack_size = 0;
  return *this;
}

template <typename T>
size_t stack<T>::size() {
  return this->stack_size;
}

template <typename T>
bool stack<T>::empty() {
  return this->stack_size == 0;
}

template <typename T>
void stack<T>::push(const_reference value) {
  Node *new_node = new Node(value);
  new_node->value = value;
  if (!head) {
    head = new_node;
  } else {
    new_node->prev = head;
    head = new_node;
  }
  stack_size++;
}

template <typename T>
void stack<T>::pop() {
  if (!head) throw std::logic_error("Stack is empty");
  Node *prev_node = head->prev;
  delete head;
  head = prev_node;
  stack_size--;
}

template <typename T>
void stack<T>::swap(stack<T> &other) {
  std::swap(this->head, other.head);
  std::swap(this->stack_size, other.stack_size);
}

template <typename T>
typename stack<T>::const_reference stack<T>::top() {
  if (!head) throw std::logic_error("Stack is empty");
  return head->value;
}

template <typename T>
void stack<T>::remove_stack() {
  while (head) {
    pop();
  }
}

template <typename T>
template <typename... Args>
void stack<T>::insert_many_front(Args &&...args) {
  std::initializer_list<value_type> items{args...};
  for (auto val : items) {
    push(val);
  }
}
}  // namespace s21
