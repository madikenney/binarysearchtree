#include "ListIterator.hpp"

/* Change the second constructor argument to Node<T>* if using a linked implementation */
template <typename T>
inline ListIterator<T>::ListIterator(List<T> *listPtr, T *itemPtr)
{
    list = listPtr;
    current = itemPtr;
}

template <typename T>
inline T ListIterator<T>::operator*() const
{
    return *current;
}

template <typename T>
inline ListIterator<T> ListIterator<T>::operator++()
{
    current++;
    return *this; // return dereferenced version of current
}

template <typename T>
inline bool ListIterator<T>::operator==(const ListIterator<T> &rhs) const
{
    return current == rhs.current;
}

template <typename T>
inline bool ListIterator<T>::operator!=(const ListIterator<T> &rhs) const
{
    return !(current==rhs.current);
}