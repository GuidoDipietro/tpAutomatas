#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Funcion para reconocer A-F a-f x X
int esDigitoHexa (char c){
    char caracteres[] = {'x', 'X', 'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < 14; i++) {
        if( caracteres[i] == c) {
            return 1;
        }
    }

    return 0;
}

// Funcion que retorna el indice de la columna de la matriz
// Funcion que retorna el indice de la columnaHexa de la matriz
int columnaHexa (int caracter) {
    char a0_F9[] = {'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (caracter == '-') {
        return 0;
    } else if (caracter == '0') {
        return 1;
    } else if (caracter == 'x' || caracter == 'X'){
        return 2;
    } else {
        for (int i = 0; a0_F9[i]; i++){
            if(a0_F9[i] == caracter){
                return 3;
            }
        }
    }

}

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verifica (char *s) {
    unsigned int i = 0;
    for (i; s[i]; i++){
        if(!(isdigit(s[i]) || esDigitoHexa(s[i]) || s[i]=='-')){
            return 0;
        }
    }
    return 1;
}



// Funcion que verifica si la cadena pertenece al lenguaje
int esPalabra (const char *cadena) {
    static int tt [6][4] = {
                            //  - | 0 | x | d
                                {4, 1, 5, 5}, //0-
                                {5, 5, 2, 5}, //1
                                {5, 3, 5, 3}, //2
                                {5, 3, 5, 3}, //3+
                                {5, 1, 5, 5}, //4
                                {5, 5, 5, 5}  //5
                           };
    int estado = 0; // Estado inicial
    unsigned int i = 0;
    int caracter = cadena[0];

    while ( caracter != '\0' ) {
        estado = tt[estado][columnaHexa(caracter)]; // Cambio de estado
        caracter = cadena[++i]; // Avanzo una posicion en la cadena
    }

    if (estado == 3) { // 3 = estado final
        return 1;
    }

    return 0;
}

int main(int argc, char *argv[]){

    //char s1[] = "-0x000F1";
    char s1[] = "";
    strcpy(s1, argv[1]);

    // Caso que tenga caracteres invalidos
    if (!verifica(s1)){
        printf("Caracteres invalidos!\n");
        return EXIT_FAILURE;
    }

    // Caso que pertenezca al lenguaje
    if (esPalabra(s1)){
        printf("Pertenece al lenguaje!\n");
        return EXIT_SUCCESS;
    }

    // Caso que no pertenezca al lenguaje
    printf("No pertenece al lenguaje!\n");
    return EXIT_FAILURE;

}