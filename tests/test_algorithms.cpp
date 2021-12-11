#include <string>
#include <vector>
#include <iostream>

#include "../catch/catch.hpp"
#include "../graph/graph.h"
#include "../graph/algorithms.h"

TEST_CASE("DFS") {
    /* Graph:                    
    *                   A             
    *               /   |   \            
    *             B     I     J        
    *           /  \         / \       
    *         C     D       K   L   
    *       / \    / \           \
    *     E    F  G   H           M 
    */

    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.InsertVertex("I");
    graph.InsertVertex("J");
    graph.InsertVertex("K");
    graph.InsertVertex("L");
    graph.InsertVertex("M");
    graph.InsertEdge("A","J", 1);
    graph.InsertEdge("A","I", 1);
    graph.InsertEdge("A","B", 1);
    graph.InsertEdge("B","D", 1);
    graph.InsertEdge("B","C", 1);
    graph.InsertEdge("C","F", 1);
    graph.InsertEdge("C","E", 1);
    graph.InsertEdge("D","H", 1);
    graph.InsertEdge("D","G", 1);
    graph.InsertEdge("J","K", 1);
    graph.InsertEdge("J","L", 1);
    graph.InsertEdge("L","M", 1);
    
    algorithms dfs(graph, "A");
    vector<string> outcome, expected;

    outcome = dfs.traverse();
    expected = {"A", "B", "C", "E", "F", "D", "G", "H", "I", "J", "L", "M", "K"};
    REQUIRE(expected == outcome);
}

TEST_CASE("Complex DFS") {
    /* Graph:
    *        A        
    *       / \       
    *      B   F           
    *      | / |      
    *      C---E--G      
    *       \ /       
    *        D        
    */

    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertEdge("A","F", 1);
    graph.InsertEdge("A","B", 1);
    graph.InsertEdge("B","C", 1);
    graph.InsertEdge("C","F", 1);
    graph.InsertEdge("C","E", 1);
    graph.InsertEdge("C","D", 1);
    graph.InsertEdge("D","E", 1);
    graph.InsertEdge("E","G", 1);
    graph.InsertEdge("E","F", 1);
    
    algorithms dfs(graph, "A");
    vector<string> outcome, expected;

    outcome = dfs.traverse();
    expected = {"A", "F", "C", "E", "G", "D", "B"};
    REQUIRE(outcome == expected);
}

TEST_CASE("Cycle DFS") {
    /* Graph:
    *         A    
    *     /   |   \   
    *    B    C    E  
    *          \  / \ 
    *            D   F
    */
   
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertEdge("A","E", 1);
    graph.InsertEdge("A","C", 1);
    graph.InsertEdge("A","B", 1);
    graph.InsertEdge("C","D", 1);
    graph.InsertEdge("D","E", 1);
    graph.InsertEdge("E","F", 1);

    algorithms dfs(graph, "A");
    vector<string> outcome, expected;

    outcome = dfs.traverse();
    expected = {"A", "B", "E", "F", "D", "C"};
    REQUIRE(outcome == expected);
}

