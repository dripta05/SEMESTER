#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row;
    int col;
    int val;
} Element;


Element* addSparseMatrices(Element* mat1, int size1, Element* mat2, int size2, int* resultSize) {
    Element* result = (Element*) malloc((size1 + size2) * sizeof(Element));
    int resultIndex = 0;

    
    int i = 0, j = 0;
    while (i < size1 && j < size2) {
        if (mat1[i].row == mat2[j].row && mat1[i].col == mat2[j].col) {
            result[resultIndex].row = mat1[i].row;
            result[resultIndex].col = mat1[i].col;
            result[resultIndex].val = mat1[i].val + mat2[j].val;
            resultIndex++;
            i++;
            j++;
        } else if (mat1[i].row < mat2[j].row || (mat1[i].row == mat2[j].row && mat1[i].col < mat2[j].col)) {
            result[resultIndex] = mat1[i];
            resultIndex++;
            i++;
        } else {
            result[resultIndex] = mat2[j];
            resultIndex++;
            j++;
        }
    }

    while (i < size1) {
        result[resultIndex] = mat1[i];
        resultIndex++;
        i++;
    }
    while (j < size2) {
        result[resultIndex] = mat2[j];
        resultIndex++;
        j++;
    }

    *resultSize = resultIndex;
    return result;
}

int main() {
    
    Element mat1[] = {{0, 0, 1}, {1, 1, 2}, {2, 2, 3}};
    Element mat2[] = {{0, 1, 4}, {1, 0, 5}, {2, 2, 6}};
    int size1 = sizeof(mat1) / sizeof(mat1[0]);
    int size2 = sizeof(mat2) / sizeof(mat2[0]);

    int resultSize;
    Element* result = addSparseMatrices(mat1, size1, mat2, size2, &resultSize);

    
    for (int i = 0; i < resultSize; i++) {
        printf("(%d, %d, %d) ", result[i].row, result[i].col, result[i].val);
    }
    printf("\n");

    free(result);
    return 0;
}