/**
 * 
 * author Mauricio Freire
 * Pontuação na Partida de Vôlei: Na Liga Mundial de Vôlei, uma equipe faz 3
 * pontos se vercer a partida por 3x0 ou 3x1, faz 2 pontos se vencer a partida
 * por 3x2, faz 1 ponto se perder a partida por 2x3 e não marca pontos de
 * perder por 1x3 ou 0x3.
 * Escreva um programa que dados os placares de N partidas de uma equipe na
 * Liga Mundial de Vôlei, informe quantos pontos ela fez no total das N partidas.
 * Volleyball Match Score: counts how many points a team scored in the
 * Volleyball World League.
*/
#include <stdio.h>

int main()
{
    int n, a, b, pts = 0;
    // Quantidade de partidas jogadas por uma equipe.
    // Amount of matches played by a team in the league.
    do {
        scanf("%d", &n);
    } while (n < 0 || n > 1000);
    
    do {
        // Verifica se a quantidade de sets jogados.
        // Checks the amount of sets played.
        do {
            scanf("%d %d", &a, &b);
            // Garante que apenas uma equipe tenha vencido 3 sets.
            // Ensure that just one team has won 3 sets.
            if (a == b)
                a = 5;
            // Garante que uma equipe tenha vencido 3 sets.
            // Ensure a team has won 3 sets.
            if (a != 3)
                if (b != 3)
                    a = 5;
        } while (a < 0 || a > 3 || b < 0 || b > 3);
        // Soma os pontos da equipe.
        // Sum up the points of the team.
        if (a - b >= 2)
            pts += 3;
        else if (a - b == 1)
            pts += 2;
        else if (a - b == -1)
            pts++;
        n--;
    } while (n > 0);
    
    printf("%d\n", pts);
    return 0;
}
