/*
 * Tracking.c
 *
 *  Created on: 13 may. 2022
 *      Author: Alí Ansidey
 */
#include "Tracking.h"

static int id =1;

int generarIdTracking(){
	return id++;
}

int initTracking(Tracking* list, int len){
    int retorno = ERROR;
    int i;
    if(list != NULL && len >0){
    	for(i =0; i<len;i++){
    		list[i].idTracking = 0;
    		list[i].isEmpty = CANCELADO;
    	}
    	retorno = 0;
    }

    return retorno;
}

int findFirstSpaceTracking (Tracking* list, int len){
	int index = ERROR;
	int i;
	for(i = 0; i < len; i++){
		if(list[i].isEmpty == CANCELADO){
			index = i;
			break;
		}
	}
return index;
}


int findTrackingById(Tracking* list, int len,int id){
    int retorno = ERROR;
    int i;
    for(i= 0; i < len; i++){
    	if(list[i].idTracking == id){
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}

int kmPorCodigoPostal(int codigoPostal){
	int km = 0;
	if(codigoPostal >=1 || codigoPostal <= 1000){
		km = 20;
	}
	if(codigoPostal >=1001 || codigoPostal <= 3000){
		km = 30;
	}
	if(codigoPostal >=3001 || codigoPostal <= 5000){
		km = 50;
	}
	if(codigoPostal >=5001 || codigoPostal <= 8000){
		km = 80;
	}
	if(codigoPostal >=8001 || codigoPostal <= 9000){
		km = 150;
	}
	return km;
}

int calcularKm(Usuario* list, int lenUsuarios, int indexUsuario){
	int km = 0;
	int codigoPostal;
	if(list!= NULL && lenUsuarios > 0 && indexUsuario != ERROR){
			codigoPostal = list[indexUsuario].codPostal;
			km= kmPorCodigoPostal(codigoPostal);
	}
return km;
}



double secondsAdd(int distancia){
	//Calculo los segundos adicionales a la hora de compra
	double secondsAdd = distancia * 0.2;
	return secondsAdd;

}

long int time_current(void){
	return time(NULL);
}

long int time_Add(double secondsAdd){
	return secondsAdd + time_current();
}



/*int altaTracking(Tracking* trackings,int lenTracking,Usuario* usuarios, int lenUsuarios,int idProducto,int indexUsuario,int cantidadProductos){
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
*/

void showTrackingData(Tracking tracking){
	printf("\n IdTracking: %d,\t IdProducto: %d,\t, Cantidad: %d,\t Distancia: %d km,\t estado compra: %d\n", tracking.idTracking, tracking.idProducto, tracking.cantidad, tracking.distanciaKM,tracking.isEmpty);
	char* cadenaHoraLlegada = ctime(&tracking.horaLlegada);
	printf("\n El tiempo de llegada del pedido es: %s \n",cadenaHoraLlegada);
}

int printTrackingEnViaje(Tracking* list, int length){
    int retorno = -1;
    int i;
    if(list != NULL && length > 0){
    	printf("\nListado de Trackings:");
    	for(i=0; i < length; i++){
    		if(list[i].isEmpty != CANCELADO && list[i].isEmpty != ENTREGADO && list[i].idTracking > 0){
    			showTrackingData(list[i]);
    	}
    }
    	retorno = 0;
    }

    return retorno;
}

int actulizarTracking(Tracking* trackings,int lenTracking){
	int retorno = -1;
	int i;
	double diferenciaTiempo;
	long int horaActual = time(NULL);

	if(trackings != NULL && lenTracking > 0){
		for(i = 0; i < lenTracking; i++){
			diferenciaTiempo = difftime(trackings[i].horaLlegada, horaActual);
				if(diferenciaTiempo <= 0){
					trackings[i].isEmpty = ENTREGADO;
				}
		}
		retorno = 0;
	}
	return retorno;
}

/*
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
*/

int ventasFinalizadas(Tracking* list, int length){
    int retorno = -1;
    int i;
    if(list != NULL && length > 0){
    	actulizarTracking(list,length);
    	printf("\nListado de ventas finalizadas o canceladas:");
    	for(i=0; i < length; i++){
    		if((list[i].isEmpty == CANCELADO || list[i].isEmpty == ENTREGADO) && list[i].idTracking > 0){
    			showTrackingData(list[i]);
    	}
    }
    	retorno = 0;
    }

    return retorno;
}

int printTrackings(Tracking* list, int length){
    int retorno = -1;
    int i;
    if(list != NULL && length > 0){
    	printf("\nListado de Trackings:");
    	for(i=0; i < length; i++){
    		if(list[i].isEmpty != CANCELADO && list[i].idTracking != 0){
    			showTrackingData(list[i]);
    	}
    }
    	retorno = 0;
    }

    return retorno;
}
