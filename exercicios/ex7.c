#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome [30];
    float n1,n2,media;
}fAluno;

int compMedia(const void *fa,const void *fb){
    fAluno a = *(fAluno*)fa;
    fAluno b = *(fAluno*)fb;
    return ( b.media-a.media );
}
void lerD (fAluno n[], int N){
    int i;
    printf("Dados: nome,nota1,nota2\n");
    for (i=0;i<N; i++){
        printf("\nDigite o nome(%i): ",i+1);
        scanf("%s",n[i].nome);
        printf("\nDigite nota 1(%i): ",i+1);
        scanf("%f",&n[i].n1);
        printf("\nDigite o nota 2(%i): ",i+1);
        scanf("%f",&n[i].n2);
        printf("------------------------------\n");
    }   
}
void calMedia(fAluno n[], int N){
    int i;
    for (i=0;i<N; i++){
        n[i].media=(n[i].n1+(2*n[i].n2)/3);
        }
    }
void mostrarD(fAluno n[], int N){
    int i;
    for(i=0; i<N; i++)
	   printf("%-20s %05.2f\n",n[i].nome,n[i].media);
	printf("\n\n\n");
}
int main(void) {
	fAluno alunos[100];
    int N;
    printf("Digite quantos alunos tem na turma: ");
    scanf("%d",&N);
	lerD(alunos,N);
    calMedia(alunos,N);
	qsort(alunos, N, sizeof(fAluno), compMedia);
    mostrarD(alunos,N);
	return 0;
}

