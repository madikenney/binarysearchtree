#include "ArrayList.hpp"

template <typename T>
ArrayList<T>::ArrayList()
{
  arr = new T[0];
  length = 0;
}

template <typename T>
ArrayList<T>::~ArrayList() 
{
  delete[] arr;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList &x) 
{ 
  arr = new T[x.getLength()];
  for(int i=0; i<x.getLength(); i++){
    arr[i] = x.getEntry(i);
  }

  length = x.getLength();
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList x)
{
  swap(x);
  return *this;
}

template <typename T>
void ArrayList<T>::swap(ArrayList &x) 
{
  std::swap(arr,x.arr);
  std::swap(length,x.length);
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept
{
  return (length==0);
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void ArrayList<T>::insert(std::size_t position, const T &item)
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
void ArrayList<T>::remove(std::size_t position)
{
  if(position >= length){
    throw std::out_of_range("Out of bounds");
  }

  T* newArr = new T[length-1];
}

template <typename T>
void ArrayList<T>::clear() 
{
  // TODO
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const
{
  if(position >= length){
    throw std::out_of_range("Out of bounds");
  }
  return arr[position];
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T &newValue) 
{
  // TODO
}
