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
    char cpf[11];
    char data_nascimento[8];
    char celular[11];
    char outros[50];
}hospede;


hospede le_hospede()
{
    /*
        esta função serve exclusivamente para ler um hospede e retorna ele pra outras funções
    */
    hospede h;
    printf("digite o nome do hospede e ao final de enter: ");
    scanf(" %[^\n]",h.nome);

    printf("digite o email do hospede: ");
    scanf(" %[^\n]",h.email);

    printf("digite os 11 digitos do cpf do hospede: ");
    scanf(" %[^\n]",h.cpf);

    printf("digite a data de nascimento do hospede (apenas digitos): ");
    scanf(" %[^\n]",h.data_nascimento);

    printf("digite o numero do hospede: ");
    scanf(" %[^\n]",h.celular);

    listar_quartos_vagos();
    printf("\nEscolha um dos quartos para o hospede: ");
    scanf("%d",&h.usando_quarto);

    printf("se tiver algum complemento ou especificidade(se nao digite 0): ");
    scanf(" %[^\n]",h.outros);

    return h;
}

void inserir_hospede()
{
    /*
        essa parte da função cuida da leitura de todo o arquivo hospede.txt para guardar em um vetor 
    */

    hospede y, *vetor;
    int n = 1,idmaior =0;
    FILE *f = fopen("hospede.txt","r");
    while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n",&vetor[n-1].id,&vetor[n-1].usando_quarto,vetor[n-1].nome,vetor[n-1].email,vetor[n-1].cpf,vetor[n-1].data_nascimento,vetor[n-1].celular,vetor[n-1].outros) == 8)
    {
        n++;
        vetor = (hospede *)realloc(vetor, n * sizeof(hospede));
        if(y.id <= idmaior)
        {
            idmaior = y.id;
        }
    }
    vetor[n-1] = le_hospede();
    vetor[n-1].id = idmaior + 1;
    fclose(f);
    /*
        essa parte cuida de acresentar mais 1 hospede no caso o novo
    */

    FILE *ff = fopen("hospede.txt","w");
    for(int a=0;a<n;a++)
    {
        fprintf(ff,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n",(vetor[a]).id,(vetor[a]).usando_quarto,(vetor[a]).nome,(vetor[a]).email,(vetor[a]).cpf,(vetor[a]).data_nascimento,(vetor[a]).celular,(vetor[a]).outros);
    }
    fclose(ff);
    alocar_quarto(idmaior,vetor[n-1].usando_quarto);
}

void listar_hospede()
{
    hospede y;
    FILE *f = fopen("hospede.txt","r");
    printf("ID |      Nome    |       email      |    cpf   |  data de nascimeto  |    contato   |quarto| outras informacoes|\n");
    while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&y.id,&y.usando_quarto,y.nome,y.email,y.cpf,y.data_nascimento,y.celular,y.outros) == 8)
    {
        printf(" %d |%s| %s|%s|%s|%s|   %d  |",y.id,y.nome,y.email,y.cpf,y.data_nascimento,y.celular,y.usando_quarto);
        if (y.outros == '0')
        {
            printf("|                   |\n");
        }else
        {
            printf("%s\n",y.outros);
        }
    }
    fclose(f);
}

void excluir_hospede()
{
    int a;
    listar_hospede();
    printf("digite o id do hospede a ser excluido: ");
    scanf("%d",&a);
    printf("o hospede de id %d sera excluido do sistema. para confirmar digite\n novamente o numro do id: ",a);
    scanf("%d",&a);
    if(a)
    {
        hospede *vetor;
        int n=1;
        FILE *f = fopen("hospede.txt","w");
        while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n\n%[^\n]\n%[^\n]\n%[^\n]",&vetor[n-1].id,&vetor[n-1].usando_quarto,vetor[n-1].nome,vetor[n-1].email,vetor[n-1].cpf,vetor[n-1].data_nascimento,vetor[n-1].celular,vetor[n-1].outros) == 8)
        {
            n++;
            vetor = (hospede*)realloc(vetor, n*sizeof(hospede));
        }
        n--;
        for (int i = 0; i < n; i++)
        {
            if(vetor[i].id==a)
            {
                vetor[i] = vetor[n-1];
                break;
            }
        }
        vetor = (hospede*) realloc(vetor,(n-1) * sizeof(hospede));
        FILE *ff = fopen("hospede.txt","w");
        for(int i = 0;i<(n-1);i++)
        {
            fprintf(ff,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n",(vetor[a]).id,(vetor[a]).usando_quarto,(vetor[a]).nome,(vetor[a]).email,(vetor[a]).cpf,(vetor[a]).data_nascimento,(vetor[a]).celular,(vetor[a]).outros);
        }
        fclose(ff);
    }
}