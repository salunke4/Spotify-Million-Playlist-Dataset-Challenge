#include "data.h"
#include "json-develop/single_include/nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

Data::Data(std::vector<string> filenames): filenames_(filenames) {}
Graph Data::readFiles() {
  Graph graph;
  ifstream infile;
  int weight = 1;
  for (string filename : filenames_) {
    infile.open(filename);
    if (!infile) {
      throw std::runtime_error("Could not open file");
    }
    json parser;
    infile >> parser;
    for (auto& el : parser["playlists"].items()) {
      for (size_t i = 0; i < el.value()["tracks"].size(); i++) {
        graph.InsertVertex(el.value()["tracks"][i]["track_name"]);
        for (size_t j = i + 1; j < el.value()["tracks"].size(); j++) {
          graph.InsertEdge(el.value()["tracks"][i]["track_name"], el.value()["tracks"][j]["track_name"], weight);
        }
      }
    }
  }
  infile.close();
  return graph;
}