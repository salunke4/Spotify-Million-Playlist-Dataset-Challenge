#include <string>
#include <vector>

#include "../catch/catch.hpp"

#include "../graph/graph.h"
#include "../data.h"
#include "../graph/algorithms.h"

TEST_CASE("Test Data Parsing") {
  // duplicate nodes in different playlists not added
  SECTION("Parsing returns correct number of nodes") {
    std::vector<string> files;
    files.push_back("tests/parsing_sample.json");
    Data data(files);
    Graph gr = data.readFiles();
    REQUIRE(gr.GetNumVertices() == 11);
  }

  // nodes are only connected to other nodes in the same playlist
  SECTION("Parsing correctly returns edges") {
    std::vector<string> files;
    files.push_back("tests/parsing_sample.json");
    Data data(files);
    Graph gr = data.readFiles();
    REQUIRE(gr.GetNumEdges() == );
  }

  SECTION("Parsing correctly adds edges between nodes") {
    std::vector<string> files;
    files.push_back("tests/parsing_sample.json");
    Data data(files);
    Graph g = data.readFiles();
    vector<string> expected1 = {"Dynasty", "First", "Like It Doesn't Hurt (feat. Husser)", "One Dance",
                                 "Water Under the Bridge", "Your Girl"};
    vector<string> actual1 = g.AdjacentVertices("Bare");
    sort(actual1.begin(), actual1.end());
    REQUIRE(expected1 == actual1);
    vector<string> expected2 = {"Bare", "Dynasty", "Like It Doesn't Hurt (feat. Husser)", "One Dance",
                                 "Your Girl"};
    vector<string> actual2 = g.AdjacentVertices("First");
    sort(actual2.begin(), actual2.end());
    REQUIRE(expected2 == actual2);
    vector<string> expected3 = {"Like It Doesn't Hurt (feat. Husser)", "Your Girl"};
    vector<string> actual3 = g.AdjacentVertices("Letting In");
    sort(actual3.begin(), actual3.end());
    REQUIRE(expected3 == actual3);
  }

  SECTION("Edge weights properly updated") {
    std::vector<string> files;
    files.push_back("tests/sample.json");
    Data data(files);
    Graph g = data.readFiles();
    REQUIRE(1 == g.GetEdgeValue("Bare", "Dynasty"));
    REQUIRE(2 == g.GetEdgeValue("Bare", "Your Girl"));
    REQUIRE(3 == g.GetEdgeValue("Your Girl", "Like It Doesn't Hurt (feat. Husser)"));
    }

SECTION("Throws exception when file is invalid") {
    std::vector<string> files;
    files.push_back("tests/invalid_file.json");
    Data data(files);
    REQUIRE_THROWS_AS(data.readFiles(), std::runtime_error);
  }
}