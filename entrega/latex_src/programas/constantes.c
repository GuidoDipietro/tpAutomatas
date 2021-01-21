#include <ctype.h>
#include "constantes.h"

////////////////////////// COLUMNAS //////////////////////////////

// Funcion que retorna el indice de la columna de la matriz
static int columnaOctal(int caracter);
static int columnaOctal(int caracter) {
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

// Funcion que retorna el indice de la columna de la matriz
static int columnaDecimal(int caracter);
static int columnaDecimal(int caracter) {
    if(caracter=='-') return 0;
    else if(caracter=='0') return 1;
    else if(caracter=='u' || caracter=='U') return 3;
    else if(caracter=='l' || caracter=='L') return 4;
    else return 2; //Si no es nada de lo anterior, y tiene todos simbolos validos, debe ser uno de 1-9
}

// Funcion que retorna el indice de la columnaHexaSuf (columna hexa sufijos) en la matriz
static int columnaHexa (char caracter);
static int columnaHexa (char caracter) {
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

/////////////////////////// VERIFICADORES /////////////////////////////

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaOctal (char *s);
int verificaOctal (char *s){
    unsigned int i = 0;
    for (i; s[i]; i++){
        if(!( ( isdigit(s[i]) && (s[i] != '8' && s[i] != '9') ) || s[i] == 'u' || s[i] == 'U' || s[i] == 'l' || s[i] == 'L' || s[i] == '-')){
            return 0;
        }
    }
    return 1;
}

// Funcion que reconoce otros simbolos HEXA, se usa en verificaHexa
static int perteneceAlfabetoHexa (char c);
static int perteneceAlfabetoHexa (char c) {
    char caracteres[] = {'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F', 'u', 'U', 'l', 'L', 'x', 'X'};

    for (int i = 0; i < 18; i++) {
        if (caracteres[i] == c) {
            return 1;
        }
    }

    return 0;
}

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaHexa (char *s);
int verificaHexa (char *s) {
    unsigned int i = 0;
    for (i; s[i]; i++) {
        if (!(isdigit(s[i]) || perteneceAlfabetoHexa(s[i]) || s[i]=='-' )){
            return 0;
        }
    }
    return 1;
}

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaDecimal (char *s);
int verificaDecimal (char *s){
    unsigned int i = 0;
    for (i; s[i]; i++){
        if(!(isdigit(s[i]) || s[i]=='-' || s[i]=='u' || s[i]=='U' || s[i]=='l' || s[i]=='L')){
            return 0;
        }
    }
    return 1;
}

/////////////////////////// AUTOMATAS /////////////////////////////

//Verifica si la cadena OCTAL pertenece al lenguaje
int automataOctal (const char *cadena);
int automataOctal (const char *cadena) {
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

//Verifica si la cadena HEXA pertenece al lenguaje
int automataHexa (const char *cadena);
int automataHexa (const char *cadena) {
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
        estado = tt[estado][columnaHexa(caracter)];
        caracter = cadena[++i];
    }

    if (estado == 4 || estado == 5 || estado == 6 || estado == 3) {
        return 1;
    }

    return 0;
}

//Este automata para decimales SI acepta sufijos con "u,U" si la cadena comienza con "-"
//Verifica si la cadena DECIMAL pertenece al lenguaje
int automataDecimal (const char *cadena);
int automataDecimal (const char *cadena) {
    static int tt [7][5] = {
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

    while ( caracter != '\0' ) {
        estado = tt[estado][columnaDecimal(caracter)]; // Cambio de estado
        caracter = cadena[++i]; // Avanzo una posicion en la cadena
    }

    if (estado==1 || estado==2 || estado==3 || estado==4) { //estados finales
        return 1;
    }

    return 0; 
}