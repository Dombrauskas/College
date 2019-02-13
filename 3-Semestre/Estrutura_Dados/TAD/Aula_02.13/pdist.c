#include <stdio.h>
#include "ponto.h"

int main()
{
	ponto p1, p2;
	int a, b;
	printf("Informe dois pontos: ");
	scanf("%d %d", &a, &b);
	pto_inti(&p1, a, b);
		
	printf("Informe dois pontos: ");
	scanf("%d %d", &a, &b);
	pto_inti(&p2, a, b);

	printf("Distancia entre os pontos: %.2lf\n", pto_dist(p1, p2));
	
	return 0;
}
