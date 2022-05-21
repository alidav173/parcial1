/*
 * Producto.h
 *
 *  Created on: 13 may. 2022
 *      Author: Alí Ansidey
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include "limits.h"
#include "stdio.h"
#include "input.h"

#define ERROR -1
#define INACTIVO 0
#define ACTIVO 1
#define MODA 4
#define CONSTRUCCION 5
#define TECNOLOGIA 6
#define SUPERMERCADO 7

typedef struct{
	int idProducto;
	short int isEmpty;
	char nombreProducto[25];
	float precio;
	short int categoria;
	int stock;
}Producto;

int initProduct(Producto* list, int len);

int findFirstSpace (Producto* list, int len);

int findProductById(Producto* list, int len,int id);

int findProductByName(Producto* list, int len,char* nombreProducto);

void showProductData(Producto producto);

int addProduct(Producto* list, int len, int idProducto, char* nombreProducto, float precio, short int categoria, int stock);

int chargeProductData(Producto* list, int len);

int removeProduct(Producto* list, int len, int id);

int printProduct(Producto* list, int length);

int printProductEnStock(Producto* list, int length);

int sortProducts(Producto* list, int len, int order);

int sortProducts2(Producto* list, int len, char* nombreBuscado, int lenNombre);

int reponerStock(Producto* list, int len, int id, int cantidadAreponer);


#endif /* PRODUCTO_H_ */
