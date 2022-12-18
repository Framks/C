#include <stdio.h>
#include "hospede.h"
#include "quartos.h"

void quartos()
{
    /*
        listar de imediato os quartos vagos e ocupados
    */
    int i=1, a,b;
    while (i)
    {
        system("cls");                          // limpar tela
        printf("[0] Volta ao menu principal.\n[1] listar os quartos vagos.\n[2] Listar todos os quartos.\n[3] Despejar hospede\n[4] Hospedar cliente cadastrado\n");
        scanf("%d",&i);
        switch(i)
        {
            case 0:
                break;
            case 1:
                listar_quartos_vagos();
                printf("tecle enter para voltar ao menu! ");
                getchar();
                getchar();
                break;
            case 2:
                listar_quartos();
                printf("tecle enter para voltar ao menu! ");
                getchar();
                getchar();
                break;
            case 3:
                despejar_hospede();
                printf("tecle enter para voltar ao menu! ");
                getchar();
                getchar();
                break;
            case 4:
                listar_hospede();
                listar_quartos_vagos();
                printf("digite o id do usuario e o numero do quarto, respectivamente: ");
                scanf("%d %d",&a,&b);
                if((a && b) !=0)
                {
                    alocar_quarto(a,b);
                }else{
                    printf("por favor digite um numero diferente de 0");
                }
                break;
            default:
                printf("nao foi dessa vez.\ndigite 0 e confirme para voltar para o menu!\n");
                getchar();
                getchar();
            break;
        }
    }
}

void hospedes()
{
    /* 
        listar os hospedes que estão cadastrados no sistema
    */
    int i;
    while(i)
    {
        /*
            menu do hospede onde se cadastra, exclui e lista os hospedes
        */ 
        system("cls");
        printf("[0] Voltar ao Menu.\n[1] Cadastrar novo hospede.\n[2] Listar hospedes cadastrados.\n[3] Excluir hospede.\n");
        scanf("%d",&i);
        switch(i)
        {
            case 0:
                break;
            case 1:
                inserir_hospede();
                printf("tecle enter para ir ao menu: ");
                getchar();
                getchar();
                break;
            case 2:
                listar_hospede();
                printf("tecle enter para ir ao menu: ");
                getchar();
                getchar();
                break;
            case 3:
                excluir_hospede();
                printf("tecle enter para ir ao menu: ");
                getchar();
                getchar();
                break;
            default:
                printf("nao foi dessa vez.\ndigite 0 e confirme para voltar para o menu!\n");
                printf("tecle enter para ir ao menu: ");
                getchar();
                getchar();
            break;
        }
    }
}

int main()
{
    int rodar_menu=1;
    system("cls");                  // limpar tela de saida
    while (rodar_menu)
    {
        printf("|---------------------------------------------|\n|            Bem vindo ao programa            |\n|              Hotel Phoenix                  |\n|---------------------------------------------|\n");
        printf("\nEste \x82 o programa do hotel onde voc\x88 pode ver \nas disponibilidade dos quartos,\nos h\xa2spedes e cadastralos excluirem.\n\n");
        printf("para navegar no menu de op\x87oes\n");
        printf("digite o numero correspondente da\n");
        printf("op\x87\x83o\n\n");
        printf("[0] Sair\n[1] Quarto.\n[2] Hospedes.\n");
        scanf(" %d",&rodar_menu);

        switch (rodar_menu)
        {
            /*
                caso 0 ele não retorna nada e sai do menu
            */
        case 0:
            break;
        case 1:
            quartos();
        	break;
        case 2:
            hospedes();
        	break;
        default:
            printf("nao foi dessa vez.\ndigite 0 e confirme para voltar para o menu!");
            getchar();
            getchar();
            break;
        }
    }
    system("cls");
    printf("\t\t\t|-------------------------|\n");
    printf("\t\t\t|         The             |\n");
    printf("\t\t\t|            End          |\n");
    printf("\t\t\t|                         |\n");
    printf("\t\t\t|     Program Credits     |\n");
    printf("\t\t\t|          Dev's:         |\n");
    printf("\t\t\t|                         |\n");
    printf("\t\t\t|     Guilherme Lessa     |\n");
    printf("\t\t\t|      Maria Beatriz      |\n");
    printf("\t\t\t|    Francisco Gabriel    |\n");
    printf("\t\t\t|-------------------------|");
}
