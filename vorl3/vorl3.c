#include "vorl3.h"
#include "matrix.h"

void vorl3() {
    Matrixf matrixA = MatrixZeros(2, 3);
    Matrixf matrixB = MatrixZeros(3, 2);

    MatrixSetElement(&matrixA, 0, 0, 3);
    MatrixSetElement(&matrixA, 0, 1, 2);
    MatrixSetElement(&matrixA, 0, 2, 1);
    MatrixSetElement(&matrixA, 1, 0, 1);
    MatrixSetElement(&matrixA, 1, 1, 0);
    MatrixSetElement(&matrixA, 1, 2, 2);

    MatrixSetElement(&matrixB, 0, 0, 1);
    MatrixSetElement(&matrixB, 0, 1, 2);
    MatrixSetElement(&matrixB, 1, 0, 0);
    MatrixSetElement(&matrixB, 1, 1, 1);
    MatrixSetElement(&matrixB, 2, 0, 4);
    MatrixSetElement(&matrixB, 2, 1, 0);

    MatrixPrint(matrixA);
    printf("\n");
    MatrixPrint(matrixB);
    printf("\n");

    Matrixf matrixC = MatrixMatMul(matrixA, matrixB);
    MatrixPrint(matrixC);
    printf("\n");

    MatrixFree(&matrixA);
    MatrixFree(&matrixB);
    MatrixFree(&matrixC);
}