//# 4_EDAI_2018II_P6
//Estructuras de datos lineales: Cola circular y cola doble
		||	4_EDAI_2018II_A1	|| Práctica 06	Estructuras de datos lineales: Cola circular y cola doble

/*

	------------------------------------------------------------------------------------------
	
	Actividad:
	
	La práctica consiste en implementar una función adicional al código de colas visto en 
	clase, que permita desencolar el último elemento ingresado (como una pila). Los procesos 
	de encolar y descencolar originales con el metodo FIFO se deben mantener iguales.
	
	------------------------------------------------------------------------------------------
	Descripción del archivo.
	
	Uso de variables:
	
		Las variables se nombran de la siguiente manera: 
				
				(Tipo-de-variable)(Tipo-dato)_(palabra_en_funcion_del_uso_de_la_variable)  
	
				Global  = g		int   = i	* Al momento de declararla se requiere hacer una	
				funcion = f 	float = f		descripción de su uso dentro del programa.
								char  = c
								short = sh
				
		Al momento de declararla, por ejemplo:
					
						int fi_contadorUsuario 	// Contador del número que ingresa el usuario 
						int fi_contadorPc;	// Contador del número génerado por el pc.
				
		* Las variables que tienen la finalidad de actuar cómo contadores dentro de un 
		ciclo, son i, j, k y l. (En ese orden conforme se este trabajando).
			
	Uso de funciónes:
	
		Las funciónes se nombran de acuerdo con el siguiente criterio:
		
			(Tipo-de-funcion)_(descripción_Cada_palabra_inicil_con_mayuscula)
			
			void	= v			* Al momento de declararla se requiere hacer una
			int		= i				descripción de su uso dentro del programa.
				
		Al momento de declararla, por ejemplo:
		
						i_SumaDatos , v_RestaResultados , i_ImprimirDatos 	
	
	------------------------------------------------------------------------------------------
*/

/*		1- Librerias		*///--------------------------------------------------------------

	#include <stdio.h>
	#include <conio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <float.h>
	#include <time.h>

/*--	1- Librerias   	  --*/
							
/*		2- Manejo de variables Globales		*///----------------------------------------------
	
	struct Color
	{
		short configuracionRapida;
		short texto;
		short fondo;
		short espacio;
		char tituloDelPrograma[50];
		char autor[40];	
	};
	
	union entradaDeUsuario
	{
		//	-------------------------------------------------------------------------------------------------------------
		char c_caracter;							//	|	   ( 0 ) 	   | 	char				 |		  1			|	
		unsigned char unc_caracter ;				//	|	   ( 1 )	   |	unsigned char		 |		  1			|
		short int shi_num;							//	|	   ( 2 )	   |	short int			 |		  2			|
		unsigned short int unshi_num;				//	|	   ( 3 )	   |	unsigned short int	 |		  2			|
		int i_num;									//	|	   ( 4 )	   |	int					 |		  4			|
		unsigned int uni_num;						//	|	   ( 5 )	   |	unsigned int		 |		  4			|
		long int loi_num;							//	|	   ( 6 )	   |	long int			 |		  4			|
		unsigned long int unloi_num;				//	|	   ( 7 )	   |	unsigned long int	 |		  4			|
		char array_fifty[50];						//	|	   ( 8 )	   |	char array[50]		 |	*	  50	*	|	
		float f_num;								//  |	   ( 9 )	   |	float 			 	 |		  4			|
		//	-------------------------------------------------------------------------------------------------------------							
	} ;
	
	/*----------------------------------------------------------------------------------*/
	
	typedef struct _nodo {
		int valor;
		struct _nodo *siguiente;
	} tipoNodo;
	
	typedef tipoNodo *pNodo;
	typedef tipoNodo *Pila;
	
/*--	2- Manejo de variables Glovales   	  --*/

/*		3- Prototipado de funciones		*///--------------------------------------------------
	 
	int Leer( pNodo * primero, pNodo *ultimo);
	void Anadir( pNodo *primero, pNodo *ultimo, int v);
	int i_Pop (Pila *P_ultimo );
	void v_instrucciones( unsigned char uc_comparador, unsigned char uc_rango);
	void v_ImprimirMaquetacion ( struct Color *as_Color_Maqueta );
	union entradaDeUsuario eDU_AnalizarEntrada( unsigned short sh_configuracion , unsigned short sh_numeroDeVeces );
	
/*--	3- Prototipado de funciones 	  --*/

