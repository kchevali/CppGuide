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
    fill(defaultVal);
  }
  Vector(int length) : length(length) { allocate(3 * length / 2); }
  Vector(const Vector& that) : length(that.length) {
    allocate(that.cap);
    copy(that.data);
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

  void fill(const ValType& val) {
    for (int i = 0; i < length; i++) data[i] = val;
  }

  void iota(ValType&& val) {
    for (int i = 0; i < length; i++) data[i] = val++;
  }

  void iota(const ValType& val) { return iota(ValType(val)); }

  void clear() { length = 0; }

  void push_back(ValType& val) {
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
  void copy(const ValType* that) {
    for (size_t i = 0; i < length; i++) data[i] = that[i];
  }

  void copy(const Vector& that) {
    length = that.length;
    if (length >= cap) {
      delete[] data;
      allocate(that.cap);
    }
    copy(that.data);
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
  Vector<int> v(2, 1);
  for (int i = 2; i < 30; i++) {
    v.push_back(v[i - 1] + v[i - 2]);
  }

  for (int num : v) {
    printf("%d\n", num);
  }
}
#endif