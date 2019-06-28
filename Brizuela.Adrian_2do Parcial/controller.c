#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "ventas.h"
#include "controller.h"
#include "informes.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListVentas)
{
    int retorno = -1; //Variable que retorna la funcion (1 - TodoOK // 0 - Error)
    FILE* pArchivo; //Variable puntero al archivo
    if((pArchivo = fopen(path, "r")) != NULL) //Condicional, verifico si la lectura del archivo, si no retorna NULL accedo al parse_Ventas
    {
        parser_FromText(pArchivo, pArrayListVentas); //Funcion parser empleados modo texto
        retorno = 0;
    }
    else  //Si retorna NULL no encontro el archivo, por lo tanto lo creo e informo que no se encontro y se creo uno nuevo
    {
        if((pArchivo = fopen(path, "w")) != NULL)
        {
            printf("\n --> No se encontro el archivo. Se creo uno nuevo con el tipo \"%s\"\n\n", path);
            retorno = 0; //Cambio el el valor del retorno
        }
    }
    return retorno; //Retorno a la varaible
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListVentas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* listaVentas)
{
    printf("Empezo a guardar\n");
    FILE* pArchivo; //Puntero al archivo
    //Ventas* this; //Creo puntero a estructura empleado
    int retorno = -1; //Variable retorno
    //Variables buffer -->
    int cantFotos = 0;
    int mayorA150 = 0;
    int mayorA300 = 0;
    int fotosPolaroids = 0;
    //<---
    printf("Inicializo variables\n");

    inf_cantFotos(listaVentas, &cantFotos);
    //inf_cantEntTipoFoto(listaVentas, &cantPlus, &cantRegular/*, &cantGold*/);
    ll_count(listaVentas, (void*)inf_contMayorA150, &mayorA150);
    ll_count(listaVentas, (void*)inf_contMayorA300, &mayorA300);
    ll_count(listaVentas, (void*)inf_contPolaroid, &fotosPolaroids);

    pArchivo = fopen(path, "w"); //Abro el archivo en modo escritura
    if(pArchivo != NULL && listaVentas != NULL) //Condicional, verifico que la apertura del archivo y el array de empelados no sea NULL, si no lo es ingreso
    {
        fprintf(pArchivo, "********************\nInforme de ventas\n********************\n");
        fprintf(pArchivo, "- Cantidad total de fotos reveladas totales: %d\n", cantFotos);
        fprintf(pArchivo, "- Cantidad de ventas por un monto mayor a $150: %d\n", mayorA150);
        fprintf(pArchivo, "- Cantidad de ventas por un monto mayor a $300: %d\n", mayorA300);
        fprintf(pArchivo, "- Promedio de fotos polaroids reveladas: %d\n", fotosPolaroids);
        fprintf(pArchivo, "********************\n");

        printf("\n --> Datos guardados con exito.\n\n");
        retorno = 0; //Cambio el valor de la variable que retorna la funcion
    }
    fclose(pArchivo); //Cierro el archivo
    return retorno; //Retorno el valor de la variable
}
