// TrabBisseccao.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>

double euler = 2.718281828459045235360287;

//Calcula o valor de f(x)
double equacao(double d, double t, double i, double c, double x) {
	return (d - (pow(euler, (-x*t / (2 * i)))
		* cos(sqrt((1 / (i*c)) - pow(x / (2 * i), 2))*t)));
}

double bisseccao(double d, double t, double i, double c, double min, double max, int interacao) {

	//Interacao
	interacao += 1;

	//Raiz
	double raiz = (min + max) / 2.0f;

	//Limite de interacoes
	if (interacao >= 2500)
		return raiz;

	//Calcular funcao
	double eqMin = equacao(d, t, i, c, min);
	double eqRaiz = equacao(d, t, i, c, raiz);

	//Passo 3
	double divisao = eqMin * eqRaiz;
	//Seção inferior
	if (divisao < 0) {
		double newBisseccao = bisseccao(d, t, i, c, min, raiz, interacao);
		return newBisseccao;
	}
	else if (divisao > 0) {
		double newBisseccao = bisseccao(d, t, i, c, raiz, max, interacao);
		return newBisseccao;
	}
	else
	{
		return raiz;
	}
}

double bisseccaoLoop(double d, double t, double i, double c, double min, double max) {

	//Interacao
	int interacao = 1;

	//Variaveis
	double raiz, eqMin, eqRaiz, divisao, novoMin = min, novoMax = max;

	do {
		//Interacao
		interacao += 1;

		//Raiz
		raiz = (novoMin + novoMax) / 2.0f;

		//Calcular funcao
		eqMin = equacao(d, t, i, c, novoMin);
		eqRaiz = equacao(d, t, i, c, raiz);

		//Passo 3
		divisao = eqMin * eqRaiz;
		//Seção inferior
		if (divisao < 0) {
			novoMax = raiz;
		}
		//Seção superior
		else if (divisao > 0) {
			novoMin = raiz;
		}
		//Achou raiz (EITA PORRA)
		else
		{
			printf("Achou");
			return raiz;
		}


	} while (interacao < 2000);

	//Retorno
	return raiz;
}

int main()
{

	//  Qt    =  e^(-rt/2L) * cos[(sqrt((1/lc)-(r/2L)^2)*t]
	//----------
	//  Q0

	double dissipacao = 0.01;
	double resistencia;
	double tempo = 0.05;
	double indutancia = 5;
	double capacitancia = 0.0001;

	/*

	printf("Digite os valores:\n");
	printf("Dissipacao: ");
	scanf_s("%lf", &dissipacao);
	printf("\ntempo: ");
	scanf_s("%lf", &tempo);
	printf("\nindutancia: ");
	scanf_s("%lf", &indutancia);
	printf("\ncapacitancia: ");
	scanf_s("%lf", &capacitancia);
	*/

	double min, max;
	printf("Digite o intervalo da resistencia:");
	scanf_s("%lf", &min);
	scanf_s("%lf", &max);

	double raiz = bisseccaoLoop(dissipacao, tempo, indutancia, capacitancia, min, max);
	printf("%.100lf", raiz);

	getchar();
	getchar();

    return 0;
}

