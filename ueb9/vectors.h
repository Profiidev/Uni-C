#ifndef C_VECTORS_H
#define C_VECTORS_H

struct Vector2_s {
    double x;
    double y;
};

void printVectorArray(struct Vector2_s data[], int n);


double normL2(struct Vector2_s * vec);
int argMin(struct Vector2_s * data, int start, int end);
void swap(struct Vector2_s * a, struct Vector2_s * b);
void selectionSort(struct Vector2_s data[], int n);

#endif //C_VECTORS_H
