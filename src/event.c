#include <stdio.h>
#include <string.h>
#include "event.h"


const char *tipo_p_string(TipoEvento tipo) {
  switch (tipo) {
    // acidente de trânsito
    case ACIDENTE_DE_TRANSITO_SEM_VITIMAS:
      return "Acidente de Transito sem Vitimas";

    case ACIDENTE_DE_TRANSITO_COM_VITIMA_LEVE:
      return "Acidente de Transito com Vitima Leve";
       
    case ACIDENTE_DE_TRANSITO_COM_VITIMA_GRAVE:
      return "Acidente de Transito com Vitima Grave";
        
    case ENGAVETAMENTO_NA_VIA_EXPRESSA:
      return "Engavetamento na Via Expressa";

    case ATROPELAMENTO_DE_PEDESTRE:
      return "Atropelamento de Pedestre";

    case VEICULO_EM_CHAMAS_NA_PISTA:
      return "Veiculo em Chamas na Pista";
 
    // infraestrutura
    case SEMAFORO_INOPERANTE:
      return "Semaforo Inoperante";

    case SEMAFORO_INTERMITENTE:
      return "Semaforo Intermitente";

    case QUEDA_DE_POSTE_ILUMINACAO:
      return "Queda de Poste de Iluminacao";

    case BUEIRO_ABERTO:
      return "Bueiro Aberto"; 

    // energia
    case QUEDA_DE_ENERGIA_BAIRRO_RESIDENCIAL:
      return "Queda de Energia - Bairro Residencial";

    case QUEDA_DE_ENERGIA_CENTRO_COMERCIAL:
      return "Queda de Energia - Centro Comercial";

    case QUEDA_DE_ENERGIA_AREA_INDUSTRIAL:
      return "Queda de Energia - Area Industrial";

    case QUEDA_DE_ENERGIA_EM_HOSPITAL:
      return "Queda de Energia em Hospital";
    
    case EXPLOSAO_DE_TRANSFORMADOR:
      return "Explosao de Transformador";
    
    case BLECAUTE_TOTAL:
      return "Blecaute Total"; 
    
    // alagamento    
    case ALAGAMENTO_BAIRRO_RESIDENCIAL:
      return "Alagamento - Bairro Residencial";
    
    case ALAGAMENTO_CENTRO_COMERCIAL:
      return "Alagamento - Centro Comercial";
    
    case ALAGAMENTO_ZONA_INDUSTRIAL:
      return "Alagamento - Zona Industrial";
    
    case GALERIA_PLUVIAL_TRANSBORDANDO:
      return "Galeria Pluvial Transbordando"; 
    
    // incêndio    
    case QUEIMA_DE_LIXO_OU_MATO:
      return "Queima de Lixo ou Mato";
    
    case INCENDIO_FLORESTAL:
      return "Incendio Florestal";
    
    case INCENDIO_EM_EDIFICIO_RESIDENCIAL:
      return "Incendio em Edificio Residencial";
    
    case INCENDIO_EM_EDICIO_COMERCIAL:
      return "Incendio em Edificio Comercial";
    
    case INCENDIO_EM_PLANTA_INDUSTRIAL:
      return "Incendio em Planta Industrial";
    
    case INCENDIO_EM_REGIAO_PERIFERICA:
      return "Incendio em Regiao Periferica";
    
    case INCENDIO_EM_SHOPPING_CENTER:
      return "Incendio em Shopping Center";
    
    case INCENDIO_EM_INSTITUICAO_DE_ENSINO:
      return "Incendio em Instituicao de Ensino";
    
    case INCENDIO_EM_PREDIO_PUBLICO:
      return "Incendio em Predio Publico";
    
    case INCENDIO_EM_MASSA:
      return "Incendio em Massa"; 
    
    // desastres naturais    
    case VENTANIA:
      return "Ventania";
    
    case VENDAVAL:
      return "Vendaval";
    
    case CICLONE:
      return "Ciclone";
    
    case TORNADO:
      return "Tornado";
    
    case CHUVA_DE_GRANIZO:
      return "Chuva de Granizo";
    
    case TEMPESTADE_MEDIA:
      return "Tempestade Media";
    
    case TEMPESTADE_SEVERA:
      return "Tempestade Severa";
    
    case TEMPESTADE_CRITICA:
      return "Tempestade Critica";
    
    case ONDA_DE_CALOR_EXTREMO:
      return "Onda de Calor Extremo";
    
    case ONDA_DE_FRIO_EXTREMO:
      return "Onda de Frio Extremo";
    
    case NEVASCA:
      return "Nevasca";
    
    case ENCHENTE:
      return "Enchente";
    
    case TERREMOTO:
      return "Terremoto";
    
    // segurança pública     
    case FURTO:
      return "Furto";
    
    case ASSALTO_A_TRANSEUNTES:
      return "Assalto a Transeuntes";
    
    case ARRASTAO:
      return "Arrastao";
    
    case ASSALTO_AO_BANCO:
      return "Assalto ao Banco";
    
    case SEQUESTRO_DE_TRANSEUNTE:
      return "Sequestro de Transeunte";
    
    case SEQUESTRO_DE_ONIBUS:
      return "Sequestro de Onibus";
    
    case SEQUESTRO_DE_AVIAO:
      return "Sequestro de Aviao";
    
    case TIROTEIO_EM_VIA_PUBLICA:
      return "Tiroteio em Via Publica";
    
    case TIROTEIO_ESCOLAR:
      return "Tiroteio Escolar";
    
    case INVASAO_ARMADA_A_EDIFICIO:
      return "Invasao Armada a Edificio";
    
    case CONFRONTO_DE_FACCOES:
      return "Confronto de Faccoes";
    
    case BOMBA_EM_VIA_PUBLICA:
      return "Bomba em Via Publica";
    
    // desastres estruturais    
    case DESLIZAMENTO_DE_TERRA_EM_COMUNIDADE:
      return "Deslizamento de Terra em Comunidade";
    
    case DESABAMENTO_DE_PREDIO_RESIDENCIAL:
      return "Desabamento de Predio Residencial";
    
    case DESABAMENTO_DE_INSTUICAO_DE_ENSINO:
      return "Desabamento de Instituicao de Ensino";
    
    case DESABAMENTO_DE_PREDIO_COMERCIAL:
      return "Desabamento de Predio Comercial";
    
    case DESABAMENTO_DE_PLANTA_INDUSTRIAL:
      return "Desabamento de Planta Industrial";
    
    case COLAPSO_DE_VIADUTO:
      return "Colapso de Viaduto";
   
    case VAZAMENTO_DE_GAS_EM_AREA_DENSAMENTE_POVOADA:
      return "Vazamento de Gas em Area Densamente Povoada";
    
    case VAZAMENTO_QUIMICO_ZONA_INDUSTRIAL:
      return "Vazamento Quimico - Zona Industrial";
    
    case EXPLOSAO_DE_POSTO_DE_COMBUSTIVEL:
      return "Explosao de Posto de Combustivel";
    
    case ROMPIMENTO_DE_BARRAGEM:
      return "Rompimento de Barragem";
    
    // saúde pública    
    case SURTO_DE_DOENCA:
      return "Surto de Doenca";
    
    case CONTAMINACAO_DE_AGUA_POTAVEL:
      return "Contaminacao de Agua Potavel";
 
    // sem       
    default:
      return "Tipo Desconhecido";
    }
}

