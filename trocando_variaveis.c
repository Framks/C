/*
Leia os valores de duas variáveis inteiras a e b, troque os valores destas variáveis, e imprima os valores das variáveis a e b (nesta ordem).

<<
2
3
>>
3
2
*/

#include <stdio.h>

int main(){
    int num1, num2, copo;
    scanf("%d %d", &num1, &num2);
    copo = num1;
    num1 = num2;
    num2 = copo;
    printf("%d\n%d", num1, num2);
}