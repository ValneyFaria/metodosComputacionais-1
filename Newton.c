#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Metodo Newton
// V. 1.0.0
// 08/08/2016
// Autor: Guilherme Garutti Rossafa

double funcao(double x) {
	/********************************
			Entrada da funcao		
	********************************/
	return (x * x) + (x) - 1;
	/*******************************/
}

double derivada(double x) {
	/********************************
		    Derivada da funcao		
	********************************/	
	return 2 * x + 1;
	/*******************************/

}

void main() {
	/********************************
			Entrada dos dados		
	********************************/
	double x = 1;
	double erro = pow(10, -3);
	/*******************************/
	
	double fx, fd;
	int cont = 0;
		
	fx = funcao(x);
	fd = derivada(x);
	
	printf("cont = %d\n", cont);
	printf("x = %f\n", x);
	printf("f(x) = %f\n", fx);
	printf("f'(x) = %f\n\n", fd);
		
	while (fabs(fx) > erro) {	
		x = x - fx / fd;
		fx = funcao(x);
		fd = derivada(x);
		cont++;
		
		printf("cont = %d\n", cont);
		printf("x = %f\n", x);
		printf("f(x) = %f\n", fx);
		printf("f'(x) = %f\n\n", fd);
	}
}
