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
/**
 * @brief Helper function for Traverse
 * 
 * @param src
 * @param g
 * @param visited
 */


void algorithms::SCCUtil(Vertex src, Graph & g, unordered_set<Vertex> & visited, vector<Vertex> & s)
{
    visited.insert(src); // vertex is marked as visited
    vector<Vertex> vertex_list = graph_.AdjacentVertices(src);  // obtain a list of vertices that are adjacent
    for (size_t i = 0; i < vertex_list.size(); i++) // iterates over vertices that are close together
    {
        if(visited.find(vertex_list[i]) == visited.end()) // determines whether or not this adjacent vertex is unvisted
        {
            SCCUtil(vertex_list[i], g, visited, s); //recursively calls DFS on adjacent vertex
        }
    }
    s.push_back(src); //vertext + 1 to stack
}
/**
 * @brief Our DFS Algorithm, Uses SCCUtil
 * 
 */
vector<Vertex> algorithms::traverse()
{
    vector<Vertex> explored; // Vector to store all vertices in graph explored through DFS
    unordered_set<Vertex> visited; // Visited vertices are tracked using an unordered collection

    vector<Vertex> vertices = graph_.GetVertices(); // Gets the vector of all the graph's vertices
    for(size_t i = 0; i < vertices.size(); i++) // Iterates through all of the vertices
    {
        if(visited.find(vertices[i]) == visited.end()) // Checks if a vertex hasn't been visited before
        {
            SCCUtil(vertices[i], graph_, visited, explored); // DFSs from this vertex and adds all reachable vertices if it is unexplored
        }
    }
    reverse(explored.begin(),explored.end());
    return explored; // Returns vector of all vertices in graph explored through DFS
}


/**
 * @brief Dijkstras Algorithm Implementation
 * 
 * @param source
 * @param destination
 */
vector<Vertex> algorithms::Dijkstras(Vertex source, Vertex destination) {
  std::priority_queue<VertexWeight*, std::vector<VertexWeight*>, Compare> travelled;
  map<Vertex, VertexWeight*> vmap;
  vector<Vertex> vertices = graph_.GetVertices(); //Gets vertices from the graph
  vector<VertexWeight*> weights;

  size_t i = 0;
  while (i < vertices.size()) {
    VertexWeight *newWeight = new VertexWeight; // Establishes the weights of the vertexs
    newWeight->vertexName = vertices.at(i);
    newWeight->distance = std::numeric_limits<double>::max();
    newWeight->visited = false;
    weights.push_back(newWeight);
    
    vmap[vertices.at(i)] = newWeight; // The new weight being set while iterated through
    
    if (vertices.at(i) == source) {
      newWeight->distance = 0;
      travelled.push(newWeight);
    }
    i++;
  }
  
  while (travelled.top()->vertexName != destination) { 
    VertexWeight *current = travelled.top();
    travelled.pop();
    
    if (!current->visited) {
      vector<Vertex> neighborList = graph_.AdjacentVertices(current->vertexName);
      i = 0;
      while (i < neighborList.size()) {
        VertexWeight *neighbor = vmap[neighborList.at(i)];
        if (!neighbor->visited) { 
          double currentToNeighborEdgeWeight = graph_.GetEdgeValue(current->vertexName, neighbor->vertexName);

          if (neighbor-> distance > current->distance + currentToNeighborEdgeWeight) {
            neighbor-> distance = current->distance + currentToNeighborEdgeWeight;
            neighbor-> previous = current -> vertexName;
          }
          travelled.push(neighbor);
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
  
  reverse(path.begin(),path.end());
  return path;
}

/**
 * @brief Helper function for Interative depth first search algorithm
 * 
 * @param source
 * @param target
 * @param limit
 */
bool algorithms::DLS(Vertex source, Vertex target, int limit) {
  if (source == target) {
    return true;
  }
  if (limit <= 0) {
    return false;
  }
  for (Vertex adjacent : graph_.AdjacentVertices(source)) {
    if (DLS(adjacent, target, limit - 1) == true) return true; // Calls function DLS Recursive
  }
  return false;
}
/**
 * @brief Interative depth first search algorithm
 * 
 * @param source
 * @param target
 * @param max_depth
 */
bool algorithms::iterative_dfs(Vertex source, Vertex target, int max_depth) {
  for (int i = 0; i <= max_depth; i++) {
    if (DLS(source, target, i) == true) { //Calls itself recursively
      return true;
    }
  }
  return false;
}
