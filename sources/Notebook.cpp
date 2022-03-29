#include "Notebook.hpp"

using namespace ariel;

Notebook::Notebook() {
    
}
int Notebook::write(int page, int row, int column, Direction dir, string content) {    
    // checking the input
    if((page < 0) || (row < 0) || (column < 0) || (column >= limit)) {
        throw invalid_argument("Wrong input");
    }
    
    if((dir == Direction::Horizontal) && (((size_t)column + content.length()) >= limit)) {
        throw invalid_argument("Wrong input");
    }
    
    
    for(size_t i=0; i<content.length(); i++) {
        if(content.at(i) < minValue || maxValue < content.at(i) || (content.at(i) == '~')) {
            throw invalid_argument("Wrong input");
        }
    }
    // end of checking input

    
    // check if the page exist
    if (!this->pages.contains(page)) {
        this->pages[page] = vector<vector<char>>((size_t)row + 1, vector<char>(limit, '_'));
    }
    
    // check if the row exist
    while(pages[page].size() <= row) {
        vector<char> newRow(limit, '_');
        pages[page].push_back(newRow);
    }
    
    
    size_t trow = (size_t)row;
    size_t tcol = (size_t)column;
    for (int i=0; i<content.size(); i++) {
        if((dir == Direction::Vertical) && (pages[page].size() <= row + i)) {
                vector<char> newRow(limit, '_');
                pages[page].push_back(newRow);
            }
        if(pages[page][trow][tcol] != '_') {
            throw invalid_argument("Wrong input");
        }
        
        if(dir == Direction::Horizontal) {
            tcol++;
        } else if(dir == Direction::Vertical) {
            trow++;
        }   
    }    
    for (size_t i=0; i<content.length(); i++) {
        pages[page][(size_t)row][(size_t)column] = content[i];
        if(dir == Direction::Horizontal) {
            column++;
        }
        else if(dir == Direction::Vertical) {
            row++;
        }
    }
    
    return 0;
}


string Notebook::read(int page, int row, int column, Direction dir, int length) {
    if((page < 0) || (row < 0) || (column < 0) || (column >= limit) || (length <= 0)) {
        throw invalid_argument("Wrong input");
    }
    if((dir == Direction::Horizontal) && (column + length > limit)) {
        throw invalid_argument("Wrong input");
    }

    string ans;
    if (!this->pages.contains(page)) {
        this->pages[page] = vector<vector<char>>((size_t)row + 1, vector<char>(limit, '_'));
    }
    
    // check if the row exist
    while(pages[page].size() <= row) {
        vector<char> newRow(limit, '_');
        pages[page].push_back(newRow);
    }
    
    
    size_t trow = (size_t)row;
    size_t tcol = (size_t)column;
    for (int i=0; i<length; i++) {
        if((dir == Direction::Vertical) && (pages[page].size() <= row + i)) {
                vector<char> newRow(limit, '_');
                pages[page].push_back(newRow);
            }
        
        if(dir == Direction::Horizontal) {
            tcol++;
        } else if(dir == Direction::Vertical) {
            trow++;
        }   
    }    
    for (size_t i=0; i<length; i++) {
        ans += pages[page][(size_t)row][(size_t)column];
        if(dir == Direction::Horizontal) {
            column++;
        }
        else if(dir == Direction::Vertical) {
            row++;
        }
    }
    return ans;
}


int Notebook::erase(int page, int row, int column, Direction dir, int length) {
    if((page < 0) || (row < 0) || (column < 0) || (column >= limit) || (length <= 0)) {
        throw invalid_argument("Wrong input");
    }
    if((dir == Direction::Horizontal) && (column + length > limit)) {
        throw invalid_argument("Wrong input");
    }
if (!this->pages.contains(page)) {
        this->pages[page] = vector<vector<char>>((size_t)row + 1, vector<char>(limit, '_'));
    }
    
    // check if the row exist
    while(pages[page].size() <= row) {
        vector<char> newRow(limit, '_');
        pages[page].push_back(newRow);
    }
    
    
    size_t trow = (size_t)row;
    size_t tcol = (size_t)column;
    for (int i=0; i<length; i++) {
        if((dir == Direction::Vertical) && (pages[page].size() <= row + i)) {
                vector<char> newRow(limit, '_');
                pages[page].push_back(newRow);
            }
        
        if(dir == Direction::Horizontal) {
            tcol++;
        } else if(dir == Direction::Vertical) {
            trow++;
        }   
    }    
    for (size_t i=0; i<length; i++) {
        pages[page][(size_t)row][(size_t)column] = '~';
        if(dir == Direction::Horizontal) {
            column++;
        }
        else if(dir == Direction::Vertical) {
            row++;
        }
    }
    return 0;
}

int Notebook::show(int page) {
    if(page < 0) {
        throw invalid_argument("Wrong input");
    }
    for (size_t i=0; i<pages[page].size(); i++) {
        for(size_t j=0; j<limit; j++) {
            cout << pages[page][i][j];
        }
        cout << endl;
    }
    
    return 0;
}