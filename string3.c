#include <stdio.h>
#include <string.h>
#define TAMANHO 10

int main(){

        int i, contador, caracteres;
        char ch1, ch2,sinicial[TAMANHO], sfinal[TAMANHO] ;

        printf("Digite a palavra com ate 10 letras.\n");

        scanf("%[^\n]", sinicial);

        printf("Voce digitou: %s\n", sinicial);

        printf("Digite o caractere a ser trocado:\n");

        scanf(" %c", &ch1);

        scanf("Digite para qual caractere sera trocado:\n");

        scanf(" %c", &ch2);

        caracteres = strlen(sinicial);

        printf("Numero de caracteres: %d\n", caracteres);

        // Criando sfinal

        contador = 0;
        for(i=0; i<caracteres; i++){
                if (sinicial[i] = ch1){
                        sfinal[i] = ch2;
                        contador++;
                }
                else{
                        sfinal[i] = sinicial[i];

                }
        }


        printf("Final: %s\n",sfinal);

        printf("Numero de caracteres: %d\n", strlen(sfinal));

        printf("Numero de caracteres trocados: %d\n", contador);


        return 0;
}

