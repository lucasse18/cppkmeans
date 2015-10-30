TARGET = cppkmeans

CC = g++
CFLAGS = -std=c++11 -Wall -ggdb3

INCLUDE = "include"

SOURCE = src/main.cpp\
	src/Algoritmo.cpp\
	src/InicializacaoSimples.cpp\
	src/InicializacaoPP.cpp\
	src/IteracaoSimples.cpp\
	src/IteracaoYinYang.cpp\
	src/Leitura.cpp\
	src/Exemplo.cpp\
	src/Dataset.cpp

${TARGET}: ${SOURCE}
	${CC} ${CFLAGS} -I ${INCLUDE} -o $@ $^

clean:
	rm ${TARGET}
