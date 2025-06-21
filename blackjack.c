#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "blackjack.h"

Carta* criarCarta(Naipe naipe, Valor valor) {
    Carta* nova = (Carta*)malloc(sizeof(Carta));
    nova->naipe = naipe;
    nova->valor = valor;
    nova->prox = NULL;
    return nova;
}

void adicionarCarta(Carta** mao, Carta* nova) {
    nova->prox = *mao;
    *mao = nova;
}

void liberarMao(Carta* mao) {
    while (mao) {
        Carta* temp = mao;
        mao = mao->prox;
        free(temp);
    }
}

int calcularPontuacao(Carta* mao) {
    int total = 0;
    int ases = 0;

    while (mao) {
        if (mao->valor >= DEZ)
            total += 10;
        else
            total += mao->valor;

        if (mao->valor == AS)
            ases++;

        mao = mao->prox;
    }

    while (ases > 0 && total + 10 <= 21) {
        total += 10;
        ases--;
    }

    return total;
}

void imprimirMao(Carta* mao) {
    while (mao) {
        printf("Carta: %d de %d\n", mao->valor, mao->naipe);
        mao = mao->prox;
    }
}

void salvarPontuacao(const char* nome, int pontuacao) {
    FILE* arquivo = fopen("placar.txt", "a");
    if (arquivo) {
        fprintf(arquivo, "%s: %d\n", nome, pontuacao);
        fclose(arquivo);
    }
}

void exibirPlacar() {
    FILE* arquivo = fopen("placar.txt", "r");
    if (arquivo) {
        char linha[100];
        printf("\n--- PLACAR ---\n");
        while (fgets(linha, sizeof(linha), arquivo)) {
            printf("%s", linha);
        }
        fclose(arquivo);
        printf("---------------\n");
    } else {
        printf("Placar ainda não disponível.\n");
    }
}



// Cria todas as 52 cartas do baralho
Carta* inicializarBaralho() {
    Carta* baralho = NULL;
    for (int n = 0; n < 4; n++) {
        for (int v = AS; v <= REI; v++) {
            Carta* nova = criarCarta((Naipe)n, (Valor)v);
            adicionarCarta(&baralho, nova);
        }
    }
    return baralho;
}

// Embaralha as cartas (simplificação: embaralha movendo aleatoriamente para nova lista)
void embaralharBaralho(Carta** baralho) {
    srand(time(NULL));
    Carta* embaralhado = NULL;
    int total = 0;

    // Conta o total de cartas
    for (Carta* temp = *baralho; temp; temp = temp->prox) total++;

    while (total > 0) {
        int index = rand() % total;
        Carta** atual = baralho;
        for (int i = 0; i < index; i++) atual = &(*atual)->prox;

        Carta* selecionada = *atual;
        *atual = selecionada->prox;
        selecionada->prox = embaralhado;
        embaralhado = selecionada;
        total--;
    }
    *baralho = embaralhado;
}

// Remove a primeira carta do baralho e retorna ela
Carta* comprarCarta(Carta** baralho) {
    if (*baralho == NULL) return NULL;
    Carta* carta = *baralho;
    *baralho = carta->prox;
    carta->prox = NULL;
    return carta;
}

// Cria um jogador com nome e mão vazia
Jogador criarJogador(const char* nome) {
    Jogador jogador;
    strcpy(jogador.nome, nome);
    jogador.mao = NULL;
    jogador.pontuacao = 0;
    return jogador;
}

// Turno manual do jogador: compra enquanto quiser ou até estourar 21
void turnoDoJogador(Jogador* jogador, Carta** baralho) {
    char escolha;
    do {
        Carta* nova = comprarCarta(baralho);
        adicionarCarta(&jogador->mao, nova);
        jogador->pontuacao = calcularPontuacao(jogador->mao);
        printf("\n%s comprou uma carta. Pontuação atual: %d\n", jogador->nome, jogador->pontuacao);
        imprimirMao(jogador->mao);

        if (jogador->pontuacao >= 21) break;

        printf("Deseja comprar mais uma carta? (s/n): ");
        scanf(" %c", &escolha);
    } while (escolha == 's');
}

// Turno automático do dealer: compra até ter 17 ou mais
void turnoDoDealer(Jogador* dealer, Carta** baralho) {
    while (1) {
        dealer->pontuacao = calcularPontuacao(dealer->mao);
        if (dealer->pontuacao >= 17) break;

        Carta* nova = comprarCarta(baralho);
        adicionarCarta(&dealer->mao, nova);
        printf("Dealer comprou uma carta. Pontuação atual: %d\n", dealer->pontuacao);
    }
}
