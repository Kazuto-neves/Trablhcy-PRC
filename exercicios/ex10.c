////printf("sMMMMMMMMMMMMMMMMs\n");                  
//printf("sMMMNyyyyyyyyyhMMy\n");
//printf("sMMMm         sMMy\n");
//printf("sMMMm        dNdmNy\n");
//printf("sMMMm       sMy  dN\n");
//printf("sMMMm        hmmmmy\n");
//printf("sMMMm    ydhs  Mh  shdy\n");
//printf("sMMMm     syhdmMNmdhys\n");
//printf("sMMMm          Mh\n");
//printf("sMMMm          Mh\n");
//printf("sMMMm          Mh\n");
//printf("sMMMm          Md\n");
//printf("sMMMm        hmhdNy\n");
//printf("sMMMm      hmh   sdNy\n");
//printf("sMMMm    hmh       sdNs\n");
//printf("sMMMm    s           ss\n");
//printf("sMMMm                    \n");
//printf("mmmmmmMMMMmmmmmmmmmmmmmmm\n");
//printf("MMMMMMMMMMMMMMMMMMMMMMMMM\n");

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char pala[50],espa[50]="-",let[50],er[50],tam;
    int vidas = 5,retor,pts=0,i,n=0;
    printf("Digite a palavra :");
    gets(pala);
    for (i = 0; i <strlen(pala); i++){
        espa[i]='-';
        tam=strlen(pala);
        do{
            retor=0;
            printf("\n%s\n",espa);
            printf("Digite uma letra: ");
            gets(let);
            printf("\nLetra digitadas foi %s\n",er);
            for (i = 0; i < strlen(pala); i++){
                if (let[0] == pala[i]){
                    espa[i]= pala[i];
                    retor++;
                    pts++;
                }
            }
            if (retor == 0){vidas--;
                if (vidas == 0){
                    printf("\nGame Over.");//printf("\nYou died");
                    printf("\nA palavra era %s \n",pala);
                    break;
                }else{
                    printf("\nVoce errou a letra.\nRestam %d vidas",vidas);
                    er[n] = let[0];
                    n++;
                }
            }else{
                if (pts == tam){
                    printf("\n Voce acertou a palavra, muito bem!\n");
                    break;
                }else{
                    printf("\n Voce acertou a letra continue assim");
                }
            }
        }while(vidas>0);
    }
    return 0;
}