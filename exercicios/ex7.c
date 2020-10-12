#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char nome [30];
    float n1,n2,media,acima,baixo;
    
}faluno;

int compMedia(const void *fa,const void *fb){
    faluno a = *(faluno*)fa;
    faluno b = *(faluno*)fb;
    return ( b.media-a.media );
}
int main(void) {
    setlocale(LC_ALL, "Portuguese");
    faluno alunos[100];
    faluno todos[100];
    faluno abaixo[100];
    int n,i,c=0,d=0;
    double mediat;
    printf("quantos alunos são: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        setbuf(stdin,NULL);
        printf("nome do aluno(a):");
        //scanf("%s",  alunos[i].nome);
        gets(alunos[i].nome);
        printf("nota1: ");
        scanf("%f", &alunos[i].n1);
        printf("nota2: ");
        scanf("%f", &alunos[i].n2);
        setbuf(stdin,NULL);
    }
      for(i=0;i<n;i++){
          alunos[i].media=((alunos[i].n1+(2*alunos[i].n2))/3);
          mediat+=alunos[i].media/n;
      }
      qsort(alunos, n, sizeof(faluno), compMedia);
      for(i=0;i<n;i++){
         if(alunos[i].media>mediat){
             todos[c].media = alunos[i].media;
             strcpy(todos[c].nome, alunos[i].nome);
             todos[c].n1 = alunos[i].n1;
             todos[c].n2 = alunos[i].n2;
             c++;
         }//else{
             //abaixo[d].media = alunos[i].media;
             //strcpy(abaixo[d].nome, abaixo[i].nome);
             //abaixo[d].n1 = alunos[i].n1;
            // abaixo[c].n2 = alunos[i].n2;
             //d++;
             
         //}
      }
      printf("Media da turma: %05.2lf\n",mediat);
      printf("----------------------------------------\n");
      printf("|nome               |nota1|nota 2|media|\n");
      printf("----------------------------------------\n");
     for(i=0;i<n;i++) printf("|%-20s|%05.2f|%05.2f|%05.2f|\n", alunos[i].nome, alunos[i].n1, alunos[i].n2,alunos[i].media);
    printf("----------------------------------------\n\n");
    printf("os alunos acima da media da turma = %05.2lf\n",mediat);
    printf("----------------------------------------\n");
    printf("|nome               |nota1|nota 2|media|\n");
    printf("----------------------------------------\n");
    for(i=0;i<c;i++) printf("|%-20s|%05.2f|%05.2f|%05.2f|\n", todos[i].nome,todos[i].n1, todos[i].n2,todos[i].media);
    printf("----------------------------------------\n");
    return 0;
}