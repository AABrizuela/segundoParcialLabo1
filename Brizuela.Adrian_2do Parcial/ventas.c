#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "ventas.h"
#include "controller.h"
#include "utn.h"
#include "informes.h"

/** \brief Crea posicion de memoria para un nuevo empleado.
 *
 * \return Entrega* posición de memoria de entrega.
 *
 */


Ventas* ven_new(void)
{
    return (Ventas*) malloc(sizeof(Ventas));
}

/** \brief Crea un nuevo empleado con posicion de memoria y contenido basado en strings.
 *
 * \param1 char* ID
 * \param2 char* tipo
 * \param3 char* cantidad
 * \param4 char* precioUnitario
 * \return retorno Ventas*. Devuelve el empleado si todo salio bien, o NULL si se pasaron mal parametros o no se pudo completar la operacion.
 *
 */


Ventas* ven_newParametros(char* id, char* fechaVenta, char* tipoFoto, char* cantidad, char* precioUnitario, char* cuitCliente)
{
    Ventas* retorno = NULL;
    Ventas* pAuxVenta;
    if(id != NULL && fechaVenta != NULL && tipoFoto != NULL && cantidad != NULL && precioUnitario != NULL && cuitCliente != NULL)
    {
        pAuxVenta = ven_new();
        if(pAuxVenta != NULL)
        {
            if( !ven_setIdAsString(pAuxVenta, id) && !ven_setFechaVenta(pAuxVenta, fechaVenta) && !ven_setTipoFoto(pAuxVenta, tipoFoto) &&
                !ven_setCantidadAsString(pAuxVenta, cantidad) && !ven_setPrecioUnitarioAsString(pAuxVenta, precioUnitario) && !ven_setCuitCliente(pAuxVenta, cuitCliente))
            {
                retorno = pAuxVenta;
            }else
            {
                printf("Borra elemento\n");
                ven_delete(pAuxVenta);
            }
        }
    }
    return retorno;
}

/** \brief Elimina un empleado.
 *
 * \param1 this Ventas* Empleado a eliminar.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */


int ven_delete(Ventas* this)
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
 * \param1 this Ventas* Empleado a tomar.
 * \param2 id int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int ven_setId(Ventas* this, int id)
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
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado int* ID donde se encuentra.
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int ven_getId(Ventas* this, int* resultado)
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
 * \param1 this Ventas* Empleado a tomar.
 * \param2 id char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */


int ven_setIdAsString(Ventas* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        if(esNumerico(id))
        {
            retorno = ven_setId(this, atoi(id));
        }

    }
    return retorno;
}

/** \brief Obtiene el ID de un empleado como string.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no se encontró.
 *
 */

int ven_getIdAsString(Ventas* this, char* resultado)
{
    int retorno = -1;
    int bufferId;
    if(this != NULL && resultado != NULL)
    {
        ven_getId(this, &bufferId);
        sprintf(resultado, "%d", bufferId);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el tipo de un empleado.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 tipo char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */

int ven_setTipoFoto(Ventas* this, char* tipoFoto)
{
    int retorno = -1;
    if(this != NULL && esTipoFoto(tipoFoto))
    {
        strncpy(this->tipoFoto, tipoFoto, sizeof(this->tipoFoto));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el tipo de un empleado.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ven_getTipoFoto(Ventas* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->tipoFoto, 10);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el tipo de un empleado.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 tipo char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */

int ven_setFechaVenta(Ventas* this, char* fechaVenta)
{
    int retorno = -1;
    if(this != NULL && esFecha(fechaVenta))
    {
        strncpy(this->fechaVenta, fechaVenta, sizeof(this->fechaVenta));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el tipo de un empleado.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ven_getFechaVenta(Ventas* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->fechaVenta, 10);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el cuit de una venta.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 cuit char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no es valido.
 *
 */

int ven_setCuitCliente(Ventas* this, char* cuitCliente)
{
    int retorno = -1;
    if(this != NULL && esCuit(cuitCliente))
    {
        strncpy(this->cuitCliente, cuitCliente, sizeof(this->cuitCliente));
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el cuit de una venta.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ven_getCuitCliente(Ventas* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        strncpy(resultado, this->cuitCliente, 10);
        retorno = 0;
    }
    return retorno;
}

/** \brief Define las horas trabajadas de un empleado.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 cantidad int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ven_setCantidad(Ventas* this, int cantidad)
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
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ven_getCantidad(Ventas* this, int* resultado)
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
 * \param1 this Ventas* Empleado a tomar.
 * \param2 cantidad char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ven_setCantidadAsString(Ventas* this, char* cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        if(esNumerico(cantidad))
        {
            retorno = ven_setCantidad(this, atoi(cantidad));
        }
    }
    return retorno;
}

/** \brief Obtiene las horas trabajadas de un empleado como string.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ven_getCantidadAsString(Ventas* this, char* resultado)
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

/** \brief Define el precioUnitario de un empleado.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 precioUnitario int
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ven_setPrecioUnitario(Ventas* this, float precioUnitario)
{
    int retorno = -1;
    if(this != NULL && precioUnitario >= 0)
    {
        this->precioUnitario = precioUnitario;
        retorno = 0;
    }
    return retorno;
}

/** \brief Obtiene el precioUnitario de un empleado.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado int*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ven_getPrecioUnitario(Ventas* this, float* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->precioUnitario;
        retorno = 0;
    }
    return retorno;
}

/** \brief Define el precioUnitario de un empleado como string.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 precioUnitario char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos o no son validos.
 *
 */

int ven_setPrecioUnitarioAsString(Ventas* this, char* precioUnitario)
{
    int retorno = -1;
    if(this != NULL && precioUnitario >= 0)
    {
        if(esNumericoFlotante(precioUnitario))
        {
            retorno = ven_setPrecioUnitario(this, atof(precioUnitario));
        }
    }
    return retorno;
}

/** \brief Define el precioUnitario de un empleado como string.
 *
 * \param1 this Ventas* Empleado a tomar.
 * \param2 resultado char*
 * \return retorno int. 0 si salio todo correctamente. -1 Si se pasaron parametros nulos.
 *
 */

int ven_getPrecioUnitarioAsString(Ventas* this, char* resultado)
{
    int retorno = -1;
    int bufferPrecioUnitario;
    //char bufferResultado[50];
    if(this != NULL && resultado != NULL)
    {
        bufferPrecioUnitario = this->precioUnitario;
        sprintf(resultado, "%d", bufferPrecioUnitario);
        retorno = 0;
    }
    return retorno;
}

/** \brief Controla si el id ingresado se encuentra en la lista
 *
 * \param pArrayListVentas LinkedList* lista de empelados
 * \param idStr char* id en formato string
 * \return int 0 si hubo error - 1 si salio bien
 *
 */
int ven_ControlId(LinkedList* pArrayListVentas, char* idStr)
{
    int retorno = 0; //Variable retorno funcion
    int id; //Variable ID
    id = atoi(idStr); //Casteo de string a entero
    Ventas* this; //Puntero a estructura
    if(pArrayListVentas != NULL) //Condicional, verifica que sea distinto de NULL
    {
        for(int i=0; i<ll_len(pArrayListVentas); i++) //Recorro el for en busca del ID ingresado
        {
            this = (Ventas*)ll_get(pArrayListVentas, i); //Le asigno a this la estructura que retorna ll_get()
            if(this->id == id) //Si se encuentra el id ingresado se cambia la bandera y se rompe l iteraccion
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno; //Se retorna a la funcion el valor de retorno
}
