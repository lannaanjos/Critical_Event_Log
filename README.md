# Sistema de Gerenciamento de Eventos Críticos
Sistema desenvolvido em C para simular o monitoramento de eventos urbanos a partir de uma árovre AVL.

## Compilação
*Pré-requisitos*:
- GCC instalado
- Sistema operacional Linux ou Windows com MinGW instalado.

#### Compilar
```
make
```

### Compilar e executar
```
make run
```

### Remover executável
```
make clean
```

### Compilação manual (sem make)
```
gcc -Wall -Wextra -pedantic -g -o cidade_inteligente src/main.c src/event.c src/avl.c src/queries.c src/metrics.c src/menu.c
```

## Descrição
O sistema permite o cadastro, consulta, atualização e remoção de eventos críticos urbanos como acidentes de trânsito, falhas em semáforos, interrupções de energia, alagamentos, incêndios, desastres naturais, ocorrências de segurança pública, desastres estruturais e surtos de saúde pública.
O sistema suporta 67 tipos de eventos distribuídos em 8 categorias:
- Acidentes de Trânsito
- Infraestrutura
- Energia
- Alagamento
- Incêndio
- Desastres Naturais
- Segurança Pública
- Desastres Estruturais
- Saúde Pública

### Módulos
```
cidade_inteligente/
├── src/
│   ├── main.c        # Ponto de entrada
│   ├── event.h/c     # Definições e utilitários do Evento
│   ├── avl.h/c       # Árvore AVL completa
│   ├── queries.h/c   # Consultas avançadas
│   ├── metrics.h/c   # Métricas da árvore
│   └── menu.h/c      # Interface textual
├── docs/
│   └── relatorio.md  # Relatório técnico com testes
├── Makefile
└── README.md
```
**`event`** — Define o tipo `Evento` com seus campos (ID, tipo, magnitude, timestamp, região, status) e funções utilitárias de validação e exibição. A magnitude é atribuída automaticamente com base no tipo do evento via `magnitude_por_tipo`.
 
**`avl`** — Implementa a Árvore AVL completa: inserção, remoção (apenas eventos resolvidos), busca por ID, rotações simples e duplas, rebalanceamento e atualização de campos. Mantém contadores de nós, ativos e rotações.
 
**`queries`** — Consultas avançadas sobre a árvore: eventos ativos por intervalo de magnitude, eventos ativos por região (percurso em-ordem) e eventos por intervalo de ID (com poda BST).
 
**`metrics`** — Calcula e exibe métricas da árvore: altura total, total de nós, eventos ativos, fator de balanceamento médio e total de rotações realizadas.
 
**`menu`** — Interface textual interativa com submenus organizados, validação de todas as entradas e confirmação antes de operações destrutivas.

### Desenvolvido por
Lanna dos Anjos Costa, 2026 
