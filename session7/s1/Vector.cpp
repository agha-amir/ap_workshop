#include "Vector.h"
using namespace amir;
template <typename T>
Vector<T>::Vector() : size(0), capacity(1) {
    arrayOfElements = new T[capacity];
}

template <typename T>
Vector<T>::Vector(int count) : size(count), capacity(count) {
    arrayOfElements = new T[capacity];
}

template <typename T>
Vector<T>::Vector(int count, const T& value) : size(count), capacity(count) {
    arrayOfElements = new T[capacity];
    for (int i = 0; i < size; ++i) {
        arrayOfElements[i] = value;
    }
}

template <typename T>
Vector<T>::Vector(const Vector& o) : size(o.size), capacity(o.capacity) {
    arrayOfElements = new T[capacity];
    for (int i = 0; i < size; ++i) {
        arrayOfElements[i] = o.arrayOfElements[i];
    }
}

template <typename T>
Vector<T>::Vector(Vector&& o) : arrayOfElements(o.arrayOfElements), size(o.size), capacity(o.capacity) {
o.arrayOfElements = nullptr;
o.size = 0;
o.capacity = 0;
}

template <typename T>
Vector<T>::~Vector() {
    delete[] arrayOfElements;
}

template <typename T>
T &Vector<T>::operator[](int pos) {
    return arrayOfElements[pos];
}

template <typename T>
T Vector<T>::at(int pos) {
    if(pos >= size){throw out_of_range("out of range");}
    return arrayOfElements[pos];
}

template <typename T>
bool Vector<T>::empty() noexcept {
    return this->size == 0;
}

template <typename T>
T &Vector<T>::back() {
    if(empty()){throw out_of_range("empty vector");}
    return arrayOfElements[size - 1];
}

template <typename T>
T &Vector<T>::front() {
    if(empty()){throw out_of_range("empty vector");}
    return this->arrayOfElements[0];
}

template <typename T>
int Vector<T>::Size() const noexcept {
    return size;
}

template <typename T>
int Vector<T>::Capacity(){
    return this->capacity;
}


template <typename T>
void Vector<T>::reserve(int new_cap) {
    if(new_cap <= capacity){return;}

    T* newArrayOfElements = new T[new_cap];
    for (int i = 0; i < size; i++){
        newArrayOfElements[i] = arrayOfElements[i];
    }
    delete[] arrayOfElements;
    arrayOfElements = newArrayOfElements;
    capacity = new_cap;
}

template <typename T>
void Vector<T>::resize(int count) {
    if(count < size){size = count;}
    else{
        reserve(count);
        for (int i = size; i < count; ++i) {
            arrayOfElements[i] = T();
        }
        size = count;
    }
}

template <typename T>
void Vector<T>::push_back(const T &value){
    if(capacity == size){
        reserve(capacity * 2);
    }
    this->arrayOfElements[size] = move(value);
    size++;

}

template <typename T>
void Vector<T>::push_back(T &&value) {
    if (size == capacity) {
        reserve(capacity * 2);
    }
    arrayOfElements[size] = value;
    size++;


}

template <typename T>
void Vector<T>::pop_back() {
    if(!size){throw out_of_range("empty vector");}
    size --;
}

template <typename T>
void Vector<T>::clear() noexcept {
    size = 0;
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &o) {
    if(this != &o){
        size = o.size;
        capacity = o.capacity;
        delete[] arrayOfElements;
        arrayOfElements = new T[capacity];

        for (int i = 0; i < size; ++i) {
            arrayOfElements[i] = o.arrayOfElements[i];
        }
    }
    return *this;
}


template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> && o) {
    if(this != &o){
        size = o.size;
        capacity = o.capacity;
        delete[] arrayOfElements;
        arrayOfElements = o.arrayOfElements;

        o.size = 0;
        o.capacity = 0;
        o.arrayOfElements = nullptr;
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const T &value) {
    push_back(value);
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator+=(const Vector<T> &o) {
    if(o.empty()){
        throw concatenate_error("the other vector is empty");
    }
    for (int i = 0; i < o.size; ++i) {
        push_back(o.arrayOfElements[i]);
    }
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator--() {
    if (empty()) {
        throw out_of_range("empty vector");
    }
    for (int i = 0; i < size-1; ++i) {
        arrayOfElements[i] = move(arrayOfElements[i + 1]);
    }
    size --;
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator++() {
    if (size == capacity) {
        reserve(capacity * 2);
    }
    for (int i = size; i > 0; --i) {
        arrayOfElements[i] = std::move(arrayOfElements[i - 1]);
    }
    size++;
    return *this;
}


template <typename T>
Vector<T> &Vector<T>::operator--(int) {
    if (empty()) {
        throw out_of_range("empty vector");
    }
    for (int i = 0; i < size-1; ++i) {
        arrayOfElements[i] = move(arrayOfElements[i + 1]);
    }
    size --;
    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator++(int) {
    if (size == capacity) {
        reserve(capacity * 2);
    }
    for (int i = size; i > 0; --i) {
        arrayOfElements[i] = std::move(arrayOfElements[i - 1]);
    }
    size++;
    return *this;
}
