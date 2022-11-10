text0 = 
text1 = Se procedera a compilar la práctica...
text2 = Modo de empleo:
text3 = ./p06_automata_simulator input.fa input.txt
text4 = Se ha eliminado el fichero ejecutable y los ficheros objetos.

CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = src/p06_automata_simulator.o src/symbol.o src/alphabet.o src/transition.o src/state.o src/automata.o

all: ${OBJS}
	@echo $(text0)
	@echo $(text1)
	$(CC) $(CXXFLAGS) -o p06_automata_simulator ${OBJS}
	@echo $(text0)
	@echo $(text2)
	@echo $(text3)

clean: 
	rm -rf src/*.o p06_automata_simulator
	@echo $(text4)