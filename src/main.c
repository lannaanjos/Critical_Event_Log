#include <stdio.h>
#include <stdlib.h>

#include "avl.h"
#include "menu.h"

int main(){
  AVL *avl = criar_avl();
  if (avl == NULL){
    printf("[ERRO]\nIncialização da árvore falhou!\n");
    return 1;
  }
  menu_principal(avl);
  destruir_avl(avl);
  return 0;
}
