#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "../graph/graph.h"

using namespace std;

class Data {
    explicit Data(vector<string> filenames);
    Graph readFiles();

    private:
        vector<string> filenames_;
};