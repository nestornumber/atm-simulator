// LLAMADO DE LIBRERIAS
#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>
#include "gotoxy.h"				//hace referncia al archivo del mismo nombre que esta en el solution
#pragma warning(disable : 4996)// me tiraba un error por lo de la fecha me decia CRL_SECURE_ y con esto se quita T-T

// Sstos son los define con el codigo ascci para poder mover con las flechas del teclado
#define UP 80
#define down 72
#define ENTER 13

// DECLARACION DE FUNCIONES
void menu_y_opciones(int numerocuenta, float fondos, float nuevofondo, const char *nombre);
// nombre es una constante porque una vez escrito el numero de cuenta, el nombre no cambia

int introducir_cuenta();
void presioneunatecla();

using namespace std;

// LA FUNCION PRINCIPAL
// Consta solamente de la declaracion de variables basicas y la asignacion de las distintas cuentas de prueba del programa
int main()
{
	// DECLARACION DE VARIABLES
	int numerocuenta;// la cuenta predeterminada es 123456
	const char *nombre;
	float fondos = 0, nuevofondo = 0;// fondos: use una suma de dinero aleatoria para poder usar en todo el programa como si fuese una base de datos

	// Instrucción que declara el color de fondo
	system("color 3F");

	// Variable booleana (de tipo verdadera o falsa) necesaria para que el dowhile repita la accion de pedir el numero de cuenta por algun error
	bool repetir_programa = true;

	// Distintas cuentas a usar dentro del programa
	{
		do
		{
			numerocuenta = 0;
			numerocuenta = introducir_cuenta();
			// La variable numero de cuenta tendra el valor que retorne la funcion de introducir_cuenta() usando la variable cuenta

			// Existen 6 numeros de cuenta distintos en donde cada uno tiene una cantidad distinta en la variable fondos, un valor distinto en la variable caracter.
			// Esto es para cambiar en cada numero de cuenta, el nombre de cada persona y cuanto dinero tiene cada una

			if (numerocuenta == 123456)
			{
				fondos = 500;
				const char *nombre("Jose Perez");
				menu_y_opciones(numerocuenta, fondos, nuevofondo, nombre);
			}

			else if (numerocuenta == 654321)
			{
				fondos = 700;
				const char *nombre("Diego Perez");
				menu_y_opciones(numerocuenta, fondos, nuevofondo, nombre);
			}

			else if (numerocuenta == 159753)
			{
				fondos = 1500;
				const char *nombre("Alejandro Garcia");
				menu_y_opciones(numerocuenta, fondos, nuevofondo, nombre);
			}

			else if (numerocuenta == 000000)
			{
				fondos = 250;
				const char *nombre("Toni Morales");
				menu_y_opciones(numerocuenta, fondos, nuevofondo, nombre);
			}

			else if (numerocuenta == 987654)
			{
				fondos = 5000;
				const char *nombre("Irma Salazar");
				menu_y_opciones(numerocuenta, fondos, nuevofondo, nombre);
			}

		} while (repetir_programa);
	}
}


// Funcion PRESIONE UNA TECLA
// Funcion que se usa para indicar al usuario que presione una tecla para seguir con el programa
void presioneunatecla()
{
	system("cls");
	cout << "\n\n\n\t\t\tPresione cualquier tecla para continuar.....";

	_getch();

	system("cls");
}


// PRIMERA INTERFAZ DEL PROGRAMA
// Funcion introducir_cuenta() que pide el numero de cuenta
int introducir_cuenta()
{
	int cuenta;

start:
	system("cls");// el ancla que marca el inicio del programa

	//--------Bienvenida del programa y verificacion de cuenta---------

	cout << "\n\t\t-------------------------------------------------------------------------" << endl;
	cout << "\n\t\t		Bienvenido al cajero de BANCO NACIONAL\n"
		 << endl;

	cout << "\n\t\t		Por favor introduzca su n\xA3mero de cuenta:\n"
		 << endl;

	cout << "\t\t---------------------------------------------------------------------------" << endl;
	cout << "\t\t	Introduzca su n\xA3mero de cuenta: ";
	// El numero de cuenta que utilizaremos como ejemplo sera 123456 y 654321 *tilde*
	cin >> cuenta;/// tilde*

	//----------------------Fin de la bienvenida-----------------------------------

	return cuenta;
}


