#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

// Desarrolle un programa comando que reciba una expresión aritmética simple y retorne su valor

int columna(int caracter)
{
    switch(caracter)
    {
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        case '/': return 4;
        case '0': return 5;
        default:  return 0;
    }
}

// Controla que no haya caracteres inválidos
// (solo se aceptan 0-9 + - / *)
int verifica(char *s)
{
    unsigned int i;
    for(i=0;s[i];i++)
        if(! (isdigit(s[i]) || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')){
            return 0;
        }
    return 1;
}

// operacionAritmetica(cadena, *resultado)
// Esta función es un autómata que controla que la expresión dada sea de la forma:
// [número] [operando] [número]
// Siendo [número] un entero positivo,
// y [operando] uno de {+, -, *, /}.

// El autómata también clasifica como inválidas las cadenas de la forma:
// [numero] / 0
// Ya que la división por 0 no está definida.

// Retorna 1 si la operación fue válida, 0 si no lo fue.
// El resultado queda guardado en el puntero "*resultado"

int operacionAritmetica (const char *cadena, double *out)
{
    //TT para reconocer el lenguaje
    static int tt[6][6] = {//D + - * / 0
                            {1,5,5,5,5,1}, //0-, inicial
                            {1,2,2,2,3,1}, //1, ingreso de num1
                            {4,5,5,5,5,4}, //2, se ingresó un operando + - *
                            {4,5,5,5,5,5}, //3, se ingresó un operando /
                            {4,5,5,5,5,4}, //4+, ingreso de num2 (final)
                            {5,5,5,5,5,5}  //5, operación no válida
                        };

    int estado = 0; //estado inicial = 0
    int estadoFinal = 4; //sólo un estado final
    int c = cadena[0]; //caracter leído

    double num1=0, num2=0, num3=0; //guarda valores numéricos (operandos y el resultado)

    char operador; //Será uno de + - * /

    unsigned int i=0;
    while (c != '\0'){
        estado = tt[estado][columna(c)]; // Cambio de estado

        //Evaluamos dónde guardar el caracter (num1, operando, o num2)
        //en base al estado en el que estamos
        if(estado==1) num1 = num1*10 + (c - '0');
        else if(estado==2 || estado==3) operador = c;
        else if(estado==4) num2 = num2*10 + (c - '0');

        c = cadena[++i]; //Avanzo una posición en la cadena
    }
    
    if(estado==estadoFinal){
        //Si la operación es válida la evaluamos según el operando recibido
        if(operador == '+') num3 = num1 + num2;
        else if(operador == '-') num3 = num1 - num2;
        else if(operador=='*') num3 = num1 * num2;
        else if(operador == '/') num3 = num1 / num2; //no contemplamos /0 porque el automata no la reconoce

        *out = num3; //Resultado final asignado al puntero
        return 1;
    }
    else{
        //operación no válida
        return 0;
    }
}

int main(int argc, char *argv[])
{

    /* ******* PARA COMPILAR DESDE EL IDE DESCOMENTAR LINEA 100 Y COMENTAR LINEA 101 Y 102 ******** */

    //char s1[]="1427*49";
    char s1[] = "";
    strcpy(s1, argv[1]);
    double out; //Guardaremos acá el resultado

    if(!verifica(s1))
    {
        printf("Caracteres invalidos.\n");
        return EXIT_FAILURE;
    }

    if(operacionAritmetica(s1, &out)){ //operación válida
        printf("Resultado de %s = %f", s1, out);
        return EXIT_SUCCESS;
    }

    printf("Operacion no valida.");
    return 0;
}