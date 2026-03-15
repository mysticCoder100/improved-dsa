//
// Created by abdul on 06/03/2026.
//

#ifndef IMPROVED_DSA_DOUBLY_LIST_H
#define IMPROVED_DSA_DOUBLY_LIST_H

void doublyDemo();

template<typename T>
struct DLLNode {
    T data{};
    DLLNode<T> *next = nullptr;
    DLLNode<T> *prev = nullptr;

    explicit DLLNode(T data = {}, DLLNode *next = nullptr,
                     DLLNode *prev = nullptr) : data{data}, next{next}, prev{prev} {
    }
};

/**
 * Having a sentinel head and tail
 */
template<typename T>
class DoublyList {
    DLLNode<T> *head = nullptr, *tail = nullptr;

public:
    explicit DoublyList() {
        head = new DLLNode<T>;
        tail = new DLLNode<T>;

        head->next = tail;
        tail->prev = head;
    }

    ~ DoublyList() {
        DLLNode<T> *curr = head;

        while (curr != nullptr) {
            head = curr->next;
            delete curr;
            curr = head;
        }

        tail = nullptr;
    }

    void addHead(T d) {
        auto *node = new DLLNode<T>{d, head->next, head};
        node->next->prev = node;
        head->next = node;
    }

    void addTail(T d) {
        auto *node = new DLLNode<T>{d, tail, tail->prev};
        node->prev->next = node;
        tail->prev = node;
    }

    T removeFromHead() {
        DLLNode<T> *toRemove = head->next;
        T data = toRemove->data;
        head->next = toRemove->next;
        toRemove->prev = head;
        delete toRemove;
        return data;
    }


    T removeFromTil() {
        DLLNode<T> *toRemove = tail->pev;
        T data = toRemove->data;
        head->next = toRemove->next;
        toRemove->prev = head;
        delete toRemove;
        return data;
    }
};

#endif //IMPROVED_DSA_DOUBLY_LIST_H
