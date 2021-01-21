int main(int argc, char *argv[]){
    char s1[] = "";
    strcpy(s1, argv[1]);
    double out; //Almacenaremos en esta variable el resultado

    if(!verifica(s1))
    {
        printf("Caracteres invalidos.\n");
        return EXIT_FAILURE;
    }
    if(operacionAritmetica(s1, &out)){ //operacion valida
        printf("Resultado de %s = %f", s1, out);
        return EXIT_SUCCESS;
    }

    printf("Operacion no valida.");
    return 0;
}