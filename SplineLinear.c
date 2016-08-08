#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Metodo Spline Linear
// V. 1.0.0
// 08/08/2016
// Autor: Guilherme Garutti Rossafa

void main() {
	float *x, *fx, d, aux1, aux2;
	int i, j, n;

	//Entra com numero de pontos	
	printf("Este e' a funcao Spline Linear.\n");
	printf("Digite o numero de entradas pra 'x': ");
	scanf("%d", &n);
	
	//Aloca memoria
    x = (float*) malloc(n * sizeof(float));
    fx = (float*) malloc(n * sizeof(float));
    
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
	
	//Faz o calculo para encontrar os valores e concatena com 'x'(aux2) e com os denominadores 'd'
	printf("\nAs funcoes 's' sao:\n\n");
	for(i = 0; i < n - 1; i++) {
		aux1 = (fx[i] * x[i + 1]) + (fx[i + 1] * (-x[i]));
		aux2 = (-1 * fx[i]) + fx[i + 1];
		d = x[i + 1] - x[i];
		printf("s[%d] = (%.3fx + (%.3f)) / %.3f\n", i + 1, aux2, aux1, d);
		printf("s[%d] = %.3fx + (%.3f)\n\n", i + 1, aux2 / d, aux1 / d);

	}
	
	//Libera memoria
	free(x);
	free(fx);
}
