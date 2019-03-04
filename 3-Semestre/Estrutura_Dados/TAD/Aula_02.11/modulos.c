#include <stdio.h>
#include <stdbool.h>
#define MAX_LENGTH 120

void read_line(char[], int);
bool read_int(int *);

void read_line (char line[], int max_length)
{
    int i = 0;
    char ch;
        while ((ch = getchar()) != '\n')
            if (i < max_length)
            line[i++] = ch;
    line[i] = '\0';
}

bool read_int(int *val)
{
    char line[MAX_LENGTH + 1];
    read_line(line, MAX_LENGTH);
    return (sscanf(line, "%d", val) == 1);
}

// A main deveria estar em um arquivo separado.
int main()
{
    int n;
    
    while (!read_int(&n) || n < 5)
        printf("Mais de 5 plz\n");
    char str[n + 1];
    
    read_line(str, n);
    printf("String informada: %s\n", str);
    return 0;
}
