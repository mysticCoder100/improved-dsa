#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <algorithm>

template <typename Object> class MyVector {
  int size;
  int capacity;
  Object *arr;

public:
  static const int spareCapacity = 16;

  explicit MyVector(int intiSize = 0)
      : size(intiSize), capacity(intiSize + spareCapacity) {
    arr = new Object[capacity];
  }

  MyVector(const MyVector &rhs)
      : size{rhs.size}, capacity{rhs.capacity}, arr{nullptr} {
    arr = new Object[capacity];
    for (int k = 0; k < size; k++) {
      arr[k] = rhs[k];
    }
  }

  MyVector &operator=(const MyVector &rhs) {
    MyVector copy = rhs;
    std::swap(*this, copy);
    return *this;
  }

  ~MyVector() { delete[] arr; }

  MyVector(MyVector &&rhs)
      : size{rhs.size}, capacity{rhs.capacity}, arr{rhs.arr} {
    rhs.size = 0;
    rhs.capacity = 0;
    rhs.arr = nullptr;
  }

  MyVector &operator=(MyVector &&rhs) {
    std::swap(capacity, rhs.capacity);
    std::swap(size, rhs.size);
    std::swap(arr, rhs.arr);
    return *this;
  }

  void resize(const int newSize) {
    if (newSize > capacity)
      reserve(newSize * 2);

    size = newSize;
  }

  void reserve(const int newCapacity) {

    if (newCapacity < size)
      return;

    Object *tempArray = new Object[newCapacity];
    for (int i = 0; i < size; ++i) {
      tempArray[i] = std::move(arr[i]);
    }
    capacity = newCapacity;
    std::swap(arr, tempArray);
    delete[] tempArray;
  }

  const Object &operator[](const int index) const { return arr[index]; }
  Object &operator[](const int index) { return arr[index]; }

  bool empty() const { return getSize() == 0; }
  int getSize() const { return size; }
  int getCapacity() const { return capacity; }

  void push_back(const Object &newItem) {
    if (size == capacity)
      resize(2 * capacity + 1);

    arr[size++] = newItem;
  }

  void push_back(Object &&newItem) {
    if (size == capacity)
      resize(2 * capacity + 1);

    arr[size++] = std::move(newItem);
  }

  const Object &back() const { return arr[size - 1]; }

  void pop_back() { --size; }

  typedef Object *iterator;
  const typedef Object *const_iterator;

  iterator begin() { return &arr[0]; }
  const_iterator begin() const { return &arr[0]; }

  iterator end() { return &arr[getSize()]; }
  const_iterator end() const { return &arr[getSize()]; }
};

#endif // MY_VECTOR_H