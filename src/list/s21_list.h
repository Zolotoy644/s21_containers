#ifndef CPP2_S21_CONTAINERS_1_LIST_H
#define CPP2_S21_CONTAINERS_1_LIST_H

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <limits>

namespace s21 {

template <typename T>
class list {
 public:
  class Node;
  class ListIterator;
  class ListConstIterator;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using iterator = ListIterator;
  using const_iterator = ListConstIterator;

  class Node {
   public:
    Node *prev;
    Node *next;
    value_type value;
    Node();
    explicit Node(value_type val);
  };

  class ListIterator {
   private:
    Node *current = nullptr;

   public:
    // constructor
    ListIterator();
    explicit ListIterator(Node *ptr);
    // overload operators
    value_type operator*();
    iterator &operator++();
    iterator &operator--();
    bool operator==(const iterator &other);
    bool operator!=(const iterator &other);
    Node *getCurrent() { return current; }
  };

  class ListConstIterator : public ListIterator {
   public:
    ListConstIterator();
    const value_type operator*();
    const const_iterator &operator++();
  };

  // constructors
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &s);
  list(list &&s);
  // destructor
  ~list();
  // overload operator
  list &operator=(list &&s);

  // List Iterators
  iterator begin();
  iterator end();

  // list Element access
  const_reference front();
  const_reference back();

  // List Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // public methods
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  // bonus
  template <typename... Args>
  void insert_many_front(Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  iterator insert_many(iterator pos, Args &&...args);

 private:
  Node *head;
  Node *tail;
  Node *base;
  size_type list_size;
};
}  // namespace s21

#include "s21_list.tpp"
#endif  // CPP2_S21_CONTAINERS_1_LIST_H
