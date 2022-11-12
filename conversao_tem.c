/*
Leia o tempo em segundos, e imprima este tempo em horas, minutos e segundos.

Dica: use divisão inteira e o operador de resto da divisão.

1 minuto = 60 segundos.
1 hora = 60 minutos * 60 segundos = 3600 segundos.

Exemplo:
<<
7384
>>
2
3
4
*/

#include <stdio.h>

int main(){
    int tem;
    scanf("%d", &tem);
    printf("%d\n%d\n%d",((tem/60)/60), ((tem%3600)/60), ((tem%3600)%60));
}