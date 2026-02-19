#include "image.hpp"


void Image::makeP3PPM(string filename){
    ofstream outfile(filename , ios::out);
    if(!outfile){
        cerr<< "could not open outfile for writing\n";
        return;
    }
   // Write the PPM header
    outfile << "P3\n";
    outfile << cols << " " << rows << "\n";
    outfile << 255 << "\n"; // Max color value is 255

    //writing rgb channels
    for(int y = 0 ; y < rows;y++){
        for(int x = 0;x <cols;x++){
            int r = (int)R.mat[y][x];
            int g = (int)G.mat[y][x];
            int b = (int)B.mat[y][x];
            outfile << r << " " << g  << " " << b << " ";
        }
        outfile << endl;
    }
      // Close the file
    outfile.close();
    std::cout << "Successfully created " << filename << std::endl;
}

void Image::dotFilter(Matrix & filter){
    Matrix newR(rows , cols);
    Matrix newG(rows , cols);
    Matrix newB(rows , cols);
    for(int i =0 ; i < rows ;i++){
        for(int j = 0 ; j < cols ;j++){

            float newPixelValueR = 0;
            float newPixelValueG = 0;
            float newPixelValueB = 0;
            for(int x = 0 ;x < filter.rows;x++){
                for(int y =0;y <filter.cols;y++){

                    if((i-filter.cols/2 + x) < 0 || (i-filter.cols/2 + x) >= rows  )continue;
                    if((j-filter.rows/2 + y) < 0 || (j-filter.rows/2 + y) >= cols  )continue;
                    newPixelValueR = newPixelValueR + (filter.mat[x][y] *R.mat[i-(int)filter.cols/2+x][j -(int)filter.rows/2 + y]);
                    newPixelValueG = newPixelValueG + (filter.mat[x][y] *G.mat[i-(int)filter.cols/2+x][j -(int)filter.rows/2 + y]);
                    newPixelValueB = newPixelValueB + (filter.mat[x][y] *B.mat[i-(int)filter.cols/2+x][j -(int)filter.rows/2 + y]);
                    
                }
            }
            newR.mat[i][j]= (int)newPixelValueR;
            newG.mat[i][j]= (int)newPixelValueG;
            newB.mat[i][j]= (int)newPixelValueB;
        }
    }
    R = newR;
    G = newG;
    B = newB;
}