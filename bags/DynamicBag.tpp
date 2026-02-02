#include "DynamicBag.hpp"
#include <utility>

template<typename T>
DynamicBag<T>::DynamicBag() {
  bag = new T[0];
}
  

template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x){
  bag = new T[size];
  for(int i=0; i<size; i++){
    bag[i] = x.bag[i];
  }
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete[] bag;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  std::swap(bag, x.bag);
  std::swap(size, x.size);
  
  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  int newSize = size++;
  T* newBag = new T[newSize];

  for(int i=0; i<newSize; i++){
    newBag[i] = bag[i];
  }

  delete[] bag;
  bag = newBag;
  size = newSize;

  bag[size] = item;

  return true;
}

template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  for(int i=0; i<newSize; i++){
    if(bag[i] == item){
      int newSize = size--;
      T* newBag = new T[newSize];
      
      for(int j=i; j<size-1; j++){
        newBag[j]=bag[j+1];
      }

      for(int k=0; k<i; k++){
        newBag[k]=bag[k];
      }

      delete[] bag;
      bag = newBag;
      size = newSize;
      return true;
    }
  }

  return false;
  
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  if(size==0){
    return true;
  }
  return false;
}

template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for(int i=0; i<size; i++){
    if(item == Bag[i]){
      return true;
    }
  }
  return false;
}

template<typename T>
void DynamicBag<T>::clear(){
  T* newBag = new T[0];
  delete[] bag;
  bag = newBag;
  size = 0;
}

template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  int count = 0;
  for(int i=0; i<size; i++){
    if(item == bag[i]){
      count++;
    }
  }
  return count;
};
