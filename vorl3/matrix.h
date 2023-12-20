#ifndef C_MATRIX_H
#define C_MATRIX_H

#include <stdlib.h>
#include <stdio.h>

struct Matrixf_s {
    int rows;
    int cols;
    double *data;
};

typedef struct Matrixf_s Matrixf;

Matrixf MatrixArange(int rows, int cols);
Matrixf MatrixZeros(int rows, int cols);

double MatrixGetElement(Matrixf *matrix, int row, int col);
void MatrixSetElement(Matrixf *matrix, int row, int col, double value);

Matrixf MatrixMatMul(Matrixf *matrixA, Matrixf *matrixB);

void MatrixFree(Matrixf *matrix);
void MatrixPrint(Matrixf matrix);

#endif //C_MATRIX_H
