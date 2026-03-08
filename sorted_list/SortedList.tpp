#include "SortedList.hpp"
#include <stdexcept>

template <typename T>
SortedList<T>::SortedList()
{
  // base constructor gets called automatically
}

template <typename T>
SortedList<T>::SortedList(List<T> unsorted_list) 
{
  for(int i=0; i<unsorted_list.getLength(); i++){
    insert(unsorted_list.getEntry(i));
  }
}

template <typename T>
SortedList<T>::SortedList(const SortedList<T> & x):
  List<T>(x)
{
}

template <typename T>
SortedList<T>& SortedList<T>::operator=(SortedList<T> x)
{
  List<T>::operator=(x);
  return *this;
}

template <typename T>
SortedList<T>::~SortedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedList<T>::isEmpty() const noexcept
{
  return List<T>::isEmpty();
}

template <typename T>
std::size_t SortedList<T>::getLength() const noexcept
{
  return List<T>::getLength();
}

template <typename T>
void SortedList<T>::insert(const T& item)
{
  if(List<T>::getLength() == 0){
    List<T>::insert(0, item);
    return;
  }
  
  int i = 0;
  while(i < List<T>::getLength() && List<T>::getEntry(i) < item){
    i++;
  }
  List<T>::insert(i, item);
}

template <typename T>
void SortedList<T>::remove(const T& item)
{  
  List<T>::remove(SortedList<T>::getPosition(item));
}

template <typename T>
void SortedList<T>::removeAt(std::size_t position)
{  
  // TODO
}

template <typename T>
void SortedList<T>::clear()
{
  List<T>::clear();
}

template <typename T>
T SortedList<T>::getEntry(std::size_t position) const
{
  return List<T>::getEntry(position);
}

template <typename T>
std::size_t SortedList<T>::getPosition(const T& item)
{
  int position = -1;
  for(int i=0; i<List<T>::getLength(); i++){
    if(List<T>::getEntry(i) == item){
      position = i;
      break;
    }
  }
  if(position == -1){
    throw std::invalid_argument("Item not found!");
  } else {
    return position;
  }
}
