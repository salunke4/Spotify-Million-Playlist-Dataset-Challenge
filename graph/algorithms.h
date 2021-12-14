#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include "graph.h"

using namespace std;
using std::unordered_set;

class algorithms {
    private:
        Graph graph_;
        string start_;
        void DFS_helper(Vertex src, Graph & g, unordered_set<Vertex> & visited, vector<Vertex> & s);

    public:
        algorithms(Graph g, Vertex start);
        vector<string> traverse();
        vector<Vertex> Dijkstras(Vertex source, Vertex target);
        bool iterative_dfs(Vertex source, Vertex target, int max_depth);
        bool DLS(Vertex source, Vertex destination, int limit);
};