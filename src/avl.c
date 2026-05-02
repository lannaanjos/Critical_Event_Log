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
