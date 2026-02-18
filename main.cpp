#include <iostream>

#include "image.cpp"

int main()
{
    int width = 16 * 60;
    int height = 9 * 60;
    Image img(width , height);
    for(int i = 0 ; i < width;i++){
        for(int j = 0; j < height;j++){

            //simple gradient
            img.B.mat[i][j] = (int)(((double)i/width) *255);
        }
    }
    img.makeP3PPM("output.ppm");

}