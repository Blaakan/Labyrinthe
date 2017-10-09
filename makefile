CFLAGS = -O3 -Wall -g
LDLIBS = -L /usr/X11R6/lib -lX11
IFLAGS = -Iinclude
OPATH = obj/
CPATH = src/

vpath %.h include
vpath %.c src
vpath %.o obj
vpath main bin

ALL=cheminlab genlaby

all:$(ALL)

cheminlab : cheminlab.o graph.o ensemble.o matrice.o fct_laby.o
	gcc $(CFLAGS) -o cheminlab $(OPATH)cheminlab.o $(OPATH)graph.o $(OPATH)ensemble.o $(OPATH)matrice.o $(OPATH)fct_laby.o $(LDLIBS)
	mv cheminlab bin/

genlaby : genlaby.o ensemble.o matrice.o fct_laby.o
	gcc $(CFLAGS) -o genlaby $(OPATH)genlaby.o $(OPATH)graph.o $(OPATH)ensemble.o $(OPATH)matrice.o $(OPATH)fct_laby.o $(LDLIBS)
	mv genlaby bin/

graph.o : graph.c graph.h
	gcc $(CFLAGS) -c $(CPATH)graph.c $(IFLAGS) $(LDLIBS)
	mv graph.o $(OPATH)

ensemble.o : ensemble.c ensemble.h 
	gcc $(CFLAGS) -c $(CPATH)ensemble.c $(IFLAGS)
	mv ensemble.o $(OPATH)

matrice.o : matrice.c matrice.h 
	gcc $(CFLAGS) -c $(CPATH)matrice.c $(IFLAGS)
	mv matrice.o $(OPATH)

fct_laby.o : fct_laby.c fct_laby.h 
	gcc $(CFLAGS) -c $(CPATH)fct_laby.c $(IFLAGS) $(LDLIBS)
	mv fct_laby.o $(OPATH)

genlaby.o : genlaby.c constante.h
	gcc $(CFLAGS) -c $(CPATH)genlaby.c $(IFLAGS)
	mv genlaby.o $(OPATH)

cheminlab.o : cheminlab.c constante.h
	gcc $(CFLAGS) -c $(CPATH)cheminlab.c $(IFLAGS)
	mv cheminlab.o $(OPATH)

doc: 
	doxygen Doxyfile

clean : 
	rm obj/* bin/*
