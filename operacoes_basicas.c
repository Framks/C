/*
Motivação
    Com o programa ficará mais fácil realizar as operaçôes básicas da matemática

Ação
    Leia dois números inteiros e imprima a soma, a subtração, a multiplicação, a divisão e o resto da divisão entre eles respectivamente.

Entrada e Saída
    Entrada:

        Valores de A,B em inteiro, um por linha.
    Saída:

        Valores da soma, subtração, multiplicação e resto da divisão em inteiro, um por linha.
        Valor da divisão em ponto flutuante de duas casas decimais.
        O valor de B nunca será 0, então não se preocupe com divisão por 0.
*/
#include <stdio.h>

int main(){
    // variaveis
     int num1;
     int num2;
     int soma;
     int sub;
     int multi;
     float divi;
     int resto;
    /* entradas */
     scanf("%d %d", &num1, &num2);
     /* operações */
     soma = num1 + num2;
     sub = num1 - num2;
     multi = num1 * num2;
     divi = (double) num1/ num2;
     resto = num1 % num2;
    /* impressão */
     printf("%d\n%d\n%d\n%.2f\n%d",soma,sub,multi,divi,resto);
}