#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char j[50];
    printf("digite o numero do quarto a ser vago: ");
    scanf("%d",&aux);
    if(aux !=0){
        int n=1;
        hospede *vetor = 0,y;
        FILE *f = fopen("hospede.txt","w");
        while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&y.id,&y.usando_quarto,y.nome,y.email,y.cpf,y.data_nascimento,y.celular,y.outros) == 8)
        {
            vetor = (hospede*)realloc(vetor, n*sizeof(hospede));
            vetor[n-1] = y;
            n++;
        }
        for ( int i = 0;vetor[i].nome; i++)
        {
            if(vetor[i].usando_quarto == aux)
            {
                for (int a = 0; vetor[i].nome[a]; a++)
                {
                    j[a]=vetor[i].nome[a];
                }
                break;
            }
        }
        printf("o quarto de numero %d sera vago e o hospede %s sera despejado",aux, j);
        free(vetor);
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

    hospede *vetor = 0,y;
    n = 1;
    FILE *f = fopen("hospede.txt","r");
    while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&y.id,&y.usando_quarto,y.nome,y.email,y.cpf,y.data_nascimento,y.celular,y.outros) == 8)
    {
        vetor = (hospede*)realloc(vetor, n*sizeof(hospede));
        vetor[n-1] = y;
        n++;
    }

    for(int i=0;i<n;i++)
    {
        if(vetor[i].id == id_usuario)
        {
            vetor[i].usando_quarto = id_quarto;
            break;
        }
    }
    free(f);
    fclose(f);
    FILE *ff = fopen("hospede.txt","w");
    for (int a = 0; a < n; a++)
    {
        fprintf(ff,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n",(vetor[a]).id,(vetor[a]).usando_quarto,(vetor[a]).nome,(vetor[a]).email,(vetor[a]).cpf,(vetor[a]).data_nascimento,(vetor[a]).celular,(vetor[a]).outros);
    }
    fclose(ff);    
    free(q);
}