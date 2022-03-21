//
// Created by yohanan on 13.3.2022.
//
#include <iostream>
#include "mat.cpp"

int main() {
    int row;
    std::cout << "pleas insert row size of carpet!" << endl;
    std::cout << "(valid - only integers)";
    std::cin >> row;
    int column;
    std::cout << "pleas insert column size of carpet!" << endl;
    std::cout << "(valid - only integers)" << endl;
    std::cin >> column;
    std::cout << "receiving your request, carpet size is " << row << "X" << column;
    char f;
    std::cout << "pleas insert external frames of carpet!" << endl;
    std::cin >> f;
    char l;
    std::cout << "pleas insert internal frames of carpet!" << endl;
    std::cin >> l;
    std::cout << "(working on your request...)" << endl;
    std::cout << "(done!, here is your sketch)" << endl;
    std::cout << ariel::mat(column,row,f,l);
    return 0;
}
