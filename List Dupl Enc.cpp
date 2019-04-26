/*

Author: Thales Costa
Discipline: ED1
Professor: Irineu
May/2017

*/

#include "List Dupl Enc.h"

Lista* inicializar(){
	
	return NULL;
}

Lista* insere_Inicio(Lista* L, int dado){		//Insere no inicio da lista o elemento informado e retorna o ponteiro criado.
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = dado;
	novo->ant = NULL;

	if(L == NULL){
		novo->prox = NULL;
		
	}else{
		novo->prox = L;
		L->ant = novo;
		
	}
	return  novo;
}

Lista* insere_Fim(Lista* L, int dado){		//Insere no fim da lista o elemento informado.
	
	Lista* novo = (Lista*)malloc(sizeof(Lista));
	novo->info = dado;
	novo->prox = NULL;

	if(L == NULL){
		novo->ant = NULL;
		
		return  novo;
	}else{
		Lista* P;
		
		for(P = L; P->prox != NULL; P = P->prox);
		
		novo->ant = P;
		P->prox = novo;
	
		return L;
	}
	
}

Lista* retira_Inicio(Lista* L, int* elemento){		//Retira o primeiro elemento da lista.
	
	if(L == NULL){
		
		return NULL;
	}else{
		*elemento = L->info;
		Lista* P1;
		Lista* P2;
		
		P1 = L;
		P2 = L->prox;
		
		if(L->prox != NULL){
			L->prox->ant = NULL;
		}
		
		free(P1);
		
		return P2;
	}
	
}

Lista* retira_Fim(Lista* L, int* elemento){		//Retira o último elemento da lista.
	
	if(L == NULL){
		
		return NULL;
	}else{

		Lista* P;
		
		for(P = L; P->prox != NULL; P = P->prox);
		
		*elemento = P->info;
		if(P->ant == NULL){
			free(P);
		
			return NULL;
		}
		
		P->ant->prox = NULL;
		free(P);
		
		return L;
	}
	
}

Lista* retira_Elemento(Lista* L, int elemento, bool* found){		//Retira determinado elemento da lista.
	
	Lista* P;
		
	for(P = L; P != NULL; P = P->prox){
		if(elemento == P->info){
			*found = true;

			if((P->ant == NULL) && (P->prox == NULL)){
				free(P);
				return NULL;
				
			}else if(P->ant == NULL){
				P->prox->ant = NULL;
				Lista* N = P->prox;
				free(P);
				
				return N;
				
			}else if(P->prox == NULL){
				P->ant->prox = NULL;
				
			}else{
				P->ant->prox = P->prox;
				P->prox->ant = P->ant;
				
			}
			
			free(P);
			return L;
		}
	}
	
	*found = false;
	return L;
}


void mostra_Inicio_Fim(Lista* L){		//Mostra do primeiro ao último elemento da lista.
	Lista* P = L;
	
	while(P != NULL){
			printf("%d\t", P->info);
			P = P->prox;
	}
	
	printf("\n\n");
}

void mostra_Fim_Inicio(Lista* L){		//Mostra do último ao primeiro elemento da lista.
	Lista* P = L;
	for(P = L; P->prox != NULL; P = P->prox);
	
	while(P != NULL){
			printf("%d\t", P->info);
			P = P->ant;
	}
	
	printf("\n\n");
}

bool busca_Elemento(Lista* L, int elemento){		//Busca por determinado elemento na lista e retorna 'true' caso esteja presente.
	Lista* P = L;
	
	for(P = L; P != NULL; P = P->prox){
		if(elemento == P->info){
			
			return true;
		}
	}
	
	return false;
}

void libera(Lista* L){		//Libera, de forma recursiva, a memória alocada, caso tenha alguma.
	
	if(L != NULL){
		libera(L->prox);
		free(L);
	}
	
}



