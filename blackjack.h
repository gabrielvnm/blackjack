
#ifndef BLACKJACK_H
#define BLACKJACK_H



// ENUMS
typedef enum {
    COPAS,
    OUROS,
    ESPADAS,
    PAUS
} Naipe;

typedef enum {
    DOIS = 2, TRES, QUATRO, CINCO, SEIS,
    SETE, OITO, NOVE, DEZ,
    VALETE = 10, DAMA = 10, REI = 10, AS = 11
} ValorCarta;

// STRUCTS
typedef struct Carta {
    Naipe naipe;
    ValorCarta valor;
    struct Carta* proxima;
} Carta;

typedef struct {
    Carta* mao;
    int pontuacao;
    int venceu;
} Jogador;

// FUNÇÕES
Carta* criarCarta(Naipe naipe, ValorCarta valor);
void adicionarCarta(Carta** mao, Naipe naipe, ValorCarta valor);
int calcularPontuacao(Carta* mao);
void liberarCartas(Carta* mao);
void embaralharBaralho(Carta** baralho);
void iniciarBaralho(Carta** baralho);
Carta* puxarCarta(Carta** baralho);
void salvarPontuacao(const char* nomeArquivo, int pontuacao);
void exibirPontuacoes(const char* nomeArquivo);

#endif
