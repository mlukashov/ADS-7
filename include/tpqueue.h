// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
    struct Item {
        T value;
        Item* next;
    };
    Item* head;


 public:
    TPQueue() :head(nullptr) {}
    void push(const T& data);
    T pop();
};
template<typename T>
T TPQueue<T>::pop() {
    if (head == NULL) {
        throw std::string("Empty");
    } else {
        T data = head->value;
        Item* mull = head->next;
        delete head;
        head = mull;
        return data;
    }
}
template<typename T>
void TPQueue<T>::push(const T& data) {
    if (head == NULL) {
        Item* temp = new Item;
        temp->value = data;
        temp->next = NULL;
        head = temp;
    } else {
        Item* tek = head;
        Item* mull = new Item;
        uint64_t f = 0;
        while (tek) {
            if (tek->value.prior < data.prior) {
                break;
            } else {
                tek = tek->next;
                f++;
            }
        }
        if (f == 0) {
            mull->next = head;
            mull->value = data;
            head = mull;
        } else {
            tek = head;
            for (int i = 1; i < f; i++) {
                tek = tek->next;
            }
            mull->next = tek->next;
            mull->value = data;
            tek->next = mull;
        }
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
