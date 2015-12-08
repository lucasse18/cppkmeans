CC = g++
CFLAGS = -std=c++11 -Wall -O3
DBGFLAGS = -std=c++11 -Wall -ggdb3
PRFFLAGS = -std=c++11 -Wall -O3 -pg

DATA_FILES =\
	src/Dados/Dataset.cpp\
  src/Dados/Leitura.cpp\
  src/Dados/MementoDataset.cpp\
  src/Dados/MementoMelhorCluster.cpp

KMEANS_FILES =\
	lib/kmeans.c\
	src/Algoritmos/KMeans/Inicializacao.h\
  src/Algoritmos/KMeans/InicializacaoSimples.cpp\
  src/Algoritmos/KMeans/InicializacaoPP.cpp\
  src/Algoritmos/KMeans/Iteracao.h\
  src/Algoritmos/KMeans/IteracaoSimples.cpp\
  src/Algoritmos/KMeans/IteracaoYY.cpp\
  src/Algoritmos/KMeans/KMeans.cpp\
  src/Algoritmos/KMeans/Lloyd.cpp\
  src/Algoritmos/KMeans/YinYang.cpp\
  src/Algoritmos/KMeans/KMeansPP.cpp

CLI_FILES =\
	src/CLI/main.cpp

GUI_FILES =\
	src/GUI/JanelaPrincipal.h\
  src/GUI/JanelaPrincipal.cpp\
  src/GUI/main-gtk.cpp

INCLUDES = -I"src/Algoritmos/KMeans" -I"src/Dados" -I"lib"

# Release
CLI_TARGET = kmeans
${CLI_TARGET}: ${DATA_FILES} ${KMEANS_FILES} ${CLI_FILES}
	${CC} ${CFLAGS} ${INCLUDES} -I "src/CLI" -I"lib" -o $@ $^

GUI_TARGET = kmeans-gtk
${GUI_TARGET}: ${DATA_FILES} ${KMEANS_FILES} ${GUI_FILES}
	${CC} ${CFLAGS} ${INCLUDES} -I"src/Algoritmos/KMeans" -I"src/Dados" -I "src/GUI" -o $@ $^


# Debug
debug: ${DATA_FILES} ${KMEANS_FILES} ${CLI_FILES}
	${CC} ${DBGFLAGS} ${INCLUDES} -I "src/CLI" -o $@ $^

debug-gtk: ${DATA_FILES} ${KMEANS_FILES} ${GUI_FILES}
	${CC} ${DBGFLAGS} ${INCLUDES} -I "src/GUI" -o $@ $^


# Profile
prof: ${DATA_FILES} ${KMEANS_FILES} ${CLI_FILES}
	${CC} ${PRFFLAGS} ${INCLUDES} -I "src/CLI" -o $@ $^

prof-gtk: ${DATA_FILES} ${KMEANS_FILES} ${GUI_FILES}
	${CC} ${PRFFLAGS} ${INCLUDES} -I "src/GUI" -o $@ $^

clean:
	rm ${CLI_TARGET}
	rm ${GUI_TARGET}
	rm debug
	rm debug-gtk
	rm prof
	rm prof-gtk
