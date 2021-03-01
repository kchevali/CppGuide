#ifndef PTR_IT_CPP
#define PTR_IT_CPP

template <typename ValType>
class PointerIterator {
 public:
  PointerIterator(ValType* ptr) : ptr(ptr) {}

  PointerIterator& operator++() {
    ptr++;
    return *this;
  }
  PointerIterator operator++(int) {
    PointerIterator tmp = *this;
    ptr++;
    return tmp;
  }
  PointerIterator& operator--() {
    ptr--;
    return *this;
  }
  PointerIterator operator--(int) {
    PointerIterator tmp = *this;
    ptr--;
    return tmp;
  }

  PointerIterator& operator+=(int value) {
    ptr += value;
    return *this;
  }
  PointerIterator& operator-=(int value) {
    ptr -= value;
    return *this;
  }
  PointerIterator operator+(int value) { return PointerIterator(ptr + value); }
  PointerIterator operator-(int value) { return PointerIterator(ptr - value); }

  ValType& operator*() { return *ptr; }
  ValType* operator->() { return ptr; }

  ValType& operator[](size_t index) { return *(ptr + index); }

  bool operator==(const PointerIterator& that) const { return ptr == that.ptr; }
  bool operator!=(const PointerIterator& that) const { return ptr != that.ptr; }

 private:
  ValType* ptr;
};

#endif