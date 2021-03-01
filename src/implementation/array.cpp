#ifndef ARRAY_CPP
#define ARRAY_CPP

#include <cstdio>
#include <stdexcept>

#include "ptr_it.cpp"

template <class ValType, size_t S>
class Array {
 public:
  using Iterator = PointerIterator<ValType>;
  using ConstIterator = PointerIterator<const ValType>;

  Array() {}
  Array(const ValType& defaultVal) { fill(defaultVal); }
  Array(const Array& that) {
    for (int i = 0; i < S; i++) data[i] = that.data[i];
  }

  ValType& operator=(const Array& that) {
    for (int i = 0; i < S; i++) data[i] = that.data[i];
  }
  ValType& operator[](size_t index) { return data[index]; }
  const ValType& operator[](size_t index) const { return data[index]; }

  ValType& at(size_t index) {
    if (index >= S) throw std::out_of_range("Array out of bounds.");
    return data[index];
  }
  const ValType& at(size_t index) const {
    if (index >= S) throw std::out_of_range("Array out of bounds.");
    return data[index];
  }

  void fill(const ValType& val) {
    for (ValType& d : data) d = val;
  }

  void iota(ValType&& val) {
    for (ValType& d : data) d = val++;
  }

  void iota(const ValType& val) { return iota(ValType(val)); }

  void swap(Array& that) {
    for (int i = 0; i < S; i++) {
      std::swap(data[i], that.data[i]);
    }
  }

  Iterator begin() { return Iterator(data); }
  ConstIterator begin() const { return ConstIterator(data); }

  Iterator end() { return Iterator(data + S); }
  ConstIterator end() const { return ConstIterator(data + S); }

  constexpr size_t size() const { return S; }

 private:
  ValType data[S];
};

int main() {
  constexpr int n = 15;
  Array<int, n> arr(0);

  arr.iota(0);
  for (int x : arr) {
    printf("%d\n", x);
  }

  arr[0] = arr[1] = 1;
  for (int i = 1; i < n; i++) arr[i] = arr[i - 1] + arr[i - 2];

  for (int x : arr) {
    printf("%d\n", x);
  }
}
#endif