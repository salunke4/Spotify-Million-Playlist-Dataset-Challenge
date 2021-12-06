#include <string>
#include <vector>
#include <iostream>
#include "../catch/catch.hpp"
#include "../graph/graph.h"
#include "../graph/algorithms.h"

TEST_CASE("DFS") {
    /* Graph structure                    
    *                   1             
    *              /    |    \            
    *             2     7     8        
    *          /   \         / \       
    *        3      6       12  9   
    *      /  \    / \   
    *     4    5  10 11              
    */

    Graph graph;
    graph.InsertVertex("1");
    graph.InsertVertex("2");
    graph.InsertVertex("3");
    graph.InsertVertex("4");
    graph.InsertVertex("5");
    graph.InsertVertex("6");
    graph.InsertVertex("7");
    graph.InsertVertex("8");
    graph.InsertVertex("9");
    graph.InsertVertex("10");
    graph.InsertVertex("11");
    graph.InsertVertex("12");
    graph.InsertEdge("1","8", 1);
    graph.InsertEdge("1","7", 1);
    graph.InsertEdge("1","2", 1);
    graph.InsertEdge("2","6", 1);
    graph.InsertEdge("2","3", 1);
    graph.InsertEdge("3","5", 1);
    graph.InsertEdge("3","4", 1);
    graph.InsertEdge("8","12",1);
    graph.InsertEdge("8","9", 1);
    graph.InsertEdge("9","11",1);
    graph.InsertEdge("9","10",1);
    
    algorithms dfs(graph, "1");

    vector<string> outcome = dfs.traverse();
    vector<string> expected = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    REQUIRE(expected == outcome);
}