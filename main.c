#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include "blackjack.h"

int main(){
    
    char c;
    int op = 0;
    char nome_jogador[MAX_NOME_JOGADOR];

    printf("Bem vindo ao jogo de BlackJack!\n");
    printf("Digite o nome do jogador:\n");
    fgets(nome_jogador, MAX_NOME_JOGADOR, stdin);
    nome_jogador[strcspn(nome_jogador, "\n")] = '\0';
    printf("Nome do jogador: %s\n",nome_jogador);

    while (op!=4){
        //validação de input do usuario, se ele digitar alguma coisa que nao é integer
        do{
            printf("Selecione uma opção:\n");
            printf("1: Novo Jogo\n2: Ver histórico de pontuação\n3: Regras\n4: Sair\n");
        } while (
            ((scanf("%d%c", &op, &c)!=2 || c!='\n') && limpar_stdin())
        );
        switch (op){
            default:
                printf("Erro! Digite uma opcao valida!\n");
                break;
            case 1:{
                Jogador jogador1 = criarJogador(nome_jogador);
                Jogador dealer = criarJogador("Dealer");
                Carta* baralho = inicializarBaralho();
                embaralharBaralho(&baralho);
                turnoDoDealer(&dealer, &baralho);
                turnoDoJogador(&jogador1, &baralho);

                //a ordem desses ifs importa!!!
                if (jogador1.pontuacao >21){
                    printf("Voce perdeu!\n");
                    printf("Pontuacao jogador %s: %d\n",nome_jogador,jogador1.pontuacao);
                    printf("Pontuacao dealer: %d\n",dealer.pontuacao);
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                    salvarJogo(dealer.nome);
                }
                else if(jogador1.pontuacao == 21){
                    printf("Voce venceu!\n");
                    printf("Pontuacao jogador %s: %d\n",nome_jogador,jogador1.pontuacao);
                    printf("Pontuacao dealer: %d\n",dealer.pontuacao);
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }
                else if(jogador1.pontuacao<21 && dealer.pontuacao>21){
                    printf("Voce venceu!\n");
                    printf("Pontuacao jogador %s: %d\n",nome_jogador,jogador1.pontuacao);
                    printf("Pontuacao dealer: %d\n",dealer.pontuacao);
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }
                else if(jogador1.pontuacao<21 && jogador1.pontuacao>dealer.pontuacao){
                    printf("Voce venceu!\n");
                    printf("Pontuacao jogador %s: %d\n",nome_jogador,jogador1.pontuacao);
                    printf("Pontuacao dealer: %d\n",dealer.pontuacao);
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }
                else if(jogador1.pontuacao<21 && jogador1.pontuacao<dealer.pontuacao){
                    printf("Voce perdeu!\n");
                    printf("Pontuacao jogador %s: %d\n",nome_jogador,jogador1.pontuacao);
                    printf("Pontuacao dealer: %d\n",dealer.pontuacao);
                    salvarPontuacao(nome_jogador,jogador1.pontuacao);
                    salvarPontuacao(dealer.nome,dealer.pontuacao);
                }                
                break;
            }
            case 2:
                exibirPlacar();
                
                break;
            case 3:
                exibirRegras();
                
                break;
            case 4:
                break;
            
        }
        printf("Encerrando jogo!\n");
    }
    return 0;
}