#include "Graph.hpp"

template <typename LabelType>
Graph<LabelType>::Graph() {}

template <typename LabelType> 
int Graph<LabelType>::getNumVertices() const {
    return adjacent.size();
}

template <typename LabelType> 
int Graph<LabelType>::getNumEdges() const {
    int count = 0;

    for(int i=0; i<adjacent.size(); i++){
        LabelType v = vertices[i];
        count += adjacent.at(v).size();
    }

    return count / 2;
}
        
template <typename LabelType> 
bool Graph<LabelType>::add(LabelType start, LabelType end) { 
    return false; 
}   

template <typename LabelType> 
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    return false;
}

template <typename LabelType> 
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // BONUS
}

template <typename LabelType> 
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // BONUS
}