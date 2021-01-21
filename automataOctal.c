#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Funcion que retorna el indice de la columna de la matriz
int columna(int caracter) {
    switch (caracter) {
        case '-': return 0;
        case '0': return 1;
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
        if(isdigit(s[i]) && (s[i]!='8') && (s[i]!='9')){
            return 1;
        }
    }
    return 0;
}

// Funcion que verifica si la cadena pertenece al lenguaje
int esPalabra (const char *cadena) {
    static int tt [5][3] = {
                            //  - | 0 | d
                                {3, 1, 4}, //0-
                                {4, 2, 2}, //1
                                {4, 2, 2}, //2+
                                {4, 1, 4}, //3
                                {4, 4, 4}, //4
                           };
    int estado = 0; // Estado inicial
    unsigned int i = 0;
    int caracter = cadena[0];

    while ( caracter != '\0' ) {
        estado = tt[estado][columna(caracter)]; // Cambio de estado
        caracter = cadena[++i]; // Avanzo una posicion en la cadena
    }

    if (estado == 2) { // 2 = Estado final
        return 1;
    }

    return 0; 
}

// Palabras testeadas: [0-12304567, 12304567, -112304567,  -12304567, -012304567, 012304567, 01230+4567]

int main(int argc, char *argv[]){

    /* ******* PARA COMPILAR DESDE EL IDE DESCOMENTAR LINEA 55 Y COMENTAR LINEA 56 Y 57 ******** */

    //char s1[] = "-0002";
    char s1[] = "";
    strcpy(s1, argv[1]);

    // printf(s1);
    // printf("\n");

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