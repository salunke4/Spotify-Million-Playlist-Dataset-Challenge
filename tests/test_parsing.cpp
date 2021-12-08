#include <string>
#include <vector>

#include "../catch/catch.hpp"
#include "../graph/graph.h"
#include "../data/data.h"
#include "../graph/algorithms.h"

// duplicate nodes in different playlists not added
TEST_CASE("Correct Number of Nodes") {
  std::vector<string> files;
  files.push_back("tests/parsing_sample.json");
  Data data(files);
  Graph gr = data.readFiles();
  REQUIRE(gr.GetNumVertices() == 5);
}

// nodes are only connected to other nodes in the same playlist
TEST_CASE("Correct Number of Edges") {
  std::vector<string> files;
  files.push_back("tests/parsing_sample.json");
  Data data(files);
  Graph gr = data.readFiles();
  REQUIRE(gr.GetNumEdges() == 8);
}

// if songs are in n playlists together, their incident edge has weight n
TEST_CASE("Correct Edge Weights") {
  std::vector<string> files;
  files.push_back("tests/parsing_sample.json");
  Data data(files);
  Graph gr = data.readFiles();
  REQUIRE(gr.GetEdgeValue("Pink + White", "Sober") == 1);
  REQUIRE(gr.GetEdgeValue("Love$ick (feat. A$AP Rocky)", "Redbone") == 2);
}

// nodes are only connected to other nodes in the same playlist
TEST_CASE("Correct Edges Between Nodes") {
  std::vector<string> files;
  files.push_back("tests/parsing_sample.json");
  Data data(files);
  Graph gr = data.readFiles();
  vector<string> expected, outcome; 

  outcome = gr.AdjacentVertices("Pink + White");
  expected = {"Love$ick (feat. A$AP Rocky)", "Redbone", "Sober"};
  sort(outcome.begin(), outcome.end());
  REQUIRE(expected == outcome);

  outcome = gr.AdjacentVertices("Me and Your Mama");
  expected = {"Love$ick (feat. A$AP Rocky)", "Redbone"};
  sort(outcome.begin(), outcome.end());
  REQUIRE(expected == outcome);

  outcome = gr.AdjacentVertices("Love$ick (feat. A$AP Rocky)");
  expected = {"Me and Your Mama", "Pink + White", "Redbone", "Sober"};
  sort(outcome.begin(), outcome.end());
  REQUIRE(expected == outcome);
}

// throws runtime error for invalid file
TEST_CASE("Invalid Files") {
  std::vector<string> files;
  files.push_back("tests/nonexistent.json");
  Data data(files);
  REQUIRE_THROWS_AS(data.readFiles(), std::runtime_error);
}