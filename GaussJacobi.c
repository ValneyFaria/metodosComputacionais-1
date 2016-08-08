#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Metodo Gauss-Jacobi
// V. 1.0.0
// 08/08/2016
// Autor: Guilherme Garutti Rossafa

void main() {
	float **a, **c, *b, *x, *g, soma, maiorb, maiorx, erro, eps;
	int i, j, k, n, it = 1;

	//Valor de epsilon
	eps = 0.05;

	//Entra com numero de equacoes
	printf("Este e' o metodo iterativo de Gauss-Jacobi.\n");
	printf("Digite o numero de equacoes do sistema: ");
	scanf("%d", &n);

	//Alocacao de memoria
	a = (float**) malloc(n * sizeof(float*));
	for(i = 0; i < n; i++) {
		a[i] = (float*) malloc(n * sizeof(float));
	}

	c = (float**) malloc(n * sizeof(float*));
	for(i = 0; i < n; i++) {
		c[i] = (float*) malloc(n * sizeof(float));
	}

	b = (float*) malloc(n * sizeof(float));
	x = (float*) malloc(n * sizeof(float));
	g = (float*) malloc(n * sizeof(float));

	//Armazena os valores do usuario para a matriz 'a'
	printf("\nDigite o valor de cada coeficiente de a:\n\n");
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			printf("a[%d][%d] = ", i + 1, j + 1);
			scanf("%f", &a[i][j]);
		}
	}

	//Armazena os valores do usuario para a matriz 'b'
	printf("\nDigite o valor de cada coeficiente de b:\n\n");
	for(i = 0; i < n; i++) {
		printf("b[%d] = ", i + 1);
		scanf("%f", &b[i]);
		x[i] = b[i] / a[i][i];
		g[i] = b[i] / a[i][i];
	}
	printf("\n");

	//Faz o calculo para gerar a matriz 'c'
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i == j) {
				c[i][j] = 0;
			} else {
				c[i][j] = (-a[i][j]) / a[i][i];
			}
		}
	}

	//Bloco realiza o calculo de Gauss-Seidel
	do {
		soma = 0;
		maiorx = 0;
		maiorb = 0;
		//Calcula os proximos 'x' e armazena em 'b'
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				soma = soma + c[i][j] * x[j];
			}
			b[i] = soma + g[i];
			soma = 0;
			//Armazena o modulo do maior em 'x' e tambem o maior da diferenca deste pelo anterior
			if((fabs(b[i]) > maiorb)) {
				maiorb = fabs(b[i]);
			}
			if((fabs(b[i]) - fabs(x[i])) > maiorx) {
				maiorx = (fabs(b[i]) - fabs(x[i]));
			}
		}
		//Clona a matriz calulada 'b' para 'x' novamente
		for(i = 0; i < n; i++) {
			x[i] = b[i];
		}
		//Imprime os valores de 'x' atuais, a iteracao e calcula o erro
		printf("iteracao %d \n", it);
		for(k = 0; k < n; k++) {
			printf("x[%d] = %f\n", k + 1, x[k]);
		}
		printf("maiorx = %f\n", maiorx);
		printf("maiorb = %f\n", maiorb);
		erro = (maiorx / maiorb);
		printf("erro = %f\n", erro);
		printf("\n");
		it++;
	} while(erro > eps);

	//Libera memoria
	for(i = 0; i < n; i++) {
		free(a[i]);
		free(c[i]);
	}
	free(a);
	free(c);
	free(b);
	free(x);
	free(g);
}
