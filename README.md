# pilhas_e_listas.c

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
<img width="925" height="2538" alt="image" src="https://github.com/user-attachments/assets/c1895a21-022a-4a13-a7da-6420c1cd425f" />
