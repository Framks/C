/*
Descrição
Três competidores olímpicos de arremesso de disco tinham desempenhos muito parecidos. 
Constantemente eles jogavam os discos à mesma distância. Decidiram então criar um algoritmo 
que informava quantos deles tinham conseguido o mesmo resultado.

[DS]

Entrada e Saida
Leia três valores do usuário.
Imprima a quantidade de valores iguais dentre os três.
Exemplos
>>
1
4
4
<<
2
*/

#include <stdio.h>

int main(){
    int num1, num2, num3, quantos = 0;
    scanf("%d %d %d",&num1, &num2, &num3);
    if(num1 == num2 && num2 == num3){
        quantos = 3;
    }else if(num1 == num2 || num2 == num3 || num3 == num1){
        quantos = 2;
    }
    printf("%d\n",quantos);
}