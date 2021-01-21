//No anda el autómata

// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>

// int columna(int caracter)
// {
//    switch(caracter)
//    {
//        case '.': return 2;
//        case '-': return 1;
//        case '0': return 0;
//        case '1': return 0;
//        case '2': return 0;
//        case '3': return 0;
//        case '4': return 0;
//        case '5': return 0;
//        case '6': return 0;
//        case '7': return 0;
//        case '8': return 0;
//        case '9': return 0;
//    }
// }

// int verifica (char *s)
// {
//     unsigned int i = 0;
//     for (i; s[i]; i++){
//         if(isdigit(s[i]) || (s[i]=='-') || (s[i]=='.')) return 1;
//     }
//     return 0;
// }

// int esPalabra (const char *cadena) 
// {
//     static int tt [5][3] = {  // D - , 
//                                 {1,1,4}, //0-
//                                 {2,4,4}, //1
//                                 {2,4,3}, //2
//                                 {2,4,4}, //3+
//                                 {4,4,4}, //4
//                            };
//     int estado = 0; // Estado inicial
//     unsigned int i = 0;
//     int caracter = cadena[0];
//     int num=0;
//     while ( caracter != '\0' ) {
//         estado = tt[estado][columna(caracter)]; // Cambio de estado
//         num = num*10 + caracter;
//         if(caracter == '.')
//             num = 0;
//         caracter = cadena[++i];
//     }

//     if (estado == 3)  // 1 = Estado final
//         return 1;
//     return 0; 
// }

// int main()
// {
//     char vec[] = "256025";

//     if(esPalabra(vec)){
//         printf("Es palabra");
//     }

//     return 0;
// }