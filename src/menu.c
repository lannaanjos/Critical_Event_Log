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

static int _tipo_evento_valido(int valor){
  if (valor == 66) // pq esse ta n sequencial
    return 1;
  if (valor >= 0 && valor <= 65)
    return 1;

  return 0; // invalido 
}

static TipoEvento _let_tipo_evento(void){
  _exibir_tipos_evento();
  int valor;

  do {
    printf("Insira código do tipo de evento: ");
    if (scanf("%d", &valor) != 1)
      valor = -1;
    while (getchar() != '\n');
    if(!_tipo_evento_valido(valor))
      printf("[ERRO]\nCódigo inválido! Tente novamente.");
  } while(!_tipo_evento_valido(valor));

  return (TipoEvento)valor;
}

static DataHora _let_datahora(void){
  DataHora dh;

  printf("Data e Hora do Evento\n\n");
  dh.dia = ler_int("  Dia     (1-31): ", 1, 31);
  dh.mes = ler_int("  Mês     (1-12): ", 1, 12);
  dh.ano = ler_int("  Ano     (1900 - 2100): ", 1900, 2100);
  dh.hora = ler_int("  Hora    (0-23): ", 0, 23);
  dh.minuto = ler_int("  Minuto  (0-59): ", 0, 59);
  dh.segundo = ler_int("  Segundo (0-59): ", 0, 59);

  return dh;
}


// /\/\/\ SUBMENU CADASTRO
void menu_cadastro_evento(AVL *avl){
  int opcao;

  do {
    limpa_tela();
    printf("  CADASTRO DE EVENTOS\n\n");
    printf("[1] Inserir novo evento\n");
    printf("[2] Remover evento resolvido\n");
    printf("[0] Voltar\n");

    opcao = ler_int("Opção: ", 0, 2);

    if (opcao == 1){
      limpa_tela();
      printf("  INSERIR NOVO EVENTO\n\n");

      Evento e;
      e.id = ler_int("ID do evento: ", 1, 999999);
      e.magnitude = magnitude_por_tipo(e, tipo);
      e.timestamp = _let_datahora();
      ler_string("Região da cidade: ", e.regiao. TAM_MAX_NOME_REGIAO);
      e.status = ATIVO;

      printf("\n\nConfirmar cadastro?\n");
      exibe_evento(&e);
      int confirma = ler_int("[1] SIM\n[0] NÂO", 0, 1);

      if (confirma){
        if (avl_inserir_evento(avl, e))
          printf("\n[SUCESSO]\nEvento de ID %d foi inserido na árvore!", e.id);
      } else {
        printf("\n[CANCELADO]\nCadastro interrompido!");
      }

      pausa();

    } else if (opcao == 2){
      limpa_tela();
      printf("  REMOVER EVENTO RESOLVIDO\n\n");

      int id = ler_int("ID do evento a ser remnovido: ", 1, 999999);

      NoAVL *no = avl_buscar_evento(avl, id);
      if (no != NULL){
          exibe_evento(&no->evento);
        int confirma = ler_int("\nConfirmar remoção? [1] SIM [0] NÃO: ", 0, 1);
        if (confirma){
          if (avl_remover_evento(avl, id))
            printf("\n[SUCESSO]\nEvento de ID %d removido da árvore!\n", id);
        } else {
          printf("\n[CANCELADO]\nRemoção interrompida!\n");
        }
      } else {
        printf("\n[ERRO]\nEvento com ID %d não encontrado!", id);
      }
      
      pausa();

    }
  } while (opcao != 0);
}


void menu_consulta(AVL *avl){
  int opcao;
 
  do {
    limpa_tela();
    printf("  CONSULTAS\n\n");
    printf("[1] Eventos ativos por intervalo de magnitude\n");
    printf("[2] Eventos ativos por regiao\n");
    printf("[3] Eventos por intervalo de ID\n");
    printf("[0] Voltar\n\n");
 
    opcao = ler_int("Opcao: ", 0, 3);
 
    if (opcao == 1){
      limpa_tela();
      printf("  ATIVOS POR MAGNITUDE\n\n");
      int mag_min = ler_int("Magnitude minima (1-5): ", MAGNITUDE_MIN, MAGNITUDE_MAX);
      int mag_max = ler_int("Magnitude maxima (1-5): ", mag_min, MAGNITUDE_MAX);
      query_ativos_por_magnitude(avl, mag_min, mag_max);
      pausa();
 
    } else if (opcao == 2){
      limpa_tela();
      printf("  ATIVOS POR REGIAO\n\n");
      char regiao[TAM_MAX_NOME_REGIAO];
      ler_string("Nome da regiao: ", regiao, TAM_MAX_NOME_REGIAO);
      query_ativos_por_regiao(avl, regiao);
      pausa();
 
    } else if (opcao == 3){
      limpa_tela();
      printf("  EVENTOS POR INTERVALO DE ID\n\n");
      int id_min = ler_int("ID minimo: ", 1, 999999);
      int id_max = ler_int("ID maximo: ", id_min, 999999);
      query_eventos_por_intervalo_id(avl, id_min, id_max);
      pausa();
    }
 
  } while (opcao != 0);
}

