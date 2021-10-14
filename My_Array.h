#pragma once

#include <iostream>

template <typename T>
class MyArray
{
public:
    MyArray(size_t arrSize = 0, T defValue = T());
    ~MyArray();
    MyArray(const MyArray &);
    MyArray(MyArray &&);

    MyArray& operator=(const MyArray &);
    MyArray& operator=(MyArray &&);
    T& operator[](size_t) const;

    void resize(size_t newSize, T defValue = T());
    void push_back(T);
    void pop_back();
    size_t GetArrSize() const;
    void PrintArr() const;

private:
    T *arrPtr;
    size_t arrSize;
};

#include "My_Array.cpp"