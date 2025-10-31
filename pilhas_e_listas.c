#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



/*
DESAFIO NÍVEL MESTRE - PILHAS E FILAS
By Speedydev77

O que você vai fazer?
Desenvolver um gerenciador de peças que usa duas estruturas de dados: uma fila circular com capacidade para 5 peças e uma pilha com capacidade para 3 peças. O sistema irá executar ações estratégicas com elas, como jogar, reservar, recuperar e realizar uma troca em bloco entre as peças da fila e as da pilha.
Requisitos funcionais
Seu programa em C deverá:
 
Inicializar a fila de peças com um número fixo de elementos (por exemplo, 5).
 
Inicializar uma pilha de peças reservadas com capacidade limitada (por exemplo, 3).
 
Permitir as seguintes ações:
 
Jogar uma peça: remove a peça da frente da fila (dequeue).
 
Reservar uma peça: move a peça da frente da fila para o topo da pilha, se houver espaço.
 
Usar uma peça reservada: remove a peça do topo da pilha, simulando seu uso.
 
Exibir o estado atual: mostra as peças na fila e na pilha após cada ação.
 
Trocar peça atual: substitui a peça da frente da fila com o topo da pilha.
 
Troca múltipla: alterna as três primeiras peças da fila com as três peças da pilha (caso ambas tenham, pelo menos, 3 peças).
 
Visualizar o estado atual da fila e da pilha.
 
Gerar uma nova peça de forma automática a cada remoção ou envio à pilha, a fim de manter a fila sempre cheia (quando possível).
 
Encerrar o programa.
 
Lembre-se: as peças removidas da fila ou da pilha não voltam para o jogo.
Atributos das peças
Cada peça possui:
 
nome: caractere que representa o tipo da peça ('I', 'O', 'T', 'L').
 
id: número inteiro único que representa a ordem de criação da peça.
 
As peças são geradas automaticamente por uma função chamada gerarPeca.
Exemplo de saída
Estado atual:

Fila de peças	[I 0] [L 1] [T 2] [O 3] [I 4] 
Pilha de reserva	(Topo -> base): [O 8] [L 7] [T 6]
Tabela: Visualização atual da fila de peças e da pilha de reserva.
Curadoria de TI.
Opções disponíveis:

Código	Ação
1	Jogar peça da frente da fila
2	Enviar peça da fila para a pilha de reserva
3	Usar peça da pilha de reserva
4	Trocar peça da frente da fila com o topo da pilha
5	Trocar os 3 primeiros da fila com as 3 peças da pilha
0	Sair
Tabela: Comandos para movimentar peças entre a fila e a pilha de reserva.
Curadoria de TI.
Opção escolhida: 5

Ação: troca realizada entre os 3 primeiros da fila e os 3 da pilha.
 
Novo estado:

Fila de peças	[O 8] [L 7] [T 6] [O 3] [I 4] 
Pilha de reserva	(Topo -> base): [T 2] [L 1] [I 0]
Tabela: Novo estado após a troca entre fila e pilha de peças.
Curadoria de TI.
Requisitos não funcionais
Observe os seguintes elementos importantes:
 
Usabilidade: a saída do programa deve ser clara e fácil de entender, com separação visual entre fila e pilha.
 
Legibilidade: o código deve ser bem organizado, com comentários explicando a lógica utilizada. Lembre-se: utilize nomes descritivos de variáveis.
 
Documentação: comente seu código, explicando o propósito de cada parte.
Simplificações para o nível avançado  
O foco é o uso combinado da fila e da pilha. Algumas limitações são:
 
O jogador não pode escolher o tipo da peça, pois elas são sempre geradas de forma aleatória.
 
Possibilidade de trocar diretamente a peça da fila com a da pilha.
 
A fila sempre mantém o tamanho, e a pilha tem um tamanho máximo fixo.
Conceitos trabalhados
Os pontos fundamentais são:
 
Fila circular: manipulação eficiente de elementos com reaproveitamento de espaço.
 
Integração de estruturas: troca de valores em estruturas compostas.
 
Pilha linear: armazenamento em estilo LIFO (último a entrar, primeiro a sair).
 
Structs e arrays: definição e uso de tipos personalizados para representar peças.
 
Entrada e saída de dados: interação com o jogador via terminal.
 
Funções e modularização: separação de responsabilidades no código.
 
Operadores lógicos e condicionais: controle de fluxo para validação de operações e restrições.

*/



#define TAM_FILA 5
#define TAM_PILHA 3



//Estrutura da peça
typedef struct {
    char nome; //Tipo da peça: I, O, T, L
    int id;    //Identificador único
} Peca;



//Estrutura da fila circular
typedef struct {
    Peca itens[TAM_FILA];
    int inicio;
    int fim;
    int tamanho;
} Fila;



//Estrutura da pilha
typedef struct {
    Peca itens[TAM_PILHA];
    int topo;
} Pilha;



//Funções de Geração
Peca gerarPeca(int id) {
    char tipos[] = {'I', 'O', 'T', 'L'};
    Peca nova;
    nova.nome = tipos[rand() % 4];
    nova.id = id;
    return nova;
}



//Operações de Fila
void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int filaVazia(Fila *f) {
    return f->tamanho == 0;
}

int filaCheia(Fila *f) {
    return f->tamanho == TAM_FILA;
}

