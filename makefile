text0 = 
text1 = Compilación del proyecto...
text2 = Modo de empleo:
text3 = ./dfa2grammar input.fa output.gra
text4 = Se han eliminado el fichero ejecutable y los ficheros objetos.

CC=g++
CXXFLAGS=-g -std=c++14

OBJS = src/dfa2grammar.o src/alphabet.o src/transition.o src/state.o src/automata.o src/chain.o src/grammar.o

all: ${OBJS}
	@echo $(text0)
	@echo $(text1)
	$(CC) $(CXXFLAGS) -o dfa2grammar ${OBJS}
	@echo $(text0)
	@echo $(text2)
	@echo $(text3)

clean: 
	rm -rf src/*.o dfa2grammar
	@echo $(text4)