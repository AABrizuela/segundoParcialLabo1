#ifndef ENTREGAS_H
#define ENTREGAS_H

typedef struct{

    int id;
    char tipo[51];
    int cantidad;
    float importe;

}Entregas;

#endif


void ent_menu(LinkedList* listaEntregas);
Entregas* ent_new();
Entregas* ent_newParametros(char* id,char* tipo,char* cantidad, char* importe);
int ent_delete(Entregas* this);

int ent_setId(Entregas* this,int id);
int ent_getId(Entregas* this,int* resultado);
int ent_setIdAsString(Entregas* this, char* id);
int ent_getIdAsString(Entregas* this, char* resultado);

int ent_setTipo(Entregas* this,char* tipo);
int ent_getTipo(Entregas* this,char* resultado);

int ent_setCantidad(Entregas* this,int cantidad);
int ent_getCantidad(Entregas* this,int* resultado);
int ent_setCantidadAsString(Entregas* this, char* cantidad);
int ent_getCantidadAsString(Entregas* this, char* resultado);

int ent_setImporte(Entregas* this,float importe);
int ent_getImporte(Entregas* this,float* resultado);
int ent_setImporteAsString(Entregas* this, char* importe);
int ent_getImporteAsString(Entregas* this, char* resultado);
int ent_ControlId(LinkedList* pArrayListEntregas, char* idStr);