/* ---------------------------------------------------------
 * magnitude_por_tipo
 * Retorna a magnitude padrão de um tipo de evento.
 * Elimina a necessidade de entrada manual da magnitude
 * no cadastro, garantindo consistência nos dados.
 * --------------------------------------------------------- */
int magnitude_por_tipo(TipoEvento tipo) {
  switch (tipo) {

  // magnitude 1
  case ACIDENTE_DE_TRANSITO_SEM_VITIMAS:
  case SEMAFORO_INTERMITENTE:
  case BUEIRO_ABERTO:
  case QUEIMA_DE_LIXO_OU_MATO:
  case VENTANIA:
  case FURTO:
  case ASSALTO_A_TRANSEUNTES:
    return 1;

  // magnitude 2
  case ACIDENTE_DE_TRANSITO_COM_VITIMA_LEVE:
  case SEMAFORO_INOPERANTE:
  case QUEDA_DE_POSTE_ILUMINACAO:
  case ALAGAMENTO_BAIRRO_RESIDENCIAL:
  case ALAGAMENTO_CENTRO_COMERCIAL:
  case QUEDA_DE_ENERGIA_BAIRRO_RESIDENCIAL:
  case QUEDA_DE_ENERGIA_CENTRO_COMERCIAL:
  case VENDAVAL:
  case CHUVA_DE_GRANIZO:
  case TEMPESTADE_MEDIA:
    return 2;

  // magnitude 3
  case VAZAMENTO_DE_GAS_EM_AREA_DENSAMENTE_POVOADA:
  case ARRASTAO:
  case GALERIA_PLUVIAL_TRANSBORDANDO:
  case INCENDIO_FLORESTAL:
  case ACIDENTE_DE_TRANSITO_COM_VITIMA_GRAVE:
  case ENGAVETAMENTO_NA_VIA_EXPRESSA:
  case ATROPELAMENTO_DE_PEDESTRE:
  case QUEDA_DE_ENERGIA_AREA_INDUSTRIAL:
  case ALAGAMENTO_ZONA_INDUSTRIAL:
  case INCENDIO_EM_EDIFICIO_RESIDENCIAL:
  case INCENDIO_EM_REGIAO_PERIFERICA:
  case INCENDIO_EM_INSTITUICAO_DE_ENSINO:
  case TEMPESTADE_SEVERA:
  case ONDA_DE_CALOR_EXTREMO:
  case ONDA_DE_FRIO_EXTREMO:
  case ENCHENTE:
  case ASSALTO_AO_BANCO:
  case SEQUESTRO_DE_TRANSEUNTE:
  case EXPLOSAO_DE_POSTO_DE_COMBUSTIVEL:
  case SURTO_DE_DOENCA:
  case VEICULO_EM_CHAMAS_NA_PISTA:
  case EXPLOSAO_DE_TRANSFORMADOR:
    return 3;

  // magnitude 4
  case DESABAMENTO_DE_PREDIO_RESIDENCIAL:
  case DESABAMENTO_DE_PREDIO_COMERCIAL:
  case VAZAMENTO_QUIMICO_ZONA_INDUSTRIAL:
  case TIROTEIO_EM_VIA_PUBLICA:
  case DESLIZAMENTO_DE_TERRA_EM_COMUNIDADE:
  case CONTAMINACAO_DE_AGUA_POTAVEL:
  case QUEDA_DE_ENERGIA_EM_HOSPITAL:
  case INCENDIO_EM_PLANTA_INDUSTRIAL:
  case INCENDIO_EM_SHOPPING_CENTER:
  case INCENDIO_EM_PREDIO_PUBLICO:
  case INCENDIO_EM_EDICIO_COMERCIAL:
  case CICLONE:
  case TEMPESTADE_CRITICA:
  case NEVASCA:
  case SEQUESTRO_DE_ONIBUS:
  case INVASAO_ARMADA_A_EDIFICIO:
  case CONFRONTO_DE_FACCOES:
  case DESABAMENTO_DE_INSTUICAO_DE_ENSINO:
  case DESABAMENTO_DE_PLANTA_INDUSTRIAL:
  case COLAPSO_DE_VIADUTO:
  case BLECAUTE_TOTAL:
    return 4;

  // magnitude 5
  case BOMBA_EM_VIA_PUBLICA:
  case TORNADO:
  case INCENDIO_EM_MASSA:
  case TIROTEIO_ESCOLAR:
  case SEQUESTRO_DE_AVIAO:
  case ROMPIMENTO_DE_BARRAGEM:
  case TERREMOTO:
    return 5;

  default:
    return MAGNITUDE_MIN;
  }
}

