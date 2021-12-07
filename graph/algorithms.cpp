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