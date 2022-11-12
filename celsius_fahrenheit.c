/*
Leia uma temperatura em graus Celsius e imprima seu correspondente em graus Fahrenheit.

Fórmula: Fahrenheit = Celsius * 9 / 5 + 32

<<
10
>>
50.000000
*/

#include <stdio.h>

int main(){
    float celsius;
    float fahren;
    scanf("%f", &celsius);
    fahren = (celsius * 9 /5) + 32;
    printf("%.6f", fahren);
}