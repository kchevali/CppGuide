#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <algorithm>
#include <cstdio>
#include <stdexcept>

#include "ptr_it.cpp"

template <class ValType>
class Vector {
 public:
  using Iterator = PointerIterator<ValType>;
  using ConstIterator = PointerIterator<const ValType>;

  Vector() { allocate(0); }
  Vector(int length, const ValType& defaultVal) : length(length) {
    allocate(3 * length / 2);
    fill(begin(), end(), defaultVal);
  }
  Vector(int length) : length(length) { allocate(3 * length / 2); }
  Vector(const Vector& that) : length(that.length) {
    allocate(that.cap);
    copyData(that.data);
  }
  Vector(Vector&& that) { move(that); }

  Vector& operator=(const Vector& that) {
    copy(that);
    return *this;
  }
  Vector& operator=(Vector&& that) {
    move(that);
    return *this;
  }
  ValType& operator[](size_t index) { return data[index]; }
  const ValType& operator[](size_t index) const { return data[index]; }

  ValType& at(size_t index) {
    if (index >= length) throw std::out_of_range("Vector out of bounds.");
    return data[index];
  }
  const ValType& at(size_t index) const {
    if (index >= length) throw std::out_of_range("Vector out of bounds.");
    return data[index];
  }

  void fill(Iterator&& begin, const Iterator& end, const ValType& val) {
    while (begin != end) *(begin++) = val;
  }
  void fill(const Iterator& begin, const Iterator& end, const ValType& val) { return fill(Iterator(begin), end, val); }

  void iota(Iterator&& begin, const Iterator& end, ValType&& val) {
    while (begin != end) *(begin++) = val++;
  }
  void iota(const Iterator& begin, const Iterator& end, const ValType& val) { return iota(Iterator(begin), end, ValType(val)); }

  void clear() { length = 0; }

  void push_back(const ValType& val) {
    if (length >= cap) reallocate();
    data[length++] = val;
  }

  void push_back(ValType&& val) {
    if (length >= cap) reallocate();
    data[length++] = std::move(val);
  }

  ValType pop() {
    if (length == 0) throw std::out_of_range("Empty vector cannot pop.");
    return data[--length];
  }

  Iterator begin() { return Iterator(data); }
  ConstIterator begin() const { return ConstIterator(data); }

  Iterator end() { return Iterator(data + length); }
  ConstIterator end() const { return ConstIterator(data + length); }

  size_t size() const { return length; }
  size_t capacity() const { return cap; }

  virtual ~Vector() {
    length = cap = 0;
    delete[] data;
    data = nullptr;
  }

 private:
  void copyData(const ValType* that) {
    for (size_t i = 0; i < length; i++) data[i] = that[i];
  }

  void copy(const Vector& that) {
    length = that.length;
    if (length >= cap) {
      delete[] data;
      allocate(that.cap);
    }
    copyData(that.data);
  }

  void move(Vector& that) {
    length = that.length, cap = that.cap;
    delete[] data;
    data = that.data;

    that.data = nullptr;
    that.length = that.cap = 0;
  }

  void allocate(size_t cap) {
    this->cap = std::max(10UL, cap);
    data = new ValType[this->cap];
  }

  void reallocate() {
    ValType* currData = data;
    allocate(3 * cap / 2);
    length = std::min(cap, length);
    for (int i = 0; i < length; i++) data[i] = std::move(currData[i]);
    delete[] currData;
  }

  size_t length = 0, cap = 0;
  ValType* data = nullptr;
};

int main() {
  Vector<int> a;

  for (int i = 10; i >= 0; i--) {
    a.push_back(i);
  }

  a.fill(a.begin() + 1, a.begin() + 4, 99);

  for (int x : a) {
    printf("%d\n", x);
  }
}
#endif