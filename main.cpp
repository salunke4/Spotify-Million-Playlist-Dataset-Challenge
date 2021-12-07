#include "data/data.h"
#include "graph/graph.h"
#include "graph/algorithms.h"
#include <string>

int main() {
  std::string start, end, lim;
  int limit;
  
  std::cout << "Starting Song Name:" << std::endl;
  std::getline(std::cin, start);
  std::cout << "Ending Song Name:" << std::endl;
  std::getline(std::cin, end);

  vector<string> files;
  files.push_back("data/output.json");

  Data data(files);
  Graph graph = data.readFiles();
  algorithms generator(graph, start);
  
  std::cout << "Maximum Search Limit:" << std::endl;
  std::getline(std::cin, lim);
  limit = stoi(lim);
  
  if (generator.iterative_dfs(start, end, limit)) {
    std::cout << "Songs are connected !!" << std::endl;
    vector<string> playlist = generator.Dijkstras(end, start);
    std::cout << "Your recommended playlist:" << std::endl;
    
    for (string song : playlist) {
      std::cout << song << std::endl;
    }
  } else {
    std::cout << "Songs are not connected :((" << std::endl;
  }
}