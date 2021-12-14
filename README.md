# sperka2-rohanhh2-guneets2-salunke4

## Overview

Welcome to our CS225 final project, a playlist generator. This program will provide you with a list of recommended songs based on two tracks, utilizing Spotify's Million Playlist Dataset. To use this program, please follow the following instructions:

1. Download the repository to your computer and unzip the program
2. Run "make" and then "./main"
3. When prompted by the terminal, enter your song selections and a maximum search depth (we recommend 200 to gain a good selection of songs while minimzing the amount of time taken for the program to run)
4. If your songs are connected, your playlist will be created and recommended for you!

## Testing

To test our application, simply run "make test" and "./test". This will run a set of three test cases: tests for the graph class, tests for the three algorithms used in this application, and tests to ensure that the data parsing methods work correctly. Upon all of these tests passing, you will see that 98 assertions pass in 26 test cases, verifying that everything is working correctly. 

## Repository Contents

* [README.md](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/README.md): Contains a high level overview of our project and instructions to run and test our code.
* docs: Contains all necessary project documentation
    * [Proposal](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/project_proposal.md): Details our initial proposal for this project
    * [Contract](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/team_contract.md): Our team's contract, including distribution of work and communication methods
    * [Development](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/development.md): A week-by-week update of our team's progress and a breakdown of roles for each week
    * [Results](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/results.md): Our final report, detailing how our objectives were met and a discussion of our findings
    * [Video Report](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/docs/final_recording.mp4): Our team's video report for the project
* graph: Contains implementations for our graph and algorithm classes
    * [Graph](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/graph/graph.cpp)
    * [Algorithms](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/graph/algorithms.cpp)
* data: Contains our raw data, as well as a our Python script to process the data
    * [Python](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/data/cleaner.py)
    * [Proccessor](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/data/data.cpp)
    * [Output](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/data/output.json)
* tests: Contains test cases for our graph, algorithms, and data parsing
    * [Graph Test](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/tests/test_graph.cpp)
    * [Algorithms Test](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/tests/test_algorithms.cpp)
    * [Parsing Test](https://github-dev.cs.illinois.edu/cs225-fa21/sperka2-rohanhh2-guneets2-salunke4/blob/main/tests/test_parsing.cpp)