/*
Descrição
Pedro e João foram no Silvio Santos. O programa era aquele que o Silvio mostrava um produto do mercantil e a pessoa que chegasse mais próximo do preço real ganhava.

O objetivo do seu programa é informar quem ganhou a disputa. Você receberá o valor do produto e o valor do chute de cada jogador. O jogador que chegar mais perto ganha.

Se ambos ficarem à mesma distancia do valor real, então houve empate.

[DS]

I/O
Entrada:

linha 1: o valor do produto.(valor inteiro entre 1 e 100)
linha 2: o chute do Primeiro
linha 3: o chute de Segundo
Saida:

"primeiro" se o chute do Primeiro for o mais próximo do valor do produto
"segundo" se o chute do Segundo for o mais próximo do valor do produto
"empate" caso ambos ficarem à mesma distancia
Exemplos
>>
1
2
3
<<
primeiro
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
    int v1, v2, caso;
    scanf("%d %d %d", &caso, &v1, &v2);
    v1 = abs((caso-v1));
    v2 = abs((caso-v2));
    if(v1 < v2){
        printf("primeiro");
    }else if(v2 < v1){
        printf("segundo");
    }else{
        printf("empate");
 
    }
}