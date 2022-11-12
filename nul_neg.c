/*
Motivação
Chaves, se eu tenho 5 bananas e como 5 bananas, com o que eu fico?
Prisão de ventre!
Não chaves, suponha que eu tenha 5 mamões e como os 5, com o que eu fico?
Intestino frouxo!
Chaves, não seja burro! Se você TINHA 5 moedas, cada sanduíche era uma moeda e você comeu 5 sanduíches, com quanto você fica?
1 moeda!
Mas como uma moeda Chaves, você fica com zero, 0, ZERO!!!!
Não, é porque na mercearia do Chiquim a promoção é leve 5 e pague 4.
O Chaves não sabe diferenciar positivo, negativo e nulo, mas você sabe! Eu espero!

Ação
Entrada: Leia um valor inteiro do usuário.

Saída: Imprima "positivo", "nulo" ou "negativo" de acordo com o valor lido.

Exemplos
>>
5
<<
positivo
*/

#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    if(num >0){
        printf("positivo\n");
    }else if(num < 0){
        printf("negativo\n");
    }else{
        printf("nulo\n");
    }
}