/*
Motivação
Margarida Maria levantou Gislene com carinho. Olhou nos olhos da penosa e disse.

- 4 ovinhos hoje ein! Pense Gislene, que hoje eu vou comer um super omeletão.

Ainda olhando pra penosa, sentiu dor e remorso. O olhar de Gislene parecia dizer:

- Você realmente vai comer meus filhinhos?.

Mas a fome era mais forte que o remorso.

Então como que procurando uma solução pro doloroso conflito entre consciência

empática e fome, decidiu comer só o ovo maiorzinho.

Ação
Leia 4 números e imprima o maior valor.

Entrada e Saída
Leia quatro valores inteiros do usuário.
Imprima o maior valor lido.
Exemplos
>>
3
3
2
2
<<
3
*/

#include <stdio.h>

int main(){
    int v1, v2, v3, v4, maior;
    scanf("%d %d %d %d", &v1, &v2, &v3, &v4);
    
    if(v1 > v2 && v1 > v3 && v1 > v4){
        maior = v1;
    }else if(v2>v3 && v2 >v4){
        maior = v2;
    }else if(v3 > v4){
        maior = v3;
    }else{
        maior = v4;
    }
    printf("%d", maior);
}