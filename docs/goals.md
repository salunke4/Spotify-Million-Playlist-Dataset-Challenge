# Project Goals

The goal of this project was to load a data file as a graph and be able to use that graph to run several algorithms of 
interest on it. The code must work on our chosen data set and other data that has a matching format and must compile and run on EWS. 
For our project, we have chosen the Spotify Million Playlist Dataset Challenge. It is an open-end challenge where the objective is, 
given a playlist title or initial set of tracks in a playlist, to predict a list of recommended tracks for that playlist, basically 
functioning as a recommendation system where users can receive new music titles similar to ones they already enjoy. 

### The Data Set

Our team has chosen to use the Million Playlist Dataset (MPD) by Spotify. It consists of 1 million playlists, with over 2 million unique tracks and around 300,000 artists. The dataset is from [AICrowd](https://www.aicrowd.com/challengesspotify-million-playlist-dataset-challenge#dataset). Each playlist contains a title, the tracklist, and several other 
metadata. We processed and cleaned the data using the JSON library, Jupyter Notebook, and Python. This allowed us to create a graph 
connecting each song, where each song is represented by a node.

### The Algorithms We Chose to Implement

We have chosen to implement Depth-First Search (DFS), Dijkstra’s Algorithm, and Iterative Deepening Depth-First Search (IDDFS) 
algorithms. We have utilized Depth-First Search to find song nodes that are connected to the input song due to being in other 
playlists that share the same input song. We used Dijkstra’s algorithm on the input song node to find the shortest path from the 
input to each of the other songs on the graph, generating a list of similar songs. 
We will then iterate over these songs and create nodes for each song in the list after the first node is made. We will start with the 
input node and use Iterative Deepening Depth-First Search (IDDFS), (which is a state-space/graph search strategy in which a 
depth-limited version of DFS is run repeatedly with increasing depth limits until the goal is found) to connect every pair of songs 
that share a playlist with edge weights equal to the inverse of the number of shared playlists. Once the graph has been formed, we 
will then use Dijkstra's algorithm to find the shortest path from the input node to each song in the network. We will then use this 
data to find the closest nodes to the input song and add them to the playlist of suggested songs. Implementing all three algorithms 
help in keeping the runtime low and also ensures that the algorithm will correctly generate similar songs. 
The runtimes are as follows:
- Depth-First Search (DFS): O(m+n)
- Iterative Deepening Depth-First Search (IDS): O(m^n)
- Dijkstra’s Algorithm: O(m + log(n))

### Final Deliverable

Our final deliverable will be a graph and algorithms class that can satisfy all of our required test cases to ensure that all of our 
graphs are implemented correctly. To ensure that the program builds the playlist correctly, we will test it using a variety of songs 
from our database. 

### Timeline

We plan to adhere to the following schedule.
- Week 0 (11/1): Complete the team contract and project proposal
- Week 1 (11/8): Confirm reliability of the dataset and begin data cleaning & processing
- Week 2 (11/15): Finish data cleaning and begin implementing the algorithms
- Week 3 (11/22): Continue implementation of algorithms and start testing
- Week 4 (11/29): Finalize the algorithms and complete testing
- Week 5 (12/6): Complete the written report and final presentation in advance of the final deadline of 12/13