// FUNCION PRINCIPAL
// Funcion principal que engloba toda las disintas variables y opciones y subopciones de cada menu
void menu_y_opciones(int numerocuenta, float fondos, float nuevofondo, const char *nombre)
{
	// DECLARACION DE VARIABLES DE LOS MENUS
	// Se declaran algunas variables que se usaran dentro de los menus

	// CASO 1 - ESTADO DE CUENTA
	int opcion1enconsultasaldo = 0;// puse opcion1enconsultasaldo y opcion2enpagorecibo pero son sub opciones dento de los menus

	// CASO 2 - DEPOSITAR
	// fondo y nuevofondo en la funcion principal #1.
	int agregarsaldodeposito = 0;

	// 3. RETIRAR
	// fondo y nuevofondo en la funcion principal #1.
	int retirofondo = 0;

	// 4. PAGO DE RECIBOS
	int opcion1enpagorecibo = 0, opcion2enpagorecibo = 0;// puse opcion1enpagorecibo y opcion2enpagorecibo pero son sub opciones dento de los menus
	float factura = 0;									// una factura falsa
	char empresanombre[100];									// nombre de la empresa usando un vector de tipo caracter

	// variables del mini menu de opciones
	const char *titulocaso4 = "PAGO DE RECIBOS";																	// Titulo del menu de la opcion/caso 4
	const char *menuopcionescaso4[] = {"Pago de recibo pendiente", "Pago de otro recibo", "Volver al menu", "Salir"};// Menu de opciones de la opcion/caso 4

	// averiguar para que el n4 o n5, tecla4, bool menu
	int n4 = 4;
	char tecla4;
	bool menu4 = true;
	int opcionSelec4 = 1;

	bool pagoFactura = false;// variable para determinar si se a pagado o no la factura pendiente

	// CASO 5 - ENVIO DE REMESAS
	int opcionremesas = 0;

	// Vaiables del mini menu de opciones de envio de remesas
	const char *titulo5 = "\xA8Que desea hacer?";																// Titulo del menu de la opcion/caso 5
	const char *opciones5[] = {"Recibir una remesa", "Enviar una remesa", "Volver al menu principal", "Salir"};// Menu de opciones de la opcion/caso 5
	int n5 = 4;
	char tecla5;
	bool menu5 = true;
	int opcionSelec5 = 1;

	// CASO 5.1 - RECIBIR REMESAS
	int codigoremesarecibir_contadordigitos = 0, numdigitos = 0;
	double codigoremesarecibir = 0;

	// CASO 5.2 - ENVIAR REMESAS
	int cantidadremesaenviar = 0, paisremesaenviar = 0, codigoremesaenviar = 0, acuerdoenviarremesa = 0;
	const char *titulo_r = "\xA8 A que pais desea enviar la remesa?";// titulo de mini menu de opciones*signos actualizado*
	const char *opciones_r[] = {"Estados Unidos", "Canada", "Salir"};// para el menu secundario
	bool menu_r = true;
	int n_r = 3;
	char tecla_r;
	int opcionSelec_r = 1;

	const char *titulo_si = "\xA8 Esta usted seguro/a?";// Titulo de mini menu de opciones//MODIFICAR POR UN TEXTO MÁS LEGIBLE
	const char *opciones_si[] = {"Si", "NO"};	// Para el menu secundario
	bool menu_si = true;
	int n_si = 2;
	char tecla_si;
	int opcionSelec_si = 1;

	// VARIABLE FECHA Y TIEMPO LOCAL
	time_t t;
	t = time(0);// fecha actual
	struct tm *f;// puntero de variable fecha
	f = localtime(&t);

	// MENU PRINCIPAL
	//  VARIABLES DE FUNCIONES DEL MENU DE SELECCION PRINCIPAL
	const char *titulo = "Bienvenido";																		// Titulo de menu principal
	const char *titulo2 = "\xA8Que desea hacer ahora?";														// Titulo de mini menu de opciones
	const char *opciones[] = {"Estado de cuenta", "Depositar", "Retirar", "Pagar recibos", "Remesas", "Salir"};// Opciones del menu principal

	// Variable usada para crear un mini menu al finalizar la ejecucion de una opcion del menu principal
	const char *opciones2[] = {"Realizar otra acci\xA2n", "Salir"};// para el menu secundario*tilde actualizado*
	int n = 6;														// El numero de opciones en el menu principal: estado de cuenta, deposito, retiro, pagar recibos, remesa, salir
	int n2 = 2;														// El numero de opciones en el mini menu: realizar otra accion, salir
	bool menu = true;

	int opcion2;
	// Aqui terminan las opciones

	int opcionSelec = 1;
	bool repeticion = true;
	char tecla;
	int opcion;

	int opcionSelec2 = 1;

	char tecla2;

	bool repeticion2 = true;


// ANCLA AL MENU DE INICIO O PAGINA PRINCIPAL
menu1:

	//FLECHAS DE SELECCION Y MENU DE OPCIONES DE MENU PRINCIPAL
	do
	{
		// En este ciclo se compila todo el menu de inicio y se controla por el ciclo menu

		system("cls");// todos los cls son los que borran lo que habia en la pantalla al elegir una opcion
		gotoxy(5, 2 + opcionSelec);
		cout << "\t\t-->";// la flechita de seleccion y sus coordenadas

		// titulo del menu y sus coordenadas
		gotoxy(10, 2);
		cout << "\t\t" << titulo;

		// OPCIONES DEL MENU PRINCIPAL
		// opciones del menu son en tipo vector o constante
		for (int i = 0; i < n; i++)
		{
			gotoxy(10, 3 + i);
			cout << "\t\t" << i + 1 << " ) " << opciones[i];
		}

		do
		{// segundo do anidado para que se mantenga en ciclo esperando a presionar una tecla
			tecla = _getch();
		} while (tecla != UP && tecla != down && tecla != ENTER);

		switch (tecla)// switch para definir las acciones a mostrar dependiendo las teclas precionadas
		{
		case UP:
			opcionSelec++;
			if (opcionSelec > n)
			{
				opcionSelec = 1;
			}

			break;
		case down:
			opcionSelec--;
			if (opcionSelec < 1)
			{
				opcionSelec = n;
			}
			break;
		case ENTER:
			menu = false;
			break;
		}

	} while (menu);
	// al presionar enter el ciclo do nos devuelve el valor int=opcioSelec que luego usamos en sel switch para el menu
	opcion = opcionSelec;
	system("cls");

	// SWITCH QUE CONTIENE TODAS LAS OPCIONES DEL MENU PRINCIPAL
	switch (opcion)
	{


// ELEMENTOS DEL MENU DE OPCIONES PRINCIPAL
	// 1 - ESTADO DE CUENTA
	case 1:
	{
		cout << "\n\n\t\tESTADO DE CUENTA\n\t\t================================\n" << endl;// mensaje de acccion a realizar

		cout << "\t\tCuenta N " << numerocuenta << endl;// aqui iria el nombre que le dimos a la variablecon el numero de cuenta

		cout << "\t\t" << nombre << endl;// un nombre ramdom o el nombre del lic ya que seria innesesario pedir el nombre si ya posee una cuenta

		cout << "\t\tFecha: " << f->tm_mday << "/ " << f->tm_mon + 1 << "/ " << f->tm_year + 1900 << endl;// finaliza la accion de fecha

		cout << "\t\tDinero en la cuenta: $ " << fondos << endl;

		cout << "\t\tUltima acci\xA2n:  Estado de cuenta "
			 << "Fecha: " << f->tm_mday << "/ " << f->tm_mon + 1 << "/ " << f->tm_year + 1900 << " Hora: " << f->tm_hour << ":" << f->tm_min << ":" << f->tm_sec << endl;// sorry no se me ocurrio nada mas en esta parte

		_getch();
		system("cls");

		//FLECHAS DE SELECCION Y MENU DE QUE DESEA HACER
		do
		{
			// este menu es el mismo formato del oto menu
			system("cls");

			gotoxy(5, 2 + opcionSelec2);
			cout << "\t\t-->";

			// titulo del menu
			gotoxy(10, 2);
			cout << "\t\t" << titulo2;

			// MINIMENU SALIR
			// opciones del menu son en tipo vector o constante,
			for (int i = 0; i < n2; i++)
			{
				gotoxy(10, 3 + i);
				cout << "\t\t" << i + 1 << " ) " << opciones2[i];
			}

			do
			{
				tecla2 = _getch();
			} while (tecla2 != UP && tecla2 != down && tecla2 != ENTER);

			switch (tecla2)
			{
			case UP:
				opcionSelec2++;
				if (opcionSelec2 > n2)
				{
					opcionSelec2 = 1;
				}

				break;
			case down:
				opcionSelec2--;
				if (opcionSelec2 < 1)
				{
					opcionSelec2 = n2;
				}
				break;
			case ENTER:
				repeticion2 = false;
				break;
			}

		} while (repeticion2);
		opcion2 = opcionSelec2;

		
		// ACCIONES DE LA PREGUNTA "QUE DESEA HACER"
		switch (opcion2)
		{
		case 1:
			system("cls");// se borra el menu en pantalla
			repeticion2 = true;// esto nos deja volver a usar el menu secundario
			menu = true;// esto nos deja volver a usar el menu principal o el emnu de opciones

			goto menu1;
			break;
		case 2:
			system("cls");

			cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
			repeticion2 = true;
			menu = true;
			presioneunatecla();
			break;
		}

		break;
		// fin del caso 1 para estado de cuenta
	}

	// 2 - DEPOSITAR
	case 2:
	{
		cout << "\n\n\t\tDEPOSITAR\n\t\t================================\n" << endl;
		// Se sugiere introducir el resto de datos aqui, o hacer cambios segun se necesite

		cout << "\t\tIngrese la cantidad a agregar: $ ";
		cin >> agregarsaldodeposito;
		nuevofondo = fondos + agregarsaldodeposito;
		cout << "\t\tNuevo saldo en cuenta: $ " << nuevofondo << endl;
		// aqui saldra la nueva cantidad en cuenta

		fondos = nuevofondo;
		// para poder volver al menu de inicio correctamente
		_getch();
		repeticion2 = true;
		menu = true;
		system("cls");
		goto menu1;

		break;
		// fin del caso 2 o deposito
	}

	// 3 - RETIRAR
	case 3: 
	{
		cout << "\n\n\t\tRETIRAR\n\t\t================================\n" << endl;
		cout << "\n\t\tDigite la cantidad a retirar: $ ";
		retirocin:
		cin >> retirofondo;
		if (retirofondo > 5000)
		{
			system("cls");
			cout << "\t\tLa cantidad ingresada es mayor a 5000, digite otra cantidad";
			// comprueba la cantidad si es mayor no dejara hacer el retiro, y si e menor se hara facilmente el retiro.
			goto retirocin;
		}
		nuevofondo = fondos - retirofondo;
		cout << "\n\t\tCantidad en cuenta despues del retiro: $ " << nuevofondo << endl;
		// se resta el nuevofondo inicial y queda el total de cuenta

		fondos = nuevofondo;

		// para poder volver al menu de inicio correctamente
		_getch();// sustituye a system("pause) y no muestra el mensaje de presione otra tecla

		repeticion2 = true;
		menu = true;
		system("cls");
		goto menu1;

		break;
		// fin del caso 3 o retiro
	}

	// 4 - PAGO DE RECIBOS
	case 4: 
	{
		//FLECHAS DE SELECCION Y MENU DE OPCIONES DEL PAGO DE RECIBOS
		do
		{
			system("cls");

			gotoxy(5, 2 + opcionSelec4);
			cout << "\t\t-->";

			// titulo del menu
			gotoxy(10, 2);
			cout << "\t\t" << titulocaso4;

			// opciones del menu son en tipo vector o constante,
			for (int i = 0; i < n4; i++)
			{
				gotoxy(10, 3 + i);
				cout << "\t\t" << i + 1 << " ) " << menuopcionescaso4[i];
			}

			do
			{
				tecla4 = _getch();
			} while (tecla4 != UP && tecla4 != down && tecla4 != ENTER);

			switch (tecla4)
			{
			case UP:
				opcionSelec4++;
				if (opcionSelec4 > n4)
				{
					opcionSelec4 = 1;
				}

				break;
			case down:
				opcionSelec4--;
				if (opcionSelec4 < 1)
				{
					opcionSelec4 = n4;
				}
				break;
			case ENTER:
				menu4 = false;
				break;
			}

		} while (menu4);
		opcion1enpagorecibo = opcionSelec4;

		switch (opcion1enpagorecibo)
		{

		// 4.1 - PAGO DE RECIBO PENDIENTE
		case 1: 
		{
			system("cls");
			cout << "\n\n\t\tPAGO DE RECIBO PENDIENTE\n\t\t================================\n" << endl;
			factura = 99.99;// CANTIDAD DE FACTURA FALSA
			nuevofondo = fondos - factura;

			// IF QUE HACE MOSTRAR QUE SE HA PAGADO EL RECIBO, Y LO MARCA COMO YA PAGADO
			if (pagoFactura == false)
			{
				cout << "\n\n\t\tSe a realizado el pago de su factura pendiente con un monto de: " << factura << endl;
				cout << "\t\tSu nuevo saldo es: " << nuevofondo << endl;
				cout << "\n\t\tSu proxima factura pendiente esta programada para: " << f->tm_mday << "/ " << f->tm_mon + 2 << "/ " << f->tm_year + 1900 << endl;
				fondos = nuevofondo;
				pagoFactura = true;
				_getch();
				
				//FLECHAS DE SELECCION Y MENU DE QUE DESEA HACER
				do
				{
					// este menu es el mismo formato del otro menu
					system("cls");

					gotoxy(5, 2 + opcionSelec2);
					cout << "\t\t-->";

					// titulo del menu
					gotoxy(10, 2);
					cout << "\t\t" << titulo2;

					// opciones del menu son en tipo vector o constante,
					for (int i = 0; i < n2; i++)
					{
						gotoxy(10, 3 + i);
						cout << "\t\t" << i + 1 << " ) " << opciones2[i];
					}

					do
					{
						tecla2 = _getch();
					} while (tecla2 != UP && tecla2 != down && tecla2 != ENTER);

					switch (tecla2)
					{
					case UP:
						opcionSelec2++;
						if (opcionSelec2 > n2)
						{
							opcionSelec2 = 1;
						}

						break;
					case down:
						opcionSelec2--;
						if (opcionSelec2 < 1)
						{
							opcionSelec2 = n2;
						}
						break;
					case ENTER:
						repeticion2 = false;
						break;
					}

				} while (repeticion2);
				opcion2 = opcionSelec2;

				// ACCIONES DE LA PREGUNTA "QUE DESEA HACER"
				switch (opcion2)
				{
				case 1:

					system("cls");		// se borra el menu en pantalla
					repeticion2 = true;// esto nos deja volver a usar el menu secundario
					menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
					menu4 = true;
					goto menu1;
					break;
				case 2:
					system("cls");
					cout << "\n\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
					_getch();
					system("cls");		// se borra el menu en pantalla
					repeticion2 = true;// esto nos deja volver a usar el menu secundario
					menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
					menu4 = true;
					presioneunatecla();
					break;
				}
				// fin del switch para opcion pago de recibo
			}
			else
			{
				system("cls");
				cout << "\n\t\tNo posee facturas de credito pendientes\n";

				cout << "\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
				_getch();
				system("cls");		// se borra el menu en pantalla
				repeticion2 = true;// esto nos deja volver a usar el menu secundario
				menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
				menu4 = true;
				goto menu1;
				break;
			}
			// fin del if de pago de recibo
		}

		// 4.2 - PAGO DE OTRO RECIBO
		case 2:
		{
			system("cls");
			cout << "\n\n\t\tPAGO DE OTRO RECIBO\n\t\t================================\n" << endl;

			cout << "\n\t\tNombre de la empresa a realizar el pago: ";
			// BUSCAR COMO CREAR UN STRING Y METER COMO TEXTO EL NOMBRE DE LA EMPRESA
			cin >> empresanombre;
			cout << "\n\t\tSe realizara un pago a " << empresanombre << endl;
			cout << "\n\t\tEscriba el monto de el recibo: $ ";
			cin >> factura;
			nuevofondo = fondos - factura;
			system("cls");
			cout << "\n\n\t\tSe ha realizado un pago a " << empresanombre << " por la suma de $ " << factura << endl;
			cout << "\t\tSu nuevo saldo es de $ " << nuevofondo << endl;
			fondos = nuevofondo;

			_getch();

			//FLECHAS DE SELECCION Y MENU DE QUE DESEA HACER
			do
			{
				// este menu es el mismo formato del otro menu
				system("cls");

				gotoxy(5, 2 + opcionSelec2);
				cout << "\t\t-->";

				// titulo del menu
				gotoxy(10, 2);
				cout << "\t\t" << titulo2;

				// opciones del menu son en tipo vector o constante,
				for (int i = 0; i < n2; i++)
				{
					gotoxy(10, 3 + i);
					cout << "\t\t" << i + 1 << " ) " << opciones2[i];
				}

				do
				{
					tecla2 = _getch();
				} while (tecla2 != UP && tecla2 != down && tecla2 != ENTER);

				switch (tecla2)
				{
				case UP:
					opcionSelec2++;
					if (opcionSelec2 > n2)
					{
						opcionSelec2 = 1;
					}

					break;
				case down:
					opcionSelec2--;
					if (opcionSelec2 < 1)
					{
						opcionSelec2 = n2;
					}
					break;
				case ENTER:
					repeticion2 = false;
					break;
				}

			} while (repeticion2);
			opcion2 = opcionSelec2;

			// ACCIONES DE LA PREGUNTA "QUE DESEA HACER"
			switch (opcion2)
			{
			case 1:

				system("cls");		// se borra el menu en pantalla
				repeticion2 = true;// esto nos deja volver a usar el menu secundario
				menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
				menu4 = true;
				goto menu1;
				break;
			case 2:
				system("cls");
				cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
				_getch();
				repeticion2 = true;// esto nos deja volver a usar el menu secundario
				menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
				menu4 = true;
				presioneunatecla();
				break;
			}
			break;
		}

		// 4.3 - VOLVER AL MENU PRINCIPAL
		case 3:
		{
			_getch();
			system("cls");		// se borra el menu en pantalla
			repeticion2 = true;// esto nos deja volver a usar el menu secundario
			menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
			menu4 = true;
			goto menu1;
			break;
		}

		// 4.4 - SALIR
		case 4:
		{
			system("cls");
			cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
			_getch();
			repeticion2 = true;// esto nos deja volver a usar el menu secundario
			menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
			menu4 = true;
			presioneunatecla();
			break;
			// fin del caso 6 o salir
			break;
		}
		}

		break;
		// fin del caso 4 o pago de recibos
	}

	// 5 - REMESAS
	case 5:
	{
		//FLECHAS DE SELECCION Y MENU DE OPCIONES DE LAS REMESAS
		do
		{
			system("cls");

			gotoxy(5, 2 + opcionSelec5);
			cout << "\t\t-->";

			// titulo del menu
			gotoxy(10, 2);
			cout << "\t\t" << titulo5;

			// opciones del menu son en tipo vector o constante,
			for (int i = 0; i < n5; i++)
			{
				gotoxy(10, 3 + i);
				cout << "\t\t" << i + 1 << " ) " << opciones5[i];
			}

			do
			{
				tecla5 = _getch();
			} while (tecla5 != UP && tecla5 != down && tecla5 != ENTER);

			switch (tecla5)
			{
			case UP:
				opcionSelec5++;
				if (opcionSelec5 > n5)
				{
					opcionSelec5 = 1;
				}

				break;
			case down:
				opcionSelec5--;
				if (opcionSelec5 < 1)
				{
					opcionSelec5 = n5;
				}
				break;
			case ENTER:
				menu5 = false;
				break;
			}

		} while (menu5);
		opcionremesas = opcionSelec5;

		switch (opcionremesas)
		{
		
		// 5.1 - RECIBIR REMESAS
		case 1:
		{
			system("cls");
			cout << "\n\t\tRECIBIR REMESAS\n\t\t================================\n" << endl;
			codigoremesarecibircin:
			cout << "\t\tEscriba el codigo de envio (entre 8 y 12 cifras):" << endl;
			// numdigitos = 0 esta para que haga de nuevo el conteo de digitos en caso de que lo ponga mal el usuario
			numdigitos = 0;
			cout << "\t\t\t";
			cin >> codigoremesarecibir;
			// CONVIERTE EL CODIGO A UN ENTERO
			codigoremesarecibir_contadordigitos = codigoremesarecibir;

			// VERIFICADOR DE DIGITOS DE REMESAS
			// CUENTA CUANTOS DIGITOS EXISTEN EN ESE CODIGO Y DEVUELVE SI ES VALIDO O NO

			while (codigoremesarecibir_contadordigitos > 0)
			{
				codigoremesarecibir_contadordigitos = codigoremesarecibir_contadordigitos/ 10;

				numdigitos = numdigitos + 1;
			}

			// Si el numero de cifras esta entre 8 y 12 esta bien
			if (numdigitos >= 8 && numdigitos <= 12)
			{
				system("cls");
				cout << "\n\n\t\tTodo bien." << endl;
				cout << "\t\tEl codigo de remesa tiene " << numdigitos << " cifras, es valido." << endl;

				cout << "\t\t------------------------------------------" << endl;
				cout << "\t\tEl valor de esta remesa es de $100." << endl;

				cout << "\t\tSaldo anterior: $" << fondos << endl;
				nuevofondo = fondos + 100;
				fondos = nuevofondo;
				cout << "\t\tSaldo actual: $" << fondos << endl;
			}

			else
			{
				system("cls");
				cout << "\n\n\t\tError." << endl;
				cout << "\t\tEl codigo de la remesa tiene " << numdigitos << " cifras, no es un codigo valido." << endl;
				cout << "\t\tPor favor, digite el codigo nuevamente." << endl;
				goto codigoremesarecibircin;
			}
			_getch();

			//FLECHAS DE SELECCION Y MENU DE QUE DESEA HACER
			do
			{
				// este menu es el mismo formato del otro menu
				system("cls");

				gotoxy(5, 2 + opcionSelec2);
				cout << "\t\t-->";

				// titulo del menu
				gotoxy(10, 2);
				cout << "\t\t" << titulo2;

				// opciones del menu son en tipo vector o constante,
				for (int i = 0; i < n2; i++)
				{
					gotoxy(10, 3 + i);
					cout << "\t\t" << i + 1 << " ) " << opciones2[i];
				}

				do
				{
					tecla2 = _getch();
				} while (tecla2 != UP && tecla2 != down && tecla2 != ENTER);

				switch (tecla2)
				{
				case UP:
					opcionSelec2++;
					if (opcionSelec2 > n2)
					{
						opcionSelec2 = 1;
					}

					break;
				case down:
					opcionSelec2--;
					if (opcionSelec2 < 1)
					{
						opcionSelec2 = n2;
					}
					break;
				case ENTER:
					repeticion2 = false;
					break;
				}

			} while (repeticion2);
			opcion2 = opcionSelec2;

			// ACCIONES DE LA PREGUNTA "QUE DESEA HACER"
			switch (opcion2)
			{
			case 1:

				system("cls");		// se borra el menu en pantalla
				repeticion2 = true;// esto nos deja volver a usar el menu secundario
				menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
				menu5 = true;
				menu_r = true;
				menu_si = true;
				goto menu1;
				break;
			case 2:
				system("cls");
				cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
				_getch();
				repeticion2 = true;// esto nos deja volver a usar el menu secundario
				menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
				menu5 = true;
				menu_si = true;
				menu_r = true;
				presioneunatecla();
				break;
			}

			break;// BREAK DEL SWITCH

		}

		// 5.2 - ENVIAR REMESAS
		case 2:
		{
			// CANTIDAD
			system("cls");
			cantidadremesaenviarcin:
			cout << "\n\n\t\tENVIAR REMESAS\n\t\t================================\n" << endl;
			cout << "\t\tEscriba la cantidad que desea enviar (sin centavos):" << endl;

			cout << "\t\t$ ";
			cin >> cantidadremesaenviar;

			if (cantidadremesaenviar > 1 && cantidadremesaenviar < 50000)
			{
				system("cls");
				cout << "\n\n\t\tTodo bien." << endl;
				cout << "\t\tUsted ha decidido enviar $" << cantidadremesaenviar << ", es posible." << endl;
				cout << "\t\t----------------------------------------------------------------" << endl;
				cout << "\t\tPresione cualquier tecla para continuar" << endl;
				_getch();
			}

			else
			{
				system("cls");
				cout << "\n\n\t\tError." << endl;
				cout << "\t\tLa cantidad de dinero que ha escrito es: $" << numdigitos << ", es una cantidad muy grande." << endl;
				cout << "\t\tLa cantidad debe estar entre $1 y $50,000" << endl;
				cout << "\t\tPor favor, escriba la cantidad nuevamente." << endl;
				_getch();
				goto cantidadremesaenviarcin;
			}

			// PAIS A ENVIAR

			//FLECHAS DE SELECCION Y MENU DE OPCIONES DEL PAIS A ENVIAR LA REMESA
			do
			{
				// este menu es el mismo formato del oto menu
				system("cls");

				gotoxy(5, 2 + opcionSelec_r);
				cout << "\t\t-->";

				// titulo del menu
				gotoxy(10, 2);
				cout << "\t\t" << titulo_r;

				// opciones del menu son en tipo vector o constante,
				for (int i = 0; i < n_r; i++)
				{
					gotoxy(10, 3 + i);
					cout << "\t\t" << i + 1 << " ) " << opciones_r[i];
				}

				do
				{
					tecla_r = _getch();
				} while (tecla_r != UP && tecla_r != down && tecla_r != ENTER);

				switch (tecla_r)
				{
				case UP:
					opcionSelec_r++;
					if (opcionSelec_r > n_r)
					{
						opcionSelec_r = 1;
					}

					break;
				case down:
					opcionSelec_r--;
					if (opcionSelec_r < 1)
					{
						opcionSelec_r = n_r;
					}
					break;
				case ENTER:
					menu_r = false;
					break;
				}

			} while (menu_r);
			paisremesaenviar = opcionSelec_r;

			switch (paisremesaenviar)
			{
			case 1:

				system("cls");
				cout << "\n\n\t\tUsted ha decidido enviar $" << cantidadremesaenviar << "a Estados Unidos." << endl;

				_getch();

				//FLECHAS DE SELECCION Y MENU DE OPCIONES DE "SI" O "NO", PREGUNTA SI ESTA SEGURO/A SI DESEA ENVIAR LA REMESA A ESE PAIS
				do
				{
					// este menu es el mismo formato del oto menu

					system("cls");

					gotoxy(5, 2 + opcionSelec_si);
					cout << "\t\t-->";

					// titulo del menu
					gotoxy(10, 2);
					cout << "\t\t" << titulo_si;

					// opciones del menu son en tipo vector o constante,
					for (int i = 0; i < n_si; i++)
					{
						gotoxy(10, 3 + i);
						cout << "\t\t" << i + 1 << " ) " << opciones_si[i];
					}

					do
					{
						tecla_si = _getch();
					} while (tecla_si != UP && tecla_si != down && tecla_si != ENTER);

					switch (tecla_si)
					{
					case UP:
						opcionSelec_si++;
						if (opcionSelec_si > n_si)
						{
							opcionSelec_si = 1;
						}

						break;
					case down:
						opcionSelec_si--;
						if (opcionSelec_si < 1)
						{
							opcionSelec_si = n_si;
						}
						break;
					case ENTER:
						menu_si = false;
						break;
					}

				} while (menu_si);

				acuerdoenviarremesa = opcionSelec_si;

				switch (acuerdoenviarremesa)
				{
				case 1:
					system("cls");
					cout << "\n\n\t\tDe acuerdo." << endl;
					cout << "\t\tUsted ha enviado $ " << cantidadremesaenviar << " hacia Estados Unidos." << endl;
					cout << "\t\tEl codigo de remesa es: 1234-567-890" << endl;
					nuevofondo = fondos - cantidadremesaenviar;
					fondos = nuevofondo;
					cout << "\t\tSu saldo actual es $ " << fondos << endl;

					_getch();

					system("cls");		// se borra el menu en pantalla
					repeticion2 = true;// esto nos deja volver a usar el menu secundario
					menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
					menu5 = true;
					menu_r = true;
					menu_si = true;
					goto menu1;

					break;

				case 2:
					system("cls");
					cout << "\n\n\t\tUsted no ha aceptado el envio de esta remesa." << endl;
					cout << "\n\nRegresara al principio de la opcion de Envio de Remesas." << endl;
					_getch();
					system("cls");		// se borra el menu en pantalla
					repeticion2 = true;// esto nos deja volver a usar el menu secundario
					menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
					menu5 = true;
					menu_r = true;
					menu_si = true;
					goto cantidadremesaenviarcin;
					break;
				}

				break;

			case 2:
				system("cls");
				cout << "\n\n\t\tUsted ha decidido enviar $" << cantidadremesaenviar << "a Canada." << endl;

				_getch();

				do
				{
					// este menu es el mismo formato del oto menu

					system("cls");

					gotoxy(5, 2 + opcionSelec_si);
					cout << "\t\t-->";

					// titulo del menu
					gotoxy(10, 2);
					cout << "\t\t" << titulo_si;

					// opciones del menu son en tipo vector o constante,
					for (int i = 0; i < n_si; i++)
					{
						gotoxy(10, 3 + i);
						cout << "\t\t" << i + 1 << " ) " << opciones_si[i];
					}

					do
					{
						tecla_si = _getch();
					} while (tecla_si != UP && tecla_si != down && tecla_si != ENTER);

					switch (tecla_si)
					{
					case UP:
						opcionSelec_si++;
						if (opcionSelec_si > n_si)
						{
							opcionSelec_si = 1;
						}

						break;
					case down:
						opcionSelec_si--;
						if (opcionSelec_si < 1)
						{
							opcionSelec_si = n_si;
						}
						break;
					case ENTER:
						menu_si = false;
						break;
					}

				} while (menu_si);

				acuerdoenviarremesa = opcionSelec_si;

				switch (acuerdoenviarremesa)
				{
				case 1:
					system("cls");
					cout << "\n\n\t\tDe acuerdo." << endl;
					cout << "\t\tUsted ha enviado $ " << cantidadremesaenviar << " hacia Canada." << endl;
					cout << "\t\tEl codigo de remesa es: 1234-567-890" << endl;
					nuevofondo = fondos - cantidadremesaenviar;
					fondos = nuevofondo;
					cout << "\t\tSu saldo actual es $ " << fondos << endl;

					_getch();

					system("cls");		// se borra el menu en pantalla
					repeticion2 = true;// esto nos deja volver a usar el menu secundario
					menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
					menu5 = true;
					menu_r = true;
					menu_si = true;
					goto menu1;

					break;

				case 2:
					system("cls");
					cout << "\n\n\t\tUsted no ha aceptado el envio de esta remesa." << endl;
					cout << "\n\nRegresara al principio de la opcion de Envio de Remesas." << endl;
					_getch();
					system("cls");		// se borra el menu en pantalla
					repeticion2 = true;// esto nos deja volver a usar el menu secundario
					menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
					menu5 = true;
					menu_r = true;
					menu_si = true;
					goto cantidadremesaenviarcin;
					break;
				}
				break;
			}

		// 5.3 - VOLVER AL MENU PRINCIPAL
		case 3:
		{
			system("cls");		// se borra el menu en pantalla
			repeticion2 = true;// esto nos deja volver a usar el menu secundario
			menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
			menu5 = true;
			menu_r = true;
			menu_si = true;
			goto menu1;
			break;
		}

		// 5.4 - SALIR
		case 4:
		{
			system("cls");
			cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
			_getch();
			repeticion2 = true;// esto nos deja volver a usar el menu secundario
			menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
			system("cls");		// se borra el menu en pantalla
			repeticion2 = true;// esto nos deja volver a usar el menu secundario
			menu = true;		// esto nos deja volver a usar el menu principal o el emnu de opciones
			menu5 = true;
			menu_r = true;
			menu_si = true;
			presioneunatecla();
			break;
			// fin del caso 6 o salir
		}

		break;
		// fin del caso 5 o remesas
		}

		break;
		}
	}
		
	// 6 - SALIR
	case 6:
	{
			system("cls");
			cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
			_getch();
			menu = true;// esto nos deja volver a usar el menu principal o el emnu de opciones
			presioneunatecla();
			break;
			// fin del caso 6 o salir
		}
	
	}
}


