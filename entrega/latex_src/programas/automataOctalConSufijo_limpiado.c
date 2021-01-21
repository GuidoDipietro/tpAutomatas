#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Funcion que retorna el indice de la columna de la matriz
int columnaOctal(int caracter) {
    switch (caracter) {
        case '-': return 0;
        case '0': return 1;
        case 'u': return 3;
        case 'U': return 3;
        case 'l': return 4;
        case 'L': return 4;
        case '1': return 2;
        case '2': return 2;
        case '3': return 2;
        case '4': return 2;
        case '5': return 2;
        case '6': return 2;
        case '7': return 2;
    }
}

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verifica (char *s){
    unsigned int i = 0;
    for (i; s[i]; i++){
        if(!( ( isdigit(s[i]) && (s[i] != '8' && s[i] != '9') ) || s[i] == 'u' || s[i] == 'U' || s[i] == 'l' || s[i] == 'L' || s[i] == '-')){
            return 0;
        }
    }
    return 1;
}

// Funcion que verifica si la cadena pertenece al lenguaje
int esPalabra (const char *cadena) {
    static int tt [8][5] = {
        // - | 0 | d | u | l
          {6, 1, 7, 7, 7}, //0-
          {7, 2, 2, 7, 7}, //1
          {7, 2, 2, 3, 4}, //2+
          {7, 7, 7, 7, 5}, //3+
          {7, 7, 7, 5, 7}, //4+
          {7, 7, 7, 7, 7}, //5+
          {7, 1, 7, 7, 7}, //6
          {7, 7, 7, 7, 7}  //7
    };
    int estado = 0; // Estado inicial
    unsigned int i = 0;
    int caracter = cadena[0];

    while ( caracter != '\0' ) {
        estado = tt[estado][columnaOctal(caracter)]; // Cambio de estado
        caracter = cadena[++i]; // Avanzo una posicion en la cadena
    }

    if (estado == 5 || estado == 2 || estado == 3 || estado == 4) { //estados finales
        return 1;
    }

    return 0; 
}

int main(int argc, char *argv[]){
    char s1[] = "";
    strcpy(s1, argv[1]);

    // Caso que tenga caracteres invalidos
    if (!verifica(s1)){
        printf("Caracteres invalidos!\n");
        return EXIT_FAILURE;
    };

    // Caso que pertenezca al lenguaje 
    if (esPalabra(s1)){
        printf("Pertenece al lenguaje!\n");
        return EXIT_SUCCESS;
    }

    // Caso que no pertezca al lenguaje
    printf("No pertenece al lenguaje!\n");
    return EXIT_FAILURE;
}