void menu_atualizacoes(AVL *avl){
  int opcao;
 
  do {
    limpa_tela();
    printf("  ATUALIZAÇÕES\n\n");
    printf("[1] Alterar status do evento\n");
    printf("[2] Alterar magnitude do evento\n");
    printf("[0] Voltar\n\n");
 
    opcao = ler_int("Opção: ", 0, 2);
 
    if (opcao == 1){
      limpa_tela();
      printf("  ALTERAR STATUS\n\n");
 
      int id = ler_int("ID do evento: ", 1, 999999);
 
      NoAVL *no = avl_buscar_evento(avl, id);
      if (no == NULL){
        printf("\n[ERRO]\nEvento com ID %d não encontrado.\n", id);
      } else {
        exibe_evento(&no->evento);
        printf("Novo status:\n  [0] Ativo\n  [1] Resolvido\n");
        int s = ler_int("Opção: ", 0, 1);
        if (avl_atualizar_status(avl, id, (StatusEvento)s))
          printf("\n[SUCESSO]\nStatus do evento ID %d atualizado!\n", id);
      }
      pausa();
 
    } else if (opcao == 2){
      limpa_tela();
      printf("  ALTERAR MAGNITUDE\n\n");
 
      int id = ler_int("ID do evento      : ", 1, 999999);
 
      NoAVL *no = avl_buscar_evento(avl, id);
      if (no == NULL){
        printf("\n[ERRO]\nEvento com ID %d não encontrado.\n", id);
      } else {
        exibe_evento(&no->evento);
        int mag = ler_int("Nova magnitude (1-5): ", MAGNITUDE_MIN, MAGNITUDE_MAX);
        if (avl_atualizar_magnitude(avl, id, mag))
          printf("\n[SUCESSO]\nMagnitude do evento ID %d atualizada!\n", id);
      }
      pausa();
    }
 
  } while (opcao != 0);
}

void menu_relatorio(AVL *avl){
  int opcao;
 
  do {
    limpa_tela();
    printf("  RELATORIOS E METRICAS\n\n");
    printf("[1] Buscar evento por ID\n");
    printf("[2] Metricas da arvore\n");
    printf("[0] Voltar\n\n");
 
    opcao = ler_int("Opcao: ", 0, 2);
 
    if (opcao == 1){
      limpa_tela();
      printf("  BUSCAR EVENTO POR ID\n\n");
 
      int id = ler_int("ID do evento: ", 1, 999999);
      NoAVL *no = avl_buscar_evento(avl, id);
 
      if (no != NULL){
        printf("\n  Evento encontrado:\n");
        exibe_evento(&no->evento);
      } else {
        printf("\n[ERRO]\nEvento com ID %d não encontrado.\n", id);
      }
      pausa();
 
    } else if (opcao == 2){
      limpa_tela();
      metric_exibir_relatorio(avl);
      pausa();
    }
 
  } while (opcao != 0);
}

// /\/\/\ MENU PRINCIPAL
void menu_principal(AVL *avl){
  int opcao;

  do {
    limpa_tela();
    printf("  SISTEMA DE EVENTOS CRÍTICOS\n");
    printf("=-=-=-= Menu Principal =-=-=-=\n");
    printf("[1] Cadastro de eventos\n");
    printf("[2] Consultas\n");
    printf("[3] Atualizações\n");
    printf("[4] Relatórios e Métricas\n");
    printf("[0] Sair\n\n");

    opcao = ler_int("Opção: ", 0, 4);

    switch(opcao){
      case 1:
        menu_cadastro_evento(avl);
        break;
      case 2:
        menu_consulta(avl);
        break;
      case 3:
        menu_atualizacoes(avl);
        break;
      case 4:
        menu_relatorio(avl);
        break;
      case 0:
        printf("Encerrando...\n");
        break;
    }

  } while(opcao != 0);
}
