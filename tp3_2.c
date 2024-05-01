#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ANIO 5
#define MES 12

void cargarArreglo(int arreglo[][MES], int anio, int mes);
void mostrarArreglo(int arreglo[][MES], int anio, int mes);
void mostrarPromedios(int arreglo[][MES], int anio, int mes);
void mostrarMaxMin(int arreglo[][MES], int anio, int mes);

int main(){
    srand(time(NULL));
    int empresa[ANIO][MES];
    cargarArreglo(empresa, ANIO, MES);
    mostrarArreglo(empresa, ANIO, MES);
    mostrarPromedios(empresa, ANIO, MES);
    mostrarMaxMin(empresa, ANIO, MES);
}

void cargarArreglo(int arreglo[][MES], int anio, int mes){
    for (int i = 0; i < anio; i++)
    {
        for (int j = 0; j < mes; j++)
        {
            arreglo[i][j] = 10000 + rand() % 50000;
        }   
    }
}

void mostrarArreglo(int arreglo[][MES], int anio, int mes){
    for (int i = 0; i < anio; i++)
    {
        for (int j = 0; j < mes; j++)
        {
            printf(" %d ", arreglo[i][j]);
        }   
        printf("\n");
    }
}

void mostrarPromedios(int arreglo[][MES], int anio, int mes){
    for (int i = 0; i < anio; i++)
    {
        float promedio = 0;
        for (int j = 0; j < mes; j++)
        {
            promedio = promedio + arreglo[i][j];
        }  
        promedio = promedio/12;
        
        printf("\nEl promedio del anio %d es %.2f", i+1, promedio);
        printf("\n");
    }
}


void mostrarMaxMin(int arreglo[][MES], int anio, int mes){
    int min = 50000;
    int max = 10000;
    int anioMin;
    int mesMin;
    int anioMax;
    int mesMax;
    for (int i = 0; i < anio; i++)
    {
        for (int j = 0; j < mes; j++)
        {
            if ( arreglo[i][j]>max)
            {
                max = arreglo[i][j];
                anioMax = i+1;
                mesMax = j+1;
            }

            if (arreglo[i][j]<min)
            {
                min = arreglo[i][j];
                anioMin = i+1;
                mesMin = j+1;
            }
        }   
    }
    printf("\nEl maximo fue %d logrado el anio %d, mes %d", max, anioMax, mesMax);
    printf("\nEl minimo fue %d logrado el anio %d, mes %d", min, anioMin, mesMin);
}

