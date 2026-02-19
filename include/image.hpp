#pragma once
#include "matrices.cpp"

class Image{
    public:
        ll rows;
        ll cols;
        Matrix R;
        Matrix G;
        Matrix B;
        Image(ll row , ll col): rows(row) , cols(col){
            R = Matrix(row , col);
            G = Matrix(row , col);
            B = Matrix(row , col);
        }

        void makeP3PPM(string filename);

        void dotFilter(Matrix & filter);
        


};