/*		4- Función principal (Descripción de uso)	*///--------------------------------------

	void main()
	{
		/*----------------------------------------------------------------------------------*/
		struct Color Color_Maqueta;
		short sh_i;
		/*----------Asignar doble espacio al final del c_tituloPrograma y c_nombreAutor-----*/
		char c_tituloPrograma[50] = "Cola circular y cola doble  ";
		char c_nombreAutor[40] = "Jose Luis Bautista Rodriguez  " ;
		/*-------------Configuracion Rapida---------------------------------------------------
			Programado:						0	(Usará los valores de titulo y fondo)
			Normal:							1	Texto Blanco	Fondo Negro
			Nocturno:						2	Texto Gris 		Fondo Negro
			Papel:							3	Texto Negro		Fondo Blanco
			Facultad de Ingenieria:			4	Texto Rojo		Fondo Blanco
			Claro:							5	Texto Gris		Fondo Blanco
			Clasico 1:						6	Texto Verde		Fondo Negro
			Clasico 2:						7	Texto Negro		Fondo Verde
			Todo esta bien:					8	Texto Verde	Cl	Fondo Verde
			Advertencia:					9	Texto Amarillo	Fondo Rojo
		------------------------------------------------------------------------------------*/
		Color_Maqueta.configuracionRapida = 4 ;
		Color_Maqueta.fondo   = 4 ;
		Color_Maqueta.texto   = 3 ;
		Color_Maqueta.espacio = 75 ;
		
		for ( sh_i = 0 ; sh_i < 50 ; sh_i++)Color_Maqueta.tituloDelPrograma[sh_i] = c_tituloPrograma[sh_i];
		for ( sh_i = 0 ; sh_i < 40 ; sh_i++) Color_Maqueta.autor[sh_i] = c_nombreAutor[sh_i];
		
		v_ImprimirMaquetacion( &Color_Maqueta );
		/*-----------------------------------------------------------------------------------*/	
		
		union entradaDeUsuario DatosDeEntrada;
		//DatosDeEntrada = eDU_AnalizarEntrada( /*Configuracion*/ 3 , /*Intentos*/ 3);	
		
		/*-----------------------------------------------------------------------------------*/		
		
		pNodo primero = NULL, ultimo = NULL;
		unsigned char uc_parametro = 0, uc_rango, uc_comparador = 0 ;
		
		printf("\n\t%c Ingres%c el n%cmero de valores m%cximo que podr%c ingresar: ", 219, 130, 163, 160, 160 );
		DatosDeEntrada = eDU_AnalizarEntrada( /*Configuracion*/ 1 , /*Intentos*/ 3);	
		uc_rango = DatosDeEntrada.unc_caracter;
		
		system("cls");
		
		while( uc_parametro != 4 ){
			
			v_ImprimirMaquetacion( &Color_Maqueta );
			printf("%c	Valores dentro de la estructura: %i, n%cmero de valores m%cximo: %i %c%c%c\n", 219, uc_comparador, 163, 160, uc_rango, 219, 219, 219);
			v_instrucciones( uc_comparador, uc_rango );
			
			DatosDeEntrada = eDU_AnalizarEntrada( /*Configuracion*/ 1 , /*Intentos*/ 3);	
			uc_parametro = DatosDeEntrada.unc_caracter;
			
			switch( uc_parametro )
			{
				case 1 :
					printf("\t%c Ingresa el nuevo valor: " , 219);
					DatosDeEntrada = eDU_AnalizarEntrada( /*Configuracion*/ 4 , /*Intentos*/ 3);
					Anadir(&primero, &ultimo, DatosDeEntrada.i_num );
					uc_comparador++;
					break;
				
				case 2 :
					printf("\t%c Primer valor liberado : %i." , 219, Leer(&primero, &ultimo) );
					uc_comparador--;
					Sleep(2500);
					break;
					
				case 3 :
					printf("\t%c %cltimo valor liberado : %i." , 219, 233, i_Pop( &ultimo) );
					uc_comparador--;
					break;
				
				case 4 : 
					printf("\n\n\tEl programa termino.\n\n");
					break;
										
				default : 
				printf("\n\t%c%c%c Valor ingresado no valido. %c%c%c", 219, 219, 219, 219, 219, 219);
					break;	
			}
			
			Sleep(1500);
			system("cls");
			
		}	
		
		/*pNodo primero = NULL, ultimo = NULL;
		Anadir(&primero , &ultimo, 20);
		printf("\n\tA%cadir (20)\n", 164 );
		Anadir(&primero , &ultimo, 10);
		printf("\tA%cadir (10)\n", 164 );		 
		
		printf("\tLeer: %d\n " , Leer(&primero, &ultimo));

		Anadir(&primero , &ultimo, 40);
		printf("\n\tA%cadir (40)\n", 164 );
		Anadir(&primero , &ultimo, 30);
		printf("\tA%cadir (30)\n", 164 ); */	
		
		
		system ("pause");
	}

