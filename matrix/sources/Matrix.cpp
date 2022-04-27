//
// Created by yohanan on 30.3.2022.
//
#include <iostream>
#include <vector>
#include <string>
#include "Matrix.hpp"
#include <algorithm>
using namespace std;
using namespace zich;

namespace zich {

    void checkTwoMat(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.columns != mat2.columns || mat1.rows != mat2.rows) {
            throw invalid_argument("Mats size is different!!");
        }
    }

    void vaildMult(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.columns != mat2.rows) {
            throw invalid_argument("Mats size is different!!");
        }
    }

    Matrix Matrix::operator+(const Matrix &mat2) {
        Matrix mat1 = *this;
        checkTwoMat(mat1, mat2);
        vector<double> ans;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            ans.push_back(mat1.identity[i] + mat2.identity[i]);
        }
        return {ans, mat2.rows, mat2.columns};
    }

    Matrix Matrix::operator+=(Matrix &mat2) {
        Matrix mat1 = *this;
        checkTwoMat(mat1, mat2);
        vector<double> ans;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            this->identity.at(i) = (mat1.identity[i] + mat2.identity[i]);
        }
        return *this;
    }

    Matrix Matrix::operator+() {
        Matrix mat1 = *this;
        return mat1;
    }

    Matrix Matrix::operator-(const Matrix &mat2){
        Matrix mat1 = *this;
        checkTwoMat(mat1, mat2);
        vector<double> ans;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            ans.push_back(mat1.identity[i] - mat2.identity[i]);
        }
        return {ans, mat2.rows, mat2.columns};
    }

    Matrix Matrix::operator-=(Matrix &mat2) {
        Matrix mat1 = *this;
        checkTwoMat(mat1, mat2);
        vector<double> ans;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            this->identity.at(i) = (mat1.identity[i] - mat2.identity[i]);
        }
        return *this;
    }

    Matrix Matrix::operator-(){
        Matrix mat1 = *this;
        vector<double> ans;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            mat1.identity.at(i) = mat1.identity.at(i) * -1;
            if (mat1.identity.at(i) == 0) {
                mat1.identity.at(i) = 0;
            }
        }
        return mat1;
    }

    bool Matrix::operator>(const Matrix &mat2){
        checkTwoMat(*this, mat2);
        Matrix mat1 = *this;
        long sum1 = 0;
        long sum2 = 0;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            sum1 += mat1.identity[i];
        }
        for (uint i = 0; i < mat2.identity.size(); i++) {
            sum2 += mat2.identity[i];
        }
        return (sum1 > sum2);
    }

    bool Matrix::operator>=(const Matrix &mat2){
        checkTwoMat(*this, mat2);
        Matrix mat1 = *this;
        long sum1 = 0;
        long sum2 = 0;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            sum1 += mat1.identity[i];
        }
        for (uint i = 0; i < mat2.identity.size(); i++) {
            sum2 += mat2.identity[i];
        }
        return (sum1 >= sum2);
    }

    bool Matrix::operator<(const Matrix &mat2){
        checkTwoMat(*this, mat2);
        Matrix mat1 = *this;
        long sum1 = 0;
        long sum2 = 0;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            sum1 += mat1.identity[i];
        }
        for (uint i = 0; i < mat2.identity.size(); i++) {
            sum2 += mat2.identity[i];
        }
        return (sum1 < sum2);
    }


    bool Matrix::operator<=(const Matrix &mat2){
        checkTwoMat(*this, mat2);
        Matrix mat1 = *this;
        long sum1 = 0;
        long sum2 = 0;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            sum1 += mat1.identity[i];
        }
        for (uint i = 0; i < mat1.identity.size(); i++) {
            sum2 += mat2.identity[i];
        }
        return (sum1 <= sum2);
    }

    bool Matrix::operator==(const Matrix &mat2) const{
        checkTwoMat(*this, mat2);
        Matrix mat1 = *this;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            if (mat1.identity.at(i) != mat2.identity.at(i)){
                return false;
            }
        }
        return true;
    }

    bool Matrix::operator!=(const Matrix &mat2)const{
        checkTwoMat(*this, mat2);
        Matrix mat1 = *this;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            if (mat1.identity.at(i) != mat2.identity.at(i)){
                return true;
            }
        }
        return false;
    }

    Matrix Matrix::operator++() {
        for (uint i = 0; i < this->identity.size(); i++) {
            this->identity.at(i)++;
        }
        return *this;
    }

    Matrix Matrix::operator++(int num) {
        vector<double> ans = this->identity;
        for (uint i = 0; i < this->identity.size(); i++) {
            this->identity.at(i)++;
        }
        return {ans, this->rows, this->columns};
    }

    Matrix Matrix::operator--() {
        for (uint i = 0; i < this->identity.size(); i++) {
            this->identity.at(i)--;
        }
        return *this;
    }

    Matrix Matrix::operator--(int num) {
        vector<double> ans = this->identity;
        for (uint i = 0; i < this->identity.size(); i++) {
            this->identity.at(i)--;
        }
        return {ans, this->rows, this->columns};
    }

    Matrix Matrix::operator*(const Matrix &mat2) {
        Matrix mat1 = *this;
        vaildMult(mat1, mat2);
        vector<double> ans;
        for (uint i = 0; i < mat1.rows; i++) {
            for (uint j = 0; j < mat2.columns; j++) {
                ans.push_back(0);
            }
        }
        for (uint i = 0; i < mat1.rows; i++) {
            for (uint j = 0; j < mat2.columns; j++) {
                for (uint k = 0; k < mat1.columns; k++) {
                    ans[i * unsigned(mat2.columns) + j] = ans[i * unsigned(mat2.columns) + j] +
                                                          mat1.identity[(i * unsigned(mat1.columns) + k)] *
                                                          mat2.identity[k * unsigned(mat2.columns) + j];
                }
            }
        }
        return {ans, mat1.rows, mat2.columns};
    }

    Matrix operator*(int num, const Matrix &mat1) {
        vector<double> ans;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            ans.push_back(mat1.identity.at(i) * num);
        }
        return {ans, mat1.rows, mat1.columns};
    }

    Matrix Matrix::operator*(double num) {
        Matrix mat1 = *this;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            mat1.identity.at(i) = mat1.identity.at(i) * num;
        }
        return mat1;
    }

    Matrix operator*(double num, const Matrix &mat1) {
        vector<double> ans;
        for (uint i = 0; i < mat1.identity.size(); i++) {
            ans.push_back(mat1.identity[i] * num);
        }
        return {ans, mat1.rows, mat1.columns};
    }

    Matrix Matrix::operator*=(double num) {
        for (uint i = 0; i < this->identity.size(); i++) {
            this->identity.at(i) = this->identity[i] * num;
        }
        return *this;
    }

    Matrix Matrix::operator*=(const Matrix &mat2) {
        Matrix mat1 = *this;
        vaildMult(mat1, mat2);
        vector<double> ans;
        for (uint i = 0; i < mat1.rows; i++) {
            for (uint j = 0; j < mat2.columns; j++) {
                ans.push_back(0);
            }
        }
        for (uint i = 0; i < mat1.rows; i++) {
            for (uint j = 0; j < mat2.columns; j++) {
                for (uint k = 0; k < mat1.columns; k++) {
                    ans[i * unsigned(mat2.columns) + j] = ans[i * unsigned(mat2.columns) + j] +
                                                          mat1.identity[(i * unsigned(mat1.columns) + k)] *
                                                          mat2.identity[k * unsigned(mat2.columns) + j];
                }
            }
        }
        this->identity.clear();
        for (uint i = 0; i < ans.size(); ++i) {
            this->identity.push_back(ans.at(i));
        }
        *this = {identity, mat1.rows, mat2.columns};
        return {ans, mat1.rows, mat2.columns};
    }

    ostream &operator<<(ostream &out, const Matrix &mat1) {
        string ans = "[";
        int row = mat1.rows;
        int columns = mat1.columns;
        vector<double> identity = mat1.identity;
        for (uint j = 0; j < row; ++j) {
            for (uint k = 0; k < columns; ++k) {
                ans += to_string((int) identity.at(j * unsigned(columns) + k));
                ans += " ";
            }
            ans.resize(ans.size() - 1);
            ans += "]\n[";
        }
        ans.resize(ans.size() - 2);
        return out << ans;
    }

    istream &operator>>(istream &in, Matrix &mat1) {
        string matrix;
        string line;
        string temp;
        int columns = 0;
        vector<double> identity;
        while (!in.eof()) {
            in >> temp;
            matrix += " " + temp;
        }
        if (matrix.size() == 1) {
            throw (invalid_argument("invalid format"));
        }
        matrix.resize(matrix.size() - (temp.size() + 1));
        matrix.erase(0, 1);
        int rows = count(matrix.begin(), matrix.end(), ',');
        temp = "";
        if (matrix.at(0) != '[' || matrix.at(matrix.size() - 1) != ']') {
            throw (invalid_argument("invalid format"));
        }
        for (uint i = 1; i < matrix.size(); ++i) {
            for (uint j = i; j < matrix.size(); ++j) {
                if (matrix.at(j) == ']') {
                    i = j;
                    break;
                }
                line += matrix.at(j);
            }
            bool flag = false;
            for (uint j = 0; j < line.size(); ++j) {
                char curr = line.at(j);
                int digit = isdigit(curr);
                if (line.at(j) == '.') {
                    if (flag) {
                        throw (invalid_argument("invalid format"));
                    }
                    temp += curr;
                    flag = true;
                }
                else if (digit == 1) {
                    temp += curr;
                } else if (curr == ' ') {
                    if (temp.size() > 1 && temp.at(temp.size() - 1) == '.') {
                        throw (invalid_argument("invalid format"));
                    }
                    char * pEnd = NULL;
                    double d = strtod(temp.c_str(), &pEnd);
                    identity.push_back(d);
                    temp = "";
                    columns++;
                } else if(digit == 0){
                    throw (invalid_argument("invalid format"));
                }
                else {

                }
            }
            char * pEnd = NULL;
            double d = strtod(temp.c_str(), &pEnd);
            identity.push_back(d);
            temp = "";
            columns++;
            line = "";
            if (matrix.size() - i > 4) {
                if (matrix.at(i+1) == ',' && matrix.at(i+2) == ' ' && matrix.at(i+3) == '[') {
                    i = i+3;
                    columns = 0;
                }
            }
        }
        mat1.identity = identity;
        mat1.rows = rows +1;
        mat1.columns = columns;
        return in;
    }
}