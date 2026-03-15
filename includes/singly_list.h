//
// Created by abdul on 05/03/2026.
//

#ifndef IMPROVED_DSA_SINGLY_LIST_H
#define IMPROVED_DSA_SINGLY_LIST_H

template<typename T>
struct Node {
    explicit Node(const T d = 0): data{d}, next {nullptr} {}

    T data;
    Node* next;
};

template<typename T>
class SinglyLinkList {
    Node<T> *head = nullptr, *tail = nullptr;

public:
    explicit SinglyLinkList() {}

    ~SinglyLinkList() {
        auto *curr = head;
        while (curr != nullptr) {
            curr = head->next;
            delete head;
            head = curr;
        }
    }

    void addHead(const T d) {
        auto *node = new Node<T>(d);
        node->next = head;
        head = node;
        if (tail == nullptr)
            tail = head;
    }

    void addTail(const T d) {
        auto *node = new Node<T>(d);
        if (tail != nullptr) {
            tail->next = node;
            tail = node;
        } else {
            tail = head = node;
        }
    }

    bool empty() const {
        return head == nullptr;
    }

    T deleteFromHead() {
        if (empty())
            throw ("Empty list");

        auto *temp = head;
        T val = temp->data;

        if (head == tail)
            head = tail = nullptr;
        else
            head = head->next;

        delete temp;
        return val;
    }

    T deleteFromTail() {
        if (empty())
            throw ("Empty list");

        auto *currTail = tail;
        T val = tail->data;

        if (head == tail) {
            head = tail = nullptr;
        }else {
            auto *temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = nullptr;
            tail = temp;
        }

        delete currTail;
        return val;
    }

    void remove(T data) {
        if (head != nullptr) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            }

            else if (head->data == data ) {
                auto *temp = head; // copy head to temp
                head = head->next;
                delete temp;
            } else {
                Node<T> *pred, *curr;

                for (pred = head, curr = head->next; curr != nullptr && curr->data != data;) {
                    pred = curr;
                    curr = curr->next;
                }

                if (curr != nullptr) {
                    pred->next = curr->next;
                    if (curr == tail)
                        tail = pred;
                    delete curr;
                }
            }
        }
    }

    bool inList(T el) {
        auto *curr = head;
        for (; curr != nullptr && !(curr->data == el); curr = curr->next) {}

        return curr != nullptr;
    }

};

void singlyDemo();

#endif //IMPROVED_DSA_SINGLY_LIST_H