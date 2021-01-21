//Verifica si la cadena OCTAL pertenece al lenguaje
int automataOctal (const char *cadena) {
    static int tt [7][7] = {
        {1,5,5,5}, //0-
        {1,1,2,3}, //1+
        {5,5,5,4}, //2+
        {5,5,4,5}, //3+
        {5,5,5,5}, //4+
        {5,5,5,5}  //5
    };
    int estado = 0; // Estado inicial
    unsigned int i = 0;
    int caracter = cadena[0];

    while ( caracter != '\0' ) {
        estado = tt[estado][columnaOctal(caracter)]; // Cambio de estado
        caracter = cadena[++i]; // Avanzo una posicion en la cadena
    }

    if (estado == 1 || estado == 2 || estado == 3 || estado == 4) { //estados finales
        return 1;
    }

    return 0; 
}

//Verifica si la cadena HEXA pertenece al lenguaje
int automataHexa (const char *cadena) {
    static int tt [8][5] = {
                            {1,7,7,7,7}, //0-
                            {7,2,7,7,7}, //1
                            {3,7,3,7,7}, //2
                            {3,7,3,4,5}, //3+
                            {7,7,7,7,6}, //4+
                            {7,7,7,6,7}, //5+
                            {7,7,7,7,7}, //6+
                            {7,7,7,7,7}  //7
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

//Este aútómata para decimales SÍ acepta sufijos con "u,U" si la cadena comienza con "-"
//Verifica si la cadena DECIMAL pertenece al lenguaje
int automataDecimal (const char *cadena) {
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

    while ( caracter != '\0' ) {
        estado = tt[estado][columnaDecimal(caracter)]; // Cambio de estado
        caracter = cadena[++i]; // Avanzo una posicion en la cadena
    }

    if (estado==1 || estado==2 || estado==3 || estado==4) { //estados finales
        return 1;
    }

    return 0; 
}