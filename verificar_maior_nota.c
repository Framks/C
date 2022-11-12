#include <stdio.h>

int main(){
    printf("----------------------\nBem vindo ao progama\n");
    printf("esse programa e capaz:\n");
    printf("de dado um id e um\n");
    printf("numero de notas saber\n");
    printf("saber quem tem a maior\n");
    printf("nota.\n");
    printf("vc so tem que digitar\n");
    printf("Ex: \n4 que é numero alunos\n");
    printf("dois digitos que e o id\n");
    printf("e por fim as notas\n4\n04987 03887 02657 01485\nesse e o exemplo\n");
    int n;
    scanf("%d",&n);
    char v[102];
    int soma=0, ms=0,id=0,mid=0,i,a;
    for(i=0;i<n;i++){
        scanf("%s",v);
        for(a=2;v[a];a++){
            soma = (soma + (v[a]-48));
            id = (v[0]-48)*10 + (v[1]-48);
            if(soma> ms || (soma == ms && id > mid)){
                ms = soma;
                mid = id;
            }
        }
        soma =0;
        id = 0;
    }
    if(mid<10){
		printf("o id com maior nota e:0%d",mid);
	}else{
		printf("o id com mior nota e:%d",mid);
	}
}
