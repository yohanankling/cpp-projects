//
// Created by yohanan on 21.3.2022.
//
#include "Notebook.hpp"
#include <stdexcept>
const int limit = 100;
const int aCase = 32;
const int ZCase = 125;
const char def = '_';
const char del = '~';

void Notebook::write(int page, int row, int column, Direction direction, string phrases) {
    if (page < 0 || row < 0 || column < 0) {
        throw ("page, row and column must be positive");
    }
    if (column >= limit || (direction == Direction::Horizontal && column + (int) phrases.length() > limit)) {
        throw ("cant write here!");
    }
    for (char ch: phrases) {
        if (ch < aCase || ch > ZCase) {
            throw ("invalid char!");
        }
    }
    if (direction == Direction::Horizontal) {
        for (int i = 0; i < (int) phrases.length(); i++) {
            char ch = notebook[page][row][column + i];
            if (ch < aCase || ch > ZCase) {
                if (ch == '~') {
                    throw ("cant write here!");
                }
            }
            else {
                if (ch != '_'){
                throw ("cant write here!");
                }
            }
        }
        for (int i = 0; i < (int) phrases.length(); i++) {
            char ch = phrases[(uint) i];
            notebook[page][row][column + i] = ch;
        }
    }

    if (direction == Direction::Vertical) {
        for (int i = 0; i < (int) phrases.length(); i++) {
            char ch = notebook[page][row + i][column];
            if (ch < aCase || ch > ZCase) {
                if (ch == '~') {
                    throw ("cant write here!");
                }
            } else {
                if (ch != '_') {
                    throw ("cant write here!");
                }
            }
        }
        for (int i = 0; i < (int) phrases.length(); i++) {
            char ch = phrases[(uint) i];
            notebook[page][row+i][column] = ch;
        }
    }
    if (Notebook::max[page] < row){
        Notebook::max[page]  = row;
    }
}

string Notebook::read(int page, int row, int column, Direction direction, int length){
    if (page < 0 || row < 0 || column < 0 || length < 0) {
        throw ("page, row, column and chars to read must be positive");
    }
    if (column >= limit || (direction == Direction::Horizontal && column + length > limit)) {
        throw ("cant read here!");
    }
    string ans;
    if (direction == Direction::Horizontal) {
        for (int i = 0; i < length; i++) {
            char ch = notebook[page][row][column + i];
            if (ch < aCase || ch > ZCase) {
                if (ch == '~') {
                    ans += ch;}
                else{
                    ans += '_';
                }
            }
            else {
                ans += ch;}
        }
    }
    if (direction == Direction::Vertical) {
        for (int i = 0; i < length; i++) {
            char ch = notebook[page][row + i][column];
            if (ch < aCase || ch > ZCase) {
                if (ch == '~') {
                    ans += ch;}
                else{
                ans += '_';
                }
            }
            else {
                ans += ch;}
        }
    }
    return ans;
}

void Notebook::erase(int page, int row, int column, Direction direction, int length) {
    if (page < 0 || row < 0 || column < 0 || length < 0) {
        throw ("page, row, column and chars to delete must be positive");
    }
    if (column >= limit || (direction == Direction::Horizontal && column + length > limit)) {
        throw ("cant delete here!");
    }
    if (direction == Direction::Vertical) {
        for (int i = 0; i < length; i++) {
            notebook[page][row + i ][column] = '~';
        }
    }
    if (direction == Direction::Horizontal) {
        for (int i = 0; i < length; i++) {
            notebook[page][row][column + i] = '~';
        }
    }



    }

void Notebook::show(int page) {
    if (page < 0) {
        throw ("cant read a negative page");
    }
    int max = Notebook::max[page];
    string str;
    for (int i = 0; i <= max; ++i) {
        str =  Notebook::read(page, i, 0, Direction::Horizontal,limit);
        cout << str << endl;
    }
}