#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Metodo Falsa-Posicao
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

double falsap(double a, double b, double fa, double fb) {
	return ((a * fb) - (b * fa)) / (fb - fa);
}

void main() {
	/********************************
			Entrada dos dados		
	********************************/
	double a = 0;
	double b = 2;
	double erro = pow(10, -2);
	/*******************************/
	
	double x, fx, fa, fb;
	int cont = 1;
		
	fa = funcao(a);
	fb = funcao(b);
	x = falsap(a, b, fa, fb);
	fx = funcao(x);
	
	printf("cont = %d\n", cont);
	printf("x = %f\n", x);
	printf("a = %f\n", a);
	printf("b = %f\n", b);
	printf("f(x) = %f\n", fx);
	printf("f(a) = %f\n", fa);
	printf("f(b) = %f\n\n", fb);
		
	while (fabs(fx) > erro) {	
		if ((fx * fa) > 0) {
			a = x;
			fa = fx;
		} else {
			b = x;
			fb = fx;
		}
		x = falsap(a, b, fa, fb);
		fx = funcao(x);
		cont++;
		
		printf("Iteracao: %d\n", cont);
		printf("x = %f\n", x);
		printf("a = %f\n", a);
		printf("b = %f\n", b);
		printf("f(x) = %f\n", fx);
		printf("f(a) = %f\n", fa);
		printf("f(b) = %f\n\n", fb);
	}
}
