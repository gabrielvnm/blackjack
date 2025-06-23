# Blackjack (21) ♠ ♥ ♦ ♣

Jogo de cartas Blackjack (21) desenvolvido em linguagem C como atividade avaliativa da disciplina de Estrutura de Dados da Universidade Católica de Brasília.

## 🎮 Breve descrição das regras do jogo

- O jogador enfrenta o computador (dealer) em uma partida de Blackjack.
- Ambos recebem cartas de um baralho real com 52 cartas, sem repetições.
- O jogador pode escolher entre "comprar carta" ou "parar".
- O dealer joga automaticamente, comprando cartas até atingir 17 ou mais pontos.
- O Ás vale 1 ou 11, dependendo da necessidade para não ultrapassar 21 pontos.
- O vencedor é aquele que tiver a pontuação mais próxima de 21 sem ultrapassá-lo.
- Após cada rodada, o resultado é salvo no arquivo `placar.txt`.

--- 

## ⚙️ Instruções para Compilação e Execução

### Pré-requisitos
- Compilador C (GCC)
- Terminal Linux ou Windows

### Compilação
```bash
gcc blackjack.c blackjack.h main.c -o .\main.exe
//Após compilar execute o arquivo: 
.\main.exe
```
---
## 🗂️ Organização do Código

O código está modularizado nos seguintes arquivos:

- **`main.c`**  
  Contém a função principal (`main`) e o menu inicial do jogo:

- **`blackjack.c`**  
  Implementa toda a lógica do jogo:
  - Criação e embaralhamento do baralho
  - Compra de cartas pelo jogador e dealer
  - Cálculo da pontuação de cada mão
  - Manipulação de arquivos para salvar o placar

- **`blackjack.h`**  
  Arquivo de cabeçalho que define:
  - Estruturas (`struct`) das cartas e dos jogadores

- **`placar.txt`**  
  Arquivo gerado automaticamente que armazena o histórico de partidas e pontuações.

- **`Makefile`**  
  Script de automação para compilar, gerar e limpar os arquivos do projeto.

---

### 🔍 Principais Funções Implementadas

- **`inicializarBaralho()`**  
  Cria as 52 cartas do baralho utilizando lista encadeada.

- **`embaralharBaralho()`**  
  Embaralha as cartas de forma aleatória com `rand()`.

- **`comprarCarta()`**  
  Remove e retorna a carta do topo do baralho para o jogador.

- **`calcularPontuacao()`**  
  Soma os valores das cartas da mão, tratando o Ás como 1 ou 11 conforme necessário.

- **`turnoDoJogador()` / `turnoDoDealer()`**  
  Controlam as ações do jogador e do dealer, respectivamente.

- **`salvarPontuacao()`**  
  Salva no arquivo `placar.txt` o nome do jogador e sua pontuação final.

- **`exibirPlacar()`**  
  Mostra o conteúdo atual do arquivo `placar.txt` com os resultados anteriores.

- **`limpar_stdin()`**  
  Função auxiliar que limpa o buffer de entrada para evitar leituras inválidas.

- **`liberarMao()`**  
  Libera a memória alocada para as listas encadeadas das mãos dos jogadores e dealer.
