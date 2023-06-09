#include <stdlib.h>

#include "stack_int.h"

struct _stack_int {
    int capacity;
    int *data;
    int size;
};

stack_int *stack_int_new(int capacity) {
    stack_int *s = malloc(sizeof(stack_int));
    s->capacity = capacity;
    s->data = malloc(capacity * sizeof(int));
    s->size = 0;
    return s;
}

void stack_int_delete(stack_int **_s) {
    stack_int *s = *_s;
    free(s->data);
    free(s);
    *_s = NULL;
}

int stack_int_empty(stack_int *s) {
    if (s->size == 0){
        return 1;
    }
    return 0;
}

int stack_int_full(stack_int *s) {
    if (s->size == capacity){
        return 1;
    }
    return 0;
}

void stack_int_push(stack_int *s, int value) {
    s->data[s->size] = value; // escreve o novo valor no novo topo
    s->size++;                // move o topo para a direita (sobe)

    //LEMBRAR Q SIZE É +1 DO ULTIMO ELEMENTO
    // CAPACITY TBM É +1 DO ULTIMO ELEMENTO

    //LEMBRAR A IDEIA DE COBERTURA E ASSOCIAR COM PONTEIRO
    //(ONDE TA APONTANDO)
}

int stack_int_pop(stack_int *s) {
    s->size--;               // move o topo para a esquerda (desce)
    return s->data[s->size]; // devolve o valor do topo atual
}

int stack_int_genpop(stack_int *s, int index){
    int value = s->data[index];
    s->size--;
    for (int i = index; i < s->size; i++){
        s->data[i] = s->data[i+1]    ;
    }
    return value;
}

void stack_int_push(stack_int *s, int value, int index) {
    int i;
    for (i = s->size; i > s->size - index; i--) {
        s->data[i] = s->data[i - 1];
    }
    s->data[i] = value;
    s->size++;
}
