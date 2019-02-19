#include <stdio.h>
#include <stdlib.h>
typedef struct linked_node linked_node;
struct linked_node
{
    int data;
    linked_node *next;
};
void printListaNutella(linked_node *inicio)
{
    linked_node *atual = inicio;
    while(atual != NULL){
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}
void printListaRaiz(linked_node *inicio)
{
    if(inicio == NULL) return;
    printf("%d\n", inicio->data);
    printListaRaiz(inicio->next);
}
void printListaRaizContra(linked_node *inicio)
{
    if(inicio == NULL) return;
    printListaRaiz(inicio->next);
    printf("%d ", inicio->data);
}
linked_node *add(linked_node *atual, int valor)
{
    if(atual == NULL){
        linked_node *newItem = malloc(sizeof(linked_node));
        newItem->data = valor;
        newItem->next = NULL;
        return newItem;
    }
    if(atual->next == NULL){
        linked_node *newItem = malloc(sizeof(linked_node));
        newItem->data = valor;
        newItem->next = NULL;
        atual->next = newItem;
        return atual;
    }
    add(atual->next, valor);
}
int main()
{
    linked_node *lista = NULL;
    lista = add(lista, 1);
    lista = add(lista, 2);
    lista = add(lista, 3);
    lista = add(lista, 4);
    printListaRaiz(lista);
}

//linked_node *vazio = NULL;
// linked_node *inicio = malloc(sizeof(linked_node));
// inicio->data = 2;
// inicio->next = NULL;
// linked_node *segundo = malloc(sizeof(linked_node));
// segundo->data = 1;
// segundo->next = NULL;
// inicio->next = segundo;
// //printf("%d\n", inicio->data);
// printListaRaiz(inicio);
// return 0;