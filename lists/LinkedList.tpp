#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  length = 0;
  head = nullptr;
  tail = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  delete head;
  delete tail;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &x)
{
  // TODO
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> x)
{
  // TODO (use copy swap idiom)
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList &x)
{
  // TODO
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  return (length==0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  return length;
}

template <typename T>
void LinkedList<T>::insert(std::size_t position, const T &item)
{
  if(position > length){
    throw std::out_of_range("Out of bounds");
  }

  for(int i=0; i<position; i++){

  }

}

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
  // TODO
}

template <typename T>
void LinkedList<T>::clear()
{
  length = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  // TODO
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T &newValue)
{
  // TODO
}
