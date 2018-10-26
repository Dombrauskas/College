#include <stdio.h>

typedef union
{
	int digito;
	double real;
	char letra;
} uniao;

/* União só salva um valor (acima: um inteiro, um double, um caracter)
 * e o espaço que ocupa na memória é o da variavel com mais bits
 */

int main() 
{
	uniao u[3]; //[3] multiplica o tamanho da união por 3
	printf("sizeof(u) = %d\n", sizeof(u));
	u[0].digito = 14;
	printf("Digito: %d\n", u[0].digito);
	u[1].real = 2.5;
	printf("Digito: %.2lf\n", u[1].real);
	u[2].letra = 'J';
	printf("Digito: %c\n", u[2].letra);
	return 14;
}