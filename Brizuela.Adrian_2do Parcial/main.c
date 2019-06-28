#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"

int main()
{
    LinkedList* listaVentas = ll_newLinkedList();

    if(listaVentas != NULL){
        printf("LinkedList distinto de NULL\n");
    }

    if(!controller_loadFromText("data.csv", listaVentas))
    {
        printf("Controller devolvio 0\n");
        controller_saveAsText("informes.txt", listaVentas);
    }
    else
    {
        printf("Pifio en algo\n");
    }

    return 0;
}
