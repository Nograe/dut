CFLAGS=-Wunused-variable -Wunused-parameter
FLAG = -lgraph

all: snake

snake: main.o snake.o menu.o settings.o struct.h
	@echo "Création du fichier éxecutable $@ ..."
	@gcc -o snake main.o snake.o menu.o settings.o $(FLAG)

main.o: main.c main.h
	@echo "Création du fichier objet $@ ..."
	@gcc -c main.c $(CFLAGS)

snake.o: snake.c snake.h
	@echo "Création du fichier objet $@ ..."
	@gcc -c snake.c $(CFLAGS)

menu.o: menu.c menu.h
	@echo "Création du fichier objet $@ ..."
	@gcc -c menu.c $(CFLAGS)

settings.o: settings.c settings.h
	@echo "Création du fichier objet $@ ..."
	@gcc -c settings.c $(CFLAGS)

.PHONY: clean mrproper

clean:
	@echo "Suppression des fichiers objets..."
	@rm *.o

mrproper: clean
	@echo "Suppression de l'executable..."
	@rm snake
