#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../graph/graph.h"

using namespace std;

class Data {
    private:
        vector<string> filenames_;
    public:
        explicit Data(vector<string> filenames);
        Graph readFiles();
};