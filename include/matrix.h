#pragma once
#include <iostream>
#include <vector>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;
typedef long long ll;
#define NULL_MAT Matrix(0 , 0);

class Matrix
{
public:
    ll rows;
    ll cols;
    vector<vector<float>> mat;

    Matrix(ll rows, ll cols) : rows(rows), cols(cols)
    {
        // initialize with zero;
        mat = vector<vector<float>>(rows, vector<float>(cols, 0));
    }
    Matrix() : rows(0), cols(0)
    {
        // initialize with zero;
        mat = vector<vector<float>>(rows, vector<float>(cols, 0));
    }
    void clear();
    Matrix transpose(bool inPlace);
    void print();
    Matrix operator+(const Matrix &op);
    Matrix operator-(const Matrix &op);
    Matrix operator*(const Matrix &op);
    Matrix operator*(const float scale);

}; 

Matrix dot(const Matrix &a, const Matrix &b);
Matrix getCofacter(const Matrix &a, ll p, ll q);
double det(Matrix Mat);
void loadCSV(string filename , Matrix &A);