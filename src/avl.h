#ifndef AVL_H
#define AVL_H

#include "event.h"

typedef struct NoAVL{
  Evento evento;
  int altura;
  struct NoAVL *esquerda;
  struct NoAVL *direita;
} NoAVL;

typedef struct {
  NoAVL *raiz;
  int total_nos;
  int total_ativos;
  int total_rotacoes;
} AVL;

// funcs de inicialização
AVL *criar_avl(void);
void destruir_avl(AVL *avl);

// funcs auxiliares
int get_altura_no(NoAVL *no);
int get_fator_balanceamento(NoAVL *no);

// /\/\/\ operações principais
int avl_inserir_evento(AVL *avl, Evento evento);
int avl_remover_evento(AVL *avl, int id);
NoAVL *avl_buscar_evento(AVL *avl, int id);

// ops de atualização
int avl_atualizar_status(AVL *avl, int id, StatusEvento novo_status);
int avl_atualizar_magnitude(AVL *avl, int id, int nova_magnitude);

#endif
