#include <string>
#include <vector>

#include "../catch/catch.hpp"

#include "../graph/graph.h"
#include "../data/data.h"

TEST_CASE("Inserting & Removing Vertices") {
  SECTION("Inserting Vertices") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");

    vector<string> expected = {"A", "B", "C", "D", "E", "F", "G", "H"};
    vector<string> actual = graph.GetVertices();
    sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }

  SECTION("Inserting Duplicate Vertices") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("C");
    graph.InsertVertex("A");

    vector<string> expected = {"A", "B", "C", "D"};
    vector<string> actual = graph.GetVertices();
    sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }

  SECTION("Removing Vertices") {
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
    graph.RemoveVertex("B");
    graph.RemoveVertex("C");
    graph.RemoveVertex("E");

    vector<string> expected = {"A", "D", "F", "G", "H", "I"};
    vector<string> actual = graph.GetVertices();
    sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }

  SECTION("Removing Nonexistent Vertices") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.RemoveVertex("D");

    vector<string> expected = {"A", "B", "C"};
    vector<string> actual = graph.GetVertices();
    sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }

  SECTION("Removing Edges") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.InsertEdge("A", "B");
    graph.InsertEdge("A", "C");
    graph.InsertEdge("C", "F");
    graph.InsertEdge("C", "G");
    graph.InsertEdge("C", "E");
    graph.InsertEdge("D", "E");
    graph.InsertEdge("A", "H");
    graph.RemoveVertex("E");

    REQUIRE(graph.IsAdjacent("C", "E") == false);
    REQUIRE(graph.IsAdjacent("E", "D") == false);
  }
}

TEST_CASE("Inserting & Removing Edges, IsAdjacent, GetEdgeValue") {
  SECTION("GetEdgeValue") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.InsertEdge("A", "B");
    graph.InsertEdge("C", "G");
    graph.InsertEdge("C", "G");
    graph.InsertEdge("D", "E");

    REQUIRE(-1 == graph.GetEdgeValue("G", "H"));
    REQUIRE( 2 == graph.GetEdgeValue("C", "G"));
    REQUIRE( 1 == graph.GetEdgeValue("D", "E"));
  }

  SECTION("InsertVertex & IsAdjacent") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.InsertEdge("A", "B");
    graph.InsertEdge("C", "G");
    graph.InsertEdge("A", "H");

    REQUIRE(graph.IsAdjacent("A", "B"));
    REQUIRE(graph.IsAdjacent("B", "A")); 
    REQUIRE(graph.IsAdjacent("C", "G"));
    REQUIRE(graph.IsAdjacent("A", "H"));
  }

  SECTION("Inserting Duplicate Edge") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.RemoveVertex("C");
    graph.InsertEdge("A", "G");
    graph.InsertEdge("G", "A");
    graph.InsertEdge("A", "G");

    REQUIRE(graph.IsAdjacent("A", "G"));
    REQUIRE(graph.GetEdgeValue("A", "G") == 3);
    REQUIRE(graph.GetNumEdges() == 1);
  }

  SECTION("Removing Edge") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.InsertEdge("A", "B");
    graph.InsertEdge("B", "C");
    graph.RemoveEdge("A", "B");

    REQUIRE(graph.IsAdjacent("A", "B") == false);
    REQUIRE(graph.GetNumEdges() == 1);

    graph.InsertEdge("A", "B");
    graph.RemoveEdge("B", "A");
    REQUIRE(graph.IsAdjacent("A", "B") == false);
  }

  SECTION("Remove Nonexistent Edge") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");

    REQUIRE_NOTHROW(graph.RemoveEdge("A", "B"));
    REQUIRE(graph.IsAdjacent("A", "B") == false);
  }
}

TEST_CASE("AdjacentVertices") {
  SECTION("No Adjacent Vertices") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");

    int i = 1;
    while (i <= 8) {
      REQUIRE(vector<string>() == graph.AdjacentVertices(to_string(i)));
      i++;
    }
  }  

  SECTION("AdjacentVertices Functionality") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.InsertEdge("A", "B");
    graph.InsertEdge("A", "C");
    graph.InsertEdge("C", "F");
    graph.InsertEdge("C", "G");
    graph.InsertEdge("C", "E");
    graph.InsertEdge("D", "E");
    graph.InsertEdge("A", "H");

    vector<string> expected, actual;

    expected = {"A", "E", "F", "G"};
    actual = graph.AdjacentVertices("C");
    REQUIRE(expected == actual);

    expected = {"E"};
    actual = graph.AdjacentVertices("D");
    REQUIRE(expected == actual);
  }
}
