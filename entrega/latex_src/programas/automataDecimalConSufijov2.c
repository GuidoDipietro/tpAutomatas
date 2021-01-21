#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Este automata SI acepta sufijos con "u,U" si la cadena comienza con "-"

// Funcion que retorna el indice de la columna de la matriz
int columnaDecimal(int caracter) {
    if(caracter=='-') return 0;
    else if(caracter=='0') return 1;
    else if(caracter=='u' || caracter=='U') return 3;
    else if(caracter=='l' || caracter=='L') return 4;
    else return 2; //Si no es nada de lo anterior, y tiene todos simbolos validos, debe ser uno de 1-9
}

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaDecimal (char *s){
    unsigned int i = 0;
    for (i; s[i]; i++){
        if(!(isdigit(s[i]) || s[i]=='-' || s[i]=='u' || s[i]=='U' || s[i]=='l' || s[i]=='L')){
            return 0;
        }
    }
    return 1;
}

// Funcion que verifica si la cadena pertenece al lenguaje
int esPalabraDecimal (const char *cadena, int *num) {
    static int tt [9][6] = {
    	{6,5,1,5,5}, //0-
    	{5,1,1,2,3}, //1+
    	{5,5,5,5,4}, //2+
    	{5,5,5,4,5}, //3+
    	{5,5,5,5,5}, //4+
    	{5,5,5,5,5}, //5
        {5,5,1,5,5}  //6
    };
    int estado = 0; // Estado inicial
    unsigned int i = 0;
    int caracter = cadena[0];
    int signo = 1;

    while ( caracter != '\0' ) {
        estado = tt[estado][columnaDecimal(caracter)]; // Cambio de estado
        if(isdigit(caracter)) (*num) = (*num)*10 + (caracter - '0'); // Valor numerico
        else if(caracter == '-') signo = -1;
        caracter = cadena[++i]; // Avanzo una posicion en la cadena
    }
    (*num) = (*num)*signo; //Por si es negativo

    if (estado==1 || estado==2 || estado==3 || estado==4) { //estados finales
        return 1;
    }

    return 0; 
}

int main(int argc, char *argv[]){
    char s1[] = "";
    strcpy(s1, argv[1]);

    // Caso que tenga caracteres invalidos
    if (!verificaDecimal(s1)){
        printf("Caracteres invalidos!\n");
        return EXIT_FAILURE;
    };

    // Caso que pertenezca al lenguaje
    int num = 0;
    if (esPalabraDecimal(s1, &num)){
        printf("Pertenece al lenguaje!\n");
        printf("Valor numerico: %d", num);
        return EXIT_SUCCESS;
    }

    // Caso que no pertezca al lenguaje
    printf("No pertenece al lenguaje!\n");
    return EXIT_FAILURE;
}
