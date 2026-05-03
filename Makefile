CC      = gcc
CFLAGS  = -Wall -Wextra -pedantic -g
TARGET  = cidade_inteligente
SRCDIR  = src

SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/event.c \
       $(SRCDIR)/avl.c \
       $(SRCDIR)/queries.c \
       $(SRCDIR)/metrics.c \
       $(SRCDIR)/menu.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
