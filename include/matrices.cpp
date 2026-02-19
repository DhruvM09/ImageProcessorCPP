#include "matrix.h"

   // class helper functions
    void Matrix::clear()
    {
        for (ll i = 0; i < rows; i++)
        {
            for (ll j = 0; j < cols; j++)
            {
                mat[i][j] = 0;
            }
        }
    }

    // if inPlace is 1 originale matrix gets modified
    Matrix Matrix::transpose(bool inPlace)
    {
        vector<vector<float>> newMat(cols, vector<float>(rows));
        for (ll i = 0; i < cols; i++)
        {
            for (ll j = 0; j < rows; j++)
            {
                newMat[i][j] = mat[j][i];
            }
        }
        if (inPlace)
        {
            mat = newMat;
            return NULL_MAT
        }
        Matrix returnMat = Matrix(cols, rows);
        returnMat.mat = newMat;
        return returnMat;
    }

    void Matrix::print()
    {
        for (ll i = 0; i < rows; i++)
        {
            for (ll j = 0; j < cols; j++)
            {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    Matrix Matrix::operator+(const Matrix &op)
    {
        if (rows != op.rows || cols != op.cols)
        {
            cerr << "dimensions do not match\n"
                 << '\n';
            return NULL_MAT;
        }
        Matrix result(rows, cols);
        for (ll i = 0; i < rows; i++)
        {
            for (ll j = 0; j < cols; j++)
            {
                result.mat[i][j] = mat[i][j] + op.mat[i][j];
            }
        }
        return result;
    }
    Matrix Matrix::operator-(const Matrix &op)
    {
        if (rows != op.rows || cols != op.cols)
        {
            cerr << "dimensions do not match\n"
                 << '\n';
            return NULL_MAT;
        }
        Matrix result(rows, cols);
        for (ll i = 0; i < rows; i++)
        {
            for (ll j = 0; j < cols; j++)
            {
                result.mat[i][j] = mat[i][j] - op.mat[i][j];
            }
        }
        return result;
    }
    Matrix Matrix::operator*(const float scaler)
    {

        Matrix result(rows, cols);
        for (ll i = 0; i < rows; i++)
        {
            for (ll j = 0; j < cols; j++)
            {
                result.mat[i][j] = mat[i][j] * scaler;
            }
        }
        return result;
    }
    Matrix Matrix::operator*(const Matrix &op)
    {
        return dot(*this, op);
    }

// other helper functions for Matrix

Matrix dot(const Matrix &a, const Matrix &b)
{

    if (a.cols != b.rows)
    {
        std::cerr << "invalid dot product dimensions";
        return NULL_MAT;
    }
    Matrix ans(a.rows, b.cols);
    for (ll i = 0; i < ans.rows; i++)
    {
        for (ll j = 0; j < ans.cols; j++)
        {

            float ansij = 0;
            for (ll loop = 0; loop < a.cols; loop++)
            {
                ansij = ansij + (a.mat[i][loop] * b.mat[loop][j]);
            }
            ans.mat[i][j] = ansij;
        }
    }
    return ans;
}

// cofactor of pth row qth col
Matrix getCofacter(const Matrix &a, ll p, ll q)
{
    if(a.rows != a.cols){
        cerr << "not a square matrix\n";
        return NULL_MAT;
    }
    Matrix result(a.rows - 1, a.cols - 1);
    ll i = 0;
    ll j = 0;
    for (ll row = 0; row < a.rows; row++)
    {
        for (ll col = 0; col < a.cols; col++)
        {

            if (row != p && col != q)
            {
                result.mat[i][j++] = a.mat[row][col];
                if (j == a.cols - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    return result;
}
double det(Matrix Mat)
{

    if (Mat.rows != Mat.cols)
    {
        std::cerr << "not a square matrix\n";
        return 0;
    }
    double ans = 0;
    if (Mat.rows == 1)
    {
        return Mat.mat[0][0];
    }
    if (Mat.rows == 2)
    {
        return (Mat.mat[0][0] * Mat.mat[1][1] - Mat.mat[0][1] * Mat.mat[1][0]);
    }
    ll sign = 1;

    for (ll c = 0; c < Mat.rows; c++)
    {
        // stack overflow?
        Matrix cofacterMat = getCofacter(Mat, 0, c);
        ans = ans + (sign * Mat.mat[0][c] * det(cofacterMat));
        sign *= -1;
    }

    return ans;
}

void loadCSV(string filename , Matrix  & A){
    ifstream csvfile(filename);
    vector<vector<float>> data;
    if(!csvfile.is_open()){
        cerr<<"error in opening file\n";
        return;
    }
    string line;
    while(getline(csvfile , line)){
        stringstream ss(line);
        string cell;
        vector<float> row;
        while(getline(ss ,cell , ',')){
            float value = stof(cell);
            row.push_back(value);
        }
        data.push_back(row);
    }
    
    csvfile.close();
    ll n = data.size();
    ll m = data[0].size();
    A.rows = n;
    A.cols = m;
    for(ll i = 0; i < n ; i ++ ){
        for(ll j = 0 ; j < m;j++){
            A.mat[i][j] = data[i][j];
        }
    }
}

