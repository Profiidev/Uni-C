#include "matrix.h"


Matrixf MatrixArange(int rows, int cols) {
    Matrixf matrix = MatrixZeros(rows, cols);

    for (int i = 0; i < rows * cols; ++i) {
        MatrixSetElement(&matrix, i / cols, i % cols, i);
    }

    return matrix;
}

Matrixf MatrixZeros(int rows, int cols) {
    Matrixf matrix = {rows, cols, NULL};
    matrix.data = calloc(rows * cols, rows * cols * sizeof(double));

    if(matrix.data == NULL) {
        printf("Error: malloc failed in MatrixZeros()\n");
        exit(1);
    }

    return matrix;
}

double MatrixGetElement(Matrixf *matrix, int row, int col) {
    return matrix->data[row * matrix->cols + col];
}

void MatrixSetElement(Matrixf *matrix, int row, int col, double value) {
    matrix->data[row * matrix->cols + col] = value;
}

Matrixf MatrixMatMul(Matrixf matrixA, Matrixf matrixB) {
    Matrixf matrixC = MatrixZeros(matrixA.rows, matrixB.cols);

    for (int i = 0; i < matrixA.rows; ++i) {
        for (int j = 0; j < matrixB.cols; ++j) {
            for (int k = 0; k < matrixA.cols; ++k) {
                matrixC.data[i * matrixC.cols + j] += MatrixGetElement(&matrixA, i, k) * MatrixGetElement(&matrixB, k, j);
            }
        }
    }

    return matrixC;
}

void MatrixFree(Matrixf *matrix) {
    free(matrix->data);
}

void MatrixPrint(Matrixf matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            printf("%f ", MatrixGetElement(&matrix, i, j));
        }
        printf("\n");
    }
}