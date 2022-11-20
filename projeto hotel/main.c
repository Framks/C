#include <stdio.h>
/*
inserir
excluir 
listar
*/
void function1()
{
    int i;
    printf("Verificar os quartos disponiveis.");
    scanf("%d",&i);
}

void function2()
{
    int i;
    printf("Cadastrar novos hospedes.");
    scanf("%d",&i);
}

void function3()
{
    int i;
    printf("Verificar os hospedes cadastrados.");
    scanf("%d",&i);
}

int main()
{
    int rodar_menu=1;
    system("cls");
    while (rodar_menu)
    {
        printf("|---------------------------------------------|\n|            Bem vindo ao programa            |\n|              Hotel Phoenix                  |\n|---------------------------------------------|\n");
        printf("\nEste \x82 o programa do hotel onde voc\x88 pode ver \nas disponibilidade dos quartos,\nos h\xa2spedes e cadastralos excluirem.\n\n");
        printf("[0] Sair do aplicativo\n[1] verificar os quartos disponiveis.\n[2] Cadastrar novos hospedes.\n[3] Verificar os hospedes cadastrados.\n");
        scanf(" %d",&rodar_menu);

        switch (rodar_menu)
        {
        case 1:
            function1();
            system("cls");
        	break;
        
        case 2:
            function2();
            system("cls");
        	break;

        case 3:
            function3();
            system("cls");
        	break;
        
        default:
            printf("nao foi dessa vez.");
            system("cls");
            break;
        }
    }
    return 1;
}
