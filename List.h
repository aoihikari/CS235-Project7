#include <iostream>
#include <string>
#pragma once

using namespace std;

template <typename ItemType>

class List {

private:

  struct Node {

    ItemType item;
    Node* next;
    Node* prev;

    Node(const ItemType _item) : item(_item), next(NULL), prev(NULL) {}
  };

  Node* head;
  Node* tail;
  Node* e;
  Node* r;
  int size;

public:
  List() : head(NULL), tail(NULL), size(0) {}

  void insert(const ItemType& item) {
    if (size == 0){
      e = new Node(item);
      head = e;
      tail = e;
      size++;
    }
    else{
      r = new Node(item);
      r->next = NULL;
      r->prev = tail;
      tail->next = r;
      tail = r;
      size++;
    }
  }

  ItemType get_item() {

    return head->item;
  }

  int getsize() {

    return size;
  }

  void remove() {

    if (size == 1){
      head = NULL;
      delete tail;
      tail = NULL;
      size--;
    }
    else{
      if (size != 0){
        e = head->next;
        e->prev = NULL;
        delete head;
        head = e;
        size--;
      }
    }
  }

  ~List()
  {
    e = head;
    while (e != NULL)
    {
      r = e->next;
      delete e;
      e = r;
    }
    head = NULL;
    tail = NULL;
    size = 0;
  }
};