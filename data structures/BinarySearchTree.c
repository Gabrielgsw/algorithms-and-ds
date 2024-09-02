#include <stdio.h>
#include <stdlib.h>

// BST
// Discente: Gabriel Germano dos Santos Wanderley

// Estruturas básicas

typedef struct NoArvore {
  int chave;
  struct NoArvore *pai;
  struct NoArvore *esq;
  struct NoArvore *dir;
} NoArvore;

typedef struct {
  struct NoArvore *raiz;
} Arvore;

// Busca

int busca(struct NoArvore *r, int x) {
  if ((r == NULL) || (r->chave == x)) {
    return x;
  } else if (x < r->chave) {
    return busca(r->esq, x);
  } else {
    return busca(r->dir, x);
  }
}

// Inserção

int main(void) {}