#include "My_Array.h"

template <typename T>
MyArray<T>::MyArray(size_t arrSize, T defValue)
{
    this->arrSize = arrSize;

    if (arrSize > 0)
    {
        arrPtr = new T[arrSize];

        for (auto i = 0; i != arrSize; ++i)
            arrPtr[i] = defValue;
    }
    else
        arrPtr = nullptr;
}

template <typename T>
MyArray<T>::~MyArray()
{
    if (arrPtr != nullptr)
        delete[] arrPtr;
}

template <typename T>
MyArray<T>::MyArray(const MyArray &arrToCopy)
{
    arrSize = arrToCopy.GetArrSize();
    arrPtr = new T[arrSize];

    for (auto i = 0; i < arrSize; ++i)
        arrPtr[i] = arrToCopy[i];
}

template <typename T>
MyArray<T>::MyArray(MyArray &&arrToMove)
{
    arrSize = arrToMove.GetArrSize();

    arrPtr = arrToMove.arrPtr;
    arrToMove.arrPtr = nullptr;
}

template <typename T>
MyArray<T> &MyArray<T>::operator=(const MyArray &arrToCopy)
{
    if (&arrToCopy == this)
        return *this;

    if (arrPtr != nullptr)
        delete[] arrPtr;
    arrSize = arrToCopy.arrSize;
    arrPtr = new T[arrSize];

    for (auto i = 0; i < arrSize; ++i)
        arrPtr[i] = arrToCopy[i];

    return *this;
}

template <typename T>
MyArray<T> &MyArray<T>::operator=(MyArray &&arrToMove)
{
    if (&arrToMove == this)
        return *this;

    if (arrPtr != nullptr)
        delete[] arrPtr;

    arrSize = arrToMove.GetArrSize();

    arrPtr = arrToMove.arrPtr;
    arrToMove.arrPtr = nullptr;

    return *this;
}

template <typename T>
T &MyArray<T>::operator[](size_t idx) const
{
    if (idx > arrSize)
        throw "Out of range";
    else
        return arrPtr[idx];
}

template <typename T>
void MyArray<T>::resize(size_t newSize, T defValue)
{
    if (arrSize == newSize)
        return;

    if (newSize == 0)
    {
        arrSize = newSize;
        delete[] arrPtr;
        arrPtr = nullptr;

        return;
    }

    T *newArrPtr = new T[newSize];

    if (arrSize > newSize)
        for (auto i = 0; i != newSize; ++i)
            newArrPtr[i] = arrPtr[i];
    else
    {
        for (auto i = 0; i != arrSize; ++i)
            newArrPtr[i] = arrPtr[i];

        for (auto i = arrSize; i != newSize; ++i)
            newArrPtr[i] = defValue;
    }

    arrSize = newSize;
    delete[] arrPtr;
    arrPtr = newArrPtr;
}

template <typename T>
void MyArray<T>::push_back(T element)
{
    resize(arrSize + 1, element);
}

template <typename T>
void MyArray<T>::pop_back()
{
    resize(arrSize - 1);
}

template <typename T>
size_t MyArray<T>::GetArrSize() const
{
    return arrSize;
}

template <typename T>
void MyArray<T>::PrintArr() const
{
    for (auto i = 0; i < arrSize; ++i)
        std::cout << arrPtr[i] << " ";
    std::cout << std::endl;
}