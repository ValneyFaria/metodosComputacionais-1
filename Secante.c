#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Metodo Secante
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

void main() {
	/********************************
			Entrada dos dados		
	********************************/
	double xa = 0;
	double xb = 2;
	double erro = pow(10, -3);
	/*******************************/
	
	double fxa, fxb, xk;
	int cont = 0;
		
	fxa = funcao(xa);
	fxb = funcao(xb);
	
	printf("cont = %d\n", cont);
	printf("x = %f\n", xa);	
	printf("f(x) = %f\n\n", fxa);
	
	printf("cont = %d\n", cont = cont + 1);
	printf("x = %f\n", xb);
	printf("f(x) = %f\n\n", fxb);
		
	while (fabs(fxb) > erro) {	
		xk = (xa * fxb - xb * fxa) / (fxb - fxa);
		xa = xb;
		xb = xk;
		fxa = fxb;
		fxb = funcao(xb);
		cont++;
		
		printf("cont = %d\n", cont);
		printf("x = %f\n", xb);
		printf("f(x) = %f\n\n", fxb);
	}
}
