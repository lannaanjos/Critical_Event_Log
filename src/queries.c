#include <stdio.h>
#include <string.h>
#include "queries.h"

// por magnitude
static int _query_magnitude_recursiva(NoAVL *no, int mag_min, int mag_max){
  if (no == NULL)
    return 0;

  int count = 0;

  count+=_query_magnitude_recursiva(no->esquerda, mag_min, mag_max);

  if (no->evento.status == ATIVO && no->evento.magnitude >= mag_min && no->evento.magnitude <= mag_max){
    exibe_evento(&no->evento);
    count++;
  }

  count += _query_magnitude_recursiva(no->direita, mag_min, mag_max);

  return count;
}

int query_ativos_por_magnitude(AVL *avl, int mag_min, int mag_max){
  if (avl == NULL)
    return 0;

  if (mag_min < MAGNITUDE_MIN || mag_max > MAGNITUDE_MAX || mag_min > mag_max){
    printf("[ERRO]\nIntervalo de magnitude inválido! Informe valores entre %d e %d", MAGNITUDE_MIN, MAGNITUDE_MAX);
    return 0;
  }

  printf("Eventos Ativos | Magnitude %d - %d\n\n", mag_min, mag_max);
  int total = _query_magnitude_recursiva(avl->raiz, mag_min, mag_max);

  if (total == 0)
    printf("Nenhum evento foi encontrado\n");
  else
    printf("Total de %d eventos encontrados\n", total);

  return total;
}

// /\/\/\ POR regiao
static int _query_regiao_recursiva(NoAVL *no, const char *regiao){
  if (avl == NULL)
    return 0;

  int count = 0;

  count += _query_regiao_recursiva(no->esquerda, regiao);

  if (no->evento.status == ATIVO && strcmp(no->evento.regiao, regiao) == 0){
    exibe_evento(&no->evento);
    count++;
  }

  count += _query_regiao_recursiva(no->direita, regiao);

  return count;
}

int query_ativos_por_regiao(AVL *avl, const char *regiao){
  if (avl == NULL)
    return 0;

  if (regiao == NULL || strlen(regiao) == 0){
    printf("[ERRO]\nRegião inválida!\n");
    return 0;
  }

  printf("Eventos Ativos | Região: %s\n\n",regiao);

  int total = _query_regiao_recursiva(avl->raiz, regiao);

  if (total == 0)
    printf("Nenhum evento foi encontrado\n");
  else
    printf("Total de %d eventos encontrados.\n", total);

  return total;
}

// /\/\/\ por intervalo de id
static int _query_intervalo_id_rec(NoAVL *no, int id_min, int id_max){
  if (no == NULL)
    return 0;

  int count = 0;

  if (no->evento.id > id_min)
    count += _query_intervalo_id_rec(no->esquerda, id_min, id_max);

  if (no->evento.id >= id_min && no->evento.id <= id_max){
    exibe_evento(&no->evento);
    count++;
  }

  if (no->evento.id < id_max)
    count += _query_intervalo_id_rec(no->direita, id_min, id_max);

  return count;
}

int query_eventos_por_intervalo(AVL *avl, int id_min, int id_max){
  if (avl == NULL)
    return 0;

  if (id_min <= 0 || id_max <= 0 || id_min > id_max){
    printf("[ERRO]\nIntervalo de ID inválido!\n");
      return 0;
  }

  printf("Eventos | ID %d - %d", id_min, id_max);

  int total = _query_intervalo_id_rec(avl->raiz, id_min, id_max);

  if (total == 0)
    printf("Nenhum evento foi encontrado\n");
  else
    printf("Total de %d eventos encontrados\n", total);

  return total;
}
