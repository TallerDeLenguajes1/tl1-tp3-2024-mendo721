#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} Cliente;

void cargaClientes(Cliente *cliente, int cantClientes){
    printf("\nIngrese los datos de los clientes");
    for (int i = 0; i < cantClientes; i++)
    {
        cliente[i].ClienteID = i+1;
        printf("\nIngrese el nombre del cliente: ");
        fflush(stdin);
        cliente[i].NombreCliente = malloc(50*sizeof(char));
        gets(cliente[i].NombreCliente);
        cliente[i].CantidadProductosAPedir = 1 + rand()%5;
        cliente[i].Productos = malloc(sizeof(Producto)*cliente[i].CantidadProductosAPedir);

        for (int j = 0; j < cliente[i].CantidadProductosAPedir; j++)
        {
            cliente[i].Productos[j].ProductoID = j;
            cliente[i].Productos[j].Cantidad = 1 + rand()%10;
            cliente[i].Productos[j].TipoProducto = TiposProductos[j];
            cliente[i].Productos[j].PrecioUnitario = 10 + rand()%91;
        }
        
    }
    
}

float calcularPrecio (int cant, float precio){
    return cant*precio;
}

int main(){
    int cantClientes;
    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    srand(time(NULL));
    Cliente *clientes = malloc(sizeof(Cliente) * cantClientes);
    cargaClientes(clientes, cantClientes);

    printf("\nLos clintes ingresados son: ");

    for (int i = 0; i < cantClientes; i++)
    {   
        float suma = 0;
        printf("\n------------------------\n");
        printf("\nCliente %d", clientes[i].ClienteID);
        printf("\nNombre del Cliente: ");
        puts(clientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d ",clientes[i].CantidadProductosAPedir);
        printf("\nLos productos pedidos por el cliente son: ");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\n\n");
            printf("\nId %d", clientes[i].Productos[j].ProductoID);
            printf("\nCantidad: %d", clientes[i].Productos[j].Cantidad);
            printf("\nTipo producto:");
            puts(clientes[i].Productos[j].TipoProducto);
            printf("Precio del producto %.2f", clientes[i].Productos[j].PrecioUnitario);
            suma = suma + calcularPrecio(clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario);
        }
        printf("\n\nEl total a pagar por el cliente es $%.2f", suma);

        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);
    

}

