#include <stdio.h>
#include <stdlib.h>

void readPolynomials(int numPolynomials, int maxDegree, int polynomials[][maxDegree + 1]) {
    for (int i = 0; i < numPolynomials; i++) {
        printf("Introduce los coeficientes del polinomio %d (del grado 0 al %d):\n", i + 1, maxDegree);
        for (int j = 0; j <= maxDegree; j++) {
            printf("Coeficiente de x^%d: ", j);
            scanf("%d", &polynomials[i][j]);
        }
    }
}

void addPolynomials(int numPolynomials, int maxDegree, int polynomials[][maxDegree + 1], int result[]) {
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = 0; // Inicializar el resultado en 0
        for (int j = 0; j < numPolynomials; j++) {
            result[i] += polynomials[j][i];
        }
    }
}

void printPolynomial(int maxDegree, int polynomial[]) {
    for (int i = maxDegree; i >= 0; i--) {
        if (polynomial[i] != 0) {
            if (i != maxDegree && polynomial[i] > 0) {
                printf("+");
            }
            printf("%dx^%d ", polynomial[i], i);
        }
    }
    printf("\n");
}

int main() {
    int numPolynomials, maxDegree;

    // Leer el número de polinomios y el grado máximo aceptado
    printf("Introduce el número de polinomios: ");
    scanf("%d", &numPolynomials);
    printf("Introduce el mayor grado aceptado para los polinomios: ");
    scanf("%d", &maxDegree);

    // Crear una matriz para almacenar los coeficientes de los polinomios
    int polynomials[numPolynomials][maxDegree + 1];

    // Inicializar la matriz de coeficientes con ceros
    for (int i = 0; i < numPolynomials; i++) {
        for (int j = 0; j <= maxDegree; j++) {
            polynomials[i][j] = 0;
        }
    }

    // Leer los coeficientes de los polinomios
    readPolynomials(numPolynomials, maxDegree, polynomials);

    // Crear un array para almacenar el resultado de la suma de los polinomios
    int result[maxDegree + 1];

    // Sumar los polinomios
    addPolynomials(numPolynomials, maxDegree, polynomials, result);

    // Print the resulting polynomial
    printf("El polinomio resultante de la suma es: ");
    printPolynomial(maxDegree, result);

    return 0;
}
