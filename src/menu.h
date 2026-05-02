#ifndef MENU_H
#define MENU_H

#include "avl.h"
#include "queries.h"
#include "metrics.h"

int ler_int(const char *instruction, int min, int max);
void ler_string(const char *instruction, char *buffer, int tam);
void limpa_tela(void);
void pausa(void);
void menu_cadastro_evento(AVL *avl);
void menu_consulta(AVL *avl);
void menu_atualizacoes(AVL *avl);
void menu_relatorio(AVL *avl);
void menu_principal(AVL *avl);

#endif
