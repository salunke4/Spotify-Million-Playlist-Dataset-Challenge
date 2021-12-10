#include <vector>
#include <string>
#include <stack>
#include "graph.h"

using namespace std;

class algorithms {
    private:
        Graph graph_;
        string start_;
    public:
        algorithms(Graph g, Vertex start);
        vector<string> traverse();
        vector<Vertex> Dijkstras(Vertex source, Vertex target);
        bool iterative_dfs(Vertex source, Vertex target, int max_depth);
        bool DLS(Vertex source, Vertex destination, int limit);
};