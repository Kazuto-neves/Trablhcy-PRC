#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define stri 30
#define alu 100

typedef struct{
    char nome [stri];
    double n1,n2, media;
    
}faluno;

int compMedia(const void *fa,const void *fb){
    faluno a = *(faluno*)fa;
    faluno b = *(faluno*)fb;
    return ( b.media-a.media );
}

double media(double medialuno [alu], int n){
    int i;
    double soma ;
    for( i = 0; i < n; i++ ) soma += medialuno[i];
    return soma/n;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    faluno alunos[alu];
    faluno todos[alu];
    double medialuno[alu];
    char alunome[stri];
    int n,i,c=0;
    double mediat;
    printf("quantos alunos são: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("nome do aluno(a):");
        scanf(" %[^\n]",  alunos[i].nome);
        printf("nota1: ");
        scanf("%lf", &alunos[i].n1);
        printf("nota2: ");
        scanf("%lf", &alunos[i].n2);
    } 
    qsort(alunos, n, sizeof(faluno), compMedia);
      for(i=0;i<n;i++){
         medialuno[i]=((alunos[i].n1+(2*alunos[i].n2))/3);
      }
      mediat=media( medialuno, n);
      for(i=0;i<n;i++){
         if(medialuno[i]>mediat){
             todos[c]=alunos[i];
             todos[c].media=medialuno[i];
             c++;
         }
      }
     //for(i=0;i<n;i++) printf("%-20s %05.2f %05.2f %05.2f %05.2lf\n", alunos[i].nome, alunos[i].n1, alunos[i].n2,alunos[i].media ,mediat);
    printf("---------------------------------------------------------------------------------\n");
    printf("Média da turma: %05.2lf\n", mediat);
    printf("Nome                 Nota1 Nota2 Media\n");
    for(i=0;i<c;i++) printf("%-20s %05.2f %05.2f %05.2f %05.2lf\n", todos[i].nome,todos[i].n1, todos[i].n2,todos[i].media ,mediat);
    
    return 0;
}