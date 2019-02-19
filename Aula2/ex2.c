#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    char data;
    node *next;
};

int eh_adn(char base)
{
    return ((base == 'A') || (base == 'C') || (base == 'G') || (base == 'T'));
}

node *addSI(node *inicio, char valor)
{
    node *temp = NULL;
    node *novo = malloc(sizeof(node));
    if (novo == NULL)
        return inicio;
    novo->data = valor;
    novo->next = NULL;
    if (inicio == NULL)
        return novo;
    node *anterior = NULL;
    node *atual = inicio;
    while (atual->next >= valor)
    {
        anterior = atual;
        atual = atual->next;
    }
    anterior->next = novo;
    return inicio;
}

void printLista(node *inicio)
{
    if (inicio == NULL)
        return;
    printf("%c", inicio->data);
    printLista(inicio->next);
}

void main()
{
    node *lista = NULL;
    int adn = 1;
    char atual;
    atual = getchar();
    while (atual != '0')
    {
        if (!eh_adn(atual))
        {
            adn = 0;
            break;
        }
        lista = addSI(lista, atual);
        atual = getchar();
    }
    printLista(lista);
}