#include <stdio.h>
#include <stdlib.h>

/*Expresión regular: ((u+U).(l+L+ε)) + ((l+L).(u+U+ε))
Estados: {0-,1+,2+,3+,4}
Alfabeto: {u, U, l, L} (l es una L minúscula)
Palabras: {u, U, l, L, ul, uL, Ul, UL, lu, lU, Lu, LU}*/

int columna(char c){
	switch(c){
		case 'u': return 0;
		case 'U': return 1;
		case 'l': return 2;
		case 'L': return 3;
	}
}

int esSufijo(const char* cadena){
	static int TT[5][4] = {{1,1,2,2},
						{4,4,3,3},
						{3,3,4,4},
						{4,4,4,4},
						{4,4,4,4}};
	int e = 0;
	unsigned int i = 0;
	int c = cadena[0];

	while(c != '\0'){
		e = TT[e][columna(c)];
		c = cadena[++i];
	}

	if(e==1 || e==2 || e==3) return 1;
	return 0;
}

int secuenciaValidaSufijo(const char* cadena){
	int esValido = 1;
	for(unsigned int i=0; cadena[i]; i++){
		if(!(cadena[i]=='u' || cadena[i]=='U' || cadena[i]=='l' || cadena[i]=='L')) esValido = 0;
	}
	return esValido;
}

int main(int argc, char* argv[]){
	if(secuenciaValidaSufijo(argv[1])==0){
		printf("%s","Secuencia con caracteres no validos");
		return EXIT_FAILURE;
	}

	if(esSufijo(argv[1])==1){
		printf("%s","La secuencia es un sufijo valido.");
		return EXIT_SUCCESS;
	}

	else printf("%s","La secuencia no es un sufijo valido.");
	return EXIT_FAILURE;
}