#include "s21_list.h"

namespace s21 {
template <typename T>
list<T>::Node::Node() {
  prev = nullptr;
  next = nullptr;
}

template <typename T>
list<T>::Node::Node(value_type val) : Node() {
  value = val;
}

template <typename T>
list<T>::ListIterator::ListIterator() : current(nullptr) {}

template <typename T>
list<T>::ListIterator::ListIterator(Node *ptr) : current(ptr) {}

template <typename T>
typename list<T>::value_type list<T>::iterator::operator*() {
  if (current == nullptr) {
    throw std::invalid_argument("wrong argument");
  }
  return current->value;
}

template <typename T>
typename list<T>::iterator &list<T>::iterator::operator++() {
  if (current) {
    current = current->next;
  }
  return *this;
}

template <typename T>
typename list<T>::iterator &list<T>::iterator::operator--() {
  if (current) current = current->prev;
  return *this;
}

template <typename T>
bool list<T>::iterator::operator==(const iterator &other) {
  return this->current == other.current;
}

template <typename T>
bool list<T>::iterator::operator!=(const iterator &other) {
  return this->current != other.current;
}

template <typename T>
list<T>::ListConstIterator::ListConstIterator() : ListIterator() {}

template <typename T>
const typename list<T>::value_type list<T>::const_iterator::operator*() {
  return iterator::operator*();
}

template <typename T>
const typename list<T>::const_iterator &list<T>::const_iterator::operator++() {
  return iterator::operator++();
}

template <typename T>
list<T>::list() : head(nullptr), tail(nullptr), list_size(0) {
  base = new Node();
}

template <typename T>
list<T>::list(size_type n) : list() {
  for (size_type i = 0; i < n; i++) {
    push_back(value_type{});
  }
}

template <typename T>
list<T>::list(const std::initializer_list<value_type> &items) : list() {
  for (auto val : items) {
    push_back(val);
  }
}

template <typename value_type>
list<value_type>::list(const list &other) : list() {
  Node *tmp = other.head;
  while (tmp != other.base) {
    this->push_back(tmp->value);
    tmp = tmp->next;
  }
}

template <typename T>
list<T>::list(list &&s) : list() {
  swap(s);
}

template <typename value_type>
list<value_type> &list<value_type>::operator=(list &&s) {
  this->swap(s);
  return *this;
}

template <typename T>
list<T>::~list() {
  clear();
  delete base;
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::begin() {
  return iterator(head);
}

template <typename value_type>
typename list<value_type>::iterator list<value_type>::end() {
  return iterator(base);
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  if (empty()) throw std::logic_error("List is empty");
  return head->value;
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  if (empty()) throw std::logic_error("List is empty");
  return tail->value;
}

template <typename T>
bool list<T>::empty() {
  return this->list_size == 0;
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  return this->list_size;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_t>::max() / sizeof(Node) / 2;
}
template <typename T>
void list<T>::clear() {
  while (list_size) {
    pop_back();
  }
  head = nullptr;
  tail = nullptr;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  Node *new_node = new Node(value);
  new_node->value = value;
  new_node->prev = tail;
  if (tail) {
    tail->next = new_node;
  } else {
    new_node->prev = base;
  }
  new_node->next = base;
  if (!head) {
    head = new_node;
  }
  tail = new_node;
  list_size++;
  base->prev = tail;
  base->next = head;
  base->value = (int)list_size;
}

template <typename T>
void list<T>::push_front(const_reference value) {
  Node *new_node = new Node(value);
  new_node->value = value;
  new_node->next = head;
  if (head) {
    head->prev = new_node;
  } else {
    new_node->next = base;
  }
  new_node->prev = base;
  if (!tail) {
    tail = new_node;
  }
  head = new_node;
  list_size++;
  base->prev = tail;
  base->next = head;
  base->value = (int)list_size;
}

template <typename T>
void list<T>::pop_back() {
  if (!list_size) throw std::logic_error("List is empty");
  Node *tmp = tail->prev;

  if (tmp) {
    tmp->next = base;
    tail->prev->next = base;
    base->prev = tmp;
  } else
    head = nullptr;
  delete tail;
  tail = tmp;
  list_size--;
  base->value = (int)list_size;
}

template <typename T>
void list<T>::pop_front() {
  if (!list_size) throw std::logic_error("List is empty");
  Node *tmp = head->next;
  if (tmp) {
    tmp->prev = base;
    head->next->prev = base;
    base->next = tmp;
  } else
    tail = nullptr;
  delete head;
  head = tmp;
  list_size--;
  base->value = (int)list_size;
}

template <typename T>
void list<T>::swap(list &other) {
  std::swap(this->head, other.head);
  std::swap(this->tail, other.tail);
  std::swap(this->base, other.base);
  std::swap(this->list_size, other.list_size);
}

template <typename T>
void list<T>::unique() {
  iterator pos = this->begin();
  if (list_size > 1) {
    while (pos != this->end()) {
      iterator pos_perv = pos;
      ++pos;
      if (*pos == *pos_perv) {
        this->erase(pos_perv);
      }
    }
  }
}

template <typename T>
void list<T>::erase(iterator pos) {
  Node *tmp = pos.getCurrent();
  if (!tmp || tmp == base) throw std::out_of_range("iterator points to null");
  if (tmp == head) {
    pop_front();
  } else if (tmp == head) {
    pop_back();
  } else {
    Node *left = tmp->prev;
    Node *right = tmp->next;
    left->next = right;
    right->prev = left;
    delete tmp;
    list_size--;
    base->value = (int)list_size;
  }
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == this->end()) {
    push_back(value);
  } else if (pos == this->begin()) {
    push_front(value);
  } else {
    Node *right = pos.getCurrent();
    Node *left = right->prev;
    Node *new_node = new Node(value);
    new_node->prev = left;
    new_node->next = right;
    left->next = new_node;
    right->prev = new_node;
    list_size++;
    base->value = (int)list_size;
  }

  return pos;
}

template <typename T>
void list<T>::reverse() {
  list<T> tmp;
  iterator iter = this->begin();
  while (iter != this->end()) {
    tmp.push_front(*iter);
    ++iter;
  }
  this->swap(tmp);
  tmp.clear();
}

template <typename T>
void list<T>::sort() {
  if (list_size > 1) {
    for (Node *i = tail->prev; i != base; i = i->prev) {
      for (Node *j = head; j != i; j = j->next) {
        if (j->value > j->next->value) {
          value_type tmp_val = j->value;
          j->value = j->next->value;
          j->next->value = tmp_val;
          /*Node *tmp_next = j->next;
          Node *tmp = j;
          std::swap(tmp_next, tmp);*/
        }
      }
    }
  }
}

template <typename T>
void list<T>::splice(iterator pos, list &other) {
  iterator iter = other.begin();
  for (size_t i = 0; i < other.size(); ++i) {
    insert(pos, *iter);
    ++iter;
  }
  other.clear();
}

template <typename T>
void list<T>::merge(list &other) {
  if (this != &other) {
    iterator iter = begin();
    iterator iter_other = other.begin();
    while (iter != this->end() && iter_other != other.end()) {
      if (*iter_other < *iter) {
        Node *tmp = iter_other.getCurrent();
        // Node *tmp_prev = tmp->prev;
        Node *tmp_next = tmp->next;
        Node *node_this = iter.getCurrent();
        Node *node_prev = node_this->prev;
        ++iter_other;
        other.head = tmp_next;
        // if (tmp_prev) tmp_prev->next = tmp_next;
        if (tmp_next) tmp_next->prev = nullptr;
        tmp->prev = nullptr;
        tmp->next = nullptr;
        --other.list_size;
        tmp->next = node_this;
        tmp->prev = node_prev;
        if (node_prev) node_prev->next = tmp;
        node_this->prev = tmp;
        list_size++;
        base->value = (int)list_size;
      } else {
        ++iter;
      }
    }
    splice(end(), other);
  }
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  insert_many(begin(), args...);
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  std::initializer_list<value_type> items{args...};
  for (auto val : items) {
    push_back(val);
  }
}

template <typename T>
template <typename... Args>
typename list<T>::iterator list<T>::insert_many(iterator pos, Args &&...args) {
  std::initializer_list<value_type> items{args...};
  iterator iter = pos;
  iterator result;
  for (auto val : items) {
    result = insert(iter, val);
  }
  return result;
}

}  // namespace s21