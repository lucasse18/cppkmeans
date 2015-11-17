TARGET = cppkmeans

CC = g++
CFLAGS = -std=c++11 -Wall -ggdb3

INCLUDE = "include"
#LIBS = "lib"

SOURCE = src/main.cpp\
	src/Dataset.cpp\
	src/Leitura.cpp
	#src/Inicializacao.cpp\
	#src/Iteracao.cpp\
	#src/Algoritmo.cpp\
	#src/Lloyd.cpp\
	#src/YinYang.cpp\
	#src/KMeansPP.cpp\

${TARGET}: ${SOURCE}
	${CC} ${CFLAGS} -I${INCLUDE} -o $@ $^

clean:
	rm ${TARGET}
