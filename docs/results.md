# Report

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

By the end of the project, all of our objectives were met and our algorithms were successfully able to generate a playlist of recommended songs. 

## Data

In its original form, the MPD lists 1 million playlists, each containing their respective songs and various metadata about each track, including its URL, duration, album, and other information. Since we were only interested in the tracks on each playlist, our first task was to create a Python script capable of cleaning the data, i.e. parsing it so that only the track names remained. In the following picture, a slice of the raw data is parsed into the usable data by our Python script. 

![Parsing](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/images/parsing.png)

We also wrote test cases to verify that our parsing worked correctly, which you can see in tests/test_parsing.cpp. 

## Graph

To create our graph, we just to use an edge list. We implemented all of the necessary graph functions, including insert & remove vertex, insert & remove edge, find advjacent vertices, get edge weights, and a few others. These functions are implemented in graph/graph.cpp. We also wrote numerous test cases to verify that our graph class was working correctly, which are detailed in tests/test_graph.cpp. 

## Algorithms

### Depth-First Search (DFS)

The first algorithm we implemented was a DFS, used to traverse the entire graph given a starting node. This DFS also utilizes a helper function, to aid in the recursive nature of the DFS traversal.

### Dijkstra's Algorithm

Dijkstra's Algorithm was useful in easily discovering the shortest path between two nodes. The algorithm accepts a source and destination vertex, and returns a vector of vertices containing the path between the two nodes. This path was especially useful given the nature of our program, as this path provided us with a list of recommended songs for the user. 

### Iterative Deepening Depth-First Search (IDDFS)

This final algorithm accepted three parameters: a source node, a destination node, and a maximum search depth. An IDDFS works the same as a DFS, expect with a constraint - if the number of edges between the source and destination nodes is fewer than the maximum search depth, the program will return true. This algorithm was especially useful for the highly dense graphs used in this project, as determining whether two nodes are linked can quickly become very time-consuming and inefficient. IDDFS allows us to avoid these long search times and avoids the problem of recommending songs that are only loosely related. 

### Tests

All three of our algorithms are implemented in graph/algorithms.cpp and are tested in tests/test_algorithms.cpp. Each algorithm was tested on 3 test graphs: a standard, tree-like graph; a complex graph with many edges; and a graph containing a cycle. Since we knew that the graph representing our data would be highly interconnected, we wanted to ensure that the algorithms were functional on a variety of possible graphs. 

![Graphs](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/images/tests.png)

The results of these test cases are shown below. 

![Test Passing](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/images/passing.png)

## Results

After running make, our program then prompts the user to enter a starting & ending song name, as well as a max search depth. After a few seconds, the program will generate a list of song recommendations for the user, proving that the program does indeed work successfully. This process is depicted below. 

![Created Playlist](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/images/playlist.png)