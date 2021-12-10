#pragma once
#include <vector>
#include <string>
#include <set>

using namespace std;

using std::string;
typedef string Vertex;

struct Edge {
    int weight;
    string start, end;
    vector<string> shared_playlists;
    
    Edge(string start, string end, int weight): start(start), end(end), weight(weight) {}

    bool operator==(const Edge& other) const {
      return start == other.start && end == other.end && weight == other.weight;
    }

    bool operator<(const Edge& other) const {
      return weight < other.weight;
    }
};

class Graph {
    private:
        set<string> vertices_;
        vector<Edge> edge_list_;
        
    public:
        Graph();
        void InsertVertex(string track_name);
        void RemoveVertex(string track_name);
        void InsertEdge(string track1, string track2, int weight=1);
        void RemoveEdge(string track1, string track2);
        int GetEdgeValue(string track1, string track2) const;
        bool IsAdjacent(string track1, string track2) const;
        size_t GetNumEdges() const;
        size_t GetNumVertices() const;
        vector<string> AdjacentVertices(string track) const;
        vector<string> GetVertices() const;
};