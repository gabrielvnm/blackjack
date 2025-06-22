#ifndef BLACKJACK_H
#define BLACKJACK_H

#define MAX_NOME_JOGADOR 25

typedef enum {
    COPAS, OUROS, PAUS, ESPADAS
} Naipe;

typedef enum {
    AS = 1, DOIS, TRES, QUATRO, CINCO, SEIS, SETE, OITO, NOVE, DEZ, VALETE, DAMA, REI
} Valor;

typedef struct Carta {
    Naipe naipe;
    Valor valor;
    struct Carta* prox;
} Carta;

typedef struct Jogador {
    char nome[50];
    Carta* mao;
    int pontuacao;
} Jogador;

Carta* criarCarta(Naipe naipe, Valor valor);
void adicionarCarta(Carta** mao, Carta* nova);
void liberarMao(Carta* mao);
int calcularPontuacao(Carta* mao);
void imprimirMao(Carta* mao);
void salvarPontuacao(const char* nome, int pontuacao);
void exibirPlacar();
Carta* inicializarBaralho();
void embaralharBaralho(Carta** baralho);
Carta* comprarCarta(Carta** baralho);
Jogador criarJogador(const char* nome);
void turnoDoJogador(Jogador* jogador, Carta** baralho);
void turnoDoDealer(Jogador* dealer, Carta** baralho);
int limpar_stdin();
void exibirRegras();
void salvarJogo(const char* nome);

#endif