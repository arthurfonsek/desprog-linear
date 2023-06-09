#include <stdlib.h>

#include "stack_int.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _stack_int {
    node *top;
};

stack_int *stack_int_new() {
    stack_int *s = malloc(sizeof(stack_int));
    s->top = NULL;
    return s;
}

void stack_int_delete(stack_int **_s) {
    stack_int *s = *_s;
    node *n = s->top;
    while (n != NULL) {
        node *next = n->next; // primeiro fazemos um "backup" do next
        free(n);              // aí estamos livres para liberar o n
        n = next;             // e usamos o "backup" para "andar"
    }
    free(s);
    *_s = NULL;
}

int stack_int_empty(stack_int *s) {
    return s->top == NULL;
}

void stack_int_push(stack_int *s, int value) {
    node *n = malloc(sizeof(node)); // aloca um novo nó
    n->value = value;               // escreve o novo valor no novo nó
    n->next = s->top;               // faz o novo nó apontar para o topo atual
    s->top = n;                     // move o topo para o novo nó (sobe)
}

int stack_int_pop(stack_int *s) {
    node *n = s->top;     // guarda o endereço do topo atual
    s->top = n->next;     // move o topo para seu seguinte (desce)
    int value = n->value; // guarda o valor do velho topo
    free(n);              // libera o bloco do velho topo
    return value;         // devolve o valor do velho topo
}


/*
PERCORRER LISTA LIGADA:

for (node *n = s->top; n != NULL; n = n->next) {
    printf("%d\n", n->value);
}

*/