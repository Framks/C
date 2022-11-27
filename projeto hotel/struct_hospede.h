#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern void listar_quartos_vagos();
extern void listar_quartos();
extern void despejar_hospede();

typedef struct
{
    /* 
        aqui vai ficar a estrutura de quarto para o projeto
    */
    int id;
    int usando_quarto;
    char nome[50];
    char email[50];
    int cpf;
    int data_nascimento;
    int celular;
    char outros[50];
}hospede;


hospede le_hospede()
{
    /*
        esta função serve exclusivamente para ler um hospede e retorna ele pra outras funções
    */
    hospede h;
    scanf("digite o nome do hospede e ao final de enter: %[^\n]",h.nome);
    scanf("digite o email do hospede: %[^\n]",h.email);
    scanf("digite os 11 digitos do cpf do hospede: %d",&h.cpf);
    scanf("digite a data de nascimento do hospede (apenas digitos): %d",&h.data_nascimento);
    scanf("digite o numero do hospede: %d",&h.celular);
    listar_quartos_vagos();
    scanf("\nEscolha um dos quartos para o hospede: %d",&h.usando_quarto);
    scanf("se tiver algum complemento ou especificidade(se nao digite 0): %[^\n]",h.outros);

    return h;
}

void inserir_hospede()
{
    /*
        essa parte da função cuida da leitura de todo o arquivo hospede.txt para guardar em um vetor 
    */
    hospede y, *vetor;
    int n=1;
    FILE *f = fopen("hospede.txt","r");
    while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%d\n%d\n%d\n%[^\n]",&y.id,&y.usando_quarto,y.nome,y.email,&y.cpf,&y.data_nascimento,&y.celular,y.outros) == 8)
    {
        vetor = (hospede*)realloc(vetor, n * sizeof(hospede));
        vetor[n-1] = y;
        n++;
    }
    fclose(f);

    /*
        essa parte cuida de acresentar mais 1 hospede no caso o novo
    */
    FILE *ff = fopen("hospede.txt","w");

    vetor = (hospede*)realloc(vetor, n * sizeof(hospede));

    vetor[n-1] = le_hospede();

    for(int a=0;a<n;a++)
    {
        fprintf(ff,"%d\n",vetor[a].id);
        fprintf(ff,"%d\n",vetor[a].usando_quarto);
        fprintf(ff,"%s\n",vetor[a].nome);
        fprintf(ff,"%s\n",vetor[a].email);
        fprintf(ff,"%d\n",vetor[a].cpf);
        fprintf(ff,"%d\n",vetor[a].data_nascimento);
        fprintf(ff,"%d\n",vetor[a].celular);
        fprintf(ff,"%s\n",vetor[a].outros);
    }
    fclose(ff);
}

void listar_hospede()
{
    printf("ID |      Nome    |     email      |    cpf   |  data de nascimeto  |    contato   |   quarto  | outras informacoes|\n");
}

void excluir_hospede()
{
    int a;
    listar_hospede();
    printf("digite o id do hospede a ser excluido: ");
    scanf("%d",&a);
    printf("o hospede de id %d sera excluido do sistema.",a);
    scanf("%d",&a);
}