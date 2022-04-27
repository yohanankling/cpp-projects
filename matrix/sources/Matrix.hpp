//
// Created by yohanan on 30.3.2022.
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace zich
{
    class Matrix
    {
    public:
        Matrix(vector<double> identity, int rows, int columns)
        {
            if (columns <= 0 || rows <= 0 )
                throw invalid_argument("Mats size have to be positive");
            if (columns * rows != identity.size())
                throw invalid_argument("Mats size have to be equal to column*row");
            this->identity = identity;
            this->rows = rows;
            this->columns = columns;
        }

        Matrix operator+(const Matrix &mat2);
        Matrix operator+=(Matrix &mat2);
        Matrix operator+();

        Matrix operator-(const Matrix &mat2);
        Matrix operator-=(Matrix &mat2);
        Matrix operator-();

        bool operator>(const Matrix &mat2);
        bool operator>=(const Matrix &mat2);
        bool operator<(const Matrix &mat2);
        bool operator<=(const Matrix &mat2);
        bool operator==(const Matrix &mat2) const;
        bool operator!=(const Matrix &mat2) const;


        Matrix operator++();
        Matrix operator++(int num);
        Matrix operator--();
        Matrix operator--(int num);


        friend Matrix operator* (int num,const Matrix &mat1);
        Matrix operator*(double num);
        friend Matrix operator* (double num,const Matrix &mat1);
        Matrix operator*=(double num);
        Matrix operator*(const Matrix &mat2);
        Matrix operator*=(const Matrix &mat2);

        friend ostream &operator<<(ostream &out, const Matrix &mat1);
        friend istream &operator>>(istream &in, Matrix &mat1);

        int columns;
        int rows;
        vector<double> identity;
    };
}