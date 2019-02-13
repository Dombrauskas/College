/* Implemente um programa em C que
 * dados dois pontos no R², calcule e
 * imprima a distância entre eles. Utilize o
 * módulo ponto.c implementado
 * anteriormente. Forneça também o
 * makefile da aplicação.
*/

#include <math.h>
#include "ponto.h"

void pto_init(ponto * p, int x, int y)
{
	p->x = x;
	p->y = y;
}

double pto_distancia(ponto p1, ponto p2)
{
	int dx = p2.x - p1.x;
	int dy = p2.y - p1.y;
	return sqrt(dx * dx + dy * dy);
}
