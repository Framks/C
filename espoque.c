/*
espoque palindromo
#include <stdio.h>

int main(){
    int num, reverso=0, test;
    scanf("%d",&num);
    test = num;
    while(num!=0){
        reverso = (reverso*10)+(num%10);
        num = num/10;
    }
    if(test == reverso){
        printf("1");
    }else{
        printf("0");
    }
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
#include <stdio.h>

void main(){
    char v[102];
    scanf("%[^\n]",v);
    for(int i=1;v[i];i++){
        if(v[i]== ' ' && v[i-1] == v[i+1]){
            v[i] = '0';
            v[i-1] = '0';
        }
    }
    for(int i=0;v[i];i++){
        if(v[i]!='0'){
            printf("%c",v[i]);
        }
    }
}
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


#include <stdio.h>

int unhas(int value,int digito){
    return ((value*10)+digito);
}

void main(){
    int quan,number=0;
    scanf("%d",&quan);
    int v[quan];
    for(int i=0;i<quan;i++){
        scanf("%d",&v[i]);
    }
    for(int i=0;i<quan;i++){
        number=unhas(number,v[i]);
    }
    printf("%d",number);
}
*/

#include <stdio.h>

typedef struct {
   int matricula;
   char nome[100];
   float media;
} aluno;

void alunos_para_arquivo(aluno turma[], int n)
{
   FILE *f = fopen("alunos.txt","w");
   if(f==0)
   {
        printf("Erro ao abrir o arquivo.");
   }
   for(int i=0;i<n;i++)
   {
       fprintf(f,"%d\n%s\n%.1f\n",turma[i].matricula,turma[i].nome,turma[i].media);
   }
   
   fclose(f);
}

void imprime_alunos_arquivo()
{
   FILE *f = fopen("alunos.txt","r");
   if(f==0)
   {
       printf("Erro ao abrir arquivo.");
   }
   aluno a;
   while(fscanf(f,"%d\n%[^\n]\n%f",&a.matricula,a.nome,&a.media) == 3)
   {
       printf("%s\n",a.nome);
   }
   fclose(f);
}

int main()
{
   int n, i;
   scanf("%d\n", &n);
   aluno turma[n], a;

   for (i = 0; i < n; i++) {
       scanf("%d\n%[^\n]\n%f", &a.matricula, a.nome, &a.media);
       turma[i] = a;
   }
   alunos_para_arquivo(turma, n);
   imprime_alunos_arquivo();
}