/*--	4- Función principal 	--*/
	

	void v_instrucciones( unsigned char uc_comparador, unsigned char uc_rango)
	{
		/*
		-------------------------------------------------------------------------------
			Hay tres posibles casos de estado para la estructura general:
					
				1) Se encuentra vacía.
				2) Se encuentra llena.
				3) Se encuentra con elementos dentro.
			
			Ésta función imprime en pantalla las instrucciones a seguir según 
			sea el caso.
		-------------------------------------------------------------------------------
		*/
		
		if ( uc_comparador == 0)
		{
			printf("\n\t%c La cola se encuentra vac%ca. Ingresa el primer valor.\n\n\t\t1) Ingresar primer valor.\n\t\t4) Salir del programa.", 219, 161 );
			printf("\n\t%c ", 219);
		}
		
		else if( uc_comparador == uc_rango )
		{
			printf("\n\t%c La cola se encuentra llena.\n\n\t\t2) Borrar el primer valor.\n\t\t3) Borrar el %cltimo valor.\n\t\t4) Salir del programa.", 219, 163);
			printf("\n\t%c ", 219);
		}
		
		else
		{
			printf("\n\t%c Ingresa una opci%cn:\n\n\t\t1) Ingresar un valor.\n\t\t2) Borrar el primer valor.\n\t\t3) Borrar el %cltimo valor.\n\t\t4) Salir del programa.", 219, 162, 163 );
			printf("\n\t%c ", 219);
		}
	}


	int i_Pop (Pila *P_ultimo)
	{
		Pila P_temporal;
		int i_popValor;
		
		P_temporal = *P_ultimo;
		i_popValor = (*P_ultimo)->valor;
		*P_ultimo = (*P_ultimo)->siguiente;
		
		free(P_temporal);
		
		return i_popValor;	
	}


	void Anadir( pNodo *primero, pNodo *ultimo, int v)
	{
		pNodo nuevo;
		
		nuevo = (pNodo)malloc(sizeof(tipoNodo));
		nuevo -> valor = v ;
		
		nuevo->siguiente = NULL ;
		if (*ultimo) (*ultimo)->siguiente = nuevo;
		*ultimo = nuevo ;
		if (!*primero) *primero = nuevo ;
		
	}
	
	int Leer( pNodo * primero, pNodo *ultimo)
	{
		pNodo nodo ;
		int v ;
		nodo = *primero;
		if(!nodo) return 0;
		*primero = nodo->siguiente;
		v = nodo -> valor ;
		free(nodo);
		if(!*primero) * ultimo = NULL ;
		return v ;
	}
	
