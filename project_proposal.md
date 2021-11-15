# Project Proposal

### 1) Leading Question: 
Our team is planning on using Spotify's Million Playlist Dataset (MPD), which is a dataset organized by Spotify containing over 1 million playlists and 2 million unique tracks. Each playlist in the MPD contains a playlist title, the track list (including metadata for each track) and other metadata fields including edit time and number of playlist edits. Our goal is to create a recommendation system so that users can input a song name and the algorithm will return a list of similar songs based on other playlists containing the input song. This algorithm will provide the user with songs that other users associate with the input song based on existing playlists. 

### 2) Dataset Acquisition and Processing: 
The dataset that we are planning on using can be found at [AICrowd](https://www.aicrowd.com/challenges/spotify-million-playlist-dataset-challenge#dataset). We will initially process and clean the data using a Jupyter Notebook and Python with libraries like MatPlotLib, pandas, Statsmodels, and SKLearn. This will help us creating a graph connecting each of these songs. 

### 3) Graph Algorithms: 
Our algorithm will take the song name as an input from the user and return a list of 5 recommended similar songs. We will use a depth-first search (DFS) to find song nodes that are connected to the input song by being in other playlists with the input song. Additionally, we will use Dijkstra's algorithm on the input song node to determine the shortest path from the input to each other song on the graph, generating the 5 most similar songs. 
We'll iterate over this list of songs that share a playlist with the input and build song nodes for each song in the list after the first node is built. We'll start with the input node and use iterative deepening depth-first search(IDS), which is is a state space/graph search approach that involves continually running a depth-limited variant of depth-first search with increasing depth limitations until the target is reached, to connect every pair of songs that share a playlist, with edge weights equal to the inverse of the number of playlists they share. We'll use Dijkstra's techniques to find the shortest path from the input node to each song in the network once the graph has been formed. We then use this information to find the five nodes that are the closest to the input node and add them to a playlist of suggested songs. Following the addition of these nodes, we will calculate the betweenness centrality for each node on the graph and add the five nodes with the highest centrality to the list of recommended songs. Implementing all three will allow us to keep the runtime manageable and also ensures that half of the songs are very close to the input, while the other half are more popular songs with less similarities. The runtimes for Dijkstra would be O(m + nlog(n)), for DFS would be O(m+n) and for IDS it is O(m^n) with m being the branching factor and depth b.



### 4) Timeline: 
We plan to adhere to the following timeline. This timeline is subject to change based on our team's progress and any unforseen obstacles or issues which may arise over the course of the project.
- Week 0 (11/1): Complete team contract and project proposal
- Week 1 (11/8): Confirm dataset reliability and begin data cleaning & processing
- Week 2 (11/15): Finish data cleaning and begin implementing algorithms
- Week 3 (11/22): Continue implementation of algorithms and begin testing
- Week 4 (11/29): Finalize algorithms and complete testing
- Week 5 (12/6): Complete written report and final presentation in advance of final deadline on 12/13