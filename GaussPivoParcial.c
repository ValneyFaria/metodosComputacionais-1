#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Metodo Gauss Pivo Parcial
// V. 1.0.0
// 08/08/2016
// Autor: Guilherme Garutti Rossafa

void main() {
	float **a, *x, aux, soma, m;
	int i, j, k, n, pos;

	//Entra com numero de equacoes
	printf("Este e' o metodo de Gauss com pivo parcial.\n");
	printf("Digite o numero de equacoes do sistema: ");
	scanf("%d", &n);

	//Aloca memoria
	a = (float**) malloc(n * sizeof(float*));
	for(i = 0; i < n; i++) {
		a[i] = (float*) malloc(n * sizeof(float));
	}

	x = (float*) malloc(n * sizeof(float));

	//Armazena os valores do usuario (uma unica matriz 'a'n,n+1 e gerada, onde 'b' e a ultima coluna)
	printf("\nDigite o valor de cada coeficiente:\n\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i + 1, j + 1);
			scanf("%f", &a[i][j]);
		}
		printf("b[%d] = ", i + 1);
		scanf("%f", &a[i][n]);
	}

	//Acha o maior valor da primeira coluna e a partir dele troca a linha e faz o calculo
	for(i = 0; i < n; i++) {
		aux = a[i][i];
		//Posicao de referencia
		pos = i;
		//Comparacao para troca de linha
		for(k = i + 1; k < n; k++) {
			if(fabs(aux) < fabs(a[k][i])) {
				aux = a[k][i];
				pos = k;
			}
		}
		//Troca a linha (j vai ate <= pois a matriz nao e de fato quadrada, devido aos valores de b)
		for(j = 0; j <= n; j++) {
			x[j] = a[pos][j];
			a[pos][j] = a[i][j];
			a[i][j] = x[j];
		}
		//Faz o calculo da matriz triangular
		for(j = i + 1; j < n; j++) {
			m = a[j][i] / a[i][i];
			for(k = 0; k <= n; k++) {
				a[j][k] -= m * a[i][k];
			}
		}
	}

	//Calcula x1, x2 e x3 ('i' parte de n - 2 pelo fato de 'b' ocupar a ultima coluna)
	x[n-1] = a[n-1][n] / a[n-1][n-1];
	for(i = n - 2; i >= 0; i--) {
		soma = 0;
		for(j = i + 1; j < n; j++) {
			soma += (a[i][j] * x[j]);
			x[i] = (a[i][n] - soma) / a[i][i];
		}
	}

	//Imprime a matriz triangular superior calculada
	printf("\nA matriz triangular preparada e':\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j <= n; j++) {
			printf("%.6f\t", a[i][j]);
		}
		printf("\n");
	}

	//Retorna a solucao
	printf("\nO resultado e':\n");
	for(i = 0; i < n; i++) {
		printf("x[%d] = %.6f\n", i + 1, x[i]);
	}

	//Libera a memoria
	for(i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	free(x);
}
