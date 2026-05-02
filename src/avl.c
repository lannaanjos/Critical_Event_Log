#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

AVL *criar_avl(void){
  AVL *avl = (AVL*)malloc(sizeof(AVL));
  if (avl == NULL){
    printf("Alocação de memória mal-sucedida!\n");
    return NULL;
  }

  avl->raiz = NULL;
  avl->total_nos = 0;
  avl->total_ativos = 0;
  avl->total_rotacoes = 0;

  return avl;
}

// func aux
static void _destruicao_recursiva(NoAVL *no){
  if (no == NULL)
    return;
  _destruicao_recursiva(no->esquerda);
  _destruicao_recursiva(no->direita);
  free(no);
}

// destroi nós recursivamente e libera avl
void destruir_avl(AVL *avl){
  if (avl == NULL)
    return;

  _destruicao_recursiva(avl->raiz);
  free(avl);
}

// /\/\/\ funcs altura e balanceamento
int get_altura_no(NoAVL *no){
  if (no == NULL)
    return 0;
  return no->altura;
}

int get_fator_balanceamento(NoAVL *no){
  if (no == NULL)
    return 0;
  return get_altura_no(no->esquerda) - get_altura_no(no->direita);
}

void atualiza_altura(NoAVL *no){
  if (no == NULL)
    return;

  int h_esq = get_altura_no(no->esquerda);
  int h_dir = get_altura_no(no->direita);

  no->altura = 1 + (h_esq > h_dir ? h_esq : h_dir);
}

// /\/\/\ ROTAÇÕES
NoAVL *rotacao_direita(AVL *avl, NoAVL *y){
  NoAVL *x = y->esquerda;
  NoAVL filho_dir = x->direita;

  // rot
  x->direita = y;
  y->esquerda = filho_dir;

  // att altura
  atualiza_altura(y);
  atualiza_altura(x);

  avl->total_rotacoes++;
  return x; // nova raiz da subtree 
}

NoAVL *rotacao_esquerda(AVL *avl, NoAVL *x){
  NoAVL *y = x->direita;
  NoAVL filho_esq = y->esquerda;

  // rot
  y->esquerda = x;
  x->direita = filho_esq;

  // att altura
  atualiza_altura(x);
  atualiza_altura(y);

  avl->total_rotacoes++;
  return y;
}

NoAVL *rot_dupla_esq_dir(AVL *avl, NoAVL *no){
  no->esquerda = rotacao_esquerda(avl, no->esquerda);
  return rotacao_direita(avl, no);
}

NoAVL *rot_dupla_dir_esq(AVL *avl, NoAVL *no){
  no->direita = rotacao_direita(avl, no->direita);
  return rotacao_esquerda(avl, no);
}

// /\ rebalanceamento
NoAVL *rebalancear(AVL *avl, NoAVL *no){
  atualiza_altura(no);
  int fb = get_fator_balanceamento(no);

  // esquerda esquerda
  if (fb > 1 && get_fator_balanceamento(no->esquerda) >= 0)
    return rotacao_direita(avl, no);

  // esquerda direita
  if (fb > 1 && get_fator_balanceamento(no->esquerda) < 0)
    return rot_dupla_esq_dir(avl, no);

  // direita direita
  if (fb < -1 && get_fator_balanceamento(no->direita) <= 0)
    return rotacao_esquerda(avl, no);

  if (fb < -1 && get_fator_balanceamento(no->direita) > 0)
    return rot_dupla_dir_esq(avl, no);

  return no; // balanceado 
}
