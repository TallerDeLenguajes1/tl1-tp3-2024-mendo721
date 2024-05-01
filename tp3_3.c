#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define FILAS 5
int main(){
    char buff[50];
    char **buffer;
    buffer = (char**) malloc (sizeof(char*)*FILAS);

    for (int i = 0; i < FILAS; i++)
    {
        int tamCadena;
        printf("\nIngrese un nombre: ");
        scanf("%s", buff);
        tamCadena = strlen(buff);
        *(buffer+i) = (char*)malloc(sizeof(char)*tamCadena+1);
        strcpy(buffer[i],buff);
    }
    printf("\nNombres ingresados: ");

    for (int i = 0; i < FILAS; i++)
    {
        printf("\n%s", *(buffer+i));
        free( *(buffer+i));
    }
    free(buffer);
}