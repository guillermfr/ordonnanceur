# commande pour compiler
CC=gcc
CP=cp
CFLAGS=-Wall
RM=rm -r

#nom des dossiers
SRC=src
OBJ=obj
DATA=data
DOC=doc
SAVE=save

#arguments pour trouver les éléments dans les dossiers
SRCS=$(wildcard $(SRC)/*.c)
HEADS=$(wildcard $(SRC)/*.h)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

RESTORESRC=$(wildcard $(SAVE)/*.c)
RESTOREHEAD=$(wildcard $(SAVE)/*.h)

#dossier pour l'executable
BINDIR=bin
BIN=$(BINDIR)/main

#varilable pour l'archivage
nameArchive=guillerm_francois

#programme du make
all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean save restore give dox math

save:
	@$(CP) $(SRCS) $(HEADS) $(SAVE)
	@echo Fichiers sauvegarde.

restore:
	@$(CP) $(RESTORESRC) $(RESTOREHEAD) $(SRC)
	@echo Sauvegarde restaure.

give:
	@mkdir $(nameArchive) $(nameArchive)/$(SRC) $(nameArchive)/$(SAVE) $(nameArchive)/$(BINDIR) $(nameArchive)/$(OBJ) $(nameArchive)/$(DATA) || echo Fichier deja existant.
	@$(CP) $(RESTORESRC) $(RESTOREHEAD) $(nameArchive)/$(SRC) || echo Rien a copier.
	@$(CP) Makefile $(nameArchive)/

clean:
	$(RM) $(BINDIR)/* || echo Rien à supprimer dans bin
	$(RM) $(OBJ)/* || echo Rien à supprimer dans obj
	$(RM) $(nameArchive) || echo Rien a supprimer dans save

dox:
	mkdir $(DOC) || echo test
	doxygen Doxyfile