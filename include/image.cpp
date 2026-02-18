#include "image.hpp"


void Image::makeP3PPM(string filename){
    ofstream outfile(filename , ios::out);
    if(!outfile){
        cerr<< "could not open outfile for writing\n";
        return;
    }
   // Write the PPM header
    outfile << "P3\n";
    outfile << rows << " " << cols << "\n";
    outfile << 255 << "\n"; // Max color value is 255

    //writing rgb channels
    for(int y = 0 ; y < cols;y++){
        for(int x = 0;x <rows;x++){
            int r = (int)R.mat[x][y];
            int g = (int)G.mat[x][y];
            int b = (int)B.mat[x][y];
            outfile << r << " " << g  << " " << b << " ";
        }
        outfile << endl;
    }
      // Close the file
    outfile.close();
    std::cout << "Successfully created " << filename << std::endl;
}