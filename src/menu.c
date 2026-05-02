#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// /\/\/\ leitura e validação de entradas
int ler_int(const char *instruction, int min, int max){
  int valor;
  int valido = 0;

  do {
    printf("%s", instruction);
    if (scanf("%d", &valor) == 1 && valor >= min && valor <= max){
      valido = 1;
    } else {
      printf("[ERRO]\nEntrada inválida! Informe um número entre %d e %d.", min, max);
    }

    while(getchar() != '\n'); // limpa buffer

  } while(!valido);

  return valor;
}

void ler_string(const char *instruction, char *buffer, int tam){
  printf("%s", instruction);
  if (fgets(buffer, tam, stdin) != NULL){
    // tira \n
    int len = strlen(buffer);
    if (len > 0 && buffer[len-1] == '\n')
      buffer[len - 1] = '\0';
  }
}

void limpa_tela(void){
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}

void pausa(void){
  printf("Pressione Enter para continuar...");
  while(getchar() != '\n');
}
