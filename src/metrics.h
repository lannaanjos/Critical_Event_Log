#ifndef METRICS_H
#define METRICS_H

#include "avl.h"

int metric_altura_total(AVL *avl);
int metric_total_nos(AVL *avl);
int metric_total_ativos(AVL *avl);
float metric_fator_balaceamento_medio(AVL *avl);
int metric_total_rotacoes(AVL *avl);
void metric_exibir_relatorio(AVL *avl);

#endif
