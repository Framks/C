/*
    fuções que estão em struct_hospede.c
        arquivo que cuida das funções de hospede
*/
#ifndef HOSPEDE_H
#define HOSPEDE_H
typedef struct{
    int id;
    int usando_quarto;
    char nome[50];
    char email[50];
    char cpf[14];
    char data_nascimento[15];
    char celular[16];
    char outros[50];
}hospede;

hospede le_hospede();
void inserir_hospospede();
void listar_hospede();
void excluir_hospede();

#endif