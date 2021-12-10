#include "algorithms.h"
#include "graph.h"
#include <algorithm>
#include <queue>
#include <utility>
#include <map>

using namespace std;
algorithms::algorithms(Graph g, string start) {
  graph_ = g;
  start_ = start;
}

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

vector<string> algorithms::Dijkstras(Vertex source, Vertex destination) {
    // Create priority queue to store travelled locations in
    std::priority_queue<VertexWeight*, std::vector<VertexWeight*>, Compare> travelled;
    map<Vertex, VertexWeight*> vmap; // Create a map with vertex as key, and distance travelled from last point as value
    
    vector<string> vertices = graph_.GetVertices();
    vector<VertexWeight*> allVertexWeights;

    // Loop through all vertices to get vertex weights
    for (size_t i = 0; i < vertices.size(); i++) {
        VertexWeight *newVertexWeight = new VertexWeight;
        newVertexWeight->vertexName = vertices.at(i);
        newVertexWeight->distance = std::numeric_limits<double>::max();
        newVertexWeight->visited = false;
        allVertexWeights.push_back(newVertexWeight);
        
        vmap[vertices.at(i)] = newVertexWeight;
        
        if (vertices.at(i) == source) {
            newVertexWeight->distance = 0;
            travelled.push(newVertexWeight);
        }
    }
    
    while (travelled.top()->vertexName != destination) { // Check if top of priority queue is the destination, if not run through code
        VertexWeight *current = travelled.top(); // Get the last entry in path
        travelled.pop();
        
        if (!current->visited) { //Check if current node is visited
            vector<Vertex> neighborList = graph_.AdjacentVertices(current->vertexName); //Find adjacent Nodes
            for (size_t i = 0; i < neighborList.size(); i++) {
                VertexWeight *neighbor = vmap[neighborList.at(i)];
                if (!neighbor->visited) { // Check if the neighboring node had been visited already
                    double currentToNeighborEdgeWeight = graph_.GetEdgeValue(current->vertexName, neighbor->vertexName);
                    //RUn through logic to update path
                    if (neighbor-> distance > current->distance + currentToNeighborEdgeWeight) {
                        neighbor-> distance = current->distance + currentToNeighborEdgeWeight;
                        neighbor-> previous = current -> vertexName;
                    }
                    travelled.push(neighbor);
                }
            }
            current-> visited = true;
        }
    }
    
    vector<Vertex> vertexPath;
    VertexWeight *lastVertex = vmap[destination];
    vertexPath.push_back(lastVertex->vertexName);
    while (vertexPath.back() != source) {
        vertexPath.push_back(vmap[vertexPath.back()]->previous);
    }
    
    for (size_t i = 0; i<allVertexWeights.size(); i++) {
        delete allVertexWeights.at(i);
    }
    
    // returns the path in reverse order
    reverse(vertexPath.begin(),vertexPath.end());
    return vertexPath;
    
}

bool algorithms::DLS(string source, string target, int limit) {
  if (source == target) {
    return true;
  }
  if (limit <= 0) {
    return false;
  }
  for (string adjacent : graph_.AdjacentVertices(source)) {
    if (DLS(adjacent, target, limit - 1) == true) return true;
  }
  return false;
}

bool algorithms::iterative_dfs(string source, string target, int max_depth) {
  for (int i = 0; i <= max_depth; i++) {
    if (DLS(source, target, i) == true) {
      return true;
    }
  }
  return false;
}