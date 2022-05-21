/*
 * Operaciones.h
 *
 *  Created on: 13 may. 2022
 *      Author: Alí Ansidey
 */

#ifndef SRC_OPERACIONES_H_
#define SRC_OPERACIONES_H_

#include "Tracking.h"

int comprarProducto(Producto* productos, int lenProductos,Tracking* trackings, int lenTracking, Usuario* usuarios, int lenUsuarios, int indexUsuario);

float totalCompra(int cantidadProductos, float precioProducto);

int altaTracking(Tracking* trackings,int lenTracking,Usuario* usuarios, int lenUsuarios,int idProducto,int indexUsuario,int cantidadProductos);

int removeTracking(Tracking* list, int len, Producto* productos, int lenProductos);

#endif /* SRC_OPERACIONES_H_ */
