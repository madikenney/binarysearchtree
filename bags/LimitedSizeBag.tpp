#include "LimitedSizeBag.hpp"

template<typename T>
LimitedSizeBag<T>::LimitedSizeBag() {
  size = 0;
}
  
template<typename T>
bool LimitedSizeBag<T>::add(const T& item)
{
  if(size>100){
    return false;
  }
  Bag[size] = item;
  size++;
  return true;
}

template<typename T>
bool LimitedSizeBag<T>::remove(const T& item)
{
  for(int i=0; i<size; i++){
    if(Bag[i] == item){
      for(int j=i; j<size-1; j++){
        Bag[j]=Bag[j+1];
      }
      size--;
      return true;
    }
  }
  return false;
}

template<typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return false;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool LimitedSizeBag<T>::contains(const T& item) const
{  
  return false;
}

template<typename T>
void LimitedSizeBag<T>::clear(){
  size=0;
}

template<typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T & item) const
{
  return 0;
};
