/*
    funões que estão em struct_dis_quarto.c
        arquivo que cuida das funções de quarto
*/
#ifndef QUARTOS_H
#define QUARTOS_H
typedef struct
{
    int id;
    char status;
    int hospede_atual;
}quarto;
void listar_quartos_vagos();
void listar_quartos();
void despejar_hospede();
void alocar_quarto(int id_usuario,int id_quarto);
void desalocar_quarto(int a);
#endif 