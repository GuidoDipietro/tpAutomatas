// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaOctal (char *s){
    unsigned int i = 0;
    for (i; s[i]; i++){
        if(!((isdigit(s[i]) && s[i]!='8' && s[i]!='9') || s[i] == 'u' || s[i] == 'U' || s[i] == 'l' || s[i] == 'L')){
            return 0;
        }
    }
    return 1;
}

// Funcion que reconoce otros símbolos HEXA, se usa en verificaHexa
int perteneceAlfabetoHexa (char c) {
    char caracteres[] = {'a', 'b', 'c', 'd', 'e', 'f', 'A', 'B', 'C', 'D', 'E', 'F', 'u', 'U', 'l', 'L', 'x', 'X'};

    for (int i = 0; i < 18; i++) {
        if (caracteres[i] == c) {
            return 1;
        }
    }

    return 0;
}

// Funcion que verifica si los caracteres pertenecen al alfabeto
int verificaHexa (char *s) {
    unsigned int i = 0;
    for (i; s[i]; i++) {
        if (!(isdigit(s[i]) || perteneceAlfabetoHexa(s[i]) )){
            return 0;
        }
    }
    return 1;
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