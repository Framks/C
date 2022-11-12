/*
Três esquilos gêmeos brincavam num toquinho de árvore quando de repente aparece uma raposa faminta. A raposa pula de um sopapo, encara e encurrala os três e eles percebem que não háverá fuga para todos. Alguém vai acabar morrendo naquele encontro.

O maior Esquilo, Alfredo, puxa o papo com a Raposa.
- Dona Raposa, vejo que és uma só, enquanto nós somos 3. Sei que estás com fome. Se corrermos cada um para um lado diferente, não conseguirás pegar os três, mas certamente pegará um de nós. Para não deixar a decisão em vossa mão, permita que decidamos qual de nós vai morrer, e então poderá saborear seu almoço sem fazer esforço.

A raposa em choque decidiu esperar para ver como os irmãos iam decidir quem ia morrer. Porque ela sabia que pelo menos um morreria ali.

Os irmãos tentaram todos os critérios de decisão, mas nunca chegaram em um veredito. Morre o menor, morre o maior, morre o mais peludo, morre o mais dentuço.

A Raposa se meteu e tentou ajudar.
- Se vocês ficarem bem esticadinhos e juntinhos no chão eu meço vocês da cauda à orelha e a gente descobre quem é o médio. O menor e o maior poderão ir embora.

Os esquilos ficaram juntinhos e bem esticadinhos. A raposa foi lá e numa bocada mordeu os três.

Moral da história: Não confie em pessoas que tem claramente interesses diferentes dos seus quando elas quiserem te ajudar.

Ação
Receba três valores e imprima o valor do meio.


Entrada e Saída
Entrada:

Os três valores, uma por linha, todos os valores serão diferentes.
Saída:

O valor do meio.
Exemplos
>>
5
2
4
<<
4
*/

#include <stdio.h>

int main(){
    int num1, num2, num3;
    scanf("%d %d %d",&num1, &num2, &num3);
    if((num1 > num2 && num1 < num3) || (num1<num2 && num1>num3)){
        printf("%d",num1);
    }else if((num2>num1 && num2<num3) || (num2<num1 && num2>num3)){
        printf("%d",num2);
    }else{
        printf("%d",num3);
    }
}