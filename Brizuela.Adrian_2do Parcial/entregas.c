#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "entregas.h"
#include "controller.h"
#include "utn.h"
#include "informes.h"

void ent_menu(LinkedList* listaEntregas)
{
    int opcionMenu = 0;

    do
    {
        system("clear");

        printf("Bienvenido!\n\n");

        printf("1.- Cargar datos desde archivo. (data.csv)\n");
        printf("2.- Generar informes.\n");
        printf("3.- Guardar informes en archivo. (informes.txt)\n");
        printf("4.- Salir.\n\n");

        printf("Ingrese opcion: ");
        scanf("%d", &opcionMenu);
        printf("\n");
        __fpurge(stdin);

        switch(opcionMenu)
        {

        case 1:
            controller_loadFromText("data.csv", listaEntregas);
            __fpurge(stdin);
            pause();
            break;

        case 2:

            break;

        case 3:
            controller_saveAsText("informes.txt", listaEntregas);
            __fpurge(stdin);
            pause();
            break;

        case 4:
            printf("Hasta luego!");
            break;

        default:
            printf("Las opciones correctas van del 1 al 4, reintente.\n");
            __fpurge(stdin);
            pause();
            break;
        }
    }
    while(opcionMenu != 4);
}

/** \brief Crea posicion de memoria para un nuevo empleado.
 *
 * \return Entrega* posición de memoria de entrega.
 *
 */


Entregas* ent_new(void)
{
    return (Entregas*) malloc(sizeof(Entregas));
}

/** \brief Crea un nuevo empleado con posicion de memoria y contenido basado en strings.
 *
 * \param1 char* ID
 * \param2 char* tipo
 * \param3 char* cantidad
 * \param4 char* importe
 * \return retorno Entregas*. Devuelve el empleado si todo salio bien, o NULL si se pasaron mal parametros o no se pudo completar la operacion.
 *
 */


Entregas* ent_newParametros(char* id, char* tipo, char* cantidad, char* importe)
{
    Entregas* retorno = NULL;
    Entregas* pAuxEmpleado;
    if(id != NULL && tipo != NULL && cantidad != NULL && importe != NULL)
    {
        pAuxEmpleado = ent_new();
        if(pAuxEmpleado != NULL)
        {
            if( !ent_setIdAsString(pAuxEmpleado, id) && !ent_setTipo(pAuxEmpleado, tipo) &&
                !ent_setCantidadAsString(pAuxEmpleado, cantidad) && !ent_setImporteAsString(pAuxEmpleado, importe))
            {
                retorno = pAuxEmpleado;
            }else
            {
                ent_delete(pAuxEmpleado);
            }
        }
    }
    return retorno;
}

/** \brief Elimina un empleado.
 *
 * \param1 this Entregas* Empleado a eliminar.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */


int ent_delete(Entregas* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el ID de un empleado.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 id int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int ent_setId(Entregas* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el ID de un empleado.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 resultado int* ID donde se encuentra.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int ent_getId(Entregas* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el ID de un empleado como string.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 id char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */


int ent_setIdAsString(Entregas* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        if(esNumerico(id))
        {
            retorno = ent_setId(this, atoi(id));
        }

    }
    return retorno;
}

/** \brief Obtiene el ID de un empleado como string.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int ent_getIdAsString(Entregas* this, char* resultado)
{
    int retorno = -1;
    int bufferId;
    if(this != NULL && resultado != NULL)
    {
        ent_getId(this, &bufferId);
        sprintf(resultado, "%d", bufferId);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el tipo de un empleado.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 tipo char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */

int ent_setTipo(Entregas* this, char* tipo)
{
    int retorno = -1;
    if(this != NULL && esSoloLetras(tipo))
    {
        strncpy(this->tipo, tipo, sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el tipo de un empleado.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ent_getTipo(Entregas* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->tipo, 10);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define las horas trabajadas de un empleado.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 cantidad int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ent_setCantidad(Entregas* this, int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ent_getCantidad(Entregas* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define las horas trabajadas de un empleado como string.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 cantidad char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ent_setCantidadAsString(Entregas* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        if(esNumerico(cantidad))
        {
            retorno = ent_setCantidad(this, atoi(cantidad));
        }
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado como string.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ent_getCantidadAsString(Entregas* this, char* resultado)
{
    int retorno = -1;
    int bufferCantidad;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferCantidad = this->cantidad;
        sprintf(resultado, "%d", bufferCantidad);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el importe de un empleado.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 importe int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ent_setImporte(Entregas* this, float importe)
{
    int retorno = -1;
    if(this != NULL && importe >= 0)
    {
        this->importe = importe;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el importe de un empleado.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ent_getImporte(Entregas* this, float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->importe;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el importe de un empleado como string.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 importe char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ent_setImporteAsString(Entregas* this, char* importe)
{
    int retorno = -1;
    if(this != NULL && importe >= 0)
    {
        if(esNumericoFlotante(importe))
        {
            retorno = ent_setImporte(this, atof(importe));
        }
    }
    return retorno;
}

/** \brief Define el importe de un empleado como string.
 *
 * \param1 this Entregas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ent_getImporteAsString(Entregas* this, char* resultado)
{
    int retorno = -1;
    int bufferImporte;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferImporte = this->importe;
        sprintf(resultado, "%d", bufferImporte);
        retorno = 0;
    }
    return retorno;
}

/** \brief Controla si el id ingresado se encuentra en la lista
 *
 * \param pArrayListEntregas LinkedList* lista de empelados
 * \param idStr char* id en formato string
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int ent_ControlId(LinkedList* pArrayListEntregas, char* idStr)
{
    int retorno = 0; //Variable retorno funcion
    int id; //Variable ID
    id = atoi(idStr); //Casteo de string a entero
    Entregas* this; //Puntero a estructura
    if(pArrayListEntregas != NULL) //Condicional, verifica que sea distinto de NULL
    {
        for(int i=0; i<ll_len(pArrayListEntregas); i++) //Recorro el for en busca del ID ingresado
        {
            this = (Entregas*)ll_get(pArrayListEntregas, i); //Le asigno a this la estructura que retorna ll_get()
            if(this->id == id) //Si se encuentra el id ingresado se cambia la bandera y se rompe l iteraccion
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno; //Se retorna a la funcion el valor de retorno
}
