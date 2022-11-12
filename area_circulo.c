/*
Leia o raio de um círculo e imprima sua área.

Fórmula: area = 3.14 * raio * raio

Exemplo:
<<
10
>>
314.000000
*/

#include <stdio.h>

int main (){
    int raio;
    scanf("%d",&raio);
    printf("%.6f", (3.14*raio*raio));
}