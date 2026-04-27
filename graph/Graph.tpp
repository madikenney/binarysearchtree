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
    // Check for duplicate edge
    for(int i=0; i<adjacent[start].size(); i++){
        if(adjacent[start][i] == end){
            return false;
        }
    }
    
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
    adjacent[start].push_back(end);
    adjacent[end].push_back(start);
    return true; 
}   

template <typename LabelType> 
bool Graph<LabelType>::remove(LabelType start, LabelType end) {
    // Find edge
    bool found = false;
    int index = 0;
    for(int i=0; i<adjacent[start].size(); i++){
        if(adjacent[start][i] == end){
            found = true;
            index = i;
            break;
        }
    }

    if(!found){
        return false;
    }

    // Remove from start array
    adjacent[start].erase(adjacent[start].begin() + index);

    // Remove from end array
    for(int i=0; i<adjacent[end].size(); i++){
        if(adjacent[end][i] == start){
            adjacent[end].erase(adjacent[end].begin() + i);
            break;
        }
    }

    // Remove vertices (if the removed edge was its only connection)
    if(adjacent[start].size() == 0){
        for(int i=0; i<vertices.size(); i++){
            if(vertices[i] == start) {
                vertices.erase(vertices.begin() + i);
                break;
            }
        }
        adjacent.erase(start);
    }
    
    if(adjacent[end].size() == 0){
        for(int i=0; i<vertices.size(); i++){
            if(vertices[i] == end) {
                vertices.erase(vertices.begin() + i);
                break;
            }
        }
        adjacent.erase(end);
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