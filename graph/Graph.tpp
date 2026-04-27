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
        // count all edges stored in each point's array
        LabelType v = vertices[i];
        count += adjacent.at(v).size();
    }

    return count / 2;
}
        
template <typename LabelType> 
bool Graph<LabelType>::add(LabelType start, LabelType end) { 
    // // Check for duplicate edge
    // for(int i=0; i<adjacent[start].size(); i++){
    //     if(adjacent[start][i] == end){
    //         return false;
    //     }
    // }
    
    // Check if connected
    bool startExists = false;
    bool endExists = false;

    for(int i=0; i<vertices.size(); i++){
        if(vertices[i] == start){
            startExists = true;
        }
        if(vertices[i] == end){
            endExists = true;
        }
    }

    // Cannot add edge
    if((vertices.size()) > 0 && (!startExists && !endExists)){
        return false;
    }

    // Add new vertice if it does not exist
    if(!startExists) {
        vertices.push_back(start);
    }
    if(!endExists) {
        vertices.push_back(end);
    }

    // Add new edge for both points
    adjacent[start].insert(end);
    adjacent[end].insert(start);
    return true; 
}   

template <typename LabelType> 
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    // Find edge
    if(adjacent[start].find(end) == adjacent[start].end()){
        return false;
    }
    
    // Remove edge from each adjacency list
    adjacent[start].erase(end);
    adjacent[end].erase(start);

    // Remove vertice if isolated
    if(adjacent[start].size() == 0){
        adjacent.erase(start);
        for(int i=0; i<vertices.size(); i++){
            if(vertices[i] == start){
                vertices.erase(vertices.begin() + i);
                break;
            }
        }
    }
    if(adjacent[end].size() == 0){
        adjacent.erase(end);
        for(int i=0; i<vertices.size(); i++){
            if(vertices[i] == end){
                vertices.erase(vertices.begin() + i);
                break;
            }
        }
    }

    return true;
}

template <typename LabelType> 
void Graph<LabelType>::depthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // BONUS
}

template <typename LabelType> 
void Graph<LabelType>::breadthFirstTraversal(LabelType start, void visit(LabelType&)) {
    // BONUS
}