/*
Motivação
Os administradores da Fazenda Fartura planejam criar uma nova plantação de morangos, no formato retangular. Eles têm vários locais possíveis para a nova plantação, com diferentes dimensões de comprimento e largura. Para os administradores, o melhor local é aquele que tem a maior área. Eles gostariam de ter um programa de computador que, dadas as dimensões de dois locais, determina o que tem maior área. Você pode ajudá-los?

Entrada
A entrada contém quatro linhas, cada uma contendo um número inteiro. As duas primeiras linhas indicam as dimensões (comprimento e largura) de um dos possíveis locais. As duas últimas linhas indicam as dimensões (comprimento e largura) de um outro possível local para a plantação de morangos. As dimensões são dadas em metros.
Saída
Seu programa deve escrever uma linha contendo um único inteiro, a área, em metros quadrados, do melhor local para a plantação, entre os dois locais dados na entrada.
Restrições
1 ≤ comprimento ≤ 100
1 ≤ largura ≤ 100
Exemplos
>>>>>>>>
30
8
11
56
========
616
<<<<<<<<

>>>>>>>>
12
38
5
20
========
456
<<<<<<<<
*/
#include <stdio.h>

int main(){
    int xa, xb, ya, yb, areax, areay;
    scanf("%d %d %d %d", &xa, &xb, &ya, &yb);
    if(xa<1 || xa>100 || xb<1 || xb>100 || ya<1 || ya>100 || yb<1 ||yb>100){
        
    }else{
        areax = (xa*xb);
        areay = (ya*yb);
        if(areax > areay){
            printf("%d\n",areax);
        }else{
            printf("%d\n",areay);
        }
    }
}