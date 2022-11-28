#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void listar_hospede();

typedef struct
{
    int id;
    char status;
    int hospede_atual;
} quarto;

void listar_quartos_vagos()
{
    /*
        lista os quartos disponiveis para alugar 
    */
    FILE *f = fopen("quarto.txt","r");
    quarto q;
    printf("Os quartos listados aqui sao os quartos vagos: \n");
    while(fscanf(f,"%d %c %d",&q.id, &q.status, &q.hospede_atual) == 3){
        if(q.status == 'd'){
            printf("%d ",q.id);
        }
    }
    printf("\n");
    fclose(f);
}

void listar_quartos()
{
    /*
        lista todos os quartos e os seus estados.
    */
    FILE *f = fopen("quarto.txt","r");
    quarto q;
    printf("Numero  |    estado   |    hospede   |\n");
    while(fscanf(f,"%d %c %d",&q.id, &q.status, &q.hospede_atual) == 3){
        printf("   %d    |",q.id);
        if(q.status == 'o')
        {
            printf("   ocupado   |");
            hospede y;
            FILE *ho = fopen("hospede.txt","r");
            while (fscanf(ho,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&y.id,&y.usando_quarto,y.nome,y.email,y.cpf,y.data_nascimento,y.celular,y.outros) == 8)
            {
                if (q.hospede_atual == y.id)
                {
                    printf("  %s  |\n",y.nome);
                }
                
            }
            fclose(ho);
        }else
        {
            printf(" desocupado  |              |\n");
        }
    }
    fclose(f);
}

void despejar_hospede()
{
    listar_quartos();
    int aux;
    char f = 'f';
    printf("digite o numero do quarto a ser vago: ");
    scanf("%d",&aux);
    FILE *f = fopen("hospede.txt","r");
    
    printf("o quarto de numero %d sera vago e o hospede %c sera despejado",aux, f);
}