#include <stdio.h>
#include <stdlib.h>

typedef struct linked_node linked_node;
struct linked_node
{
    char data;
    linked_node *next;
};

linked_node *append_node(linked_node *inicio, char valor) {
linked_node *novo = malloc(sizeof(linked_node));
if (novo == NULL) return inicio;
novo->data = valor;
novo->next = NULL;
if (inicio == NULL) return novo;
linked_node *anterior = NULL;
linked_node *atual = inicio;
while (atual != NULL) {
anterior = atual;
atual = atual->next;
}
anterior->next = novo;
return inicio;
}

void printLista(linked_node *inicio)
{
    if(inicio == NULL) return;
    printf("%c ", inicio->data);
    printLista(inicio->next);
}

int eh_adn(char base);

int main() 
{
  linked_node *lista = NULL;
  int adn = 1;
  char atual;
  atual = getchar();
  while (atual != '\n') 
  {
    if (!eh_adn(atual)) 
    {
	  adn = 0;
      break;
    }
    lista = append_node(lista, atual);
    atual = getchar();
  }
  
  if (adn)
  {
    printLista(lista);
    printf("\nEH ADN!!!\n");      
  }
  else
	  printf("NAO eh ADN!!!\n");      
  
  return 0;
}

int eh_adn(char base) 
{
  return ((base == 'A') 
    || (base == 'C')
    || (base == 'G')
    || (base == 'T'));
}