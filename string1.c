#include <stdio.h>
#include <string.h>
#define TAMANHO 10

int main(){

        int i,caracteres;
        char str1[TAMANHO];

        printf("Digite a palavra com ate 10 letras.\n");

        scanf("%s", str1);

        printf("Voce digitou: %s\n", str1);

        caracteres = strlen(str1);

        printf("Numero de caracteres: %d\n", caracteres);

        for(i=caracteres-1; i>=0; i--){
                printf("%c",str1[i]);
        }

        printf("\n");

        return 0;
}

