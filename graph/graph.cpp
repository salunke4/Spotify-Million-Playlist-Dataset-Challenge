#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph(){}

/**
 * @brief Inserts a vertex with a specified name
 * 
 * @param track_name Song to be inserted
 */
void Graph::InsertVertex(string track_name) {
  if (vertices_.find(track_name) != vertices_.end()) {
    return;
  }
  vertices_.insert(track_name);
}

/**
 * @brief Removes a specified song from the graph
 * 
 * @param track_name Song to be removed
 */
void Graph::RemoveVertex(string track_name) {
  for (auto it = edge_list_.begin(); it != edge_list_.end(); it++) {
    Edge e = *it;
    if (e.start == track_name) {
      edge_list_.erase(it--);
    }
    if (e.end == track_name) {
      edge_list_.erase(it--);
    }
  }
  vertices_.erase(track_name);
}

/**
 * @brief Inserts an edge between two nodes
 * 
 * @param track1 
 * @param track2 
 * @param weight 
 */
void Graph::InsertEdge(string track1, string track2, int weight) {
  for (Edge& e : edge_list_) {
    if (e.start == track2 && e.end == track1) {
      e.weight += weight;
      return;
    }
    else if (e.start == track1 && e.end == track2) {
      e.weight += weight;
      return;
    }
  }
  Edge e(track1, track2, weight);
  edge_list_.push_back(e);
}

void Graph::RemoveEdge(string track1, string track2) {
  for (auto it = edge_list_.begin(); it != edge_list_.end(); it++) {
    Edge e = *it;
    if (e.start == track2 && e.end == track1) {
      edge_list_.erase(it--);
    }
    else if (e.start == track1 && e.end == track2) {
      edge_list_.erase(it--);
    }
  }
}

int Graph::GetEdgeValue(string track1, string track2) const {
  for (const Edge& e : edge_list_) {
    if (e.start == track2 && e.end == track1) {
      return e.weight;
    }
    else if (e.start == track1 && e.end == track2) {
      return e.weight;
    }
  }
  return -1;
}

bool Graph::IsAdjacent(string track1, string track2) const {
  for (const Edge& e : edge_list_) {
    if (e.start == track2 && e.end == track1) {
      return true;
    }
    else if (e.start == track1 && e.end == track2) {
      return true;
    }
  }
  return false;
}

vector<string> Graph::AdjacentVertices(string track) const {
  vector<string> adjacents;
  for (const Edge& e : edge_list_) {
    if (e.start == track) {
      adjacents.push_back(e.end);
    }
    else if (e.end == track) {
      adjacents.push_back(e.start);
    }
  }
  return adjacents;
}

size_t Graph::GetNumVertices() const {
  return vertices_.size();
}

size_t Graph::GetNumEdges() const {
  return edge_list_.size();
}

vector<string> Graph::GetVertices() const {
  return vector<string>(vertices_.begin(), vertices_.end());
}