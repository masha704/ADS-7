// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
  public:
      TPQueue(): head(nullptr), tail(nullptr){}
      void push (const T&);
      T pop();
  private:
      struct ITEM {
          T value;
          ITEM *next;
          ITEM *prew;
      };
      TPQueue:: ITEM *create(const T&);
      ITEM *head;
      ITEM *tail;
};

struct SYM {
  char ch;
  int prior;
};

template<typename T>
typename TPQueue<T>:: ITEM *TPQueue <T> create( const T& value) {
  ITEM * temp = new ITEM;
  item->value = value;
  item->next = nullptr;
  item->prev = nullptr;
  return temp;
}

void TPQueue <T>:: push(const T& data) {
  ITEM *temp = head;
  ITEM* item = create(value);
  while(temp && temp->value.prior >= data.prior) {
    temp = temp->next;
  }
  if (!temp && head) {
    tail ->next = item;
    item->ptev=tail;
    tail=item;
  } else if(!temp && !haed) {
    head = tail = item;
  } else if (!temp->prev) {
    head->prev = item;
    item->next = head;
    head = item;
  } else {
    temp->prev->next = item;
    item->prev = temp->prev;
    item->next = temp;
    temp->prev = item;
  }
}

template<typename T>
T TPQueue<T>::pop() {
  if(haed && tail) {
    ITEM* temp = head->next;
    if(temp) {
      temp->prev = nullptr;
    }
    T data = head->value;
    delete head;
    head = temp;
    if(!head){
      tail = nullptr;
    }
    return data;
  } else {
    throw std::string ("Is Empty!");
  }
}

#endif  // INCLUDE_TPQUEUE_H_
