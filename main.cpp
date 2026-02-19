#include <iostream>

#include "image.cpp"

int main()
{
    int row = 16*5;
    int col = 9*6;
    Image img(row , col);
    for(int i = 0 ; i < row;i++){
        for(int j = 0; j < col;j++){

            if(j < col/2){
                img.R.mat[i][j] = 0;
                img.G.mat[i][j] = 0;
                img.B.mat[i][j] = 0;
            }else{
                img.R.mat[i][j] = 255;
                img.G.mat[i][j] = 255;
                img.B.mat[i][j] = 255;
            }
        }
    }
    img.makeP3PPM("output1.ppm");

    Matrix filter(3, 3);
    filter.mat = {
        {-1 , 0, 1},
        {-1 , 0, 1},
        {-1, 0, 1},
    };
    img.dotFilter(filter);
    // img.R.print();
    img.makeP3PPM("output.ppm");

}