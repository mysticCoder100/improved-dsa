#include <iostream>
#include <vector>
//
// Created by abdul on 27/02/2026.
//

namespace DSA {
    auto count = 0;
    void heapMake();
    void addToHeap(std::vector<int> &heap, int value);
    void minHeapify(std::vector<int> &heap);
    void remove(std::vector<int> &heap, int value);
    int findIndex(std::vector<int> &heap, int value);

    void runHeap() {
        heapMake();
    };

    void heapMake() {
        std::vector<int> heap = {5,6,7,3,2,3,65,4,64,6,43,33,25};
        count = heap.size();
        int item;
        std::cout<<"Enter number of items: ";
        std::cin >> item;
        std::cout<<std::endl;

        addToHeap(heap, item);

        if (count > 0)
            std::cout<<heap[count -1];
        else
            std::cout<<"Empty heap";

        std::cout<<std::endl;

        // Getting the heap's item's

        for (const auto &x : heap) {
            std::cout << x << ", ";
        }
        std::cout<<std::endl;
    }

    void addToHeap(std::vector<int> &heap, int value) {
        heap.push_back(value);
        count++;
        minHeapify(heap);
    }

    void remove(std::vector<int> &heap, int value) {
        int index = findIndex(heap, value);
    }

    int findIndex(std::vector<int> &heap, int value) {
        int index = -1;
        int itr = 0;
        while ( itr < count) {
           ++itr;
        }

        return index;
    }

    void minHeapify(std::vector<int> &heap) {
        int i = count - 1;

        while (i > 0 && heap[i] < heap[(i-1)/2]) {
            std::swap(heap[i], heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }
};