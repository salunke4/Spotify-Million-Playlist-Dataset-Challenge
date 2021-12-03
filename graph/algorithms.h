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
        algorithms(Graph g, string start);
        vector<string> traverse();
        vector<string> Dijkstras(string source, string target);
        bool iterative_dfs(string source, string target, int max_depth);
        bool DLS(string source, string destination, int limit);
};