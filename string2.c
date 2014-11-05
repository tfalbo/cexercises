#include <stdio.h>
#include <string.h>
#define TAMANHO 10

int main(){

        int i, j, caracteres;
        char str1[TAMANHO], str2[TAMANHO];

        printf("Digite a palavra com ate 10 letras.\n");

        scanf("%s", str1);

        printf("Voce digitou: %s\n", str1);

        caracteres = strlen(str1);

        printf("Numero de caracteres: %d\n", caracteres);

        // Criando reversa:

        j=0;

        for(i=caracteres-1; i>=0; i--){

                str2[j] = str1[i];
                j++;

        }

        str2[j] = '\0';

        printf("Reversa: %s\n",str2);

        printf("Numero de caracteres: %d\n", strlen(str2));

        // Comparando para ver se e palindroma

        if(strcmp(str1,str2)==0){
                printf("E palindroma!\n");
        }else{
                printf("Nao e palindroma!\n");
        }


        return 0;
}


