/*
Leia um inteiro com 4 dígitos, e imprima um dígito por linha.

<<
2468
>>
2
4
6
8
*/

#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    printf("%d\n%d\n%d\n%d", (num/1000), ((num%1000)/100), (((num%1000)%100)/10), (((num%1000)%100)%10));
}