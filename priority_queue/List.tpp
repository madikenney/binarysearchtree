#include "List.hpp"

template <typename T>
List<T>::List()
{
  arr = new T[0];
  length = 0;
}

template <typename T>
List<T>::~List()
{
  delete[] arr;
}

template <typename T>
List<T>::List(const List<T>& x)
{
  arr = new T[x.getLength()];
  for(int i=0; i<x.getLength(); i++){
    arr[i] = x.getEntry(i);
  }

  length = x.getLength();
}

template <typename T>
List<T>& List<T>::operator=(List<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void List<T>::swap(List<T>& x) 
{
  std::swap(arr,x.arr);
  std::swap(length,x.length);
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  return (length==0);
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{
  if(position > length){
    throw std::out_of_range("Out of bounds");
  }

  T* newArr = new T[length+1];

  for(int i=0; i<position; i++){
    newArr[i] = arr[i];
  }

  newArr[position] = item;

  for(int i=position; i<length; i++){
    newArr[i+1] = arr[i];
  }

  delete[] arr;

  arr = newArr;
  length++;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if(position >= length){
    throw std::out_of_range("Out of bounds");
  }

  T* newArr = new T[length-1];

  for(int i=0; i<position; i++){
    newArr[i] = arr[i];
  }

  for(int i=position+1; i<length; i++){
    newArr[i-1] = arr[i];
  }

  delete[] arr;

  arr = newArr;
  length--;
}

template <typename T>
void List<T>::clear()
{
  length = 0;
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  if(position >= length){
    throw std::out_of_range("Out of bounds");
  }
  
  return arr[position];
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue)
{
  if(position >= length){
    throw std::out_of_range("Out of bounds");
  }

  arr[position] = newValue;
}

template <typename T>
ListIterator<T> List<T>::begin() 
{
  // TODO
  return ListIterator<T>(nullptr, nullptr);
}

template <typename T>
ListIterator<T> List<T>::end() 
{
  // TODO
  return ListIterator<T>(nullptr, nullptr);
}