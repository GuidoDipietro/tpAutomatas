int operacionAritmetica (const char *cadena, double *out) {
    static int tt[6][6] = {//D + - * / 0
                            {1,5,5,5,5,1}, //0-, inicial
                            {1,2,2,2,3,1}, //1, ingreso de num1
                            {4,5,5,5,5,4}, //2, se ingreso un operando + - *
                            {4,5,5,5,5,5}, //3, se ingreso un operando /
                            {4,5,5,5,5,4}, //4+, ingreso de num2 (final)
                            {5,5,5,5,5,5}  //5, operacion no valida
                        };
    int estado = 0; //estado inicial = 0
    int estadoFinal = 4; //solo un estado final
    int c = cadena[0]; //caracter leido

    double num1=0, num2=0, num3=0; //guarda valores numericos (operandos y el resultado)

    char operador; //Sera uno de + - * /

    unsigned int i=0;
    while (c != '\0'){
        estado = tt[estado][columna(c)]; // Cambio de estado

        //Evaluamos donde guardar el caracter (num1, operando, o num2)
        //en base al estado en el que estamos
        if(estado==1) num1 = num1*10 + (c - '0');
        else if(estado==2 || estado==3) operador = c;
        else if(estado==4) num2 = num2*10 + (c - '0');

        c = cadena[++i]; //Avanzo una posicion en la cadena
    }
    if(estado==estadoFinal){
        //Si la operacion es valida la evaluamos segun el operando recibido
        if(operador == '+') num3 = num1 + num2;
        else if(operador == '-') num3 = num1 - num2;
        else if(operador=='*') num3 = num1 * num2;
        else if(operador == '/') num3 = num1 / num2;
		//no hace falta preguntar por division por 0 porque el automata
		//directamente no reconoce esa cadena

        *out = num3; //Resultado final asignado al puntero
        return 1;
    }
    else{
        //operacion no valida
        return 0;
    }
}