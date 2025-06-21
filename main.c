#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "blackjack.h"

int main(){
    
    int op;
    char nome_jogador[MAX_NOME_JOGADOR];
/*
    printf("Bem vindo ao jogo de BlackJack!\n");
    printf("Selecione uma opção:\n");
    printf("1: Novo Jogo\n2: Ver histórico de pontuação\n3: Regras\n 4: Sair\n");
    scanf("%d",&op);
    
    switch (op)
    {
        default:
            printf("Erro! Digite uma opcao valida!\n");
            break;
        case 1:*/
            printf("Digite o nome do jogador:\n");
            fgets(nome_jogador, MAX_NOME_JOGADOR, stdin);
            nome_jogador[strcspn(nome_jogador, "\n")] = '\0';
            printf("nome do jogador: %s\n",nome_jogador);

            Jogador jogador1 = criarJogador(nome_jogador);
            Jogador dealer = criarJogador("Dealer");
            Carta* baralho = inicializarBaralho();
            embaralharBaralho(&baralho);
            turnoDoDealer(&dealer, &baralho);
            turnoDoJogador(&jogador1, &baralho);

/*
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        
    }*/
    return 0;
}