/******************************************************************************

 ============================================================================
 Name        : Main.c
 Author      : Alí Ansidey
 Version     :1.0.1
 Copyright   : Copien y utilicen lo necesitan
 Description : Parcial Laboratorio de Programación 1
 ============================================================================
 */
#include <stdio.h>
#include <limits.h>
#include "Menu.h"
#include "Operaciones.h"

#define ERROR -1
#define INACTIVO 0
#define ACTIVO 1
#define ADMIN 2
#define USER 3
#define MODA 4
#define CONSTRUCCION 5
#define TECNOLOGIA 6
#define SUPERMERCADO 7
#define TAM_ARRAY 5


int main()
{
   setbuf (stdout, NULL);
   Usuario usuarios[TAM_ARRAY];
   Producto productos[TAM_ARRAY];
   Tracking trackings[TAM_ARRAY];

   //Inicializo en vacio los arrays
   initProduct(productos,TAM_ARRAY);
   initUsers(usuarios,TAM_ARRAY);
   initTracking(trackings, TAM_ARRAY);

   //Harcodeo Usuarios
   Usuario usuario1 = {1,ACTIVO,USER,"alidav170@gmail.com","1234","Los Samanes",500};
   usuarios[0] = usuario1;
   Usuario usuario2 = {2,ACTIVO,ADMIN,"elshavi@gmail.com","12345","San Rafael",1292};
   usuarios[1] = usuario2;
   Usuario usuario3 = {3,ACTIVO,USER,"elenai@gmail.com","0000","Rafael Calzada",4000};
   usuarios[2] = usuario3;

   //Harcodeo productos
   Producto producto1 = {1, ACTIVO, "Raizen 5",30000,TECNOLOGIA,1};
   productos[0] = producto1;
   Producto producto2 = {2, ACTIVO, "Santa Ana Malbec",400,SUPERMERCADO,10};
   productos[1] = producto2;
   Producto producto3 = {3, ACTIVO, "Botines nike tempo",17282,MODA,2};
   productos[2] = producto3;
   Producto producto4 = {4, ACTIVO, "Pala",17282,CONSTRUCCION,2};
   productos[3] = producto4;


   int opc1,opc2,opc3,opc4, resEmail, resNombre, resPass, orden, idProductoAeliminar,idProductoAstokear, idUsuarioAeliminar, cantidadAstockear;
   char email[25];
   char password[10];
   char nombreProductoBuscado[25];

   //Menu Principal del Programa
   mostrarMenuUno();
   utn_getNumero(&opc1, "Ingrese la opción\n","Reingrese la opción\n",0,2,3);
   do{
   switch(opc1){
   case 1:
	 utn_getEmail(email,25,"Ingrese su email:\n","Reingrese su email\n", 3);
	 resEmail = findUserByEmail(usuarios,TAM_ARRAY,email);
	 utn_getCadena(password,10,"Ingrese su password:\n","Reingrese su password\n", 3);
	 resPass =findPassUser(usuarios,TAM_ARRAY,email,password);
	 //Ingreso de un usuario registrado
	   if(resEmail != ERROR && resPass == 0){
		   printf("Bienvenido de vuelta\n");
		   printf("\n");
		   //Menu del usuario tipo USER
		   if(usuarios[resEmail].tipo==USER){
		       mostrarMenuDos();
		       utn_getNumero(&opc2, "Ingrese la opción\n","Reingrese la opción\n",0,4,3);
		       do{
		       switch(opc2){
		               case 1:
		               //Comprar un producto
		               comprarProducto(productos,TAM_ARRAY,trackings,TAM_ARRAY,usuarios,TAM_ARRAY,resEmail);
		               showTrackingData(trackings[0]);
		               break;
		               case 2:
		               utn_getNumero(&opc4, "Ingrese la opcion [1 -vender / 2-reponer stock]\n","Reingrese la opción\[1 -vender / 2-reponer stock]n",1,2,3);
		               if(opc4 == 1){
		            	   //Vender un producto
		            	   chargeProductData(productos,TAM_ARRAY);
		               }
		               else{
		            	   //reponer stock productos
		            	   utn_getNumero(&idProductoAstokear, "Ingrese el id del producto\n","Reingrese el id del producto \n",1,INT_MAX,3);
		            	   utn_getNumero(&cantidadAstockear, "Ingrese la cantidad a stockear\n","Reingrese la cantidad\n",1,INT_MAX,3);
		            	   reponerStock(productos,TAM_ARRAY,idProductoAstokear,cantidadAstockear);
		               }
		               printProductEnStock(productos, TAM_ARRAY);
		               break;
		               case 3:
		               //Estado de compra y/o cancelación
		               removeTracking(trackings, TAM_ARRAY, productos, TAM_ARRAY);
		               break;
		               case 4:
		            	//Estado de ventas y ventas finalizadas
		               ventasFinalizadas(trackings, TAM_ARRAY);
		               printf("******************\n");
		               sleep(5);
		               printProductEnStock(productos, TAM_ARRAY);
		               break;
		   }
		       mostrarMenuDos();
		       utn_getNumero(&opc2, "Ingrese la opción\n","Reingrese la opción\n",0,4,3);
		       }while(opc2 != 0);
		 }
		   //Menu del usuario tipo ADMIN
		   else{
		        mostrarMenuTres();
		        utn_getNumero(&opc3, "Ingrese la opción\n","Reingrese la opción\n",0,6,3);
		        do{
		        switch(opc3){
		                case 1:
		                //LISTAR ESTADO DE TODOS LOS USUARIOS
		                printAllUsers(usuarios,TAM_ARRAY);
		                break;
		                case 2:
		               //Ordenar productos por categorías
		                utn_getNumero(&orden, "Ingrese el orden[-1 ascendente / 1 descendente]\n","Reingrese el orden[-1 ascendente / 1 descendente]\n",-1,1,3);
		                sortProducts(productos, TAM_ARRAY,orden);
		                break;
		                case 3:
		                //BAJA DE UN PRODUCTO
		                printProduct(productos, TAM_ARRAY);
		                utn_getNumero(&idProductoAeliminar, "Ingrese el id del producto a eliminar: \n","Reingrese el id del producto a eliminar: \n",1,INT_MAX,3);
		                removeProduct(productos,TAM_ARRAY,idProductoAeliminar);
		                break;
		                case 4:
		                //BAJA DE UN USUARIO
		                printUser(usuarios,TAM_ARRAY);
		                utn_getNumero(&idUsuarioAeliminar, "Ingrese el id del usuario a eliminar: \n","Reingrese el id del usuario a eliminar: \n",1,INT_MAX,3);
		                removeUser(usuarios,TAM_ARRAY, idUsuarioAeliminar);
		                break;
		                case 5:
		                //VER TRACKING GLOBAL
		                printTrackings(trackings, TAM_ARRAY);
		                break;
		                case 6:
		                //FILTRAR POR NOMBRE PRODUCTO
		                utn_getCadena(nombreProductoBuscado,25,"Ingrese el nombre del producto a filtrar:\n","Reingrese nombre del producto\n", 3);
		                resNombre = findProductByName(productos,TAM_ARRAY,nombreProductoBuscado);
		                if(resNombre != ERROR){
		                	sortProducts2(productos, TAM_ARRAY, nombreProductoBuscado,25);
		                }
		                else{
		                	printf("No hay un producto con ese nombre\n");
		                }
		                break;
		            }
		        mostrarMenuTres();
		        utn_getNumero(&opc3, "Ingrese la opción\n","Reingrese la opción\n",0,6,3);
		        }while(opc3!=0);
		   }
	   }
	   else if(resEmail != ERROR && resPass != 0 ){
		   printf("Contraseña Inválida\n");
		   printf("\n");
	   }
	   else{
		   printf("Usuario Inválido\n");
		   printf("\n");
	   }

	   break;

   case 2:
	   //Carga de datos para un nuevo usuario del sistema
	   chargeUserData(usuarios,TAM_ARRAY);
	   break;
   }

   mostrarMenuUno();
   utn_getNumero(&opc1, "Ingrese la opción\n","Reingrese la opción\n",0,2,3);
   }while(opc1 !=0);
   printf("\n Ha salido del sistema");
 return 0;
}
