#include <stdio.h>
#include "struct_hospede.h"
#include "struct_dis_quarto.h"

void quartos()
{
    /*
        listar de imediato os quartos vagos e ocupados
    */
    int i=1,erro;
    while (i)
    {
        system("cls");
        printf("[0] Volta ao menu principal.\n[1] listar os quartos vagos.\n[2] Listar todos os quartos.\n[3] Despejar hospede\n");
        scanf("%d",&i);
        switch(i)
        {
            case 0:
                break;
            case 1:
                listar_quartos_vagos();
                scanf("%d",&erro);
                break;
            case 2:
                listar_quartos();
                scanf("%d",&erro);
                break;
            case 3:
                despejar_hospede();
                scanf("%d",&erro);
                break;
            default:
                printf("nao foi dessa vez.\ndigite 0 e confirme para voltar para o menu!\n");
                scanf("%d",&erro);
            break;
        }
    }
}

void hospedes()
{
    /* 
        listar os hospedes que estão cadastrados no sistema
    */
    int i,erro;
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
                scanf("digite 1 para continuar: %d",&erro);
                break;
            case 2:
                listar_hospede();
                scanf("%d",&erro);
                break;
            case 3:
                excluir_hospede();
                break;
            default:
                printf("nao foi dessa vez.\ndigite 0 e confirme para voltar para o menu!\n");
                scanf("%d",&erro);
            break;
        }
    }
}

int main()
{
    int rodar_menu=1,erro=0;
    system("cls");
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
            scanf("%d",&erro);
            break;
        }
    }
    return 1;
}
