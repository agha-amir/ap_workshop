typedef struct matrix
{
    int row;
    int col;
    int** data;
} Matrix;


Matrix newMat(int row, int col);
void freeMat(Matrix& mat);
void printMat(Matrix& mat);

bool addMatrix(const Matrix& mat1, const Matrix& mat2, Matrix& result);


bool addMatrix(const Matrix& mat, double scalar, Matrix& result);


bool subtractMatrix(const Matrix& mat1, const Matrix& mat2, Matrix& result);


bool subtractMatrix(const Matrix& mat, double scalar, Matrix& result);
