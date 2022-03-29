#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Direction.hpp"
using namespace ariel;
using namespace std;

const int limit = 100;
const int minValue = 32;
const int maxValue = 126;

namespace ariel {
    
    class Notebook {
        public: 
            map<int, vector<vector<char>>> pages;

            Notebook();
            Notebook(int p, int r, int c);

            int write(int page, int row, int column, Direction dir, string content);
            string read(int page, int row, int column, Direction dir, int length);
            int erase(int page, int row, int column, Direction dir, int length);
            int show(int page);
    };
}