CC=gcc
RM=rm
CFLAGS=-Wall -O3 -Wstrict-prototypes -Wmissing-prototypes -Wshadow -Wconversion
SRC = src
BIN = bin

.PHONY: all help clean $(BIN) run

SOURCES = $(wildcard $(SRC)/*.c)

EXECUTABLES = $(patsubst $(SRC)/%.c,$(BIN)/%,$(SOURCES))

all: $(BIN) $(EXECUTABLES)

$(BIN):
	mkdir -p $(BIN)

$(BIN)/%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<

help:
	@echo "Makefile per compilar tots els fitxers .c d'un directori"
	@echo "Ús: make [all|clean|help|run]"
	@echo "  all: compila tots els fitxers .c del directori sources"
	@echo "  clean: esborra tots els executables del directori bin"
	@echo "  bin/<nom>.c: compila el fitxer <nom>.c del directori sources"
	@echo "  run EXEC=<nom> ARGS='<arguments>': executa el fitxer bin/<nom> amb arguments"
	@echo "  help: mostra aquesta ajuda"

run: $(BIN)/$(EXEC)
	@ if [ -f "$<" ]; then \
		echo "Executant $< amb arguments: $(ARGS)..."; \
		./$< $(ARGS); \
	else \
		echo "Error: no s'ha trobat l'executable $(BIN)/$(EXEC)"; \
	fi

clean:
	rm -f $(BIN)/*