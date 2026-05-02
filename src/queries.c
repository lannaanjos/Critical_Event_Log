#include <stdio.h>
#include <string.h>
#include "queries.h"

static int _query_magnitude_recursiva(NoAvl *no, int mag_min, int mag_max){
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
