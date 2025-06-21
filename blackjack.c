
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "blackjack.h"

Carta* criarCarta(Naipe naipe, ValorCarta valor) {
    Carta* nova = (Carta*)malloc(sizeof(Carta));
    nova->naipe = naipe;
    nova->valor = valor;
    nova->proxima = NULL;
    return nova;
}

void adicionarCarta(Carta** mao, Naipe naipe, ValorCarta valor) {
    Carta* nova = criarCarta(naipe, valor);
    nova->proxima = *mao;
    *mao = nova;
}

int calcularPontuacao(Carta* mao) {
    int total = 0;
    int ases = 0;

    while (mao != NULL) {
        int val = mao->valor;
        if (val == AS) ases++;
        total += val;
        mao = mao->proxima;
    }

    while (total > 21 && ases > 0) {
        total -= 10; // trata AS como 1 em vez de 11
        ases--;
    }

    return total;
}

void liberarCartas(Carta* mao) {
    while (mao != NULL) {
        Carta* temp = mao;
        mao = mao->proxima;
        free(temp);
    }
}

void iniciarBaralho(Carta** baralho) {
    for (int n = 0; n < 4; n++) {
        for (int v = 2; v <= 11; v++) {
            if (v == 11) {
                adicionarCarta(baralho, n, AS);
            } else if (v > 10) {
                adicionarCarta(baralho, n, 10);
                adicionarCarta(baralho, n, 10);
                adicionarCarta(baralho, n, 10);
                break;
            } else {
                adicionarCarta(baralho, n, v);
            }
        }
    }
}

void embaralharBaralho(Carta** baralho) {
    // Simples shuffle: converte lista em array, embaralha e reconverte.
    Carta* array[52];
    int i = 0;
    Carta* temp = *baralho;
    while (temp) {
        array[i++] = temp;
        temp = temp->proxima;
    }
    srand(time(NULL));
    for (int j = 0; j < i; j++) {
        int k = rand() % i;
        Carta* t = array[j];
        array[j] = array[k];
        array[k] = t;
    }
    *baralho = NULL;
    for (int j = 0; j < i; j++) {
        array[j]->proxima = *baralho;
        *baralho = array[j];
    }
}

Carta* puxarCarta(Carta** baralho) {
    if (*baralho == NULL) return NULL;
    Carta* topo = *baralho;
    *baralho = topo->proxima;
    topo->proxima = NULL;
    return topo;
}

void salvarPontuacao(const char* nomeArquivo, int pontuacao) {
    FILE* arquivo = fopen(nomeArquivo, "a");
    if (arquivo) {
        fprintf(arquivo, "Pontuação: %d\n", pontuacao);
        fclose(arquivo);
    }
}

void exibirPontuacoes(const char* nomeArquivo) {
    char linha[100];
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo) {
        printf("Pontuações anteriores:\n");
        while (fgets(linha, sizeof(linha), arquivo)) {
            printf("%s", linha);
        }
        fclose(arquivo);
    } else {
        printf("Nenhuma pontuação registrada ainda.\n");
    }
}
