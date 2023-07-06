#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Inventario de Ferreteria


// Declaracion de funciones
void mostrarProdcutos(int ID[7],char nombre[7][50],int cantidad[7],float precio[7],char descripcion[7][50],int valor , int i);
int ingresoProductos(char nombre[7][50],char descripcion[7][50],int cantidad[7],float precio[7],int valor,int i);
void modificacionProductos(int ID[7], int cantidad[7],float precio[7],int barras , int i);
void eliminacion(int ID[7], char nombre[7][50],int cantidad[7],float precio[7],int barras , int i);

// Main
int main(int argc, char *argv[])
{
    int sn = 2 ,menu;
    int cantidad[7] = {4,5,6,7,8,0,0};
    int ID[7] = {100,111,122,133,144,155,166};
    float precio[7]= {12.12,13.13,14.14,15.15,16.16,0,0};
    char nombre[7][50] = {"Ladrillos","Tornillos","Cemento","Acero","Silicona","Nada","Nada"};
    char descripcion[7][50];
    int i, valor = 5;
    int barras;
do
{
    printf("=================================================== Bienvenido al  Menu===========================================================================\n");
    printf("  1= Ver Productos                   2=Ingreso Producto              3=Modificacion del Producto               4=Eliminacion del Prodcuto\n");
    printf("Seleccione una opcion\n");
    scanf("%d", &menu);
    switch (menu)
    {
    case 1:
        mostrarProdcutos(ID,nombre,cantidad,precio,descripcion,valor,i);
        break;
    case 2:
        valor=ingresoProductos(nombre,descripcion,cantidad,precio,valor,i);
        break;
    case 3:
        modificacionProductos(ID,cantidad,precio,barras,i);

        break;
    case 4:
        eliminacion(ID,nombre,cantidad,precio,barras,i);
        break;
    default:
        break;
    }
    printf("Quieres entrar otra vez al menu si = 2 // no = 1 \n");
    scanf("%d",&sn);
} while (sn!=1);

printf("Gracias por visitar Ferreterias Flores\n");
}


//Funciones

void mostrarProdcutos(int ID[7],char nombre[7][50],int cantidad[7],float precio[7],char descripcion[7][50],int valor,int i)
{
printf("=============================Productos===========================================\n");
        printf("ID===============Nombre===================Cantidad=====================Precio============Descripcion\n");
        for (i = 0; i < valor; i++)
        {
            printf("%d\t\t   %s\t\t\t%d                        %.2f\t\t        %s \n", ID[i], nombre[i], cantidad[i], precio[i],descripcion[i]);
        }
}

int ingresoProductos(char nombre[7][50],char descripcion[7][50],int cantidad[7],float precio[7],int valor,int i)
{
    printf("=============================Ingreso de Producto===========================================\n");
        printf("Nombre del producto\n");
        scanf(" %[^\n]", nombre[valor]);
        printf("Descripcion del producto\n");
        scanf("%s",&descripcion[valor]);
        printf("Ingresa la cantidad\n");
        scanf("%d",&cantidad[valor]);
        printf("Ingrese el precio\n");
        scanf("%f",&precio[valor]);
        valor++;
        return valor;
}

void modificacionProductos(int ID[7], int cantidad[7],float precio[7],int barras , int i)
{
    printf("=============================Modificacion del Producto===========================================\n");
        printf("Escribe el ID del producto que quieres modificar\n");
        scanf("%d",&barras);
        for (i = 0; i < 7; i++)
        {
            if (ID[i] == barras){
            printf("Ingresa la cantidad\n");
            scanf("%d",&cantidad[i]);
            printf("Ingrese el precio\n");
            scanf("%f",&precio[i]);
            }
        }
}

void eliminacion(int ID[7], char nombre[7][50],int cantidad[7],float precio[7],int barras, int i)
{
    printf("=============================Eliminacion del Producto===========================================\n");
        printf("Escribe el ID  del producto que quieres eliminar\n");
        scanf("%d",&barras);
        for (i = 0; i < 7; i++)
        {
            if (ID[i] == barras){
            ID[i]=0;
            strcpy(nombre[i],"Vacio");
            cantidad[i]=0;
            precio[i]=0;
            }
        }
}