void enfileirar(Fila *f, Peca p) {
    if (filaCheia(f)) return;
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % TAM_FILA;
    f->tamanho++;
}

Peca desenfileirar(Fila *f) {
    Peca p = {'-', -1};
    if (filaVazia(f)) return p;
    p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % TAM_FILA;
    f->tamanho--;
    return p;
}

Peca frenteFila(Fila *f) {
    if (filaVazia(f)) {
        Peca p = {'-', -1};
        return p;
    }
    return f->itens[f->inicio];
}



//Operações de Pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == TAM_PILHA - 1;
}

void empilhar(Pilha *p, Peca x) {
    if (pilhaCheia(p)) return;
    p->itens[++p->topo] = x;
}

Peca desempilhar(Pilha *p) {
    Peca v = {'-', -1};
    if (pilhaVazia(p)) return v;
    return p->itens[p->topo--];
}

Peca topoPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        Peca v = {'-', -1};
        return v;
    }
    return p->itens[p->topo];
}



//Funções de Exibição
void exibirEstado(Fila *f, Pilha *p) {
    printf("\n================ ESTADO ATUAL ================\n");
    printf("Fila de peças\t");
    int i, j;
    int pos = f->inicio;
    for (i = 0; i < f->tamanho; i++) {
        printf("[%c %d] ", f->itens[pos].nome, f->itens[pos].id);
        pos = (pos + 1) % TAM_FILA;
    }
    printf("\n");

    printf("Pilha de reserva\t(Topo -> base): ");
    for (j = p->topo; j >= 0; j--) {
        printf("[%c %d] ", p->itens[j].nome, p->itens[j].id);
    }
    printf("\n==============================================\n");
}



//Ações do jogo
void jogarPeca(Fila *fila, int *idContador) {
    if (filaVazia(fila)) {
        printf("Fila vazia! Nenhuma peça para jogar.\n");
        return;
    }
    Peca jogada = desenfileirar(fila);
    printf("Peça jogada: [%c %d]\n", jogada.nome, jogada.id);

    // Gera nova peça para manter fila cheia
    Peca nova = gerarPeca((*idContador)++);
    enfileirar(fila, nova);
}

void reservarPeca(Fila *fila, Pilha *pilha, int *idContador) {
    if (pilhaCheia(pilha)) {
        printf("Pilha cheia! Não é possível reservar.\n");
        return;
    }
    if (filaVazia(fila)) {
        printf("Fila vazia! Nenhuma peça para reservar.\n");
        return;
    }

    Peca movida = desenfileirar(fila);
    empilhar(pilha, movida);
    printf("Peça [%c %d] movida da fila para pilha.\n", movida.nome, movida.id);

    // Reposição automática da fila
    Peca nova = gerarPeca((*idContador)++);
    enfileirar(fila, nova);
}

void usarPecaReservada(Pilha *pilha) {
    if (pilhaVazia(pilha)) {
        printf("Pilha vazia! Nenhuma peça para usar.\n");
        return;
    }
    Peca usada = desempilhar(pilha);
    printf("Peça usada: [%c %d]\n", usada.nome, usada.id);
}

void trocarPeca(Fila *fila, Pilha *pilha) {
    if (filaVazia(fila) || pilhaVazia(pilha)) {
        printf("Não há peças suficientes para troca.\n");
        return;
    }
    int pos = fila->inicio;
    Peca temp = fila->itens[pos];
    fila->itens[pos] = pilha->itens[pilha->topo];
    pilha->itens[pilha->topo] = temp;
    printf("Troca realizada entre a peça da fila e o topo da pilha.\n");
}

void trocaMultipla(Fila *fila, Pilha *pilha) {
    if (fila->tamanho < 3 || pilha->topo < 2) {
        printf("Não há peças suficientes para a troca múltipla.\n");
        return;
    }
    int posFila = fila->inicio;
    for (int i = 0; i < 3; i++) {
        Peca temp = fila->itens[(posFila + i) % TAM_FILA];
        fila->itens[(posFila + i) % TAM_FILA] = pilha->itens[pilha->topo - i];
        pilha->itens[pilha->topo - i] = temp;
    }
    printf("Troca múltipla realizada entre as 3 primeiras peças.\n");
}



//Função principal
int main() {
    srand(time(NULL));

    Fila fila;
    Pilha pilha;
    inicializarFila(&fila);
    inicializarPilha(&pilha);

    int idContador = 0;



    //Inicializa fila com 5 peças
    for (int i = 0; i < TAM_FILA; i++) {
        enfileirar(&fila, gerarPeca(idContador++));
    }

    int opcao;
    do {
        exibirEstado(&fila, &pilha);
        printf("\nOpções:\n");
        printf("1 - Jogar peça da frente da fila\n");
        printf("2 - Enviar peça da fila para a pilha de reserva\n");
        printf("3 - Usar peça da pilha de reserva\n");
        printf("4 - Trocar peça da frente da fila com o topo da pilha\n");
        printf("5 - Trocar as 3 primeiras da fila com as 3 da pilha\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: jogarPeca(&fila, &idContador); break;
            case 2: reservarPeca(&fila, &pilha, &idContador); break;
            case 3: usarPecaReservada(&pilha); break;
            case 4: trocarPeca(&fila, &pilha); break;
            case 5: trocaMultipla(&fila, &pilha); break;
            case 0: printf("Encerrando o programa...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}



