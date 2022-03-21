//
// Created by yohanan on 7.3.2022.
//
#include "mat.hpp"
#include "string"
#include <cmath>
#include <stdexcept>
#include <vector>

using namespace std;

string ariel::mat(int column, int row, char f, char l) {
    const int minChar = 33;
    const int maxChar = 126;
    if (column < 0 || row < 0 || column%2 == 0 || row%2 == 0) {
        throw invalid_argument( "Mat size is always positive odd" );
    }
    if (f < minChar || f > maxChar || l < minChar || l > maxChar) {
        throw invalid_argument( "Mat sign has to be vaild char" );
    }
    string ans;
    if (column == 1){
        for (int j = 0; j < row; j++) {
            ans += f;
            ans += "\n";
        }
        return ans;
    }
    vector<vector<char>> mat( row , vector<char> (column, 0));
    // for override error tidy
    char temp = ' ';
    for (int times = 0; bool (ceil (times < row)) ; times++) {
        if (times % 2 == 0){
            temp = f;}
        else {
            temp = l;
        }
        for (int i = times; i < column - times; i++) {
            mat[times][i] = temp;
            mat[row - 1 - times][i] = temp;
        }
        for (int i = times; i < row - times; i++) {
            mat[i][times] = temp;
            mat[i][column - 1 - times] = temp;
        }
    }
    for (int i = 0; i < row; i++) {
        std::string str(mat[i].begin(), mat[i].end());
            ans += str;
            ans += "\n";
    }
    return ans;
}


