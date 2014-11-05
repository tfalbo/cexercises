#include <stdio.h>
#include <stdlib.h>

#define MAXIMO_CONTAS 5000

#define MAXIMO_OPERACOES 200

int le_saldos(int c[], float s[], int *dia, int *mes, int *ano){

	int conta, i = 0;
	float saldo;
	
	FILE *fsaldos;

	fsaldos = fopen("saldos.txt","r");

	if(fsaldos==NULL){

		printf("Nao foi possivel abrir o arquivo de saldos.\n");
		exit(1);
	}


	while(fscanf(fsaldos,"%d %f %d %d %d", &conta, &saldo, dia, mes, ano)==5){
		
		c[i]=conta;
		printf("Conta: %d\n", conta);
		s[i]=saldo;
		printf("Saldo: %.2f\n", saldo);
		i++;
	}

	fclose(fsaldos);

	printf("Data: %d %d %d\n", *dia, *mes, *ano);

	return i;	
}

int busca_conta(int c[], int conta, int quantidade){
	
	int i =0;

	for(i=0;i<quantidade;i++){
		if (conta == c[i]){
			return i;
		}
	}

	return (-1);

}


int descobre_operacao(int conta, FILE *fmovimentos, int *operacao, int *diaoperacao){

	int conta_lida;

	float valor;

	while(fscanf(fmovimentos,"%d %d %f %d", &conta_lida, operacao, &valor, diaoperacao)==4){
		
		if(conta_lida == conta){

			if(*operacao == 1){
				return 1;
			}
			if(*operacao == -1){
				return -1;
			}
		}
		
	}

	return 0;

}

int main(){

	int c[MAXIMO_CONTAS], dia, mes, ano, quantidade, indice, conta, operacao, diaoperacao;
	float s[MAXIMO_CONTAS];

	FILE *fmovimentos;

	printf("Lendo quantidade de contas...\n");

	quantidade = le_saldos(c, s, &dia, &mes, &ano);

	printf("Quantidade de contas: %d\nDigite a conta desejada:", quantidade);

	scanf("%d", &conta);

	printf("Buscando conta desejada...\n");

	indice = busca_conta(c,conta,quantidade);

	printf("Indice da conta desejada: %d\n", indice);

	printf("Lendo movimentacoes...\n");

	fmovimentos = fopen("movimentos.txt", "r");

	if(fmovimentos==NULL){

		printf("Nao foi possivel abrir o arquivo de movimentos.\n");
		exit(1);
	}


	while(descobre_operacao(conta, fmovimentos, &operacao, &diaoperacao)!= 0){
		printf("%d\n", operacao);
	}

	fclose(fmovimentos);

	return 0;

}


