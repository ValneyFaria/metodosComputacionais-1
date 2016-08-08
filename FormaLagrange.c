#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Metodo Forma de Lagrange
// V. 1.0.0
// 08/08/2016
// Autor: Guilherme Garutti Rossafa

void main() {
	float *x, *fx, *d, soma;
	int i, j, n;

	//Entra com numero de pontos	
	printf("Este e' o metodo Forma de Lagrange.\n");
	printf("Digite o numero de entradas pra 'x': ");
	scanf("%d", &n);
	
	//Aloca memoria
    x = (float*) malloc(n * sizeof(float));
    fx = (float*) malloc(n * sizeof(float));
    d = (float*) malloc(n * sizeof(float));
    
	//Armazena os valores para 'x' e em seguida para 'f(x)'
	printf("\nDigite o valor de cada 'x':\n\n");
	for(i = 0; i < n; i++) {
		printf("x[%d] = ", i + 1);
		scanf("%f", &x[i]);
	}
	printf("\nDigite o valor de cada 'f(x)':\n\n");	
	for(i = 0; i < n; i++) {
		printf("f[x%d] = ", i + 1);
		scanf("%f", &fx[i]);
	}
	
	//Faz o calculo para encontrar os valores dos denominadores
	for(i = 0; i < n; i++) {
		soma = 1;
		for(j = 0; j < n; j++) {
			if(i != j) {
				soma = soma * (x[i] - x[j]);
			}
		}
		d[i] = soma;
	}
	printf("\nOs valores dos denominadores sao:\n\n");
	for(i = 0; i < n; i++) {
		printf("d[%d] = %.6f\n", i + 1, d[i]);
	}
	
	//Concatena 'x' com os valores de entrada com os denominadores calculados para formar o polinomio final
	printf("\nO polinomio final P(x) e':\n\n");
	printf("P(x) = ");
	for(i = 0; i < n; i++) {
		printf("%.3f * (", fx[i]);
		for(j = 0; j < n; j++) {
			if(i != j) {
				printf("(x - %.3f)", x[j]);
			}
		}
		printf(" / %.3f)", d[i]);
		if (i != n - 1) {
			printf(" + ");
		}
	}
	
	//Libera memoria
	free(x);
	free(fx);
	free(d);
}
