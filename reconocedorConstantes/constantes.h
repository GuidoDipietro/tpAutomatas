/////////////////////////////// COLUMNAS ///////////////////////////////////

// #ifndef COLUMNAS
// #define COLUMNAS
// // Funcion que retorna el indice de la columna de la matriz
// int columnaOctal(int caracter);

// // Funcion que retorna el indice de la columna de la matriz
// int columnaDecimal(int caracter);

// // Funcion que retorna el indice de la columnaHexaSuf (columna hexa sufijos) en la matriz
// int columnaHexa (char caracter);

// #endif

// //////////////////////////////// VERIFICADORES //////////////////////////////////

#ifndef VERIFICADORES
#define VERIFICADORES
// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaOctal (char *s);

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaHexa (char *s);

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaDecimal (char *s);

#endif

//////////////////////////////// AUTOMATAS //////////////////////////////////

#ifndef AUTOMATAS
#define AUTOMATAS
//Verifica si la cadena OCTAL pertenece al lenguaje
int automataOctal (const char *cadena);

//Verifica si la cadena HEXA pertenece al lenguaje
int automataHexa (const char *cadena);

//Este automata para decimales SI acepta sufijos con "u,U" si la cadena comienza con "-"
//Verifica si la cadena DECIMAL pertenece al lenguaje
int automataDecimal (const char *cadena);

#endif