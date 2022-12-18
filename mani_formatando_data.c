/*
Motivação
Os formatos de data e hora são diversos. Leia hora, minuto, dia, mês e ano e imprima no formato hh:mm dd/mm/aa. Você deve certificar-se de imprimir um 0 à esquerda para garantir que todas as informações tenham 2 dígitos.

Entrada:
hora, minuto, dia, mês e ano, um por linha.
Saída:
hh:mm dd/mm/aa.
Exemplos
>>>>>>>>
4
12
12
3
1988
========
04:12 12/03/88
<<<<<<<<

>>>>>>>>
12
30
1
3
188
========
12:30 01/03/88
<<<<<<<<

>>>>>>>>
14
7
7
9
2005
========
14:07 07/09/05
<<<<<<<<

>>>>>>>>
23
1
1
1
2076
========
23:01 01/01/76
<<<<<<<<
Ajuda
Resolução
Seja a variável valor um número em inteiro, você pode imprimir essa variável completando com zeros a esquerda até formar a quantidade de dígitos que você precisa, para colocar 2 dígitos você faz assim: - C: printf("%02d", valor) - Javascript: console.log(String(valor).padStart(2, "0")) - Python: print("%02d" % (valor))

Você pode usar o operador de módulo usando ano % 100 para pegar só os dois últimos dígitos do ano.
*/

#include <stdio.h>

int main(){
    int ho1, ho2, dat1, dat2, dat3;
    scanf("%d %d %d %d %d",&ho1 , &ho2 , &dat1 , &dat2, &dat3);
    // Hora 
        if(ho1 >= 10){
            printf("%d:", ho1);
        }else{
            printf("0%d:",ho1);
        }
        if(ho2 >= 10){
            printf("%d ",ho2);
        }else{
            printf("0%d ",ho2);
        }
    // data
        if(dat1 >= 10){
            printf("%d/", dat1);
        }else{
            printf("0%d/", dat1);
        }
        if(dat2 >= 10){
            printf("%d/", dat2);
        }else{
            printf("0%d/", dat2);
        }
        if(dat3 >= 1000){
            dat3 = (dat3%1000)%100;
            if(dat3 >= 10){
                printf("%d\n", dat3);
            }else{
                printf("0%d\n",dat3);
            }
        }else{
            dat3 = (dat3%100);
            if(dat3 >= 10){
                printf("%d\n", dat3);
            }else{
                printf("0%d\n",dat3);
            }
        }
}