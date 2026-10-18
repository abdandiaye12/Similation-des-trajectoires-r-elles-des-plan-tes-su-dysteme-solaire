All: Executable
	./Executable

Executable: main.o fonctions.o vecteurs.o
	gcc main.o fonctions.o vecteurs.o -o Executable -lm && rm -f *.o

main.o: ./code_c/main.c ./code_c/ressources/fonctions.h ./code_c/ressources/vecteurs.h ./code_c/ressources/constantes.h
	gcc -Wall -c ./code_c/main.c -o main.o -lm

fonctions.o: ./code_c/fonctions.c ./code_c/ressources/fonctions.h ./code_c/ressources/constantes.h
	gcc -Wall -c ./code_c/fonctions.c -o fonctions.o -lm

vecteurs.o: ./code_c/vecteurs.c ./code_c/ressources/vecteurs.h
	gcc -Wall -c ./code_c/vecteurs.c -o vecteurs.o -lm

clean:
	rm -f *.o Executable