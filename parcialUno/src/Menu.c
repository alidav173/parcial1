/*
 * Menu.c
 *
 *  Created on: 13 may. 2022
 *      Author: Alí Ansidey
 */


#include "Menu.h"

void mostrarMenuUno (void){
	printf("***************************\n");
	printf("** 1er EXAMEN LAB I - 1H***\n");
	printf("***************************\n");
	printf("\n");
	printf("1) Ingresar\n");
	printf("2) Registrarse\n");
	printf("\n");
	printf("0) Salir\n");
}


void mostrarMenuDos (void){
	printf("***************************\n");
	printf("** 1er EXAMEN LAB I - 1H***\n");
	printf("*********USUARIO***********\n");
	printf("***************************\n");
	printf("\n");
	printf("1) COMPRAR\n");
	printf("2) VENDER\n");
	printf("3) ESTADO DE COMPRAS\n");
	printf("4) ESTADO DE VENTAS\n");
	printf("\n");
	printf("0) SALIR\n");
}

void mostrarMenuTres (void){
	printf("***************************\n");
	printf("** 1er EXAMEN LAB I - 1H***\n");
	printf("*********ADMIN***********\n");
	printf("***************************\n");
	printf("\n");
	printf("1) LISTAR ESTADO DE TODOS LOS USUARIOS\n");
	printf("2) LISTAR TODOS LOS PRODUCTOS POR CATEGORIA\n");
	printf("3) BAJA DE UN PRODUCTO\n");
	printf("4) BAJA DE UN USUARIO\n");
	printf("5) VER TRACKING GLOBAL\n");
	printf("6) FILTRAR POR NOMBRE PRODUCTO");
	printf("\n");
	printf("0) SALIR\n");
}

void listarCategorias(void){
	printf("4) MODA\n");
	printf("5) CONSTRUCCION\n");
	printf("6) TECNOLOGIA\n");
	printf("7) SUPERMERCADO\n");

}
