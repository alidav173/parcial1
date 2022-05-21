/*
 * Producto.c
 *
 *  Created on: 13 may. 2022
 *      Author: ali
 */

#include "Producto.h"


static int id =5;

static int generarIdProduct();

static int generarIdProduct(){
	return id++;
}


int initProduct(Producto* list, int len){
    int retorno = ERROR;
    int i;
    if(list != NULL && len >0){
    	for(i =0; i<len;i++){
    		list[i].isEmpty = INACTIVO;
    	}
    	retorno = 0;
    }

    return retorno;
}

int findFirstSpace (Producto* list, int len){
	int index = ERROR;
	int i;
	for(i = 0; i < len; i++){
		if(list[i].isEmpty == INACTIVO){
			index = i;
			break;
		}
	}
return index;
}


int findProductById(Producto* list, int len,int id){
    int retorno = -1;
    int i;
    for(i= 0; i < len; i++){
    	if(list[i].idProducto == id){
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}

int findProductByName(Producto* list, int len,char* nombreProducto){
    int retorno = -1;
    int i;
    for(i= 0; i < len; i++){
    	if(strcmp(nombreProducto,list[i].nombreProducto)==0){
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}


void showProductData(Producto producto){
	printf("\n IdProducto: %d,\t nombre: %s,\t Precio: $ %.2f,\t Categoría: %d,\t Stock: %d,\t isEmpty %d \n",producto.idProducto, producto.nombreProducto,producto.precio,producto.categoria, producto.stock, producto.isEmpty);

}

int addProduct(Producto* list, int len, int idProducto, char* nombreProducto, float precio, short int categoria, int stock){
     int retorno = ERROR;
     int index = findFirstSpace(list, len);
     Producto productoNuevo;
     if(index != ERROR && list != NULL && len > 0 && findProductById(list,len,idProducto)==ERROR){
    	 productoNuevo.idProducto = idProducto;
    	 strcpy(productoNuevo.nombreProducto, nombreProducto);
    	 productoNuevo.precio = precio;
    	 productoNuevo.categoria = categoria;
    	 productoNuevo.stock = stock;
    	 productoNuevo.isEmpty = ACTIVO;
    	 list[index] = productoNuevo;
    	 retorno = 0;
     }

    return retorno;
}

int chargeProductData(Producto* list, int len){
	int retorno = -1;
	Producto productoNuevo;
	if(list != NULL && len > 0){
		productoNuevo.idProducto = generarIdProduct();
		utn_getCadena(productoNuevo.nombreProducto,25,"Ingrese el nombre del producto\n","Reingrese el nombre del producto\n",3);
		utn_getNumeroFlotante(&productoNuevo.precio,"\n Ingrese el precio del producto","Reingrese el precio del producto", 1,INT_MAX, 3);
		listarCategorias();
		utn_getNumero(&productoNuevo.categoria,"\n Ingrese la categoria del producto: ","Reingrese el la categoria: ", 4,7,3);
		utn_getNumero(&productoNuevo.stock,"\n Ingrese la cantidad de productos:","Reingrese la cantidad de productos:", 0,INT_MAX, 3);

		if(addProduct(list,len, productoNuevo.idProducto, productoNuevo.nombreProducto,productoNuevo.precio, productoNuevo.categoria, productoNuevo.stock)!= ERROR){
			puts("\n Se cargaron los datos del producto con exito");
			retorno = 0;
		}
		else{
			puts("\n No se pudo cargar el producto\n");
		}
	}
	return retorno;
}


int removeProduct(Producto* list, int len, int id){
    char respuesta[3];
	int retorno = -1;
    int indice;
    	indice = findProductById(list,len,id);
    	utn_getNombre(respuesta, 3,"\n Esta seguro de eliminar el producto: [si/no]","\n Reingrese su opción [si/no]: ",3);
    	strMinuscula(respuesta);
    	if(indice != -1 && strcmp(respuesta,"si")== 0){
    		list[indice].isEmpty = INACTIVO;
    		retorno = 0;
    	}

    return retorno;
}




int printProduct(Producto* list, int length){
    int retorno = -1;
    int i;
    if(list != NULL && length > 0){
    	printf("\nListado de Productos:");
    	for(i=0; i < length; i++){
    		if(list[i].isEmpty != INACTIVO){
    			showProductData(list[i]);
    	}
    }
    	retorno = 0;
    }

    return retorno;
}


int printProductEnStock(Producto* list, int length){
    int retorno = -1;
    int i;
    if(list != NULL && length > 0){
    	printf("\nListado de Productos en stock:");
    	for(i=0; i < length; i++){
    		if(list[i].isEmpty != INACTIVO  && list[i].stock > 0){
    			showProductData(list[i]);
    	}
    }
    	retorno = 0;
    }

    return retorno;
}

int sortProducts(Producto* list, int len, int order){
     int retorno = -1;
     int i, j;
     /* case -1 -> menor a mayor (ascendente)
      * case 1 -> mayor a menor (descendente)
      *
      */
     Producto productoAux;
     if(list != NULL && len > 0){
    	 switch(order){
    	 case -1:
    		 for(i= 0; i < len-1; i++){
    			 for(j=i+1; j < len; j++){
    				 //Compruebo que los productos no esten eliminados
    				 if(list[i].isEmpty == ACTIVO && list[j].isEmpty == ACTIVO){
    					 if(strcmp(list[i].nombreProducto,list[j].nombreProducto) > 0 ){
    						 //Intercambio de posiciones en el array
    						 productoAux = list[i];
    						 list[i] = list[j];
    						 list[j] = productoAux;
    					 }
    					 else if(strcmp(list[i].nombreProducto,list[j].nombreProducto) == 0 && list[i].categoria > list[j].categoria){
    						 //Intercambio de posiciones en el array
    						 productoAux = list[i];
    						 list[i] = list[j];
    						 list[j] = productoAux;
    					 }
    				 }
    			 }
    		 }
    		 retorno = 0;
    		 printProduct(list, len);
    		 break;

    	 case 1:
    		 for(i= 0; i < len-1; i++){
    	    			 for(j=i+1; j < len; j++){
    	    				 if(list[i].isEmpty == ACTIVO && list[j].isEmpty == ACTIVO){
    	    					 if(strcmp(list[i].nombreProducto,list[j].nombreProducto ) < 0){
    	    						 //Intercambio de posiciones en el array
    	    						 productoAux = list[i];
    	    						 list[i] = list[j];
    	    						 list[j] = productoAux;
    	    					 }
    	    					 else if(strcmp(list[i].nombreProducto,list[j].nombreProducto) == 0 && list[i].categoria < list[j].categoria){
    	    						 //Intercambio de posiciones en el array
    	    						 productoAux = list[i];
    	    						 list[i] = list[j];
    	    						 list[j] = productoAux;
    	    					 }
    	    				 }
    	    			 }
    	    		 }
      		 retorno = 0;
      		printProduct(list, len);
        	break;

    	 }

     }
    return retorno;
}

int reponerStock(Producto* list, int len, int id, int cantidadAreponer){
	int retorno = -1;
    int indice;
    printProduct(list, len);
    indice = findProductById(list,len,id);
    	if(indice != -1 && cantidadAreponer > 0){
    		list[indice].stock =cantidadAreponer ;
    		retorno = 0;
    	}
    	else{
    		printf("No se pudo reponer el stock\n");
    	}

    return retorno;
}

int sortProducts2(Producto* list, int len, char* nombreBuscado, int lenNombre){
     int retorno = -1;
     int i,orden;
     int j = 0;
     Producto arrayAuxProducto[100];
     initProduct(arrayAuxProducto,100);

     if(list != NULL && len > 0){
    	 for(i = 0; i < len; i++){
    		 if(strcmp(list[i].nombreProducto,nombreBuscado)==0 && list[i].isEmpty != INACTIVO){
    			 arrayAuxProducto[j] = list[i];
    			 j++;
    		 }

    	 }
    	 retorno = 0;
     }
     utn_getNumero(&orden, "Ingrese el orden [-1 ascendente / 1 descendente]:\n","Reingrese el orden [-1 ascendente / 1 descendente]: \n",-1,1,3);
     sortProducts(arrayAuxProducto,100,orden);
return retorno;
}
