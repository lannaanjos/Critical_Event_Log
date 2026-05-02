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


static void _exibir_tipos_evento(void) {
  printf("\n--- Acidentes de Transito ---\n");
  printf("  0  - Acidente de Transito sem Vitimas\n");
  printf("  1  - Acidente de Transito com Vitima Leve\n");
  printf("  2  - Acidente de Transito com Vitima Grave\n");
  printf("  3  - Engavetamento na Via Expressa\n");
  printf("  4  - Atropelamento de Pedestre\n");
  printf("  5  - Veiculo em Chamas na Pista\n");
 
  printf("\n--- Infraestrutura ---\n");
  printf("  6  - Semaforo Inoperante\n");
  printf("  7  - Semaforo Intermitente\n");
  printf("  8  - Queda de Poste de Iluminacao\n");
  printf("  9  - Bueiro Aberto\n");
 
  printf("\n--- Energia ---\n");
  printf("  10 - Queda de Energia - Bairro Residencial\n");
  printf("  11 - Queda de Energia - Centro Comercial\n");
  printf("  12 - Queda de Energia - Area Industrial\n");
  printf("  66 - Queda de Energia em Hospital\n");
  printf("  13 - Explosao de Transformador\n");
  printf("  14 - Blecaute Total\n");
 
  printf("\n--- Alagamento ---\n");
  printf("  15 - Alagamento - Bairro Residencial\n");
  printf("  16 - Alagamento - Centro Comercial\n");
  printf("  17 - Alagamento - Zona Industrial\n");
  printf("  18 - Galeria Pluvial Transbordando\n");
 
  printf("\n--- Incendio ---\n");
  printf("  19 - Queima de Lixo ou Mato\n");
  printf("  20 - Incendio Florestal\n");
  printf("  21 - Incendio em Edificio Residencial\n");
  printf("  22 - Incendio em Edificio Comercial\n");
  printf("  23 - Incendio em Planta Industrial\n");
  printf("  24 - Incendio em Regiao Periferica\n");
  printf("  25 - Incendio em Shopping Center\n");
  printf("  26 - Incendio em Instituicao de Ensino\n");
  printf("  27 - Incendio em Predio Publico\n");
  printf("  28 - Incendio em Massa\n");
 
  printf("\n--- Desastres Naturais ---\n");
  printf("  29 - Ventania\n");
  printf("  30 - Vendaval\n");
  printf("  31 - Ciclone\n");
  printf("  32 - Tornado\n");
  printf("  33 - Chuva de Granizo\n");
  printf("  34 - Tempestade Media\n");
  printf("  35 - Tempestade Severa\n");
  printf("  36 - Tempestade Critica\n");
  printf("  37 - Onda de Calor Extremo\n");
  printf("  38 - Onda de Frio Extremo\n");
  printf("  39 - Nevasca\n");
  printf("  40 - Enchente\n");
  printf("  41 - Terremoto\n");
 
  printf("\n--- Seguranca Publica ---\n");
  printf("  42 - Furto\n");
  printf("  43 - Assalto a Transeuntes\n");
  printf("  44 - Arrastao\n");
  printf("  51 - Assalto ao Banco\n");
  printf("  45 - Sequestro de Transeunte\n");
  printf("  46 - Sequestro de Onibus\n");
  printf("  47 - Sequestro de Aviao\n");
  printf("  48 - Tiroteio em Via Publica\n");
  printf("  49 - Tiroteio Escolar\n");
  printf("  50 - Invasao Armada a Edificio\n");
  printf("  52 - Confronto de Faccoes\n");
  printf("  53 - Bomba em Via Publica\n");
 
  printf("\n--- Desastres Estruturais ---\n");
  printf("  54 - Deslizamento de Terra em Comunidade\n");
  printf("  55 - Desabamento de Predio Residencial\n");
  printf("  56 - Desabamento de Instituicao de Ensino\n");
  printf("  57 - Desabamento de Predio Comercial\n");
  printf("  58 - Desabamento de Planta Industrial\n");
  printf("  59 - Colapso de Viaduto\n");
  printf("  60 - Vazamento de Gas em Area Densamente Povoada\n");
  printf("  61 - Vazamento Quimico - Zona Industrial\n");
  printf("  62 - Explosao de Posto de Combustivel\n");
  printf("  63 - Rompimento de Barragem\n");
 
  printf("\n--- Saude Publica ---\n");
  printf("  64 - Surto de Doenca\n");
  printf("  65 - Contaminacao de Agua Potavel\n\n");
}
