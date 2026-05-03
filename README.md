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


```


