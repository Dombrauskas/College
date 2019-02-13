#ifndef _PONTO_H
#define _PONTO_H

typedef struct {
	int x;
	int y;
} ponto;

void pto_init(ponto *, int, int);

double pto_dist(ponto, ponto);

#endif
