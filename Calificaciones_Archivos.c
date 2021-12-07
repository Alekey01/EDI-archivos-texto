#include <stdio.h>
#include <conio.h>

#define ALUMNOS 3

void obtenerCalififcaciones(FILE *arch);
float calculaPromedio(FILE *arch);

int main()
{
    FILE *archivo, *archivo2;
    float promedio = 0;
    char nombre[50];
    int pudoLeer, calif, cerrado;

    archivo = fopen("Calificaciones.txt", "w");
    obtenerCalififcaciones(archivo);

    archivo2 = fopen("Calificaciones.txt", "r");
    promedio = calculaPromedio(archivo);

    printf("El promedio de los alumnos es: %0f", promedio);
   
    getch();
    return 0;
}

void obtenerCalififcaciones(FILE *arch)
{
    char nombre[50];
    int calif, cerrado;

    for (int i = 0; i < ALUMNOS; i++)
    {
        printf("Dame un nombre: ");
        scanf("%s", nombre);

        printf("Dame un valor entero: ");
        scanf("%d", &calif);

        fprintf(arch, "%s %d \n", nombre, calif);
    }

    cerrado = fclose(arch);

    if(cerrado == EOF) //fclose regresa EOF cuando no se puede cerrar correctamente    
    {
        printf("El archivo no se cerro bien");
    }

}

float calculaPromedio(FILE *arch)
{
    float promedio = 0;
    char nombre[50];
    int pudoLeer, calif;

    do
    {
        fscanf(arch, "%s", nombre);
        pudoLeer = fscanf(arch, "%d", &calif);

        printf("%s %d\n", nombre, calif);

        promedio = promedio + calif;

    }while (pudoLeer != EOF);
    
    promedio = (promedio - calif) /ALUMNOS;

    return promedio;
}