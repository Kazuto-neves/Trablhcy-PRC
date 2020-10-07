#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n1,n2,m[100],i,j,s=0,r[100],s2=0,p2;
    printf("Digite o numero 1: ");
    scanf("%d",&n1);
    printf("Digite o numero 2: ");
    scanf("%d",&n2);
    if(n1<0)n1*=-1;
    if(n2<0)n2*=-1;
    for (i=1;i<n1;i++){
        if (n1%i==0){
                m[i]=i;
                printf("%d ", i);
                s+=m[i];
                j++;
            }
        }printf("\n");
    for (i=1;i<n2;i++){
        if (n2%i==0){
                r[i]=i;
                printf("%d ", i);
                s2+=r[i];
                p2++;
            }
        }
        printf("%d\n",s);
        printf("%d\n", s2);
        if(s==n2)printf("%d E amigo de %d\n",n1,n2);
        else printf("%d não e amigo %d \n",n1,n2);
    return 0;
}