/*		5- Manejo de funciones		*///------------------------------------------------------
	
	
	union entradaDeUsuario eDU_AnalizarEntrada( unsigned short sh_configuracion , unsigned short sh_numeroDeVeces )
	{
		/*
			Configuración de la función de entrada:
			
			| Valor de entrada | 	Valor que devuelve	 |	Tamaño 	(bytes)	|
			-----------------------------------------------------------------
			|	   ( 0 ) 	   | 	char				 |		  1			|	
			|	   ( 1 )	   |	unsigned char		 |		  1			|
			|	   ( 2 )	   |	short int			 |		  2			|
			|	   ( 3 )	   |	unsigned short int	 |		  2			|
			|	   ( 4 )	   |	int					 |		  4			|
			|	   ( 5 )	   |	unsigned int		 |		  4			|
			|	   ( 6 )	   |	long int			 |		  4			|
			|	   ( 7 )	   |	unsigned long int	 |		  4			|
			|	   ( 8 )	   |	char array[50]		 |	*	  50	*	|	
			|	   ( 9 )	   |	float 			 	 |		  4			|														
			-----------------------------------------------------------------						
		
		*/
		short i, sh_parametroDeSalida = 0, sh_numeroDeVecesIngresadas = 0, s_cortaFuego;
		union entradaDeUsuario AnalisisDeEntrada;
		char c_textoDePaso[20];
		int paso, dio, k;
		float f_ppaso;
		char texa[11], texa2[11];
		long int loi_sizefloat;
		
		do{
		
		// Se resive el valor de entrada del usuario como texto:		
			fgets( c_textoDePaso, 20, stdin );
			fflush(stdin);
			
				switch( sh_configuracion )
				{
					case 0  : // | 	char				 |-----------------------------------------
						// Se analizá que el valor sea el correcto.
						
						if( (int)c_textoDePaso[1] > 33  )
						{
							printf("\n\t%c Se ha ingresado m%cs de un c%cracter.", 219, 160, 160);
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 s%clo c%cracter (Tiene %i intentos) : " , 219, 162, 160, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 s%clo c%cracter (Tiene %i intento) : " , 219, 162, 160, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.c_caracter = 'X';
							break;	
						}
						else if ( (int)c_textoDePaso[0] > 32 )
						{
							AnalisisDeEntrada.c_caracter = c_textoDePaso[0];
							// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						}else printf("\n\t%c Valor no valido", 219);
						
						AnalisisDeEntrada.c_caracter = 'X';						
						break;
						
					case 1  : // |	unsigned char		 | -----------------------------------------
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						int i_paso = atoi(c_textoDePaso);
						unsigned char unc_paso = atoi(c_textoDePaso);
						
						for ( i = 0 ; i < 3 ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							//printf("El paso es de %i", paso);

							if ( paso > 57 || paso < 48 && paso > 10 )
							{
								printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
								s_cortaFuego++;
								break;
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else 	if ( i_paso > 255 || i_paso < 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unc_caracter = unc_paso;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese 1 valor de 0 a 255 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						}
						break;	
				
					case 2  : // |	short int			 |-----------------------------------------
						//  RANGO -32768 a 32767 
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						long int loi_paso = atoi(c_textoDePaso);
						short int si_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 10 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 10 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.shi_num = 0;
							break;	
						} else 	if ( loi_paso < -32768 || loi_paso > 32767 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unc_caracter = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.shi_num = si_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.shi_num = 0;
							break;	
						}
						break;
						
					case 3  : // |	unsigned short int	 |-----------------------------------------
							  // 0 a 65535
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						unsigned short int unshi_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						} else 	if ( loi_paso < 0 || loi_paso > 65535 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unshi_num = unshi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unshi_num = 0;
							break;	
						}
						break;
						
					case 4  : // |	int					 |-----------------------------------------	
						// -32768 a 32767
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						i_paso = atoi(c_textoDePaso);
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						} else 	if ( loi_paso < -32768 || loi_paso > 32767 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.i_num = i_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -32768 a 32767 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.i_num = 0;
							break;	
						}
						break;

					case 5  :  //|	unsigned int		 |-----------------------------------------
							   //|  0 a 65535			 |
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						loi_paso = atoi(c_textoDePaso);
						unsigned int uni_paso = atoi(c_textoDePaso);
						short j;
						
						if ( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < 6 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						} else {
							for ( i = 0 ; i < 5 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						} else 	if ( loi_paso < 0 || loi_paso > 65535 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.uni_num = uni_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 65535 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.uni_num = 0;
							break;	
						}
						break;
						
					case 6  : // |	long int			 |-----------------------------------------
						      // | -2147483648 a 2147483647
						      //   12345678901   1234567890
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						double d_paso = atoi(c_textoDePaso);
						loi_paso = atoi(c_textoDePaso);
						unsigned char uc_j = 0 , uc_i = 0 ;
						
						for ( i = 0 ; i < 11 /*|| uc_j == 1*/ ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							uc_i++;
						}
						
												
						
						if ( c_textoDePaso[0] == '-' )
						{
							uc_i = 0;
							
							char ca_paso[3];
							for ( i = 1 ;  i < 4 ; i++ ) ca_paso[i-1] = c_textoDePaso[i];
							short int up = atoi(ca_paso);
							
							if ( (int)c_textoDePaso[10] > 47 && (int)c_textoDePaso[10] < 58 )
							{
								if ( up > 214 )uc_i++; 
								else if ( up == 214 )
								{
									j = 0 ;
									for ( i = 4 ;  i < 7 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
									up = atoi(ca_paso);
									
									if ( up > 748 )uc_i++;
									else if ( up == 748 )
									{
										j = 0 ;
										for ( i = 7 ;  i < 10 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 364 ) uc_i++;
										else if ( up == 364 ) if ( (int)c_textoDePaso[10] - 48 > 8 ) uc_i++;
									}
								}
							
							}
																				
							if ( uc_i == 0 )for ( i = 1 ; i < 11 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									//break;
								}							
							}							
						} else {
							
							uc_i = 0;
											
							char ca_paso[3];
							for ( i = 0 ;  i < 3 ; i++ ) ca_paso[i] = c_textoDePaso[i];
							short int up = atoi(ca_paso);
							
							if ( (int)c_textoDePaso[9] > 47 && (int)c_textoDePaso[9] < 58 )
							{
									if ( up > 214 )uc_i++; 
									else if ( up == 214 )
									{
										j = 0 ;
										for ( i = 3 ;  i < 6 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 748 )uc_i++;
										else if ( up == 748 )
										{
											j = 0 ;
											for ( i = 6 ;  i < 9 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
											up = atoi(ca_paso);
											
											if ( up > 364 ) uc_i++;
											else if ( up == 364 ) if ( (int)c_textoDePaso[9] - 48 > 7 ) uc_i++;
										}
									}
																
								}
								
								
							for ( i = 0 ; i < 10 ; i++)
								{
									paso = (int)c_textoDePaso[i] ;
		
									if ( paso > 57 || paso < 48 && paso > 32 )
									{
										printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
										s_cortaFuego++;
										break;
									}							
								}
									
							}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
							
						//-2147483648
							
						} else 	if ( uc_i > 0 || d_paso > 2147483647 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.loi_num = loi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.loi_num = 0;
							break;	
						}
						break;
						
					case 7  :  // |	unsigned long int	 |-----------------------------------------
						//   0 a 4294967295
						// Se analizá que el valor sea el correcto.
						s_cortaFuego = 0;
						d_paso = atoi(c_textoDePaso);
						unsigned long int unloi_paso = atoi(c_textoDePaso);
						uc_j = 0 , uc_i = 0 ;
						
						for ( i = 0 ; i < 11 /*|| uc_j == 1*/ ; i++)
						{
							paso = (int)c_textoDePaso[i] ;
							uc_i++;
						}
						
						if ( c_textoDePaso[0] == '-' )
						{
							uc_i ++;
														
						} else {
							
							uc_i = 0;
											
							char ca_paso[3];
							for ( i = 0 ;  i < 3 ; i++ ) ca_paso[i] = c_textoDePaso[i];
							short int up = atoi(ca_paso);// 429 496 729 5
							
							if ( (int)c_textoDePaso[9] > 47 && (int)c_textoDePaso[9] < 58 )
							{
								if ( up > 429 )uc_i++; 
								else if ( up == 429 )
								{
									j = 0 ;
									for ( i = 3 ;  i < 6 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
									up = atoi(ca_paso);
									
									if ( up > 496 )uc_i++;
									else if ( up == 496 )
									{
										j = 0 ;
										for ( i = 6 ;  i < 9 ; i++ , j++ ) ca_paso[j] = c_textoDePaso[i];
										up = atoi(ca_paso);
										
										if ( up > 729 ) uc_i++;
										else if ( up == 729 ) if ( (int)c_textoDePaso[9] - 48 > 5 ) uc_i++;
									}
								}
							}
							
							for ( i = 0 ; i < 10 ; i++)
							{
								paso = (int)c_textoDePaso[i] ;
	
								if ( paso > 57 || paso < 48 && paso > 32 )
								{
									printf("\n\t%c Se ha colocado un c%cracter no n%cmerico." , 219, 160, 163);
									s_cortaFuego++;
									break;
								}							
							}							
						}

						// Cambia el valor y lo ingresa a la estructura que se enviará de regreso.
						if ( s_cortaFuego > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 4294967295  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
							
						} else 	if ( uc_i > 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 0 a 4294967295 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
						} else if ( (int)c_textoDePaso[0] > 33 )
						{
							AnalisisDeEntrada.unloi_num = unloi_paso ;
							sh_parametroDeSalida = sh_numeroDeVeces; 
							break;	
						} else
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -2147483648 a 2147483647 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.unloi_num = 0;
							break;	
						}						
						break;
					case 8 : 
						
						dio = strlen( c_textoDePaso );
						
						c_textoDePaso[dio-1] = '\0' ;

						strcpy( AnalisisDeEntrada.array_fifty , c_textoDePaso );
						sh_parametroDeSalida = sh_numeroDeVeces;
						
						break;
					
					case 9 : // | 		flat	 	|----------------------------------------------------------|
						// 1.17549e-038  3.40282e+038
						// 4 bites
						dio = strlen( c_textoDePaso );
						char texb[10] ;
						char texc[10] ;
						dio = dio - 1 ;
						s_cortaFuego = 0;
						short l;
						j = 0, k = 0;
						float f_pa, f_pb , f_pc ;
						
						// Esta parte descarta o analiza el valor si es negativo.------------------------------|
						
						if( c_textoDePaso[0] == '-' )
						{
							for ( i = 1 ; i < dio ; i++ )
							{
								paso = (int)c_textoDePaso[i] ;
								
								if ( paso > 57 || paso < 46 && paso > 32 )
								{
									if( paso == 47 )s_cortaFuego++;
									s_cortaFuego++;
									break;
								}
		
								// El valor de j indica la posicion del punto dentro del arreglo. -------------|
								
								if ( (int)c_textoDePaso[i] != 46 && k == 0 ) 
								{
									j++;
								}else if ( (int)c_textoDePaso[i] == 46 ){
									k++;	
								}
								// K es el control para verificar que no exista más de un punto. --------------|
							}
							j++;
						
						if ( s_cortaFuego > 0 || k > 1 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.f_num = 0;
							break;	
							
						} else if ( (int)c_textoDePaso[0] < 33 && j == 0  && k == 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -1.17549e-038  3.40282e+038 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.f_num = 0;
							break;		
						} 							
							if ( k == 0 && s_cortaFuego == 0 ) // Si el valor del arreglo no contiene punto, se pasará directo.-----|
							{
								f_pa = atoi(c_textoDePaso);
								AnalisisDeEntrada.f_num = f_pa;
								break;
							}
							
							// Sí el valor de k es igual a 1, se tomará de partida el calculo de dos valores de 
							// punto flotante.
							
							if ( k == 1 && s_cortaFuego == 0 ) 						
							{
								loi_sizefloat = j ;
								
								for ( i = 0 ;  i < loi_sizefloat ; i++ ) texa[i] = c_textoDePaso[i] ;
								f_pa = atoi(texa);
								
								loi_sizefloat ++;
								j++;
								l = 0 ;
								
								for ( i = loi_sizefloat ; i < dio ; i++)
								{
									texb[l] = c_textoDePaso[i];	
									l++;
								 } 
								f_pb = atoi(texb);
								
								for ( i = 0 ; (int)texb[i] < 47 && (int)texb[i] > 58 ; i++) l++;
								
								for ( i = 0 ; i < l ; i++) f_pb = f_pb * 0.1 ;
								f_pc = f_pa - f_pb ;
								
								AnalisisDeEntrada.f_num = f_pc;
								sh_parametroDeSalida = sh_numeroDeVeces;
								break;	
							}
							
						} else
						{
							for ( i = 0 ; i < dio ; i++ )
							{
								paso = (int)c_textoDePaso[i] ;
								if ( paso > 57 || paso < 46 && paso > 32 )
								{
									if( paso == 47 )s_cortaFuego++;
									s_cortaFuego++;
									break;
								}
									
								// El valor de j indica la posicion del punto dentro del arreglo. -------------|
								
								if ( (int)c_textoDePaso[i] != 46 && k == 0 ) 
								{
									j++;
								}else if ( (int)c_textoDePaso[i] == 46 ){
									k++;	
								}
								// K es el control para verificar que no exista más de un punto. --------------|
							}
							
						if ( s_cortaFuego > 0 || k > 1 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038  (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.f_num = 0;
							break;	
							
						} else if ( (int)c_textoDePaso[0] < 33 && j == 0  && k == 0 )
						{
							if ( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) != 0 )
							{
								if( sh_numeroDeVeces-(sh_numeroDeVecesIngresadas + 1 ) > 1 )printf("\n\t%c Ingrese un valor de 1.17549e-038  3.40282e+038 (Tiene %i intentos) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );
								else printf("\n\t%c Ingrese un valor de -1.17549e-038  3.40282e+038 (Tiene %i intento) : " , 219, sh_numeroDeVeces-(sh_numeroDeVecesIngresadas+1) );	
							}
							AnalisisDeEntrada.f_num = 0;
							break;		
						} 
							
							printf("\n\tFuera del For--------- Valor de k %i ", k);
							
							if ( k == 0 && s_cortaFuego == 0 ) // Si el valor del arreglo no contiene punto, se pasará directo.-----|
							{
								f_pa = atoi(c_textoDePaso);
								AnalisisDeEntrada.f_num = f_pa;
								sh_parametroDeSalida = sh_numeroDeVeces;
								break;
								
							}
							
							// Sí el valor de k es igual a 1, se tomará de partida el calculo de dos valores de 
							// punto flotante.
							
							if ( k == 1 && s_cortaFuego == 0 ) 						
							{
								loi_sizefloat = j ;
								
								for ( i = 0 ;  i < loi_sizefloat ; i++ ) texa[i] = c_textoDePaso[i] ;
								f_pa = atoi(texa);
								
								loi_sizefloat ++;
								j++;
								l = 0 ;
								
								for ( i = loi_sizefloat ; i < dio ; i++)
								{
									texb[l] = c_textoDePaso[i];	
									l++;
								 } 
								f_pb = atoi(texb);
								for ( i = 0 ; (int)texb[i] < 47 && (int)texb[i] > 58 ; i++) l++;
								
								for ( i = 0 ; i < l ; i++) f_pb = f_pb * 0.1 ;
								f_pc = f_pa + f_pb ;
								
								AnalisisDeEntrada.f_num = f_pc;
								sh_parametroDeSalida = sh_numeroDeVeces;
								break;
								
							}					
														
						}
						
						break;
						
					default : 
					
						printf("\t\nFuncion eDU_AnalizarEntrada: Valor ingresado en sh_configuracion no valido");

						break;
				}
		
			sh_numeroDeVecesIngresadas++;
			if( sh_numeroDeVecesIngresadas == sh_numeroDeVeces ) sh_parametroDeSalida = sh_numeroDeVeces;
						
		}while( sh_parametroDeSalida != sh_numeroDeVeces );		
		
		return AnalisisDeEntrada;
	}
	
	
	void v_ImprimirMaquetacion (  struct Color *as_Color_Maqueta  )
	{
		/*------------------------------------------------------------------------------------		
		system("color FondoTexto");
		0 = Black  | Negro			   8 = Gray
		1 = Blue   | Azul			   9 = Light Blue
		2 = Green  | Verde			10 A = Light Green
		3 = Aqua   | Aguamarina		11 B = Light Aqua
		4 = Red	   | Rojo			12 C = Light Red
		5 = Purple | Púrpura		13 D = Light Purple
		6 = Yellow | Amarillo		14 E = Light Yellow					
		7 = White  | Blanco			15 F = Bright White	 	
		Ejemplo:
			Sí quieres un fondo Blanco y un texto Azul Claro entonces debes codificar:
			system("color 09"); 
		-------------------------------------------------------------------------------------*/
		
		short sh_controlDeUs = 0 , contador_a= 0, contador_b = 0, contador_c = 0 , sh_espacioParaTitulo, sh_espacioParaAutor, metrica = as_Color_Maqueta->espacio ;
		
		for ( contador_a = 0 ; contador_c < 1 ; contador_a++ )
		{
			if ( as_Color_Maqueta->tituloDelPrograma[contador_a] == ' ' )
			{
				if ( as_Color_Maqueta->tituloDelPrograma[contador_a + 1 ] == ' ')contador_c++;
			}
			contador_b++;	
		}
		contador_b--;
		
		sh_espacioParaTitulo = contador_b ;
		contador_b = 0 ;
		contador_c = 0 ;
		
		for ( contador_a = 0 ; contador_c < 1 ; contador_a++ )
		{
			if ( as_Color_Maqueta->autor[contador_a] == ' ' )
			{
				if ( as_Color_Maqueta->autor[contador_a + 1 ] == ' ')contador_c++;
			}
			contador_b++;	
		}
		contador_b--;
		
		sh_espacioParaAutor = contador_b ;
		
		if ( as_Color_Maqueta->fondo == as_Color_Maqueta->texto )
		{
			printf ("\n\t\tAdvertencia:\n");
			printf ("\n\tLos valores de color del fondo y el texto son iguales.\n");
			printf ( "\tSe les ha reasignado un color." );
			system("color 47");
			sh_controlDeUs ++;
		} 
		
		if ( as_Color_Maqueta->configuracionRapida != 0 )
		{
			switch( as_Color_Maqueta->configuracionRapida )
			{
				case 1 : //Normal:							1	Texto Blanco	Fondo Negro
					as_Color_Maqueta->texto = 7 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 2 : //Nocturno:						2	Texto Gris 		Fondo Negro
					as_Color_Maqueta->texto = 8 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 3 : //Papel:							3	Texto Negro		Fondo Blanco
					as_Color_Maqueta->texto = 0 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 4 : //Facultad de Ingenieria:			4	Texto Rojo		Fondo Blanco
					as_Color_Maqueta->texto = 4 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 5 : //Claro:							5	Texto Gris		Fondo Blanco
					as_Color_Maqueta->texto = 8 ;
					as_Color_Maqueta->fondo = 7 ; 
					break;
				case 6 : //Clasico 1:						6	Texto Verde		Fondo Negro
					as_Color_Maqueta->texto = 2 ;
					as_Color_Maqueta->fondo = 0 ; 
					break;
				case 7 : //Clasico 2:						7	Texto Negro		Fondo Verde
					as_Color_Maqueta->texto = 0 ;
					as_Color_Maqueta->fondo = 2 ; 
					break;
				case 8 : //Todo esta bien:					8	Texto verde		Fondo Verde
					as_Color_Maqueta->texto = 10 ;
					as_Color_Maqueta->fondo = 2 ; 
					break;
				case 9 : //Advertencia:						9	Texto Amarillo	Fondo Rojo
					as_Color_Maqueta->texto = 14 ;
					as_Color_Maqueta->fondo = 4 ;
					break;
				default : //Advertencia:					9	Texto Amarillo	Fondo Rojo
					printf("\n\t Valor en Color Configuracion Rapida no valido\n");
					as_Color_Maqueta->texto = 14 ;
					as_Color_Maqueta->fondo = 4 ;
					break;																										
			}
		}
		
		if ( as_Color_Maqueta->fondo != as_Color_Maqueta->texto )
		{
			if ( as_Color_Maqueta->fondo < 16 && as_Color_Maqueta->texto < 16 )
			{
				
				if ( as_Color_Maqueta->fondo > -1 && as_Color_Maqueta->texto > -1 )
				{
					
					switch ( as_Color_Maqueta->fondo )
					{
						case 0 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 00");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 01");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 02");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 03");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 04");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 05");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 06");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 07");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 08");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 09");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 0A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 0B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 0C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 0D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 0E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 0F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 1 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 10");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 11");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 12");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 13");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 14");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 15");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 16");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 17");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 18");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 19");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 1A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 1B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 1C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 1D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 1E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 1F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 2 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 20");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 21");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 22");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 23");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 24");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 25");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 26");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 27");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 28");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 29");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 2A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 2B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 2C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 2D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 2E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 2F");
									sh_controlDeUs ++;
									break;						
							}
							break;

						case 3 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 30");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 31");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 32");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 33");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 34");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 35");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 36");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 37");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 38");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 39");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 3A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 3B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 3C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 3D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 3E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 3F");
									sh_controlDeUs ++;
									break;						
							}
							break;

						case 4 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 40");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 41");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 42");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 43");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 44");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 45");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 46");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 47");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 48");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 49");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 4A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 4B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 4C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 4D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 4E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 4F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 5 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 50");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 51");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 52");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 53");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 54");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 55");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 56");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 57");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 58");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 59");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 5A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 5B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 5C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 5D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 5E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 5F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 6 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 60");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 61");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 62");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 63");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 64");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 65");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 66");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 67");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 68");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 69");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 6A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 6B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 6C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 6D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 6E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 6F");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 7 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 70");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 71");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 72");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 73");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 74");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 75");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 76");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 77");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 78");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 79");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 7A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 7B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 7C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 7D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 7E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 7F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 8 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 80");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 81");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 82");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 83");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 84");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 85");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 86");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 87");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 88");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 89");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 8A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 8B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 8C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 8D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 8E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 8F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 9 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color 90");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color 91");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color 92");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color 93");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color 94");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color 95");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color 96");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color 97");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color 98");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color 99");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color 9A");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color 9B");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color 9C");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color 9D");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color 9E");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color 9F");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 10 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color A0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color A1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color A2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color A3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color A4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color A5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color A6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color A7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color A8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color A9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color AA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color AB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color AC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color AD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color AE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color AF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 11 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color B0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color B1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color B2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color B3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color B4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color B5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color B6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color B7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color B8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color B9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color BA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color BB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color BC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color BD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color BE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color BF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 12 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color C0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color C1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color C2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color C3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color C4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color C5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color C6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color C7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color C8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color C9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color CA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color CB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color CC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color CD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color CE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color CF");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						case 13 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color D0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color D1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color D2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color D3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color D4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color D5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color D6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color D7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color D8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color D9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color DA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color DB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color DC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color DD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color DE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color DF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 14 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color E0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color E1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color E2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color E3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color E4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color E5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color E6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color E7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color E8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color E9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color EA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color EB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color EC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color ED");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color EE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color EF");
									sh_controlDeUs ++;
									break;						
							}
							break;
							
						case 15 : 
							switch ( as_Color_Maqueta->texto )
							{
								case 0 :
									system ("color F0");
									sh_controlDeUs ++;
									break;
								case 1 :
									system ("color F1");
									sh_controlDeUs ++;
									break;
								case 2 :
									system ("color F2");
									sh_controlDeUs ++;
									break;
								case 3 :
									system ("color F3");
									sh_controlDeUs ++;
									break;
								case 4 :
									system ("color F4");
									sh_controlDeUs ++;
									break;
								case 5 :
									system ("color F5");
									sh_controlDeUs ++;
									break;
								case 6 :
									system ("color F6");
									sh_controlDeUs ++;
									break;
								case 7 :
									system ("color F7");
									sh_controlDeUs ++;
									break;
								case 8 :
									system ("color F8");
									sh_controlDeUs ++;
									break;
								case 9 :
									system ("color F9");
									sh_controlDeUs ++;
									break;
								case 10 :
									system ("color FA");
									sh_controlDeUs ++;
									break;
								case 11 :
									system ("color FB");
									sh_controlDeUs ++;
									break;
								case 12 :
									system ("color FC");
									sh_controlDeUs ++;
									break;
								case 13 :
									system ("color FD");
									sh_controlDeUs ++;
									break;
								case 14 :
									system ("color FE");
									sh_controlDeUs ++;
									break;
								case 15 :
									system ("color FF");
									sh_controlDeUs ++;
									break;						
							}
							break;	
							
						default : 
							printf("\n\tFuncion v_ImprimirMaquetacion no funciono como se esperaba. \n ");
							system( "color 47" );
							break;		  																																																																																					
					}
					
				}
				else if ( as_Color_Maqueta->fondo < 0 && as_Color_Maqueta->texto < 0 )
				{
					printf ("\n\t\tAdvertencia:\n");
					printf( "\n\tEl n%cmero del color del fondo es mayor a 15. " , 163 );
					printf ( "\tSe les ha reasignado un color." );
					system("color 47");
					sh_controlDeUs ++;
				}
			}
			else if ( as_Color_Maqueta->fondo > 16 && as_Color_Maqueta->texto > 16 ) 
			{
				printf ("\n\t\tAdvertencia:\n");
				printf( "\n\tEl n%cmero del color del fondo es mayor a 15. " , 163 );
				printf ( "\tSe les ha reasignado un color." );
				system("color 47");
				sh_controlDeUs ++;
			}
		}
		
		short i, i_espacio, i_imprimir, espacio_Imprimir;
		
		if ( sh_controlDeUs == 1 )
		{
			if ( sh_espacioParaAutor > sh_espacioParaTitulo ) espacio_Imprimir = sh_espacioParaAutor ;
			else if ( sh_espacioParaTitulo > sh_espacioParaAutor ) espacio_Imprimir = sh_espacioParaTitulo ;
			
			espacio_Imprimir = metrica - espacio_Imprimir;
			espacio_Imprimir = espacio_Imprimir - 2 ;
			if ( espacio_Imprimir < 0 )
			{
				printf("\n\tEl tama%co del titulo o nombre es demaciado largo \n");
				espacio_Imprimir = 10 ;	
			}
			
			for ( i = 0 ; i < as_Color_Maqueta->espacio ; i++)printf( "%c" , 219 );
			printf("\n");
			
			for ( i = 0 ; i < espacio_Imprimir ; i++ ) printf("%c" , 219 ); 
			printf(" ");
			for( i = 0; i < 50; i++)printf("%c" ,  as_Color_Maqueta->tituloDelPrograma[i] );
			
			printf("\n");
			
			for ( i = 0 ; i < espacio_Imprimir ; i++ ) printf( "%c" , 219 );
			printf( " " );			
			for( i = 0; i < 40; i++)printf("%c" ,  as_Color_Maqueta->autor[i] );
			printf("\n");
			
			for ( i = 0 ; i < as_Color_Maqueta->espacio ; i++)printf( "%c" , 219 );
			printf("\n");	
		}
	}
	
/*--	5- Manejo de funciones 	  --*/

/*
		||		Datos Generales del archivo		||
	------------------------------------------------------------------------------------------
	Universidad Nacional Autónoma de México
	Facultad de Ingeniería
	1227 Estructura de Datos y Algoritmos 1
	Docente: Ing. Jonathan Roberto Torres Castillo
	
	Práctica: 06  Estructuras de datos lineales: Cola circular y cola doble.
	Grupo: 09 
	 
	Autor: José Luis Bautista Rodríguez
	Fecha de inicio: 08/04/2018
	Lugar: AV. UNIVERSIDAD Nº 3000, UNIVERSIDAD NACIONAL AUTÓNOMA DE MÉXICO, C.U., CIUDAD DE 
	MÉXICO, 04510
	------------------------------------------------------------------------------------------
*/


