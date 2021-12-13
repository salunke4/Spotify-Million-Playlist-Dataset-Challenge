# Results

* Our Objectives 
    * Represent data from Spotify's public playlists as a graph in which: 
    * Songs are represented as vertices 
    * Songs are connected by edges given they share a playlist 
    * The number of shared playlists determines the edge weight
* Given a song as an input, use the following techniques to locate related songs:
    * Depth-first search
    * Dijkstra’s algorithm
    * Iterative deepening depth-first search

* Visualization of a graph

    * We were able to turn our data into a network with song nodes and edges connecting songs with shared playlists.

    * The graph.cpp file contains methods for adding and removing edges and vertices, as well as retrieving all adjacent vertices to a particular vertex.

    * The data we utilized to do this is a collection of JSON files including information from over 1000000 public playlists.

    * We cleaned up these files before execution by deleting superfluous fields like the artist's name to reduce space and make the data easier to work with.

    * The readFiles method in data.cpp then processed the cleaned-up JSON file, iterating through each playlist and adding each new vertex to the graph, as well as connecting any songs in the same playlist with an edge.

* Dijkstra Algorithm

    * The shortest path from the start node to the end node is returned by our version of Dijkstra's algorithm, which accepts a source node and a destination node as inputs.

    * We can easily discover the shortest path between two songs in our graph using this method. As a result, this path contains songs that closely connect the source and destination nodes, providing us with a list of similar songs to recommend to the user.

    * This function is used by our algorithm to identify the shortest path between two input nodes, resulting in a list of songs that are connected to both inputs.

    * Three different graphs were used to test this method: a tree-like graph, a graph with a cycle, and a graph with many densely connected components.

* Depth-first search

    * Given a graph and a starting node, this method provides a valid traversal of all nodes reachable from the starting node.

    * For our purposes, this means that DFS (which we name traverse() in our application) starts with one song and builds a list of all songs accessible from the input via shared playlists.

    * Three different graphs were used to test this method: a tree-like graph, a graph with a cycle, and a graph with many densely connected components.

* Iterative deepening depth-first search
    * A source node, a destination node, and an int that defines the maximum search depth are the three parameters of iterative deeping depth-first search.

    * If the number of edges between the source and destination nodes is fewer than the maximum search depth, it returns true; otherwise, it returns false.

    * Because our graph contains a high number of densely coupled nodes, determining whether two components are linked can be time-consuming and inefficient.

    * IDDFS mitigates this problem by limiting searching up to a specific depth, allowing us to avoid extremely long search durations and avoiding the problem of recommending songs that are only loosely related and differ greatly from the source node.

    * In our software, we utilize this method to check that the two input nodes are connected by a finite number of edges before calculating the shortest path between them using Dijkstra's algorithm.

    * This method was tested on three different graphs this time: a tree-like graph, a graph containing a cycle, and a graph with a lot of densely connected components.
