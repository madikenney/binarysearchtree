#include <stdexcept>

#include "Stack.hpp"

template<class ItemType>
Stack<ItemType>::Stack() 
{
	headPtr = nullptr;
	currentSize = 0;
} 

template<class ItemType>
Stack<ItemType>::~Stack()
{
	clear();
}

template<class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return currentSize == 0;
}

template<class ItemType>
int Stack<ItemType>::size() const
{
	return currentSize;
}

template<class ItemType>
bool Stack<ItemType>::push(const ItemType& newItem)
{
	Node<ItemType>* newNode = new Node<ItemType>(newItem);
	newNode->setNext(headPtr);
	headPtr = newNode;
	currentSize++;

	return true;
}

template<class ItemType>
ItemType Stack<ItemType>::peek() const
{
	if(isEmpty()){
		throw std::out_of_range("Stack is empty");
	}	
	return headPtr->getItem();
}

template<class ItemType>
bool Stack<ItemType>::pop() 
{
	if(currentSize == 0){
		return false;
	}
	headPtr = headPtr->getNext();
	currentSize--;

	return true;
}

template<class ItemType>
void Stack<ItemType>::clear()
{
	Node<ItemType>* current = headPtr;
    
	while(current != nullptr){
        Node<ItemType>* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
  
  headPtr = nullptr;
  currentSize = 0;
}