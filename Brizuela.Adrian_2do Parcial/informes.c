#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "parser.h"
#include "LinkedList.h"
#include "ventas.h"
//#include "controller.h"
#include "informes.h"

int inf_cantFotos(LinkedList* listaVentas, int* pSumaCant)
{
    printf("Entro a contar\n");

    Ventas* this;

    int i;
    int cantidad = 0;
    int ret = -1;
    int sumaCant = 0;
    int len = ll_len(listaVentas);
    printf("Init\n");

    printf("Lista len: %d\n", len);

    if(pSumaCant != NULL)
    {
        printf("Enro al if\n");
        for(i = 0; i < len; i++)
        {
            this = (Ventas*)ll_get(listaVentas, i);
            if(this != NULL){

            cantidad = this->cantidad;

            sumaCant = sumaCant + cantidad;
            }else{
                printf("es null\n");
            }
        }
        *pSumaCant = sumaCant;
        ret = 0;
    }

    return ret;
}

int inf_contMayorA150(Ventas* this)
{
    int ret = -1;
    float total = 0;
    Ventas* aux = this;

    total = (float)aux->cantidad * aux->precioUnitario;

    if(total > 150)
    {
        ret = 0;
    }

    return ret;
}

int inf_contMayorA300(Ventas* this)
{
    int ret = -1;
    int total = 0;
    Ventas* aux = this;

    total = (float)aux->cantidad * aux->precioUnitario;

    if(total > 300)
    {
        ret = 0;
    }

    return ret;
}

int inf_contPolaroid(Ventas* this)
{
    int ret = -1;
    Ventas* aux = this;

    printf("Tipo de foto: %s\n", aux->tipoFoto);

    if(strncmp("POLAROID_11x9", aux->tipoFoto, sizeof(aux->tipoFoto)) == 0 || strncmp("POLAROID_10x10", aux->tipoFoto, sizeof(aux->tipoFoto)) == 0)
    {
        ret = 0;
    }
    //printf("retorno polaroid: %d", ret);
    return ret;
}
