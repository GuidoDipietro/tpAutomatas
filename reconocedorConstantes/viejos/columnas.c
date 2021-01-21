// Funcion que retorna el indice de la columna de la matriz
static int columnaOctal(int caracter) {
    switch (caracter) {
        case '0': return 0;
        case 'u': return 2;
        case 'U': return 2;
        case 'l': return 3;
        case 'L': return 3;
        case '1': return 1;
        case '2': return 1;
        case '3': return 1;
        case '4': return 1;
        case '5': return 1;
        case '6': return 1;
        case '7': return 1;
    }
}

// Funcion que retorna el indice de la columna de la matriz
static int columnaDecimal(int caracter) {
    if(caracter=='-') return 0;
    else if(caracter=='0') return 1;
    else if(caracter=='u' || caracter=='U') return 3;
    else if(caracter=='l' || caracter=='L') return 4;
    else return 2; //Si no es nada de lo anterior, y tiene todos simbolos validos, debe ser uno de 1-9
}

// Funcion que retorna el indice de la columnaHexaSuf (columna hexa sufijos) en la matriz
static int columnaHexa (char caracter) {
    char a0_F9[] = {'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (caracter == '0') {
        return 0;
    } else if (caracter == 'x' || caracter == 'X') {
        return 1;
    } else if (caracter == 'u' || caracter == 'U') {
        return 3;
    } else if (caracter == 'l' || caracter == 'L') { 
        return 4;
    }else {
        for (int i = 0; a0_F9[i]; i++) {
            if (a0_F9[i] == caracter) {
                return 2;
            }
        }
    }
}

//////////////////////////////////////////////////////////////////