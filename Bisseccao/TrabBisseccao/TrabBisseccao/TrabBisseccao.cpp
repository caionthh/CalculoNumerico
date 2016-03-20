// TrabBisseccao.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>

double euler = 2.718281828459045235360287;

double bisseccao(double d, double t, double i, double c, double min, double max, int interacao) {

	//Interacao
	interacao += 1;

	//
	return 0;
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
	printf("Digite o intervalo da resistencia na porra da bisseccao do jean:");
	scanf_s("%lf", &min);
	scanf_s("%lf", &max);

	//Primeiro passo da bisseccao

	double potMin = pow(euler, (-min*tempo / (2 * indutancia)));
	printf("%lf", potMin);
	double potRaiz = pow(min / (2 * indutancia), 2);
	printf("%lf", potRaiz);
	double raizCos = sqrt((1 / (indutancia*capacitancia)) - potRaiz);
	printf("%lf", raizCos);
	double cosMin = cos(raizCos*tempo);
	printf("%lf", cosMin);

	double calcMin = 
		 potMin * cosMin;
	double calcMax = 
		pow(euler, (-max*tempo / (2 * indutancia)))
		* cos(sqrt((1 / (indutancia*capacitancia)) - pow(max / (2 * indutancia), 2))*tempo);

	double multMinMax = calcMin * calcMax;
	printf("%lf", multMinMax);

	if (multMinMax < 0) {
		bisseccao(dissipacao, tempo, indutancia, capacitancia, min, max, 0);
	}

	//printf("%lf %lf %lf %lf", dissipacao, tempo, indutancia, capacitancia);


	//	dissipacao = pow(euler, (-resistencia*tempo / 2 * indutancia))
	//	* cos(sqrt((1 / indutancia*capacitancia) - pow(resistencia / 2 * indutancia, 2))*tempo);



	getchar();
	getchar();

    return 0;
}

