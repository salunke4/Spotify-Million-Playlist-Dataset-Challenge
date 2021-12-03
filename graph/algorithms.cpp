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
    if(find(visited.begin(), visited.end(), current) == visited.end()) { 
      visited.push_back(current);
      for(string str: graph_.AdjacentVertices(current)) {
        stack.push(str);
      }
    }
  }
  return visited;
}