/*
 * Usuario.h
 *
 *  Created on: 13 may. 2022
 *      Author: ali
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include "limits.h"
#include "stdio.h"
#include "input.h"
#define ERROR -1
#define INACTIVO 0
#define ACTIVO 1
#define ADMIN 2
#define USER 3


typedef struct{
	int idUsuario;
	short int isEmpty;
	short int tipo; //ADMIN - USUARIO
	char correo[25];
	char password[10];
	char direccion[50];
	int codPostal;
}Usuario;

int initUsers(Usuario* list, int len);

int findFirstSpaceUsuario (Usuario* list, int len);

int addUser(Usuario* list, int len, int id, short int isEmpty, short int tipo, char* correo, char* password, char* direccion, int codPostal);

int chargeUserData(Usuario* list, int len);

int findUserById(Usuario* list, int len,int id);

int findUserByEmail(Usuario* list, int len,char* email);

int findPassUser(Usuario* list, int len,char* email,char* pass);

int removeUser(Usuario* list, int len, int id);

int printUser(Usuario* list, int length);

void showUserData(Usuario usuario);

int printAllUsers(Usuario* list, int length);


#endif /* USUARIO_H_ */
