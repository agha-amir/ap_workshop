#include "matrix.h"
#include <iostream>
using namespace std;


int main()
{
    cout<<"please input the variables of the result matrix"<<endl;
    Matrix resMat = newMat(2, 2);

    cout<<"please input the variables of the first operand matrix (mat1)"<<endl;
    const Matrix mat1 = newMat(2, 2);

    cout<<"please input the variables of the second operand matrix (mat2)"<<endl;
    const Matrix mat2 = newMat(2, 2);

    cout<<"result after addind two matrixes (addMatrix overload 1):"<<endl;
    addMatrix(mat1, mat2, resMat);
    printMat(resMat);

    cout<<"result after adding a scalar value to the fist matrix (mat1) (addMatrix overload 2):"<<endl;
    addMatrix(mat1, 2.0, resMat);
    printMat(resMat);

    cout<<"result after subtracting the second matrix (mat2) from the first one (mat1) (subtractMatrix overload 1):"<<endl;
    subtractMatrix(mat1, mat2, resMat);
    printMat(resMat);

    cout<<"result after subtracting a scalar value from the fist matrix (mat1) (subtractMatrix overload 2):"<<endl;
    subtractMatrix(mat1, 2.0, resMat);
    printMat(resMat);

    freeMat(resMat);
}
