#include <stdio.h>
/*
inserir
excluir 
listar
*/
void quartos()
{
    int i;
    printf("Verificar os quartos disponiveis.");
    scanf("%d",&i);
}

void hospedes()
{
    int i;
    printf("Cadastrar novos hospedes.");
    scanf("%d",&i);
}

int main()
{
    int rodar_menu=1,erro=0;
    system("cls");
    while (rodar_menu)
    {
        /*
            [0] exit
            [1] verificar os quartos disponíveis
            [2] Disponibilizar quarto.
            [3] cadastrar novos hóspedes.
            [4] Excluir hóspedes.
            [5] verificar os hóspedes cadastrados.
        */
        printf("|---------------------------------------------|\n|            Bem vindo ao programa            |\n|              Hotel Phoenix                  |\n|---------------------------------------------|\n");
        printf("\nEste \x82 o programa do hotel onde voc\x88 pode ver \nas disponibilidade dos quartos,\nos h\xa2spedes e cadastralos excluirem.\n\n");
        printf("para navegar no menu de op\x87oes\n");
        printf("digite o numero correspondente da\n");
        printf("op\x87\x83o\n\n");
        printf("[0] Sair\n [1] Quarto.\n[2] Hospedes.\n");
        scanf(" %d",&rodar_menu);

        switch (rodar_menu)
        {
        case 1:
            setor_quarto();
        	break;
        
        case 2:
            setor_hospedes();
        	break;

        default:
            printf("nao foi dessa vez.\ndigite 0 e confirme para voltar para o meu!");
            scanf("%d",&erro);
            break;
        }
    }
    return 1;
}
