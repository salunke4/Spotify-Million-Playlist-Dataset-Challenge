#include <string>
#include <vector>

#include "../catch/catch.hpp"

#include "../graph/graph.h""
#include "../data/data.h"

TEST_CASE("Inserting & Removing Vertices") {
  SECTION("Inserting vertices") {
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
  SECTION("Inserting vertex that already exists does not create duplicate vertex") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("C");

    vector<string> expected = {"A", "B", "C", "D"};
    vector<string> actual = graph.GetVertices();
    sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }

  SECTION("Removing vertices") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    graph.RemoveVertex("B");
    graph.RemoveVertex("C");
    graph.RemoveVertex("E");

    vector<string> expected = {"A", "D", "F", "G", "H"};
    vector<string> actual = graph.GetVertices();
    sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
SECTION("Removing vertex that does not exist") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.RemoveVertex("E");
    graph.RemoveVertex("H");

    vector<string> expected = {"A", "B", "C"};
    vector<string> actual = graph.GetVertices();
    sort(actual.begin(), actual.end());
    REQUIRE(expected == actual);
  }
SECTION("Removing vertex properly deletes Edge") {
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
    REQUIRE(false == graph.IsAdjacent("C", "E"));
    REQUIRE(false == graph.IsAdjacent("E", "D"));
  }
}

TEST_CASE("Inserting & Removing Edges, IsAdjacent, GetEdgeValue") {
  SECTION("GetEdgeValue functionality") {
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
    REQUIRE(2 == graph.GetEdgeValue("C", "G"));
    REQUIRE(1 == graph.GetEdgeValue("D", "E"));
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
    graph.InsertEdge("A", "B");
    graph.InsertEdge("B", "A");
    graph.InsertEdge("A", "B");
    REQUIRE(graph.IsAdjacent("A", "G"));
    REQUIRE(3 == graph.GetEdgeValue("A", "G"));
    REQUIRE(1 == graph.GetNumEdges());
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
    graph.RemoveEdge("A", "B");
    REQUIRE(false == graph.IsAdjacent("A", "B"));
    REQUIRE(0 == graph.GetNumEdges());
    graph.InsertEdge("A", "B");
    graph.RemoveEdge("B", "A");
    REQUIRE(false == graph.IsAdjacent("A", "B"));
  }
  SECTION("Remove Edge that does not exist") {
    Graph graph;
    graph.InsertVertex("A");
    graph.InsertVertex("B");
    graph.InsertVertex("C");
    graph.InsertVertex("D");
    graph.InsertVertex("E");
    graph.InsertVertex("F");
    graph.InsertVertex("G");
    graph.InsertVertex("H");
    REQUIRE_NOTHROW(graph.RemoveEdge("A", "B"));
    REQUIRE(false == graph.IsAdjacent("A", "B"));
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
    for(int i = 1; i <= 8; i++) {
      REQUIRE(vector<string>() == graph.AdjacentVertices(to_string(i)));
    }
}
  SECTION("AdjacentVertices functionality") {
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

    vector<string> expectedVertex7 = {"F", "G"};
    vector<string> actualVertex7 = graph.AdjacentVertices("C");
    REQUIRE(expectedVertex7 == actualVertex7);

    vector<string> expectedVertex5 = {"E"};
    vector<string> actualVertex5 = graph.AdjacentVertices("D");
    REQUIRE(expectedVertex5 == actualVertex5);
  }
}
