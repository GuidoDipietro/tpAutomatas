///////////////////////////// VERIFICADORES /////////////////////////////

#ifndef VERIFICADORES
#define VERIFICADORES
// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaOctal (char *s);

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaHexa (char *s);

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaDecimal (char *s);

#endif

/////////////////////////// AUTOMATAS /////////////////////////////

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