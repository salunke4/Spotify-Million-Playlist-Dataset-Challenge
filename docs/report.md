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

<img src="/images/parsing.png" alt="Parsing" width="400"/> 

![Parsing](/images/parsing.png)

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
