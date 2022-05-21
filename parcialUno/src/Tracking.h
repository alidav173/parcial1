/*
 * Tracking.h
 *
 *  Created on: 13 may. 2022
 *      Author: ali
 */

#ifndef TRACKING_H_
#define TRACKING_H_

#define CANCELADO -1
#define ENVIAJE 0
#define ENTREGADO 1

#include "limits.h"
#include "stdio.h"
#include "input.h"
#include "time.h"
#include "Producto.h"
#include "Usuario.h"

typedef struct{
	int idTracking;
	int idProducto; //FK Producto
	short int isEmpty;
	int cantidad;
	int distanciaKM;
	long int horaLlegada;
}Tracking;

int generarIdTracking();

int initTracking(Tracking* list, int len);

int findFirstSpaceTracking (Tracking* list, int len);

int findTrackingById(Tracking* list, int len,int id);

int kmPorCodigoPostal(int codigoPostal);

int calcularKm(Usuario* list, int lenUsuarios, int indexUsuario);

double secondsAdd(int distancia);

long int time_current(void);

long int time_Add(double secondsAdd);

void showTrackingData(Tracking tracking);

int printTrackingEnViaje(Tracking* list, int length);

int actulizarTracking(Tracking* trackings,int lenTracking);

int ventasFinalizadas(Tracking* list, int length);

int printTrackings(Tracking* list, int length);

#endif /* TRACKING_H_ */
