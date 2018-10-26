#include <stdio.h>

int main()
{
    enum direcoes
    {
    LESTE, NORTE = 90, OESTE = 180, SUL = 270
    } ;
	printf("NORTE: %d\n", NORTE);
	return 0;
}