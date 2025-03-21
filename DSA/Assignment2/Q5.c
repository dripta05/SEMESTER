#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;


Term* multiplySparsePolynomials(Term* poly1, int size1, Term* poly2, int size2, int* resultSize) {
    Term* result = (Term*) malloc((size1 * size2) * sizeof(Term));
    int resultIndex = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            int coefficient = poly1[i].coefficient * poly2[j].coefficient;
            int exponent = poly1[i].exponent + poly2[j].exponent;

            
            result[resultIndex].coefficient = coefficient;
            result[resultIndex].exponent = exponent;
            resultIndex++;
        }
    }

    *resultSize = resultIndex;
    

    return result;
}

int main() {
    
    Term poly1[] = {{3, 5}, {2, 1}};
    Term poly2[] = {{1, 3}, {4, 0}};
    int size1 = sizeof(poly1) / sizeof(poly1[0]);
    int size2 = sizeof(poly2) / sizeof(poly2[0]);

    int resultSize;
    Term* result = multiplySparsePolynomials(poly1, size1, poly2, size2, &resultSize);

    
    for (int i = 0; i < resultSize; i++) {
        printf("%dx^%d ", result[i].coefficient, result[i].exponent);
    }
    printf("\n");

    free(result);
    return 0;
}