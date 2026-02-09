#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  length = 0;
  head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &x)
{
  // TODO
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);
  return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList &x)
{
  std::swap(head,x.head);
  std::swap(length,x.length);
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
  
  Node<T>* newNode = new Node<T>(item);

  if(position == 0){
    newNode->setNext(head);
    head = newNode;
    length++;
    return;
  }

  Node<T>* previous = head;
  for(int i=0; i<position-1; i++){
    previous = previous->getNext();
  }

  newNode->setNext(previous->getNext());
  previous->setNext(newNode);

  length++;
}

template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
  if(position >= length){
    throw std::out_of_range("Out of bounds");
  }

  Node<T>* current = head;
  for(int i=0; i<position-1; i++){
    current = current->getNext();
  }

  current->setNext(current->getNext()->getNext());
  length--;
}

template <typename T>
void LinkedList<T>::clear()
{
  length = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  if(position >= length){
    throw std::out_of_range("Out of bounds");
  }

  Node<T>* current = head;
  for(int i=0; i<position; i++){
    current = current->getNext();
  }

  return current->getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T &newValue)
{
  if(position >= length){
    throw std::out_of_range("Out of bounds");
  }

  Node<T>* current = head;
  for(int i=0; i<position; i++){
    current = current->getNext();
  }

  current->setItem(newValue);
}
