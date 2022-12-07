#include "quartos.h"
#include "hospede.h"
#include <stdio.h>
#include <stdlib.h>

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

    hospede h,*vetor = 0;
    int n = 1,idmaior =0;
    FILE *f = fopen("hospede.txt","r");
    while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&h.id,&h.usando_quarto,h.nome,h.email,h.cpf,h.data_nascimento,h.celular,h.outros) == 8)
    {
        if(h.id >= idmaior)
        {
            idmaior = h.id;
        }
        vetor = (hospede *)realloc(vetor, n * sizeof(hospede));
        vetor[n-1] = h;
        n++;
    }
    fclose(f);
    vetor = (hospede*) realloc(vetor, n * sizeof(hospede));
    vetor[n-1] = le_hospede();
    idmaior +=1;
    vetor[n-1].id = idmaior ;
    /*
        essa parte cuida de acresentar mais 1 hospede no caso o novo
    */

    FILE *hos = fopen("hospede.txt","w");
    for(int a=0;a<n;a++)
    {
        fprintf(hos,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n",vetor[a].id,vetor[a].usando_quarto,vetor[a].nome,vetor[a].email,vetor[a].cpf,vetor[a].data_nascimento,vetor[a].celular,vetor[a].outros);
    }
    fclose(hos);
    alocar_quarto(idmaior,vetor[n-1].usando_quarto);
    free(vetor);
}

void listar_hospede()
{
    hospede y;
    FILE *f = fopen("hospede.txt","r");
    system("cls");
    while (fscanf(f," %d %d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&y.id,&y.usando_quarto,y.nome,y.email,y.cpf,y.data_nascimento,y.celular,y.outros) == 8)
    {
        printf("Id: %d\n",y.id);
        printf("Nome: %s\n",y.nome);
        printf("Email: %s\n",y.email);
        printf("Cpf: %s\n",y.cpf);
        printf("Data de nascimento: %s\n",y.data_nascimento);
        printf("Celular: %s\n",y.celular);
        printf("Quarto usado: %d\n",y.usando_quarto);
        if (y.outros[0] == '0')
        {
            printf("sem informacoes adicionais.\n");
        }else
        {
            printf("Infomacoes adicionais: %s\n",y.outros);
        }
        printf("=====================================\n");
    }
    fclose(f);
}

void excluir_hospede()
{
    int a;
    listar_hospede();
    printf("digite o id do hospede a ser excluido: ");
    scanf("%d",&a);
    if(a)
    {
        hospede *vetor =0,h;
        int n=1;
        FILE *f = fopen("hospede.txt","r");
        while (fscanf(f,"%d\n%d\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]",&h.id,&h.usando_quarto,h.nome,h.email,h.cpf,h.data_nascimento,h.celular,h.outros) == 8)
        {
            vetor = (hospede*)realloc(vetor, n*sizeof(hospede));
            vetor[n-1] = h;
            n++;
        }
        n--;
        fclose(f);
        for (int i = 0; i < n; i++)
        {
            if(vetor[i].id==a)
            {
                vetor[i] = vetor[n-1];
                break;
            }
        }
        vetor = (hospede*) realloc(vetor,(n-1) * sizeof(hospede));
        for (int i = 0; i < n-1; i++)
        {
            for (int ij = 1; ij < n-1; ij++)
            {
                if(vetor[ij].id<vetor[ij-1].id)
                {
                    h = vetor[ij-1];
                    vetor[ij-1] = vetor[ij];
                    vetor[ij] = h;
                }
            }
                  
        }
        FILE *ff = fopen("hospede.txt","w");
        for(int i = 0;i<(n-1);i++)
        {
            fprintf(ff,"%d\n%d\n%s\n%s\n%s\n%s\n%s\n%s\n",vetor[i].id,vetor[i].usando_quarto,vetor[i].nome,vetor[i].email,vetor[i].cpf,vetor[i].data_nascimento,vetor[i].celular,vetor[i].outros);
        }
        fclose(ff);
        desalocar_quarto(a);
        free(vetor);
    }
}