#ifndef QUERIES_H
#define QUERIES_H

#include "avl.h"

int query_ativos_por_magnitude(AVL *avl, int mag_min, int mag_max);
int query_ativos_por_regiao(AVL *avl, const char *regiao);
int query_eventos_por_intervalo(AVL *avl, int id_min, int id_max);

#endif
