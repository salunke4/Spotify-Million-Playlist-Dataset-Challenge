# Results

## Video Report

Our final video presentation can be found [here](https://drive.google.com/file/d/1zBpBYBeDKzOXw1QtpB0e_YpvLzq0iCOb/view?usp=sharing) or in the docs folder of our repository.

## Objectives

The objective of this project was to represent data from Spotify's Million Playlist Dataset (MPD). Given two songs as inputs, we want to be able to generate a playlist of similar songs based on common songs from other playlists. This data is represented in a graph where:
* Songs are vertices
* These vertices are connected by edges if they exists in a common playlist
* The number of common playlists determines the edge weights

To identify related songs, we used three graph algorithms:
* Depth-First Search (DFS)
* Dijstra's Algorithm
* Iterative Deepening Depth-First Search (IDDFS)

## Data

In its original form, the MPD lists 1 million playlists, each containing their respective songs and various metadata about each track, including its URL, duration, album, and other information. Since we were only interested in the tracks on each playlist, our first task was to create a Python script capable of cleaning the data, i.e. parsing it so that only the track names remained. In the following picture, a slice of the raw data is parsed into the usable data by our Python script. 

![Parsing](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/images/parsing.png)

We also wrote test cases to verify that our parsing worked correctly, which you can see is tests/test_parsing.cpp. 

## Graph

To create our graph, we just to use an edge list. We implemented all of the necessary graph functions, including insert & remove vertex, insert & remove edge, find advjacent vertices, get edge weights, and a few others. These functions are implemented in graph/graph.cpp. We also wrote numerous test cases to verify that our graph class was working correctly, which are detailed in tests/test_graph.cpp. 

## Algorithms

### Depth-First Search (DFS)

The first algorithm we implemented was a DFS, used to traverse the entire graph given a starting node. This DFS also utilizes a helper function, to aid in the recursive nature of the DFS traversal.

### Dijkstra's Algorithm



### Tests

All three of our algorithms are implemented in graph/algorithms.cpp and are tested in tests/test_algorithms.cpp. Each algorithm was tested on 3 test graphs: a standard, tree-like graph; a complex graph with many edges; and a graph containing a cycle. Since we knew that the graph representing our data would be highly interconnected, we wanted to ensure that the algorithms were functional on a variety of possible graphs. 

![Graph Tests](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/images/tests.png)

### Dijkstra's Algorithm

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
