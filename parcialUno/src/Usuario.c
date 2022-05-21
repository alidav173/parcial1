/*
 * Usuario.c
 *
 *  Created on: 13 may. 2022
 *      Author: Alí Ansidey
 */

#include "Usuario.h"



static int id =4;

static int generarIdUsuario();

static int generarIdUsuario(){
	return id++;
}


int initUsers(Usuario* list, int len){
    int retorno = ERROR;
    int i;
    if(list != NULL && len >0){
    	for(i =0; i<len;i++){
    		list[i].isEmpty = INACTIVO;
    		list[i].idUsuario = INACTIVO;
    	}
    	retorno = 0;
    }

    return retorno;
}

int findFirstSpaceUsuario (Usuario* list, int len){
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


int findUserById(Usuario* list, int len,int id){
    int retorno = -1;
    int i;
    for(i= 0; i < len; i++){
    	if(list[i].idUsuario == id){
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}

int findUserByEmail(Usuario* list, int len,char* email){
    int retorno = -1;
    int i;
    for(i= 0; i < len; i++){
    	if(strcmp(email,list[i].correo)==0){
    		retorno = i;
    		break;
    	}
    }
    return retorno;
}

int findPassUser(Usuario* list, int len,char* email,char* pass){
    int retorno = -1;
    int index = findUserByEmail(list, len, email);
    if(index!=ERROR){
    	if(strcmp(list[index].password,pass)==0){
    		retorno = 0;
    	}
    }

    return retorno;
}


void showUserData(Usuario usuario){
	printf("\n IdUsuario: %d,\t correo: %s,\t Estado del Usuario: %d \n",usuario.idUsuario, usuario.correo, usuario.isEmpty);

}

int addUser(Usuario* list, int len, int id, short int isEmpty, short int tipo, char* correo, char* password, char* direccion, int codPostal){
     int retorno = ERROR;
     int index = findFirstSpaceUsuario(list, len);
     Usuario usuarioNuevo;
     if(index != ERROR && list != NULL && len > 0 && findUserByEmail(list,len,correo)==ERROR){
    	 usuarioNuevo.idUsuario = id;
    	 usuarioNuevo.isEmpty = ACTIVO;
    	 usuarioNuevo.tipo = tipo;
    	 strcpy(usuarioNuevo.correo, correo);
    	 strcpy(usuarioNuevo.password, password);
    	 strcpy(usuarioNuevo.direccion, direccion);
    	 usuarioNuevo.codPostal = codPostal;
    	 list[index] = usuarioNuevo;
    	 retorno = 0;
     }

    return retorno;
}

int chargeUserData(Usuario* list, int len){
	int retorno = -1;
	Usuario usuarioNuevo;
	if(list != NULL && len > 0){
		usuarioNuevo.idUsuario = generarIdUsuario();
		utn_getNumero(&usuarioNuevo.tipo,"\n Ingrese el tipo de usuario [2 - user / 3- admin]","Reingrese el tipo de usuario [2 - user / 3- admin]", 1, 2, 3);
		utn_getEmail(usuarioNuevo.correo,25,"Ingrese el correo\n","Reingrese el correo\n",3);
		utn_getCadena(usuarioNuevo.password, 10,"\n Ingrese la contraseña [alfanumerica sin signos]: ","\n Reingrese la constraseña [alfanumerica sin signos]: ",3);
		utn_getCadena(usuarioNuevo.direccion, 50,"\n Ingrese la dirección","\n Reingrese la dirección",3);
		utn_getNumero(&usuarioNuevo.codPostal,"\n Ingrese el código postal","Reingrese el código postal", 1,9999, 3);

		if(addUser(list,len,usuarioNuevo.idUsuario,usuarioNuevo.isEmpty,usuarioNuevo.tipo,usuarioNuevo.correo,usuarioNuevo.password,usuarioNuevo.direccion,usuarioNuevo.codPostal) != ERROR){
			puts("\n Se cargaron los datos del usuario con exito");
			retorno = 0;
		}
		else{
			puts("\n NO se pudieron cargar los datos del usuario\n");
		}
	}
	return retorno;
}


int removeUser(Usuario* list, int len, int id){
    char respuesta[3];
	int retorno = -1;
    int indice;
    printUser(list,len);
    	indice = findUserById(list,len,id);
    	utn_getNombre(respuesta, 3,"\n Esta seguro de eliminar al usuario: [si/no]","\n Reingrese su opción [si/no]: ",3);
    	strMinuscula(respuesta);
    	if(indice != -1 && strcmp(respuesta,"si")== 0){
    		list[indice].isEmpty = INACTIVO;
    		retorno = 0;
    	}

    return retorno;
}




int printUser(Usuario* list, int length){
    int retorno = -1;
    int i;
    printf("\nListado de Usuarios:");
    if(list != NULL && length > 0){
    	for(i=0; i < length; i++){
    		if(list[i].isEmpty != INACTIVO && list[i].idUsuario != INACTIVO ){
    			showUserData(list[i]);
    	}
    }
    	retorno = 0;
    }

    return retorno;
}

int printAllUsers(Usuario* list, int length){
    int retorno = -1;
    int i;
	printf("\nListado de todos los Usuarios:");
    if(list != NULL && length > 0){
    	for(i=0; i < length; i++){
    		if(list[i].idUsuario != INACTIVO){
    	    	showUserData(list[i]);
    		}
    }
    	retorno = 0;
    }

    return retorno;
}






