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
