#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Funcion que reconoce el alfabeto del lenguaje
int perteneceAlfabetoHexa (char c) {
    char caracteres[] = {'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F', 'u', 'U', 'l', 'L', 'x', 'X'};

    for (int i = 0; i < 18; i++) {
        if (caracteres[i] == c) {
            return 1;
        }
    }

    return 0;
}

// Funcion que retorna el indice de la columnaHexaSuf (columna hexa sufijos) en la matriz
int columnaHexaSuf (char caracter) {
    char a0_F9[] = {'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (caracter == '-'){
        return 0;
    } else if (caracter == '0') {
        return 1;
    } else if (caracter == 'x' || caracter == 'X') {
        return 2;
    } else if (caracter == 'u' || caracter == 'U') {
        return 4;
    } else if (caracter == 'l' || caracter == 'L') { 
        return 5;
    }else {
        for (int i = 0; a0_F9[i]; i++) {
            if (a0_F9[i] == caracter) {
                return 3;
            }
        }
    }
}

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verifica (char *s) {
    unsigned int i = 0;
    for (i; s[i]; i++) {
        if (!(isdigit(s[i]) || perteneceAlfabetoHexa(s[i]) || s[i]=='-' )){
            return 0;
        }
    }
    return 1;
}

// Funcion que verifica si la cadena ingresada pertenece al lenguaje
int esPalabra (const char *cadena) {
    static int tt [9][6] = {
                            // - | 0 | x | d | u | l
                                {7, 1, 8, 8, 8, 8}, //0-
                                {8, 8, 2, 8, 8, 8}, //1
                                {8, 3, 8, 3, 8, 8}, //2
                                {8, 3, 8, 3, 4, 5}, //3+
                                {8, 8, 8, 8, 8, 6}, //4+
                                {8, 8, 8, 8, 6, 8}, //5+
                                {8, 8, 8, 8, 8, 8}, //6+
                                {8, 1, 8, 8, 8, 8}, //7
                                {8, 8, 8, 8, 8, 8}  //8
                           };

    int estado = 0; // Estado Inicial
    unsigned int i = 0;
    int caracter = cadena[0];

    while (caracter != '\0') {
        estado = tt[estado][columnaHexaSuf(caracter)];
        caracter = cadena[++i];
    }

    if (estado == 4 || estado == 5 || estado == 6 || estado == 3) {
        return 1;
    }

    return 0;
}


int main(int args, char *argv[]){
    
    // Pruebas: -0x0123456789abcdefABCDEFul , -0X0123456789abcdefABCDEFUL, -0X0123456789abcdefABCDEFUu, -0X0123456789abcdefABCDEFLl
    //          0X0123456789abcdelU , 0X0123456789abcdeuL

    //char s1[] = "-0x00123FBFLu";
    char s1[] = "";
    strcpy(s1, argv[1]);

    //printf(s1);
    //printf("\n");

    // Caso que tenga caracteres invalidos
    if (!verifica(s1)) {
        printf("Caracteres invalidos!\n");
        return EXIT_FAILURE;
    }

    // Caso que pertenezca al lenguaje
    if(esPalabra(s1)) {
        printf("Pertenece al lenguaje!\n");
        return EXIT_SUCCESS;
    }

    // Caso que no pertenezca al lenguaje
    printf("No pertenece al lenguaje!\n");
    return EXIT_FAILURE;
}