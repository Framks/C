/*Motivação
Quem nunca numa prova de matemática ou física no ensino médio escutou um coleguinha dizer: "Professor, pode usar a calculadora?" atire a primeira pedra.

Ação
Leia dois números inteiros e um símbolo e imprima o resultado.

I/O
Leia do usuário dois valores inteiro um operador em caráter ('+', '-', '*' ou '/')
Imprima o resultado da operação em inteiro. Se a operação não pode ser realizada, imprima a string "invalida".
Exemplos
>>
5
2
/
<<
2
*/

#include <stdio.h>

int main(){
    // variaveis que reseberao os valores para as operações
    int valor1, valor2, resultado = 0;
    // variavel que resebera o argumento da condição para a operação
    char caracter;
    // entrada que vai receber dois valores inteiros e um determinante da operação
    scanf("%d %d %c", &valor1, &valor2, &caracter);
    if(caracter == '-' || caracter == '+' || caracter == '*' || caracter == '/'){
        switch(caracter){
            case '+':
                resultado = valor1 + valor2;
            break;
            case '-':
                resultado = valor1 - valor2;
            break;
            case '*':
                resultado = valor1 * valor2;
            break;
            case '/':
                if(valor2>0){
                    resultado = valor1 / valor2;
                }else{
                    caracter = 's';
                }
            break;
        }
        if(caracter != 's'){
            printf("%d",resultado);
        }else{
            printf("invalida");
        }
    }else{
        printf("invalida");
    }
}