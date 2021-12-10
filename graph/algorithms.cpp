#include "algorithms.h"
#include "graph.h"
#include <algorithm>
#include <queue>
#include <utility>
#include <map>

using namespace std;
algorithms::algorithms(Graph g, Vertex start) {
  graph_ = g;
  start_ = start;
}

struct VertexWeight{
    Vertex vertexName;
    double distance;
    bool visited;
    Vertex previous;
};

class Compare
{
  public:
      bool operator() (VertexWeight *a, VertexWeight *b)
      {
          return a->distance > b->distance;
      }
};

vector<string> algorithms::traverse() {
  stack<string> stack;
  vector<string> visited;
  stack.push(start_);
  while(!stack.empty()) {
    string current = stack.top();
    stack.pop();
    // check if current has already been visited
    if(find(visited.begin(), visited.end(), current) == visited.end()) { // This is a linear search which takes a while, maybe hash the strings to make it faster?
      visited.push_back(current);
      for(string str: graph_.AdjacentVertices(current)) {
        stack.push(str);
      }
    }
  }
//  reverse(visited.begin(), visited.end());
  return visited;
}

/**
 * @brief Returns the shortest path between a source and destination node
 * 
 * @param source Starting node
 * @param destination Ending Node
 * @return vector<Vertex> Vector containing all vertices in the shortest path between the two
 */
vector<Vertex> algorithms::Dijkstras(Vertex source, Vertex destination) {
  // creates a priority queue to store traveled locations in 
  std::priority_queue<VertexWeight*, std::vector<VertexWeight*>, Compare> traveled;

  // creates a map storing vertices as keys and distance from last point as value
  map<Vertex, VertexWeight*> vmap;
  
  vector<Vertex> vertices = graph_.GetVertices();
  vector<VertexWeight*> weights;

  // iterates through all vertices to store vertex weights
  size_t i = 0;
  while (i < vertices.size()) {
    VertexWeight *newWeight = new VertexWeight;
    newWeight->vertexName = vertices.at(i);
    newWeight->distance = std::numeric_limits<double>::max();
    newWeight->visited = false;
    weights.push_back(newWeight);
    
    vmap[vertices.at(i)] = newWeight;
    
    if (vertices.at(i) == source) {
      newWeight->distance = 0;
      traveled.push(newWeight);
    }
    i++;
  }
  
  // if highest priority element is not destination, find nodes along path
  while (traveled.top()->vertexName != destination) { 
    // get last entry of path
    VertexWeight *current = traveled.top();
    traveled.pop();
    
    if (!current->visited) {
      vector<Vertex> neighborList = graph_.AdjacentVertices(current->vertexName);
      i = 0;
      while (i < neighborList.size()) {
        VertexWeight *neighbor = vmap[neighborList.at(i)];
        // check if neighboring node has been visited already
        if (!neighbor->visited) { 
          double currentToNeighborEdgeWeight = graph_.GetEdgeValue(current->vertexName, neighbor->vertexName);
          // update path
          if (neighbor-> distance > current->distance + currentToNeighborEdgeWeight) {
            neighbor-> distance = current->distance + currentToNeighborEdgeWeight;
            neighbor-> previous = current -> vertexName;
          }
          traveled.push(neighbor);
        }
        i++;
      }
      current-> visited = true;
    }
  }
    
  vector<Vertex> path;
  VertexWeight *last = vmap[destination];
  path.push_back(last->vertexName);
  while (path.back() != source) {
    path.push_back(vmap[path.back()]->previous);
  }
  
  i = 0;
  while (i<weights.size()) {
    delete weights.at(i);
    i++;
  }
  
  // reverse path to be returned
  reverse(path.begin(),path.end());
  return path;
}

bool algorithms::DLS(Vertex source, Vertex target, int limit) {
  if (source == target) {
    return true;
  }
  if (limit <= 0) {
    return false;
  }
  for (Vertex adjacent : graph_.AdjacentVertices(source)) {
    if (DLS(adjacent, target, limit - 1) == true) return true;
  }
  return false;
}

bool algorithms::iterative_dfs(Vertex source, Vertex target, int max_depth) {
  for (int i = 0; i <= max_depth; i++) {
    if (DLS(source, target, i) == true) {
      return true;
    }
  }
  return false;
}