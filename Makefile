# --------------------
# Comandos
# --------------------
# o sinal de menos significa "se der erro, ignora e não para"
# ou seja, quando ele não conseguir deletar um arquivo (já
# deletado, ou não gerado), ele ignora.
RM 		:= -rm
CC 		:= gcc
# --------------------
# Pastas
# --------------------
SRCDIR 	:= src
OBJDIR 	:= obj
BINDIR 	:= bin
TSTDIR  := test
INCDIR  := inc
LIBDIR  := lib
# --------------------
# Arquivos
# --------------------
SRC 	:= $(wildcard $(SRCDIR)/*.c)
MAIN 	:= $(SRCDIR)/main.c
MAINO 	:= $(OBJDIR)/main.o
TARGET 	:= $(BINDIR)/main
# -lXXX vai procurar um arquivo com nome libXXX.a
LIB		:= $(wildcard $(LIBDIR)/*.o) $(wildcard $(LIBDIR)/*.a) -lopengl32 -lgdi32 -lwinmm
OBJ 	:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# --------------------
# Flags para o compilador
# --------------------
# Sobre as flags utilizadas: I é para a diretiva #include encontrar arquivos em
# tal pasta. -Wall pede todos os avisos (Warning:all) e -g ajuda no debugger
# porque preserva o número da linha de código.
CFLAGS 	:= -Iinc -Wall -g
CXXFLAGS:= -Iinc -Wall -g
TSTFLAG :=
LNKFLAG := -static
# --------------------
# Regras de compilação
# --------------------

# all é o default. O comando 'make' sem argumentos cai aqui.
all: $(TARGET)

# Usamos o comando 'make clean' quando mudamos o tamanho de alguma coisa e
# queremos recompilar TUDO. Por padrão, ele só recompilaria arquivos .c que mudaram
clean:
	$(RM) $(OBJ) $(TSTOBJ)

# A 'receita' para arquivos obj (que são os .o) envolve os arquivos .c correspondentes
obj/%.o: src/%.c
	$(CC)  $(CFLAGS) -c $(@:$(OBJDIR)/%.o=$(SRCDIR)/%.c) -o $@

# O arquivo executável final depende de todos os arquivos .o (que não são de testes)
$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LIB)
