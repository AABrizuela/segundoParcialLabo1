#ifndef VENTAS_H
#define VENTAS_H

typedef struct{

    int id;
    char fechaVenta[15];
    char tipoFoto[16];
    int cantidad;
    float precioUnitario;
    char cuitCliente[15];
}Ventas;

#endif // VENTAS_H

void ven_menu(LinkedList* listaVentas);
Ventas* ven_new();
Ventas* ven_newParametros(char* id, char* fechaVenta, char* tipoFoto, char* cantidad, char* precioUnitario, char* cuitCliente);
int ven_delete(Ventas* this);

int ven_setId(Ventas* this,int id);
int ven_getId(Ventas* this,int* resultado);
int ven_setIdAsString(Ventas* this, char* id);
int ven_getIdAsString(Ventas* this, char* resultado);

int ven_setFechaVenta(Ventas* this, char* fechaVenta);
int ven_getFechaVenta(Ventas* this, char* resultado);

int ven_setTipoFoto(Ventas* this,char* tipo);
int ven_getTipoFoto(Ventas* this,char* resultado);

int ven_setCantidad(Ventas* this,int cantidad);
int ven_getCantidad(Ventas* this,int* resultado);
int ven_setCantidadAsString(Ventas* this, char* cantidad);
int ven_getCantidadAsString(Ventas* this, char* resultado);

int ven_setPrecioUnitario(Ventas* this,float precioUnitario);
int ven_getPrecioUnitario(Ventas* this,float* resultado);
int ven_setPrecioUnitarioAsString(Ventas* this, char* precioUnitario);
int ven_getPrecioUnitarioAsString(Ventas* this, char* resultado);

int ven_setCuitCliente(Ventas* this,char* cuitCliente);
int ven_getCuitCliente(Ventas* this,char* resultado);

int ven_ControlId(LinkedList* pArrayListVentas, char* idStr);
