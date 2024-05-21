#ifndef _S21_STACK_H_
#define _S21_STACK_H_

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class stack {
 public:
  class Node;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  class Node {
   public:
    Node *prev;
    value_type value;
    Node();
    explicit Node(value_type value);
  };

  // constructors
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  // destructor
  ~stack();
  // overload operator
  stack &operator=(stack &&s);

  // public methods
  bool empty();
  size_type size();
  void push(const_reference value);
  void pop();
  void swap(stack &other);
  const_reference top();
  void remove_stack();

  // bonus
  template <typename... Args>
  void insert_many_front(Args &&...args);

 private:
  Node *head;
  size_type stack_size;
};

}  // namespace s21

#include "s21_stack.tpp"
#endif  //_S21_STACK_H_
