#include "Queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  internal_list.insert(internal_list.getLength(), item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  internal_list.remove(internal_list.getLength()-1);
}

template <typename T, typename L>
T Queue<T,L>::peekFront() const
{
  return internal_list.getEntry(0);
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  return internal_list.isEmpty();
}

