#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
namespace amir{
    using namespace std;

    template <typename T>
    class Vector{
    private:
        T* arrayOfElements;
        int size;
        int capacity;
    public:
        Vector();
        Vector(int count);
        Vector(int count, const T& value);
        Vector(const Vector& other);
        Vector(Vector&& other);
        ~Vector();
        T& operator[](int pos);
        T at(int pos);
        T& front();
        T& back();
        bool empty() noexcept;
        int Size() const noexcept;
        int Capacity();
        void reserve(int new_cap);
        void resize(int count);

        void push_back(const T& value);
        void push_back(T&& value);
        void pop_back();
        void clear() noexcept;
        Vector<T>& operator=(const Vector& o);
        Vector<T>& operator=(Vector&& o);
        Vector<T>&operator+=(const T& value);
        Vector<T>&operator+=(const Vector<T>& o);
        Vector<T>& operator--();
        Vector<T>& operator++();

        Vector<T>& operator--(int);
        Vector<T>& operator++(int);
    };

    class concatenate_error : public invalid_argument {
    public:
        concatenate_error(const string& message):invalid_argument(message){};
    };

}


#endif
