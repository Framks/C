/*
Aluízio quer comprar uma televisão parcelada. Ele tem X reais por mês disponíveis para pagar a televisão. No parcelamento, quanto mais parcelas, maior o juros que usa a seguinte regra.

1 vez sem juros
2 vezes com juros de 5%
3 vezes com juros de 10%
4 vezes com juros de 15%
5 vezes com juros de 20%
6 vezes com juros de 25%
7 vezes com juros de 30%
8 vezes com juros de 35%
9 vezes com juros de 40%
10 vezes com juros de 45%
Dado o valor da televisão e a quantidade de parcelas, um por linha, calcule o valor da parcela e o valor total que Aluízio vai pagar. Imprima a saída conforme o exemplo a seguir.

>>>>>>>>
100
1
========
100.00
100.00
<<<<<<<<

>>>>>>>>
100
2
========
52.50
105.00
<<<<<<<<

>>>>>>>>
100
10
========
14.50
145.00
<<<<<<<<

>>>>>>>>
102
3
========
37.40
112.20
<<<<<<<<

>>>>>>>>
52
4
========
14.95
59.80
<<<<<<<<

>>>>>>>>
100
5
========
24.00
120.00
<<<<<<<<
Problema proposto por Aluízio Lopes.
*/

#include <stdio.h>

int main(){
    float valor, valor_par, valor_fim;
    int parc;
    scanf("%f %d", &valor, &parc);
    switch(parc){
        case 1:
            valor_par = valor;
            valor_fim = valor;
        break;
        case 2:
            valor_fim = valor + (valor * 0.05);
            valor_par = valor_fim/2;
        break;
        case 3:
            valor_fim = valor + (valor * 0.10);
            valor_par = valor_fim/3;
        break;
        case 4:
            valor_fim = valor + (valor * 0.15);
            valor_par = valor_fim/4;
        break;
        case 5:
            valor_fim = valor + (valor * 0.20);
            valor_par = valor_fim/5;
        break;
        case 6:
            valor_fim = valor + (valor * 0.25);
            valor_par = valor_fim/6;
        break;
        case 7:
            valor_fim = valor + (valor * 0.30);
            valor_par = valor_fim/7;
        break;
        case 8:
            valor_fim = valor + (valor * 0.35);
            valor_par = valor_fim/8;
        break;
        case 9:
            valor_fim = valor + (valor * 0.40);
            valor_par = valor_fim/9;
        break;
        case 10:
            valor_fim = valor + (valor * 0.45);
            valor_par = valor_fim/10;
        break;
    }
    printf("%.2f\n%.2f\n", valor_par, valor_fim);
}