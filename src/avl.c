#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

AVL *criar_avl(void){
  AVL *avl = (AVL*)malloc(sizeof(AVL));
  if (avl == NULL){
    printf("[ERRO]\nAlocação de memória mal-sucedida!\n");
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

static void atualiza_altura(NoAVL *no){
  if (no == NULL)
    return;

  int h_esq = get_altura_no(no->esquerda);
  int h_dir = get_altura_no(no->direita);

  no->altura = 1 + (h_esq > h_dir ? h_esq : h_dir);
}

// /\/\/\ ROTAÇÕES
static NoAVL *rotacao_direita(AVL *avl, NoAVL *y){
  NoAVL *x = y->esquerda;
  NoAVL *filho_dir = x->direita;

  // rot
  x->direita = y;
  y->esquerda = filho_dir;

  // att altura
  atualiza_altura(y);
  atualiza_altura(x);

  avl->total_rotacoes++;
  return x; // nova raiz da subtree 
}

static NoAVL *rotacao_esquerda(AVL *avl, NoAVL *x){
  NoAVL *y = x->direita;
  NoAVL *filho_esq = y->esquerda;

  // rot
  y->esquerda = x;
  x->direita = filho_esq;

  // att altura
  atualiza_altura(x);
  atualiza_altura(y);

  avl->total_rotacoes++;
  return y;
}

static NoAVL *rot_dupla_esq_dir(AVL *avl, NoAVL *no){
  no->esquerda = rotacao_esquerda(avl, no->esquerda);
  return rotacao_direita(avl, no);
}

static NoAVL *rot_dupla_dir_esq(AVL *avl, NoAVL *no){
  no->direita = rotacao_direita(avl, no->direita);
  return rotacao_esquerda(avl, no);
}

// /\ rebalanceamento
static NoAVL *rebalancear(AVL *avl, NoAVL *no){
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

// inserção
static NoAVL *_insercao_recursiva(AVL *avl, NoAVL *no, Evento evento, int *sucesso){
  if (no == NULL){
    NoAVL *novo = (NoAVL*)malloc(sizeof(NoAVL));
    if (novo == NULL){
      printf("[ERRO]\nAlocação de memória mal-sucedida!\n");
      *sucesso = 0;
      return NULL;
    }
    novo->evento = evento;
    novo->altura = 1;
    novo->esquerda = NULL;
    novo->direita = NULL;
    *sucesso = 1;
    return novo;
  }

  if (evento.id < no->evento.id)
    no->esquerda = _insercao_recursiva(avl, no->esquerda, evento, sucesso);
  else if (evento.id > no->evento.id)
      no->direita = _insercao_recursiva(avl, no->direita, evento, sucesso);
  else {
    printf("[ATENÇÃO]\nJá existe um evento com este ID (%d) na árvore!\n", evento.id);
    *sucesso = 0;
    return no;
  }

  return rebalancear(avl, no);
}

int avl_inserir_evento(AVL *avl, Evento evento){
  if (avl == NULL)
    return 0;
  if (!valida_evento(&evento)){
    printf("[ATENÇÃO]\nEvento inválido!\n");
    return 0;
  }

  int sucesso = 0;
  avl->raiz = _insercao_recursiva(avl, avl->raiz, evento, &sucesso);

  if (sucesso){
    avl->total_nos++;
    if (evento.status == ATIVO)
      avl->total_ativos++;
  }

  return sucesso;
}

// /\ remoção
static NoAVL *_no_minimo(NoAVL *no){
  if (no == NULL)
    return NULL;

  while (no->esquerda != NULL) {
    no = no->esquerda;
  }
  return no;
}

static NoAVL *_remocao_recursiva(AVL *avl, NoAVL *no, int id, int *sucesso){
  if (no == NULL){
    printf("[ERRO]\n Não foi possível encontrar um evento com este ID (%d)", id);
    *sucesso = 0;
    return NULL;
  }

  if (id < no->evento.id)
    no->esquerda = _remocao_recursiva(avl, no->esquerda, id, sucesso);
  else if (id > no->evento.id)
      no->direita = _remocao_recursiva(avl, no->direita, id, sucesso);
  else {
    if (no->evento.status == ATIVO){
      printf("[ATENÇÂO]\nEvento ainda ativo. Resolva-o antes de removê-lo.\n");
      *sucesso = 0;
      return no;
    }

    *sucesso = 1;

    if (no->esquerda == NULL){
      NoAVL *temp = no->direita;
      free(no);
      return temp;
    }

    if (no->direita == NULL){
      NoAVL *temp = no->esquerda;
      free(no);
      return temp;
    }

    NoAVL *proximo = _no_minimo(no->direita);
    int id_sucessor = proximo->evento.id; // salva antes de sobrescrever o nó
    no->evento = proximo->evento;
    int sucesso_interno = 0;
    no->direita = _remocao_recursiva(avl, no->direita, id_sucessor, &sucesso_interno);
    if (!sucesso_interno)
      *sucesso = 0;
  }

  return rebalancear(avl, no);
}

int avl_remover_evento(AVL *avl, int id){
  if (avl == NULL)
    return 0;

  // verifica o status antes de remover para ajustar total_ativos
  NoAVL *alvo = avl_buscar_evento(avl, id);
  int era_ativo = (alvo != NULL && alvo->evento.status == ATIVO);

  int sucesso = 0;
  avl->raiz = _remocao_recursiva(avl, avl->raiz, id, &sucesso);

  if (sucesso){
    avl->total_nos--;
    if (era_ativo)
      avl->total_ativos--;
  }

  return sucesso;
}

// /\/\ busca
NoAVL *avl_buscar_evento(AVL *avl, int id){
  if (avl == NULL)
    return NULL;

  NoAVL *atual = avl->raiz;
  while(atual != NULL){
    if (id == atual->evento.id)
      return atual;
    else if (id < atual->evento.id)
        atual = atual->esquerda;
    else
      atual = atual->direita;
  }
  return NULL; // n achou 
}

// /\/\ ops de atualização
int avl_atualizar_status(AVL *avl, int id, StatusEvento novo_status){
  if (avl == NULL)
    return 0;

  NoAVL *no = avl_buscar_evento(avl, id);

  if (no == NULL){
    printf("[ERRO]\nEvento não encontrado!\n");
    return 0;
  }

  if (no->evento.status == novo_status){
    printf("[ATENÇÃO]\nO evento de ID %d já possui o novo status inserido!\n", id);
    return 0;
  }

  if (no->evento.status == RESOLVIDO && novo_status == ATIVO){
    printf("[ERRO]\nNão é possível reativar um evento já resolvido (ID %d).\n", id);
    return 0;
  }

  if (no->evento.status == ATIVO && novo_status == RESOLVIDO){
    avl->total_ativos--;
    no->evento.status = RESOLVIDO;
    return 1;
  }

  printf("[ERRO]\nTransição de status inválida para o evento ID %d.\n", id);
  return 0;
}

int avl_atualizar_magnitude(AVL *avl, int id, int nova_magnitude){
  if (avl == NULL)
    return 0;

  if (nova_magnitude < MAGNITUDE_MIN || nova_magnitude > MAGNITUDE_MAX){
    printf("[ERRO]\nMagnitude inválida! Insira um número entre %d e %d.\n", MAGNITUDE_MIN, MAGNITUDE_MAX);
    return 0;
  }

  NoAVL *no = avl_buscar_evento(avl, id);

  if (no == NULL){
    printf("[ERRO]\nEvento não encontrado!\n");
    return 0;
  }

  if (no->evento.status == RESOLVIDO){
    printf("[ATENÇÃO]\nNão é possível alterar magnitude um evento já resolvido\n");
    return 0;
  }

  no->evento.magnitude = nova_magnitude;
  return 1;

}
