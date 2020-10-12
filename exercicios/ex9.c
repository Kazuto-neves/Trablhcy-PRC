#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main(){
    setlocale(LC_ALL, "Portuguese");
    int i,j,d=0;
    float max,min,m[100],v=0;
    for (i = 0; i<100; i++){
        printf("Digite um numero: ");
        scanf("%f",&m[i]);
        if(m[i]==0) break;
        j++;
        }
        max=m[0];
        min=m[0];
    for (i = 1; i <j; i++){
        if (m[i]>max) max=m[i];
        else if(m[i]<min) min=m[i];
    }
    for (i = 0; i <j; i++){
        if(m[i]!=0&&min!=m[i]&&max!=m[i]){
            v+=(m[i]);
            d++;
            }
        }
    printf("extremos: %g e %g (%g é menor valor e %g é o maior valor)\n",min,max,min,max); 
    printf("media : %g\n",v/d);
    return 0;
}