/*
MOTIVAÇÃO
Ao terminar uma prova de matemática, Marcelo e João estavam na duvida se teriam acertado as questões 
que perguntava se um numero era divisível por outro. Ao chegar em casa, Marcelo ainda com essa duvida, 
pediu para o seu irmão mais velho, você, ajudar ele fazendo um programa que diz se um número é divisível por outro.

AÇÃO
Leia dois inteiros e diga se ambos são divisíveis por 3 ou por 5.

ENTRADA
Dois números inteiros.

SAÍDA
"sim" (sem aspas) caso ambos sejam divisíveis por 3, ou ambos sejam divisíveis por 5. E "nao" (sem aspas) caso contrário.

EXEMPLOS
>>

5

10

<<

sim
*/
#include <stdio.h>

int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    if(!(num1%3) && !(num2%3)){
        printf("sim\n");
    }else if(!(num1%5) && !(num2%5)){
        printf("sim\n");
    }else{
        printf("nao\n");
    }
}