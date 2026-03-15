//
// Created by abdul on 11/03/2026.
//

#ifndef IMPROVED_DSA_BST_H
#define IMPROVED_DSA_BST_H
#include <queue>

void bstDemo();

template<typename T>
struct BstNode {
    T data{};
    BstNode<T> *left = nullptr;
    BstNode<T> *right = nullptr;

    BstNode(T data, BstNode<T> *l = nullptr, BstNode<T> *r = nullptr) : data{data}, left{l}, right{r} {
    }
};

template<typename T>
class Bst {
    BstNode<T> *root = nullptr;

public:
    Bst() : root{nullptr} {
    }

    T *search(T s) const {
        BstNode<T> *itr = root;

        while (itr != nullptr) {
            if (itr->data == s) return &itr->data;

            if (itr->data > s) itr = itr->left;
            else itr = itr->right;
        }

        return nullptr;
    }

    void BreadthFirstSearch() {
        std::queue<BstNode<T> *> q;
        BstNode<T> *itr = root;

        if (itr != nullptr) {
            q.enqueue(itr);
            while (!q.empty()) {
                itr = q.dequeue();
                visit(itr);
                if (itr->left != nullptr) q.enqueue(itr->left);
                if (itr->right != nullptr) q.enqueue(itr->right);
            }
        }
    }
};


#endif //IMPROVED_DSA_BST_H
