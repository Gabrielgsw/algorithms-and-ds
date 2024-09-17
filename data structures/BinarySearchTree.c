#include <stdio.h>
#include <stdlib.h>


// Discente: Gabriel Germano dos Santos Wanderley

// Estruturas básicas

struct NoArvore {
  int chave;
  struct NoArvore *pai;
  struct NoArvore *esq;
  struct NoArvore *dir;
};
typedef struct NoArvore NoArvore;
typedef struct Arvore {
  NoArvore *raiz;
} Arvore;

// Busca

NoArvore *busca(NoArvore *r, int x) {
  if ((r == NULL) || (r->chave == x)) {
    return r;
  } else if (x < r->chave) {
    return busca(r->esq, x);
  } else {
    return busca(r->dir, x);
  }
}

// Inserção

void inserirElemento(NoArvore *no, Arvore *arvore) {
 
  NoArvore *pai = NULL;
  NoArvore *aux = arvore->raiz;
  while (aux != NULL) {
    pai = aux;
    if (no->chave <= aux->chave) {
      aux = aux->esq;
    } else {
      aux = aux->dir;
    }
  }
  no->pai = pai;
  if (pai == NULL) {
    arvore->raiz = no;
  } else if (no->chave <= pai->chave) {
    pai->esq = no;
  } else {
    pai->dir = no;
  }
  printf("Elemento inserido com sucesso!\n");
}

// Buscar o menor
NoArvore *minimo(NoArvore *no) {
  while (no->esq != NULL) {
    no = no->esq;
  }
  if(no->esq == NULL){
    printf("Não há elementos a esquerda!\n");
  }
  return no;
}

// Sucessor -> Percurso em ordem

NoArvore *buscarSucessor(NoArvore *no) {
  if (no->dir != NULL) {
    return minimo(no->dir);
  }
  NoArvore *aux = no->pai;
  while ((aux != NULL) && (no == aux->dir)) {
    no = aux;
    aux = aux->pai;
  }
  return aux;
}




NoArvore *remover(int chave, Arvore *arvore) {
  NoArvore *aux = busca(arvore->raiz, chave);
  
  if (aux == NULL) {
    printf("O nó não existe na árvore! ");
  } else {
    if ((aux->esq == NULL) && (aux->dir == NULL)) {
      //Remoção sem filhos
      NoArvore *pai = aux->pai;
      if (pai != NULL) {
        if (pai->chave == aux->chave) {
          pai->esq = NULL;
        } else {
          pai->dir = NULL;
        }
      } else {
        arvore->raiz = NULL;
      }
      aux->pai = NULL;
      printf("Elemento removido! \n");
      free(aux);
      
    } else if ((aux->esq != NULL) && (aux->dir != NULL)) {
      // Remoção com dois filhos
      NoArvore *sucessor = buscarSucessor(aux);
      sucessor = remover(sucessor->chave, arvore);
      sucessor->pai = aux->pai;
      aux->pai = NULL;
      sucessor->esq = NULL;
      aux->esq = NULL;
      sucessor->dir = aux->dir;
      aux->dir = NULL;
      NoArvore *noPai= sucessor->pai;
      if (noPai != NULL) {
        if (noPai->chave >= sucessor->chave) {
          noPai->esq = sucessor;
        } else {
          noPai->dir = sucessor;
        }
      } else {
        arvore->raiz = sucessor;
      }
      sucessor->esq->pai = sucessor;
      if (sucessor->dir != NULL) {
        sucessor->dir->pai = sucessor;
      }
      printf("Elemento removido! \n");
      free(aux);
    } else {
      // Remoção um filho
      NoArvore *pai = aux->pai;
      NoArvore *filho = NULL;
      if (aux->esq != NULL) {
        filho = aux->esq;
      } else {
        filho = aux->dir;
        aux->dir = NULL;
      }
      if (pai != NULL) {
        filho->pai = pai;
        if (pai->chave <= aux->chave) {
          pai->esq = filho;
        } else {
          pai->dir = filho;
        }
      } else {
        arvore->raiz = filho;
      }
      aux->pai = NULL;
      printf("Elemento removido! \n");
      free(aux);
    }
  }
  return aux;
}





int main(void) {
  
  Arvore *arvore = malloc(sizeof(Arvore));
  arvore->raiz = NULL;
  NoArvore *no = malloc(sizeof(NoArvore));
 
  no->chave = 100;
  inserirElemento(no, arvore);
  NoArvore *no1 = malloc(sizeof(NoArvore));
  no1->chave = 30;
  inserirElemento(no1, arvore);
  NoArvore *no2 = malloc(sizeof(NoArvore));
  no2->chave = 40;
  inserirElemento(no2, arvore);
  NoArvore *result = busca(no,no->chave);
  NoArvore *resultado = remover(no2->chave, arvore);
  
  printf("%d\n",result->chave);
  NoArvore *minimoo = minimo(no);
  printf("%d",minimoo->chave);
}
