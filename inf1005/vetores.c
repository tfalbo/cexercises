/* O arquivo numeros.txt contem uma sequencia de no maximo 200 numeros
 a) Faca uma funcao que:
	- Abra o arquivo
	- Leia os numeros para um vetos
	- Feche o arquivo
	- Retorne a quantidade de numeros lidos.
	- Prototipo:  int le_numeros(int v[])
 b) Faca uma funcao que:
	-  permita buscar a primeira ocorrencia de um determinado numero inteiro em um vetor.
	-  Sua funcao devera receber 3 parametros: 
		- o vetor(na verdade o endereco da sua base),
		- o inteiro procurado e a quantidade de posicoes a partir da posicao 0 do vetor que deverao ser procuradas.
	- A funcao devera retornar:
		- a posicao da primeira ocorrencia do numero procurado dentro do vetor.
		- caso o numero procurado nao seja encontrado, retorna -1
	- Prototipo:  int busca(int vetor[], int elem_proc, int quant)

c) Faca um programa que use as duas funcoes dos itens a e b para:
	-ler os numeros do arquivo
	- solicite que o usuario digite o numero a ser procurado
	- escreva na tela a posicao do arquivo em que esse numero apareceu pela primeira vez
	- ou exiba a mensagem "o numero nao foi encontrado
*/

#include <stdio.h>
#include <stdlib.h>

#define QTD_MAX 200

int le_numeros(int v[]){
	FILE *f;
	int i;
	f = fopen("numeros.txt","r");
	if (f==NULL){
		printf("Erro na abertura do arquivo.\n");
		exit(1);
	}
	for(i=0; i< QTD_MAX && fscanf(f,"%d", &v[i])==1; i++){
		printf("%d ", v[i]);
	}
	fclose(f);
	return i;	
}


int busca(int vetor[], int elem_proc, int quant){

	int i;

	for (i=0; i<quant; i++){
		if(vetor[i]==elem_proc){
			printf("Encontrado!\n");
			return i;
		}
	}
	printf("Elemento nao encontrado!\n");
	return -1;
}


int main(void){

	int vetor[QTD_MAX];
	int total, procurado, posicao;

	printf("Hello!\n");
	total = le_numeros(vetor);
	printf("Total de elementos: %d\n", total);

	printf("Digite o elemento procurado:\n");

	scanf("%d", &procurado);

	posicao = busca(vetor, procurado, total);

	if(posicao != -1){
		printf("Elemento encontrado na posicao %d com valor %d\n", posicao,vetor[posicao]);
	}

	return 0;



}
