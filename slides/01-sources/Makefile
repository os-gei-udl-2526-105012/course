 # ==============================================================================
 #	 Name: Makefile
 #	 Description: Makefile per compilar tots els fitxers .c d'un directori
 #   Author: Jordi Mateo
 #   Organization: Universitat de Lleida
 # ==============================================================================
 
# Variables d'entorn
# CC: compilador
# CFLAGS: flags de compilació
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Definim les variables BIN i SRC 
# BIN conté el nom del directori on es guardaran els executables
# SRC conté el nom del directori on es guardaran els fitxers .c
BIN = bin
SRC = sources

# Creem el directori bin si no existeix
# Per evitar que Make tracti aquesta com una regla d'execució, afegim .PHONY
.PHONY: all help clean $(BIN) run

# Obtenim tots els fitxers .c del directori sources
# wildcard és una funció de GNU Make que permet obtenir tots els fitxers d'una extensió concreta
SOURCES = $(wildcard $(SRC)/*.c)

# Generem una llista d'executables a partir dels fitxers .c
# Exemple: si tenim sources/main.c, l'executable serà bin/main
EXECUTABLES = $(patsubst $(SRC)/%.c,$(BIN)/%,$(SOURCES))

# Regla per defecte: compilar tots els executables
all: $(BIN) $(EXECUTABLES)

# Creem el directori bin si no existeix
$(BIN):
	mkdir -p $(BIN)

# Regla per compilar cada fitxer .c del directori sources en un executable al directori bin
# La variable $@ conté el nom de la regla (executable). Exemple: bin/main
# La variable $< conté la primera dependència (fitxer .c). Exemple: sources/main.c
$(BIN)/%: $(SRC)/%.c
	$(CC) $(CFLAGS) -o $@ $<

# Regla per mostrar l'ajuda
help:
	@echo "Makefile per compilar tots els fitxers .c d'un directori"
	@echo "Ús: make [all|clean|help|run]"
	@echo "  all: compila tots els fitxers .c del directori sources"
	@echo "  clean: esborra tots els executables del directori bin"
	@echo "  bin/<nom>.c: compila el fitxer <nom>.c del directori sources"
	@echo "  run EXEC=<nom> ARGS='<arguments>': executa el fitxer bin/<nom> amb arguments"
	@echo "  help: mostra aquesta ajuda"

# Regla per executar un dels executables
run: $(BIN)/$(EXEC)
	@ if [ -f "$<" ]; then \
		echo "Executant $< amb arguments: $(ARGS)..."; \
		./$< $(ARGS); \
	else \
		echo "Error: no s'ha trobat l'executable $(BIN)/$(EXEC)"; \
	fi

# Esborra tots els executables del directori bin
clean:
	rm -f $(BIN)/*
