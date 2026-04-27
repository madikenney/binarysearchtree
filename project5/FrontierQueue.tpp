#include "FrontierQueue.hpp"

template <typename T>
State<T> FrontierQueue<T>::pop() {

  //TODO: implement this the same way we implemented pop in the heap lecture. Compare states using getFCost.
  State<T> currRoot = queue[0];

  queue[0] = queue.back();
  queue.pop_back();

  int i=0;

  while(true){
    int left = 2*i + 1;
    int right = 2*i + 2;
    int smaller = i;

    // Find smallest child
    if( (left < queue.size()) && (queue[left].getFCost() < queue[smaller].getFCost()) ) {
      smaller = left;
    }
    if( (right < queue.size()) && (queue[right].getFCost() < queue[smaller].getFCost()) ) {
      smaller = right;
    }

    // No change occurs --> smallest is found
    if(smaller != i){
      std::swap(queue[i], queue[smaller]);
      i = smaller;
    } else{
      break;
    }
  }

  return currRoot;
}

template <typename T>
void FrontierQueue<T>::push(const T &p, std::size_t cost, std::size_t heur) {

  //TODO: implement this the same way we implemented push in the heap lecture.
  State<T> newState(p, cost, heur);
  queue.push_back(newState);

  // Counter variable
  int i = queue.size()-1;

  // Move newState to correct position
  while(i>0) {
    int parent = (i-1)/2;

    // Compare costs of current and parent
    if(queue[i].getFCost() < queue[parent].getFCost()){
      std::swap(queue[i], queue[parent]);
      i=parent;
    } else {
      break;
    }
  }
}

template <typename T>
bool FrontierQueue<T>::empty() const {
  return queue.empty();
}

template <typename T> 
bool FrontierQueue<T>::contains(const T &p) const {
  for(State<T> s : queue){
    if(s.getValue() == p){
      return true;
    }
  }
  return false;
}

template <typename T>
void FrontierQueue<T>::replaceif(const T &p, std::size_t cost) {

  for(int i=0; i<queue.size(); i++){
    // Find state & determine if path is better
    if( (queue[i].getValue() == p) && (cost < queue[i].getPathCost() )){
      // Replace state
      int heur = queue[i].getFCost() - queue[i].getPathCost();  // h = f - p
      queue[i] = State<T>(p, cost, heur);

      // Fix heap
      int curr=0;
      while(curr>0) {
        int parent = (curr-1)/2;

        if(queue[curr].getFCost() < queue[parent].getFCost()){
          std::swap(queue[curr], queue[parent]);
          i=parent;
        } else {
          break;
        }
      }
    }
  }

}


