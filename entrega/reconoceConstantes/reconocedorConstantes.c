#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"

int esOctal(char cadena[]){
	if(!verificaOctal(cadena)) return 0;
	if(automataOctal(cadena)) return 1;
	else return 0;
}
int esHexa(char cadena[]){
	if(!verificaHexa(cadena)) return 0;
	if(automataHexa(cadena)) return 1;
	else return 0;
}
int esDecimal(char cadena[]){
	if(!verificaDecimal(cadena)) return 0;
	if(automataDecimal(cadena)) return 1;
	else return 0;
}

int main(int argc, char *argv[]){
	char cadena[] = "";
	strcpy(cadena, argv[1]);

	if(esDecimal(cadena)){
		printf("%s","Es una constante decimal.");
		return EXIT_SUCCESS;
	}
	if(esHexa(cadena)){
		printf("%s","Es una constante hexadecimal.");
		return EXIT_SUCCESS;
	}
	if(esOctal(cadena)){
		printf("%s","Es una constante octal.");
		return EXIT_SUCCESS;
	}
	
	printf("%s", "Es una constante invalida.");
	return EXIT_FAILURE;
}