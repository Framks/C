/*
Uma disciplina tem uma prova de peso 5, uma prova de peso 3, e um trabalho de peso 2. Leia as 3 notas (nesta ordem) e imprima a média final.

Exemplo:
<<
8.5
6
7
>>
7.450000

*/

#include <stdio.h>

int main(){
    float n1, n2, n3;
    float media;
    scanf("%f %f %f", &n1, &n2, &n3);
    media = (5*n1 + 3*n2 + 2*n3)/10;
    printf("%.6f",media);
}