#include <stdio.h>
#include "metrics.h"

int metric_altura_total(AVL *avl){
  if (avl == NULL || avl->raiz == NULL)
    return 0;

  return get_altura_no(avl->raiz);
}

int metric_total_nos(AVL *avl){
  if (avl == NULL)
    return 0;
  return avl->total_nos;
}

int metric_total_ativos(AVL *avl){
  if (avl == NULL)
    return 0;

  return avl->total_ativos;
}

int metric_total_rotacoes(AVL *avl){
  if (avl == NULL)
    return 0;

  return avl->total_rotacoes;
}


// func aux
static void _soma_fb_rec(NoAVL *no, float *soma, int *count){
  if (no == NULL)
    return;

  _soma_fb_rec(no->esquerda, soma, count);
  _soma_fb_rec(no->direita, soma, count);

  int fb = get_fator_balanceamento(no);
  *soma += (fb < 0 ? -fb : fb);
  (*count)++;
}

float metric_fator_balanceamento_medio(AVL *avl){
  if (avl == NULL || avl->raiz == NULL)
    return 0.0f;

  float soma = 0.0f;
  int count = 0;

  _soma_fb_rec(avl->raiz, &soma, &count);

  if (count == 0)
    return 0.0f;

  return soma/(float)count;
}

void metric_exibir_relatorio(AVL *avl){
  if (avl == NULL){
    printf("[ERRO]\nÁrvore inválida!\n");
    return;
  }

  int altura = metric_altura_total(avl);
  int total = metric_total_nos(avl);
  int ativos = metric_total_ativos(avl);
  int resolvidos = total - ativos;
  int rotacoes = metric_total_rotacoes(avl);
  float fb_medio = metric_fator_balanceamento_medio(avl);

  printf("    Métricas da Árvore AVL\n\n");
  printf("Altura total                  | %-11d \n", altura);
  printf("Total de eventos              | %-11d \n", total);
  printf("Total de eventos ativos       | %-11d \n", ativos);
  printf("Total de eventos resolvidos   | %-11d \n", resolvidos);
  printf("Total de rotações realizadas  | %-11d \n", rotacoes);
  printf("Fator de balanceamento médio  | %-11.4f\n", fb_medio);

}
