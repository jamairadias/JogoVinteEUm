#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int jogador_total = 0;
    int banca_total = 0;
    int carta;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    printf("Jogo de 21!\n\n");

    // Turno do jogador
    while (1) {
        carta = rand() % 11 + 1; // cartas de 1 a 11
        jogador_total += carta;
        printf("Voce recebeu uma carta de valor %d. Total: %d\n", carta, jogador_total);

        if (jogador_total > 21) {
            printf("Voce passou de 21! A banca venceu!\n");
            break;
        }

        char resposta;
        printf("Deseja comprar mais uma carta? (s/n): ");
        scanf(" %c", &resposta);

        if (resposta != 's' && resposta != 'S') {
            break;
        }
    }

    // Se o jogador passou de 21, o jogo termina aqui
    if (jogador_total > 21) {
        printf("Fim do jogo.\n");
        return 0;
    }

    // Turno da banca
    printf("\nVez da banca...\n");
    while (banca_total < 17) {
        carta = rand() % 11 + 1; // cartas de 1 a 11
        banca_total += carta;
        printf("A banca recebeu uma carta de valor %d. Total: %d\n", carta, banca_total);
    }

    // Verifica quem ganhou
    printf("\nResultado:\n");
    printf("Seu total: %d\n", jogador_total);
    printf("Total da banca: %d\n", banca_total);

    if (banca_total > 21 || jogador_total > banca_total) {
        printf("Voce venceu!\n");
    } else if (jogador_total < banca_total) {
        printf("A banca venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}