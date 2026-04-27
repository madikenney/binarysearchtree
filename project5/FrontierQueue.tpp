#include "FrontierQueue.hpp"

template <typename T>
State<T> FrontierQueue<T>::pop() {

  //TODO: implement this the same way we implemented pop in the heap lecture. Compare states using getFCost.

  return State<T>(T(),0,0);
}

template <typename T>
void FrontierQueue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //TODO: implement this the same way we implemented push in the heap lecture.
  State<T> newState(p, cost, heur);
  heap.push_back(newState);

  // Counter variable
  int i = heap.size()-1;

  // Move newState to correct position
  while(i>0) {
    int parent = (i-1)/2;


  }
}

template <typename T>
bool FrontierQueue<T>::empty() const {

  //TODO

  return true;
}

template <typename T> 
bool FrontierQueue<T>::contains(const T &p) const {

  //TODO

  return false;

}

template <typename T>
void FrontierQueue<T>::replaceif(const T &p, std::size_t cost) {

  //TODO

}