const char *status_p_string(StatusEvento status){
  switch(status){
    case ATIVO:
      return "Ativo";
    case RESOLVIDO:
      return "Resolvido";
    default:
      return "Desconhecido";
  }
}

int valida_datahora(const DataHora *dh){
  if (dh == NULL)
    return 0;

  if(dh->ano < 1900 || dh->ano > 2100)
    return 0;

  if(dh->mes < 1 || dh->mes >12)
    return 0;

  if (dh->dia < 1 || dh->dia < 31 || // n passa de 31 dias
     ((dh->mes == 4 || dh->mes == 6 || dh->mes == 9 || dh->mes == 11) && dh->dia > 30) || // meses com 30 dias
     (dh->mes == 2 && ((dh->ano % 400 == 0 || (dh->ano % 4 == 0 && dh->ano % 100 != 0)) ? dh->dia > 29 : dh->dia > 28))) // verificação ano bissexto
    return 0;

  if(dh->hora < 0 || dh->hora > 23)
    return 0;

  if(dh->minuto < 0 || dh -> minuto > 59)
    return 0;

  if(dh->segundo < 0 || dh->segundo > 59)
    return 0;

  return 1;
}

void datahora_p_string(const DataHora *dh, char *buffer, int tam_buffer){
  if (dh == NULL || buffer == NULL || tam_buffer < 20){
    return;
  }

  snprintf(buffer, tam_buffer, "%02d/%02d/%04d %02d:%02d:%02d",
           dh->dia, dh->mes, dh->ano,
           dh->hora, dh->minuto, dh->segundo);
}

int valida_evento(const Evento *e){
  if (e == NULL)
    return 0;

  if (e->id <= 0)
    return 0;

  if (e->magnitude < MAGNITUDE_MIN || e->magnitude > MAGNITUDE_MAX)
    return 0;

  if (!valida_datahora(&e->timestamp))
    return 0;

  if (strlen(e->regiao) == 0)
    return 0;

  if (e->status != ATIVO && e->status != RESOLVIDO)
    return 0;

  return 1;
}

void exibe_evento(const Evento *e){
  if (e == NULL){
    printf("[ERRO]\nEvento inválido\n");
    return;
  }

  char bff_timestamp[20];
  datahora_p_string(&e->timestamp, bff_timestamp, sizeof(bff_timestamp));

  printf("ID          | %-5d \n", e->id);
  printf("Tipo        | %-31s \n", tipo_p_string(e->tipo));
  printf("Magnitude   | %d/5%-28s \n", e->magnitude, "");
  printf("Data e Hora | %-31s\n", bff_timestamp);
  printf("Região      | %-31s\n", e->regiao);
  printf("Status      | %-31s\n", status_p_string(e->status));
}
