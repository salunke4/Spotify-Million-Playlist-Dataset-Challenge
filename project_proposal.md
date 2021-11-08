Final Project Proposal

1) Leading Question: Our team is planning on using Spotify's Million Playlist Dataset (MPD), which is a dataset organized by Spotify containing over 1 million playlists and 2 million unique tracks. Each playlist in the MPD contains a playlist title, the track list (including metadata for each track) and other metadata fields including edit time and number of playlist edits. Our goal is to create a recommendation system so that users can input a song name and the algorithm will return a list of similar songs based on other playlists containing the input song. This algorithm will provide the user with songs that other users associate with the input song based on existing playlists. 

2) Dataset Acquisition and Processing: The dataset that we are planning on using can be found at https://www.aicrowd.com/challenges/spotify-million-playlist-dataset-challenge#dataset. We will initially process and clean the data using a Jupyter Notebook and Python with libraries like MatPlotLib, pandas, Statsmodels, and SKLearn. This will help us creating a graph connecting each of these songs. 

3) Graph Algorithms: Our algorithm will take the song name as an input from the user and return a list of 5 recommended similar songs. We will use a depth-first search (DFS) to find song nodes that are connected to the input song by being in other playlists with the input song. Additionally, we will use Dijkstra's algorithm on the input song node to determine the shortest path from the input to each other song on the graph, generating the 5 most similar songs. 

4) Timeline: We plan to adhere to the following timeline. This timeline is subject to change based on our team's progress and any unforseen obstacles or issues which may arise over the course of the project.
- Week 0 (11/1): Complete team contract and project proposal
- Week 1 (11/8): Confirm dataset reliability and begin data cleaning & processing
- Week 2 (11/15): Finish data cleaning and begin implementing algorithms
- Week 3 (11/22): Continue implementation of algorithms and begin testing
- Week 4 (11/29): Finalize algorithms and complete testing
- Week 5 (12/6): Complete written report and final presentation in advance of final deadline on 12/13