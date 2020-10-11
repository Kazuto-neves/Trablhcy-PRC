#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
    for (i=0;i<N; i++){
        setbuf(stdin,NULL);
        printf("\nDigite o nome: ");
        gets(n[i].nome);
        printf("\nDigite nota 1(%s): ",n[i].nome);
        scanf("%f",&n[i].n1);
        printf("\nDigite o nota 2(%s): ",n[i].nome);
        scanf("%f",&n[i].n2);
        printf("------------------------------\n");
        setbuf(stdin,NULL);
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
    setlocale(LC_ALL, "Portuguese");
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