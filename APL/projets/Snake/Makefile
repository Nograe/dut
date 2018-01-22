FLAG = -lgraph

all: exe

exe: main.o snake.o menu.o settings.o struct.h
	@echo "Création du fichier éxecutable ..."
	@gcc -o exe main.o snake.o menu.o settings.o $(FLAG)

main.o: main.c main.h
	@echo "Création du fichier objet \"main.o\" ..."
	@gcc -c main.c

snake.o: snake.c snake.h
	@echo "Création du fichier objet \"snake.o\" ..."
	@gcc -c snake.c

menu.o: menu.c menu.h
	@echo "Création du fichier objet \"menu.o\" ..."
	@gcc -c menu.c

settings.o: settings.c settings.h
	@echo "Création du fichier objet \"settings.o\" ..."
	@gcc -c settings.c

.PHONY: clean mrproper

clean:
	@echo "Suppression des fichiers objets..."
	@rm *.o

mrproper: clean
	@echo "Suppression de l'executable..."
	@rm exe
	@rm *.o
