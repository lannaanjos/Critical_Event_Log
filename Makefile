CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = cidade_inteligente
SRDIR = src

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/event.c \
       $(SRCDIR)/avl.c \
       $(SRCDIR)/queries.c \
       $(SRCDIR)/metrics.c \
       $(SRCDIR)/menu.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)
 
# compila e executa
run: all
	./$(TARGET)
 
# remove o executável
clean:
	rm -f $(TARGET)
 
.PHONY: all run clean 
 
