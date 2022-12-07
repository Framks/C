#include "hospede.h"
#include "quartos.h"
#include <stdio.h>
#include <stdlib.h>
 
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
    printf("digite o numero do quarto a ser vago: ");
    scanf("%d",&aux);
    if(aux !=0){
        int n=1;
        hospede *vetor = 0,y;
        FILE *f = fopen("hospede.txt","r");
        while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&y.id,&y.usando_quarto,y.nome,y.email,y.cpf,y.data_nascimento,y.celular,y.outros) == 8)
        {
            vetor = (hospede*)realloc(vetor, n*sizeof(hospede));
            vetor[n-1] = y;
            n++;
        }
        n--;
        for ( int i = 0;vetor[i].nome; i++)
        {
            if(vetor[i].usando_quarto == aux)
            {
                printf("o quarto de numero %d sera vago e o hospede %s sera despejado \n",aux, vetor[i].nome);
                break;
            }
        }
        fclose(f);
        for (int i=0;i<n;i++)
        {
            if (vetor[i].usando_quarto==aux)
            {
                vetor[i].usando_quarto = 0;
                desalocar_quarto(vetor[i].id);
            }
        }
        
        FILE *ask = fopen("hospede.txt","w");
        for(int a=0;a<n;a++)
        {
            fprintf(ask,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n",vetor[a].id,vetor[a].usando_quarto,vetor[a].nome,vetor[a].email,vetor[a].cpf,vetor[a].data_nascimento,vetor[a].celular,vetor[a].outros);
        }
        fclose(ask);
    }
}

void alocar_quarto(int id_usuario, int id_quarto)
{
    quarto *q=0, a;
    int n=1;
    FILE *jj = fopen("quarto.txt","r");
    while (fscanf(jj,"%d %c %d",&a.id,&a.status,&a.hospede_atual) == 3)
    {
        q = (quarto*) realloc(q, n * sizeof(quarto));
        q[n-1] = a;
        n++; 
    }
    for(int i =0; i<(n-1);i++){
        if(q[i].id == id_quarto)
        {
            q[i].status = 'o';
            q[i].hospede_atual = id_usuario;
            break;
        }
    }
    fclose(jj);

    FILE *as = fopen("quarto.txt","w");
    for(int i=0;i<n-1;i++)
    {
        fprintf(as,"%d %c %d\n",q[i].id,q[i].status,q[i].hospede_atual);
    }
    fclose(as);

    hospede *vetor = 0,h;
    n = 1;
    FILE *f = fopen("hospede.txt","r");
    while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&h.id,&h.usando_quarto,h.nome,h.email,h.cpf,h.data_nascimento,h.celular,h.outros) == 8)
    {
        vetor = (hospede*)realloc(vetor, n*sizeof(hospede));
        vetor[n-1] = h;
        n++;
    }
    n--;
    for(int i=0;i<n;i++)
    {
        if(vetor[i].id == id_usuario)
        {
            vetor[i].usando_quarto = id_quarto;
            break;
        }
    }
    fclose(f);
    FILE *ff = fopen("hospede.txt","w");
    for (int a = 0; a < n; a++)
    {
        fprintf(ff,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n",vetor[a].id,vetor[a].usando_quarto,vetor[a].nome,vetor[a].email,vetor[a].cpf,vetor[a].data_nascimento,vetor[a].celular,vetor[a].outros);
    }
    fclose(ff);    
    free(q);
}

void desalocar_quarto(int a)
{
    quarto *q=0, h;
    int n=1;
    FILE *jj = fopen("quarto.txt","r");
    while (fscanf(jj,"%d %c %d",&h.id,&h.status,&h.hospede_atual) == 3)
    {
        q = (quarto*) realloc(q, n * sizeof(quarto));
        q[n-1] = h;
        n++; 
    }
    n--;
    fclose(jj);
    for(int i=0;i<n;i++)
    {
        if(q[i].hospede_atual==a)
        {
            q[i].status = 'd';
            q[i].hospede_atual = 0;
            break;
        }
    }
    FILE *qua = fopen("quarto.txt","w");
    for(int i=0;i<n;i++)
    {
        fprintf(qua,"%d %c %d\n",q[i].id,q[i].status,q[i].hospede_atual);
    }
    fclose(qua);
}