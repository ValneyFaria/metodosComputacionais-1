#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Metodo Forma de Newton
// V. 1.0.0
// 08/08/2016
// Autor: Guilherme Garutti Rossafa

void main() {
	float *x, *fx, *d;
	int i, j, n, c = 1, aux;

	//Entra com numero de pontos	
	printf("Este e' o metodo Forma de Newton.\n");
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
	
	//Faz o calculo para encontrar cada valor para 'd', vai sobrepondo os valores no mesmo vetor 'fx'
	for(i = 0; i < n; i++) {
		d[i] = fx[0];
		for(j = 0; j < n - 1; j++) {
			fx[j] = ((fx[j + 1] - fx[j]) / (x[j + c] - x[j]));
		}
		c++;
	}
	printf("\nOs valores de 'd'' sao:\n\n");
	for(i = 0; i < n; i++) {
		printf("d[%d] = %.3f\n", i + 1, d[i]);
	}
	
	//Concatena os valores de 'x' com x e com 'd' para formar o polinomio final
	printf("\nO polinomio final P(x) e':\n\n");
	printf("P(x) = ");
	for(i = 0; i < n; i++) {
		c = i;
		aux = 0;
		printf("%.3f", d[i]);
		if(i == 0) {
			printf(" + ");
		}
		while(c > 0) {
			printf("(x - %.3f)", x[aux]);
			aux++;
			c--;
		}
		if(i != 0) {
			if(i < n - 1) {
				printf(" + ");				
			}
		}
	}
	
	//Libera memoria
	free(x);
	free(fx);
	free(d);
}
