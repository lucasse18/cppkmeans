TARGET = cppkmeans

CC = g++
CFLAGS = -std=c++11 -Wall -O3 -ggdb3

INCLUDE = "include"
LIB = "lib"

SOURCE = src/main.cpp\
	src/Dataset.cpp\
	src/InicializacaoSimples.cpp\
	src/InicializacaoPP.cpp\
	src/IteracaoSimples.cpp\
	src/IteracaoYY.cpp\
	src/KMeans.cpp\
	src/Lloyd.cpp\
	src/YinYang.cpp\
	src/KMeansPP.cpp\
	src/Leitura.cpp\
	lib/kmeans.c


${TARGET}: ${SOURCE}
	${CC} ${CFLAGS} -I${INCLUDE} -I${LIB} -L${LIB} -o $@ $^

clean:
	rm ${TARGET}
