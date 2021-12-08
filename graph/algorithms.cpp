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
  return visited;
}

vector<string> algorithms::Dijkstras(string source, string destination) {
  vector<string> path;
  return path;
}

bool algorithms::DLS(string source, string target, int limit) {
  return false;
}

bool algorithms::iterative_dfs(string source, string target, int max_depth) {
  return false;
}