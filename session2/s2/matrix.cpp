#include "matrix.h"
#include <iostream>
using namespace std;

Matrix newMat(int row, int col){
    Matrix mat;
    mat.data = new int*[row];
    mat.row = row;
    mat.col = col;
    for (int i = 0; i < row; i++)
    {
        mat.data[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            cout << "Enter element for position (" << i << ", " << j << "): ";
            cin>>mat.data[i][j];
            //cout<< mat->data[i][j]<<endl;
        }
    }
    cout<<endl;
    return mat;
}

void freeMat(Matrix& mat){
    for (int i = 0; i < mat.row; i++)
    {
        delete[] mat.data[i];
        mat.data[i] = NULL;
    }
    delete[] mat.data;
   mat.data = nullptr;
}

void printMat(Matrix& mat){
    for (int i = 0; i < mat.row; i++)
    {
       for (int j = 0; j < mat.col; j++)
        {
            cout<<mat.data[i][j]<<"\t";
        }
        cout<<endl;
    }
}


bool addMatrix(const Matrix& mat1, const Matrix& mat2, Matrix& result){
    if (mat1.row != mat2.row || mat1.col != mat2.col)
    {
        return false;
    }

    for (int i = 0; i < mat1.row; i++)
    {
        if (mat1.data[i] == nullptr || mat2.data[i] == nullptr)
        {
            return false;
        }

        for (int j = 0; j < mat1.col; j++)
        {
            if (mat1.data[i][j] == NULL || mat2.data[i][j] == NULL)
            {
                return false;
            }
        result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
    }      
}
    return true;    
}

bool addMatrix(const Matrix& mat, double scalar, Matrix& result){
    for (int i = 0; i < mat.row; i++)
    {
        if (mat.data[i] == nullptr)
        {
            return false;
        }

        for (int j = 0; j < mat.col; j++)
        {
            if (mat.data[i][j] == NULL)
            {
                return false;
            }
        result.data[i][j] = mat.data[i][j] + scalar;
    }      
}
return true;
}

bool subtractMatrix(const Matrix& mat1, const Matrix& mat2, Matrix& result){
    if (mat1.row != mat2.row || mat1.col != mat2.col)
    {
        return false;
    }

    for (int i = 0; i < mat1.row; i++)
    {
        if (mat1.data[i] == nullptr || mat2.data[i] == nullptr)
        {
            return false;
        }

        for (int j = 0; j < mat1.col; j++)
        {
            if (mat1.data[i][j] == NULL || mat2.data[i][j] == NULL)
            {
                return false;
            }
        result.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
    }      
}
    return true;    
}

bool subtractMatrix(const Matrix& mat, double scalar, Matrix& result){
    for (int i = 0; i < mat.row; i++)
    {
        if (mat.data[i] == nullptr)
        {
            return false;
        }

        for (int j = 0; j < mat.col; j++)
        {
            if (mat.data[i][j] == NULL)
            {
                return false;
            }
        result.data[i][j] = mat.data[i][j] - scalar;
    }      
}
return true;
}
