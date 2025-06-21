#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "blackjack.h"

int main(){
    
    int op = 0;
    char nome_jogador[MAX_NOME_JOGADOR];

    printf("Bem vindo ao jogo de BlackJack!\n");
    printf("Digite o nome do jogador:\n");
    fgets(nome_jogador, MAX_NOME_JOGADOR, stdin);
    nome_jogador[strcspn(nome_jogador, "\n")] = '\0';
    printf("nome do jogador: %s\n",nome_jogador);

    while (op!=4){
        
        printf("Selecione uma opção:\n");
        printf("1: Novo Jogo\n2: Ver histórico de pontuação\n3: Regras\n4: Sair\n");
        scanf("%d",&op);
        switch (op){
            default:
                printf("Erro! Digite uma opcao valida!\n");
                break;
            case 1:
                Jogador jogador1 = criarJogador(nome_jogador);
                Jogador dealer = criarJogador("Dealer");
                Carta* baralho = inicializarBaralho();
                embaralharBaralho(&baralho);
                turnoDoDealer(&dealer, &baralho);
                turnoDoJogador(&jogador1, &baralho);
                if (jogador1.pontuacao >21){
                    printf("voce perdeu!\n");
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }
                else if(jogador1.pontuacao == 21){
                    printf("voce venceu!\n");
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }
                else if(jogador1.pontuacao<21 && jogador1.pontuacao>dealer.pontuacao){
                    printf("voce venceu!\n");
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }
                else if(jogador1.pontuacao<21 && jogador1.pontuacao<dealer.pontuacao){
                    printf("voce perdeu!\n");
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }
                else if(jogador1.pontuacao<21 && dealer.pontuacao>21){
                    printf("voce venceu!\n");
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:
                break;
            
        }
    }
    return 0;
}