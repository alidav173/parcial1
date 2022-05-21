/*
 * Operaciones.c
 *
 *  Created on: 13 may. 2022
 *      Author: Alí Ansidey
 */

#include "Operaciones.h"


int comprarProducto(Producto* productos, int lenProductos,Tracking* trackings, int lenTracking, Usuario* usuarios, int lenUsuarios, int indexUsuario){
	int retorno = ERROR;
	int idProductoBuscado,cantidadAComprar, indice, idtracking;
	float montoCompra = 0;
	printProduct(productos, lenProductos);
	utn_getNumero(&idProductoBuscado,"\n Elija el producto a comprar por su id:","\n Reelija el producto a comprar por su id:",1,INT_MAX,3);
	indice = findProductById(productos,lenProductos,idProductoBuscado);
	if(indice !=ERROR){
		utn_getNumero(&cantidadAComprar,"\n Elija la cantidad a comprar:","\n Reelija la cantidad a comprar:",1,INT_MAX,3);
		if(cantidadAComprar >0){
			if(productos[indice].stock >= cantidadAComprar){
				productos[indice].stock -=cantidadAComprar;
				montoCompra = totalCompra(cantidadAComprar, productos[indice].precio);
				idtracking = altaTracking(trackings,lenTracking,usuarios,lenUsuarios,idProductoBuscado,indexUsuario,cantidadAComprar);
				printf("\n El total de la compra es $ %.2f y su nro de tracking es: 000%d\n",montoCompra,idtracking);
				retorno = 0;
			}
			else{
				printf("\n No se puede comprar la cantidad seleccionada");
				printf("\n El stock del producto id %d es %d unidades \n", productos[indice].idProducto,productos[indice].stock);
			}
		}
	}
	else{
		printf("\n No existe el id del producto");
	}

	return retorno;

}

float totalCompra(int cantidadProductos, float precioProducto){
	float total = cantidadProductos * precioProducto;
	return total;
}

int altaTracking(Tracking* trackings,int lenTracking,Usuario* usuarios, int lenUsuarios,int idProducto,int indexUsuario,int cantidadProductos){
	int retorno = -1;
	int distancia;
	double tiempoDemora;
	int index = findFirstSpaceTracking(trackings, lenTracking);
	Tracking trackingNuevo;
	if(index != ERROR && trackings != NULL && lenTracking > 0){
		trackingNuevo.idTracking = generarIdTracking();
		trackingNuevo.idProducto = idProducto;
		trackingNuevo.isEmpty = ENVIAJE;
		trackingNuevo.cantidad = cantidadProductos;
		distancia = calcularKm(usuarios,lenUsuarios,indexUsuario);
		trackingNuevo.distanciaKM =distancia;
		tiempoDemora = secondsAdd(distancia);
		trackingNuevo.horaLlegada = time_Add(tiempoDemora);
		// Se guardan los datos en el array de Trackings
		trackings[index] = trackingNuevo;
		retorno = trackingNuevo.idTracking;

	}

	return retorno;
}


int removeTracking(Tracking* list, int len, Producto* productos, int lenProductos){
    char respuesta[3];
	int retorno = -1;
    int indiceTracking, idTracking, idProducto, indiceProducto;
    actulizarTracking(list,len);
    printTrackingEnViaje(list,len);
    utn_getNumero(&idTracking,"\n Ingrese el id del pedido:","Reingrese el id del pedido:",1,INT_MAX,3);
    indiceTracking = findTrackingById(list,len,idTracking);
    utn_getNombre(respuesta, 3,"\n Esta seguro de cancelar el pedido: [si/no]","\n Reingrese su opción [si/no]: ",3);
    strMinuscula(respuesta);
    	if(indiceTracking != ERROR && strcmp(respuesta,"si")== 0 && list[indiceTracking].isEmpty == ENVIAJE){
    		list[indiceTracking].isEmpty = CANCELADO;
    		idProducto = list[indiceTracking].idProducto;
    		indiceProducto = findProductById(productos, lenProductos, idProducto);
    		productos[indiceProducto].stock += list[indiceTracking].cantidad;
    		printf("\n Se canceló el envio con exito");
    		retorno = 0;
    	}
    	else{
    		printf("\n No se pudo cancelar el envio");
    	}

    return retorno;
}

