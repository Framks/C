/*
Ação
Um amigo lhe deu a velocidade média do carro dele em km/h, o tempo da viagem em minutos e o consumo de um carro em litros e pediu que você faça um programa que calcule o desempenho do motor em km por litro.

Dica:
O tempo em hora eh tempo em minutos/60
A distancia percorrida é velocidade vezes tempo em horas
O desempenho é distancia / consumo.
Entrada
Velocidade em km/h
Tempo em minutos
Consumo em litros
Saída
Desempenho com duas cadas decimais.
Exemplos
>>>>>>>> corsa
100
60
10
========
10.00
<<<<<<<<

>>>>>>>> fusca
60
40
10
========
4.00
<<<<<<<<
*/

#include <stdio.h>

int main(){
    float tem, fim, dist;
    float velo, consumo;
    scanf("%f %f %f", &velo, &tem, &consumo);
    tem = tem/60;
    dist = tem * velo;
    fim = dist / consumo;
    printf("%.2f\n", fim);
}