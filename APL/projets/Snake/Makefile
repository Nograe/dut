FLAG = -lgraph

all: main snake menu settings
	@echo "Création du fichier éxecutable ..."
	@gcc -o exe main.o snake.o menu.o settings.o $(FLAG)

main: main.c main.h
	@echo "Création du fichier objet \"main.o\" ..."
	@gcc -c main.c

snake: snake.c snake.h
	@echo "Création du fichier objet \"snake.o\" ..."
	@gcc -c snake.c

menu: menu.c menu.h
	@echo "Création du fichier objet \"menu.o\" ..."
	@gcc -c menu.c

settings: settings.c settings.h
	@echo "Création du fichier objet \"settings.o\" ..."
	@gcc -c settings.c

clean:
	@echo "Suppression des fichiers objets..."
	@rm *.o