TEST_CASE("Dijkstras") {
    /* Graph:                    
    *                   A             
    *               /   |   \            
    *             B     I     J        
    *           /  \         / \       
    *         C     D       K   L   
    *       / \    / \           \
    *     E    F  G   H           M 
    */

    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.InsertVertex("I");
    graph.InsertVertex("J");
    graph.InsertVertex("K");
    graph.InsertVertex("L");
    graph.InsertVertex("M");
    graph.InsertEdge("A","B", 1);
    graph.InsertEdge("B","C", 1);
    graph.InsertEdge("B","D", 1);
    graph.InsertEdge("C","E", 1);
    graph.InsertEdge("C","F", 1);
    graph.InsertEdge("D","G", 1);
    graph.InsertEdge("D","H", 1);
    graph.InsertEdge("A","I",1);
    graph.InsertEdge("A","J", 1);
    graph.InsertEdge("J","K",1);
    graph.InsertEdge("J","L",1);
    graph.InsertEdge("L","M",1);
    
    algorithms dijkstra(graph, "A");
    vector<string> outcome, expected;

    outcome = dijkstra.Dijkstras("A", "B");
    expected = {"A", "B"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("A", "E");
    expected = {"A", "B", "C", "E"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("B", "F");
    expected = {"B", "C", "F"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("A", "M");
    expected = {"A", "J", "L", "M"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("H", "I");
    expected = {"H", "D", "B", "A", "I"};
    REQUIRE(outcome == expected);
}

TEST_CASE("Complex Dijkstras") {
    /* Graph:
    *        A        
    *       / \       
    *      B   F           
    *      | / |      
    *      C---E--G      
    *       \ /       
    *        D        
    */

    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertEdge("A","B", 1);
    graph.InsertEdge("B","C", 1);
    graph.InsertEdge("C","F", 1);
    graph.InsertEdge("C","E", 1);
    graph.InsertEdge("C","D", 1);
    graph.InsertEdge("E","G", 1);
    graph.InsertEdge("E","F", 1);
    graph.InsertEdge("F","A", 1);

    algorithms dijkstra(graph, "A");
    vector<string> outcome, expected;

    outcome = dijkstra.Dijkstras("A", "C");
    expected = {"A", "B", "C"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("B", "G");
    expected = {"B", "C", "E", "G"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("F", "G");
    expected = {"F", "E", "G"};
    REQUIRE(outcome == expected);
    
    outcome = dijkstra.Dijkstras("B", "F");
    expected = {"B", "A", "F"};
    REQUIRE(outcome == expected);
}

TEST_CASE("Cycle Dijkstras") {
    /* Graph:
    *         A    
    *     /   |   \   
    *    B    C    E  
    *          \  / \ 
    *            D   F
    */
   
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertEdge("A","E", 1);
    graph.InsertEdge("A","C", 1);
    graph.InsertEdge("A","B", 1);
    graph.InsertEdge("C","D", 1);
    graph.InsertEdge("D","E", 1);
    graph.InsertEdge("E","F", 1);

    algorithms dijkstra(graph, "A");
    vector<string> outcome, expected;

    outcome = dijkstra.Dijkstras("A", "B");
    expected = {"A", "B"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("A", "D");
    expected = {"A", "E", "D"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("A", "E");
    expected = {"A", "E"};
    REQUIRE(outcome == expected);

    outcome = dijkstra.Dijkstras("A", "F");
    expected = {"A", "E", "F"};
    REQUIRE(outcome == expected);
}

TEST_CASE("Iterative Deepening Depth-First Search (IDDFS)") {
    /* Graph:                    
    *                   A             
    *               /   |   \            
    *             B     I     J        
    *           /  \         / \       
    *         C     D       K   L   
    *       / \    / \           \
    *     E    F  G   H           M 
    */

    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.InsertVertex("I");
    graph.InsertVertex("J");
    graph.InsertVertex("K");
    graph.InsertVertex("L");
    graph.InsertVertex("M");
    graph.InsertEdge("A","B", 0);
    graph.InsertEdge("B","C", 0);
    graph.InsertEdge("B","D", 0);
    graph.InsertEdge("C","E", 0);
    graph.InsertEdge("C","F", 0);
    graph.InsertEdge("D","G", 0);
    graph.InsertEdge("D","H", 0);
    graph.InsertEdge("A","I", 0);
    graph.InsertEdge("A","J", 0);
    graph.InsertEdge("J","K", 0);
    graph.InsertEdge("J","L", 0);
    graph.InsertEdge("L","M", 0);

    algorithms idfs(graph, "A");

    REQUIRE( idfs.iterative_dfs("A", "B", 1));
    REQUIRE(!idfs.iterative_dfs("A", "B", 0));

    REQUIRE( idfs.iterative_dfs("A", "C", 2));
    REQUIRE(!idfs.iterative_dfs("A", "C", 0));
    REQUIRE(!idfs.iterative_dfs("A", "C", 1));

    REQUIRE( idfs.iterative_dfs("A", "H", 3));
    REQUIRE(!idfs.iterative_dfs("A", "H", 0));
    REQUIRE(!idfs.iterative_dfs("A", "H", 1));
    REQUIRE(!idfs.iterative_dfs("A", "H", 2));

    REQUIRE( idfs.iterative_dfs("A", "K", 2));
    REQUIRE(!idfs.iterative_dfs("A", "K", 0));
    REQUIRE(!idfs.iterative_dfs("A", "K", 1));

    REQUIRE( idfs.iterative_dfs("J", "M", 2));
    REQUIRE(!idfs.iterative_dfs("J", "M", 0));
    REQUIRE(!idfs.iterative_dfs("J", "M", 1));
}

TEST_CASE("Complex IDDFS") {
    /* Graph:
    *        A        
    *       / \       
    *      B   F           
    *      | / |      
    *      C---E--G      
    *       \ /       
    *        D        
    */

    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertEdge("A","B", 1);
    graph.InsertEdge("B","C", 1);
    graph.InsertEdge("C","F", 1);
    graph.InsertEdge("C","E", 1);
    graph.InsertEdge("C","D", 1);
    graph.InsertEdge("E","G", 1);
    graph.InsertEdge("E","F", 1);
    graph.InsertEdge("F","A", 1);

    algorithms idfs(graph, "A");

    REQUIRE( idfs.iterative_dfs("A", "B", 1));
    REQUIRE(!idfs.iterative_dfs("A", "B", 0));

    REQUIRE( idfs.iterative_dfs("A", "D", 3));
    REQUIRE(!idfs.iterative_dfs("A", "D", 0));
    REQUIRE(!idfs.iterative_dfs("A", "D", 1));
    REQUIRE(!idfs.iterative_dfs("A", "D", 2));

    REQUIRE( idfs.iterative_dfs("F", "G", 2));
    REQUIRE(!idfs.iterative_dfs("F", "G", 0));
    REQUIRE(!idfs.iterative_dfs("F", "G", 1));

    REQUIRE( idfs.iterative_dfs("C", "G", 2));
    REQUIRE(!idfs.iterative_dfs("C", "G", 0));
    REQUIRE(!idfs.iterative_dfs("C", "G", 1));
}

TEST_CASE("Cycle IDDFS") {
    /* Graph:
    *         A    
    *     /   |   \   
    *    B    C    E  
    *          \  / \ 
    *            D   F
    */
   
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertEdge("A","E", 1);
    graph.InsertEdge("A","C", 1);
    graph.InsertEdge("A","B", 1);
    graph.InsertEdge("C","D", 1);
    graph.InsertEdge("D","E", 1);
    graph.InsertEdge("E","F", 1);

    algorithms idfs(graph, "A");

    REQUIRE( idfs.iterative_dfs("A", "B", 1));
    REQUIRE(!idfs.iterative_dfs("A", "B", 0));

    REQUIRE( idfs.iterative_dfs("A", "C", 1));
    REQUIRE(!idfs.iterative_dfs("A", "C", 0));

    REQUIRE( idfs.iterative_dfs("A", "D", 2));
    REQUIRE(!idfs.iterative_dfs("A", "D", 0));
    REQUIRE(!idfs.iterative_dfs("A", "D", 1));

    REQUIRE( idfs.iterative_dfs("A", "E", 1));
    REQUIRE(!idfs.iterative_dfs("A", "E", 0));

    REQUIRE( idfs.iterative_dfs("A", "F", 2));
    REQUIRE(!idfs.iterative_dfs("A", "F", 0));
    REQUIRE(!idfs.iterative_dfs("A", "F", 1));

    REQUIRE( idfs.iterative_dfs("C", "F", 3));
    REQUIRE(!idfs.iterative_dfs("C", "F", 0));
    REQUIRE(!idfs.iterative_dfs("C", "F", 1));
    REQUIRE(!idfs.iterative_dfs("C", "F", 2));
}