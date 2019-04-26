/*

Author: Thales Costa
Discipline: ED1
Professor: Irineu
May/2017

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct List {
	
	int info;
	List* prox;
	List* ant;
	
}typedef Lista;

Lista* inicializar();
Lista* insere_Inicio(Lista* L, int dado);
Lista* insere_Fim(Lista* L, int dado);
Lista* retira_Inicio(Lista* L, int* elemento);
Lista* retira_Fim(Lista* L, int* elemento);
Lista* retira_Elemento(Lista* L, int elemento, bool* found);
void mostra_Inicio_Fim(Lista* L);
void mostra_Fim_Inicio(Lista* L);
bool busca_Elemento(Lista* L, int elemento);
void libera(Lista* L);
