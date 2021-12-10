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

void algorithms::SCCUtil(Vertex src, Graph & g, unordered_set<Vertex> & visited, vector<Vertex> & s)
{
    visited.insert(src); // marks vertex as visted
    vector<Vertex> vertex_list = graph_.AdjacentVertices(src);  // get a list of adjacent vertices
    for (size_t i = 0; i < vertex_list.size(); i++) // iterates over adjecent vertices
    {
        if(visited.find(vertex_list[i]) == visited.end()) // checks if this adjecent vertex is unvisted
        {
            SCCUtil(vertex_list[i], g, visited, s); // calls DFS recursively on adjecent vertex
        }
    }
    s.push_back(src); //add vertex to the stack
}

vector<Vertex> algorithms::traverse()
{
    vector<Vertex> explored; // Vector to store all vertices in graph explored through DFS
    unordered_set<Vertex> visited; // Unordered set to track visited vertices
    vector<Vertex> vertices = graph_.GetVertices(); // Gets vector of all vertices in graph
    for(size_t i = 0; i < vertices.size(); i++) // Iterates over all vertices
    {
        if(visited.find(vertices[i]) == visited.end()) // Checks if vertex is unvisited
        {
            SCCUtil(vertices[i], graph_, visited, explored); // If unexplored, DFSs from this vertex and adds all reachable vertices
        }
    }
    reverse(explored.begin(),explored.end());
    return explored; // Returns vector of all vertices in graph explored through DFS
}

vector<Vertex> algorithms::Dijkstras(Vertex source, Vertex destination) {
  std::priority_queue<VertexWeight*, std::vector<VertexWeight*>, Compare> travelled;
  map<Vertex, VertexWeight*> vmap;
  vector<Vertex> vertices = graph_.GetVertices();
  vector<VertexWeight*> weights;

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
