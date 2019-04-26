/*

Author: Thales Costa
Discipline: ED1
Professor: Irineu
May/2017

*/

#include "List Dupl Enc.h"

int main() {
setlocale(LC_ALL, "");
	
	system("title Lista duplamente encadeada");
	
	int funcao, elemento;
	Lista* L;
	L = inicializar();
	
	menu:
	
	printf("==Lista duplamente encadeada==\n\n");
	printf("Selecione a fun��o desejada:\n");
	printf("1 - Insere inicio\n");
	printf("2 - Insere fim\n");
	printf("3 - Remove inicio\n");
	printf("4 - Remove fim\n");
	printf("5 - Remove elemento\n");
	printf("6 - Imprime inicio_fim\n");
	printf("7 - Imprime fim_inicio\n");
	printf("8 - Busca elemento\n");
	printf("0 - Sair\n\n");
	
	scanf("%d", &funcao);
	
	switch(funcao){			//Direciona para a fun��o requisitada no menu acima.
		case(1):		//Insere no inicio da lista o elemento informado.
			printf("\nInforme o elemento inteiro a ser inserido no inicio: ");
			scanf("%d", &elemento);
			
			L = insere_Inicio(L, elemento);
			
			system("cls");
		break;
		case(2):		//Insere no fim da lista o elemento informado.
			printf("\nInforme o elemento inteiro a ser inserido no fim: ");
			scanf("%d", &elemento);
			
			L = insere_Fim(L, elemento);
			
			system("cls");
		break;
		case(3):		//Retira o primeiro elemento da lista.
			if(L != NULL){
				
				L = retira_Inicio(L, &elemento);
				
				printf("O elemento %d foi retirado.\n", elemento);
			}else{
				
				printf("\nA lista j� se encontra vazia.\n");
			}
				system("pause");
				system("cls");
		break;
		case(4):		//Retira o �ltimo elemento da lista.
			if(L != NULL){
				
				L = retira_Fim(L, &elemento);
				
				printf("O elemento %d foi retirado.\n", elemento);
			}else{
				
				printf("\nA lista j� se encontra vazia.\n");
			}
			
				system("pause");
				system("cls");
		break;
		case(5):		//Retira determinado elemento da lista.
			if(L != NULL){
				printf("Informe o elemento a ser buscado e retirado: ");
				scanf("%d", &elemento);
				
				bool found;
				
				L = retira_Elemento(L, elemento, &found);
				
				if(found){
					printf("Elemento %d retirado.\n", elemento);
				}else{
					printf("Elemento n�o encontrado.\n");
				}
				
			}else{
				
				printf("\nA lista est� vazia.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(6):		//Mostra do primeiro ao �ltimo elemento da lista.
			if(L != NULL){
				
				printf("\nLista do primeiro ao �ltimo elemento:\n");
				mostra_Inicio_Fim(L);
			}else{
				
				printf("\nA lista est� vazia.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(7):		//Mostra do �ltimo ao primeiro elemento da lista.
			if(L != NULL){
				
				printf("\nLista do �ltimo ao primeiro elemento:\n");
				mostra_Fim_Inicio(L);
			}else{
				
				printf("\nA lista est� vazia.\n");
			}
			
			system("pause");
			system("cls");
			
		break;
		case(8):		//Busca na lista pelo elemento informado.
			
			if(L != NULL){
				printf("\nInforme o elemento a ser buscado: ");
				scanf("%d", &elemento);
				
				if(busca_Elemento(L, elemento)){
					
					printf("O elemento est� presente na lista.\n");
				}else{
					
					printf("O elemento n�o est� presente na lista.\n");
				}
			}else{
				
				printf("\nA lista est� vazia.\n");
			}
			
			system("pause");
			system("cls");
		break;
		case(0):		//Libera a mem�ria alocada, caso tenha alguma, e encerra o programa.
			libera(L);
				
			printf("\nObrigado!\n");
			
			return 0;
		break;
	}
	
	goto menu;		//Mant�m no menu enquanto n�o for selecionada a op��o "sair".
	
}
