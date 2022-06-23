// LLAMADO DE LIBRERIAS
#include <iostream>
#include <conio.h> // esta para que se pueda usar getch_, getch sirve para mantener la pantalla hasta que el usuario pasa un solo valor para salir de la pantalla de la consola. Link: https://www.javatpoint.com/what-is-getch-in-c
#include <ctime>
#include <vector>
#include "gotoxy.h"				//hace referencia al archivo del mismo nombre que esta en la misma carpeta de este archivo .cpp
// "gotoxy.h" esta entre comillas porque la ubicacion del archivo de la libreria esta en el mismo lugar que este archivo main.cpp
#pragma warning(disable : 4996)// me tiraba un error por lo de la fecha me decia CRL_SECURE_ y con esto se quita T-T

// #DEFINE PARA DETECTAR LA TECLA DEL TECLADO
// Estos son los define con el codigo ascci para poder mover con las flechas del teclado
#define UP 80
#define down 72
#define ENTER 13

//declaracion de funciones

//funcion para el texto que sale al iniciar o terminar el programa
void presioneunatecla();
//funcion para pantalla de introduzca una cuenta
int introducir_cuenta();
//funcion de los switches de las opciones del menu
void opciones_del_programa(int numero_cuenta, float fondos, float nuevo_fondo, const char* nombre);
//funcion del menu principal
int menu_opciones_principal();
int menu_opciones_continuar();
int menu_opciones_caso4();
int menu_opciones_SiNo();
int menu_opciones_USAoCAN();



using namespace std;
//funcion principal donde estan los datos de los usuarios
int main()
{

	// DECLARACION DE VARIABLES
	int numero_cuenta;// la cuenta predeterminada es 123456
	const char* nombre;
	float fondos = 0, nuevo_fondo = 0;// fondos: use una suma de dinero aleatoria para poder usar en todo el programa como si fuese una base de datos

	// Instrucción que declara el color de fondo
	system("color 3F");

	// Variable booleana (de tipo verdadera o falsa) necesaria para que el dowhile repita la accion de pedir el numero de cuenta por algun error
	bool repetir_programa = true;

	// Distintas cuentas a usar dentro del programa
	{
		do
		{
			numero_cuenta = 0;
			numero_cuenta = introducir_cuenta();
			// La variable numero de cuenta tendra el valor que retorne la funcion de introducir_cuenta() usando la variable cuenta

			// Existen 6 numeros de cuenta distintos en donde cada uno tiene una cantidad distinta en la variable fondos, un valor distinto en la variable caracter.
			// Esto es para que en cada numero de cuenta, se cambie el nombre de cada persona y cuanto dinero tiene cada una

			if (numero_cuenta == 123456)
			{
				fondos = 500;
				const char* nombre("Jose Perez");
				opciones_del_programa(numero_cuenta, fondos, nuevo_fondo, nombre);
			}

			else if (numero_cuenta == 654321)
			{
				fondos = 700;
				const char* nombre("Diego Perez");
				opciones_del_programa(numero_cuenta, fondos, nuevo_fondo, nombre);

			}

			else if (numero_cuenta == 159753)
			{
				fondos = 1500;
				const char* nombre("Alejandro Garcia");
				opciones_del_programa(numero_cuenta, fondos, nuevo_fondo, nombre);

			}

			else if (numero_cuenta == 000000)
			{
				fondos = 250;
				const char* nombre("Toni Morales");
				opciones_del_programa(numero_cuenta, fondos, nuevo_fondo, nombre);

			}

			else if (numero_cuenta == 987654)
			{
				fondos = 5000;
				const char* nombre("Irma Salazar");
				opciones_del_programa(numero_cuenta, fondos, nuevo_fondo, nombre);

			}

		} while (repetir_programa);
	}

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
	cout << "\n\t\t		Bienvenido al cajero de BANCO NACIONAL\n" << endl;

	cout << "\n\t\t		Por favor introduzca su n\xA3mero de cuenta:\n" << endl;

	cout << "\t\t---------------------------------------------------------------------------" << endl;
	cout << "\t\t	Introduzca su n\xA3mero de cuenta: ";
	// El numero de cuenta que utilizaremos como ejemplo sera 123456 y 654321 *tilde*
	cin >> cuenta;/// tilde*

	//----------------------Fin de la bienvenida-----------------------------------

	return cuenta;
}

//Funcion que sale al pricipio y al final del programa
void presioneunatecla()
{
	system("cls");
	cout << "\n\n\n\t\t\tPresione cualquier tecla para continuar.....";

	_getch();

	system("cls");
}

//Menu principal 6 opciones
int menu_opciones_principal() {
	const char* titulo{ "Bienvenido" };
	const char* opciones[] = { "Estado de cuenta", "Depositar", "Retirar", "Pagar recibos", "Remesas", "Salir" };
	bool repetir_menu = true;
	char tecla;
	int numero_opciones = 6;
	int OpcionSelec = 1;
	do {
		system("cls");
		gotoxy(10, 2);  cout << "\t\t" << titulo;


		gotoxy(5, 3 + OpcionSelec); cout << "\t\t-->";

		for (int i = 0; i < numero_opciones; i++)
		{
			gotoxy(10, 4 + i); cout << "\t\t" << i + 1 << " ) " << opciones[i];

		}

		do
		{
			tecla = _getch();
		} while (tecla != UP && tecla != down && tecla != ENTER);

		switch (tecla)
		{
		case UP:
			OpcionSelec++;
			if (OpcionSelec > numero_opciones)
			{
				OpcionSelec = 1;
			}

			break;

		case down:
			OpcionSelec--;
			if (OpcionSelec < 1)
			{
				OpcionSelec = numero_opciones;
			}
			break;
		case ENTER:
			repetir_menu = false;


		}

	} while (repetir_menu);

	return OpcionSelec;
}//fin del menu pricipal #pciones 6
int menu_opciones_continuar() {
	const char* titulo{ "\xA8Que desea hacer ? " };
	const char* opciones[] = { "Salir", "Continuar con el programa"};
	bool repetir_menu = true;
	char tecla;
	int numero_opciones = 2;
	int OpcionSelec = 1;
	do {
		system("cls");
		gotoxy(10, 2);  cout << "\t\t" << titulo;


		gotoxy(5, 3 + OpcionSelec); cout << "\t\t-->";

		for (int i = 0; i < numero_opciones; i++)
		{
			gotoxy(10, 4 + i); cout << "\t\t" << i + 1 << " ) " << opciones[i];

		}

		do
		{
			tecla = _getch();
		} while (tecla != UP && tecla != down && tecla != ENTER);

		switch (tecla)
		{
		case UP:
			OpcionSelec++;
			if (OpcionSelec > numero_opciones)
			{
				OpcionSelec = 1;
			}

			break;

		case down:
			OpcionSelec--;
			if (OpcionSelec < 1)
			{
				OpcionSelec = numero_opciones;
			}
			break;
		case ENTER:
			repetir_menu = false;


		}

	} while (repetir_menu);

	return OpcionSelec;
}//fin del menu de continuar


int menu_opciones_caso4() {
	const char* titulo{ "\xA8Que desea hacer ? " };
	const char* opciones[] = { "Pago de recibo pendiente", "Pago de otro recibo", "Volver al Menu" };
	bool repetir_menu = true;
	char tecla;
	int numero_opciones = 3;
	int OpcionSelec = 1;
	do {
		system("cls");
		gotoxy(10, 2);  cout << "\t\t" << titulo;


		gotoxy(5, 3 + OpcionSelec); cout << "\t\t-->";

		for (int i = 0; i < numero_opciones; i++)
		{
			gotoxy(10, 4 + i); cout << "\t\t" << i + 1 << " ) " << opciones[i];

		}

		do
		{
			tecla = _getch();
		} while (tecla != UP && tecla != down && tecla != ENTER);

		switch (tecla)
		{
		case UP:
			OpcionSelec++;
			if (OpcionSelec > numero_opciones)
			{
				OpcionSelec = 1;
			}

			break;

		case down:
			OpcionSelec--;
			if (OpcionSelec < 1)
			{
				OpcionSelec = numero_opciones;
			}
			break;
		case ENTER:
			repetir_menu = false;


		}

	} while (repetir_menu);

	return OpcionSelec;
}//fin del menu de caso 4


int menu_opciones_caso5() {
	const char* titulo{ "\xA8Que desea hacer ? " };
	const char* opciones[] = { "Recibir una remesa", "Enviar una remesa", "Volver al Menu" };
	bool repetir_menu = true;
	char tecla;
	int numero_opciones = 3;
	int OpcionSelec = 1;
	do {
		system("cls");
		gotoxy(10, 2);  cout << "\t\t" << titulo;


		gotoxy(5, 3 + OpcionSelec); cout << "\t\t-->";

		for (int i = 0; i < numero_opciones; i++)
		{
			gotoxy(10, 4 + i); cout << "\t\t" << i + 1 << " ) " << opciones[i];

		}

		do
		{
			tecla = _getch();
		} while (tecla != UP && tecla != down && tecla != ENTER);

		switch (tecla)
		{
		case UP:
			OpcionSelec++;
			if (OpcionSelec > numero_opciones)
			{
				OpcionSelec = 1;
			}

			break;

		case down:
			OpcionSelec--;
			if (OpcionSelec < 1)
			{
				OpcionSelec = numero_opciones;
			}
			break;
		case ENTER:
			repetir_menu = false;


		}

	} while (repetir_menu);

	return OpcionSelec;
}//fin del menu de caso 5


int menu_opciones_SiNo() {
	const char* titulo{ "\xA8 Esta seguro ? " };
	const char* opciones[] = { "Si", "No" };
	bool repetir_menu = true;
	char tecla;
	int numero_opciones = 2;
	int OpcionSelec = 1;
	do {
		system("cls");
		gotoxy(10, 2);  cout << "\t\t" << titulo;


		gotoxy(5, 3 + OpcionSelec); cout << "\t\t-->";

		for (int i = 0; i < numero_opciones; i++)
		{
			gotoxy(10, 4 + i); cout << "\t\t" << i + 1 << " ) " << opciones[i];

		}

		do
		{
			tecla = _getch();
		} while (tecla != UP && tecla != down && tecla != ENTER);

		switch (tecla)
		{
		case UP:
			OpcionSelec++;
			if (OpcionSelec > numero_opciones)
			{
				OpcionSelec = 1;
			}

			break;

		case down:
			OpcionSelec--;
			if (OpcionSelec < 1)
			{
				OpcionSelec = numero_opciones;
			}
			break;
		case ENTER:
			repetir_menu = false;


		}

	} while (repetir_menu);

	return OpcionSelec;
}//fin del menu si o no


int menu_opciones_USAoCAN() {
	const char* titulo{ "\xA8 Escoja un pais: " };
	const char* opciones[] = { "Estados Unidos", "Canada" };
	bool repetir_menu = true;
	char tecla;
	int numero_opciones = 2;
	int OpcionSelec = 1;
	do {
		system("cls");
		gotoxy(10, 2);  cout << "\t\t" << titulo;


		gotoxy(5, 3 + OpcionSelec); cout << "\t\t-->";

		for (int i = 0; i < numero_opciones; i++)
		{
			gotoxy(10, 4 + i); cout << "\t\t" << i + 1 << " ) " << opciones[i];

		}

		do
		{
			tecla = _getch();
		} while (tecla != UP && tecla != down && tecla != ENTER);

		switch (tecla)
		{
		case UP:
			OpcionSelec++;
			if (OpcionSelec > numero_opciones)
			{
				OpcionSelec = 1;
			}

			break;

		case down:
			OpcionSelec--;
			if (OpcionSelec < 1)
			{
				OpcionSelec = numero_opciones;
			}
			break;
		case ENTER:
			repetir_menu = false;


		}

	} while (repetir_menu);

	return OpcionSelec;
}//fin del menu usa o canada



void opciones_del_programa(int numero_cuenta, float fondos, float nuevo_fondo, const char* nombre) {

	// DECLARACION DE VARIABLES DE LOS MENUS
	// Se declaran algunas variables que se usaran dentro de los menus

	// OPCION/CASO 2 - DEPOSITAR
// fondo y nuevofondo en la funcion principal #1.
	int agregarsaldodeposito = 0;
	// OPCION/CASO 3 - RETIRAR
	// fondo y nuevofondo en la funcion principal #1.
	int retirofondo = 0;
	// OPCION/CASO 4 - PAGO DE RECIBOS
	int opcion1enpagorecibo = 0, opcion2enpagorecibo = 0;// puse opcion1enpagorecibo y opcion2enpagorecibo pero son sub opciones dento de los menus
	float factura = 0;									// una factura falsa
	char empresanombre[100];
	int opcion4;
	// variables del mini menu de opciones
	bool pagoFactura = false;// variable para determinar si se a pagado o no la factura pendiente

// OPCION/CASO 5 - ENVIO DE REMESAS
	int opcionremesas = 0;
	// OPCION/CASO 5.1 - RECIBIR REMESAS
	int codigoremesarecibir_contadordigitos = 0, numdigitos = 0;
	double codigoremesarecibir = 0;
	// OPCION/CASO 5.2 - ENVIAR REMESAS
	int cantidadremesaenviar = 0, paisremesaenviar = 0, codigoremesaenviar = 0, acuerdoenviarremesa = 0;





	//variables de los menus
	int  opcion_elegida, opcion_elegida2, opcion_remesas;



	//variable para dar el tiempo local
		// VARIABLE FECHA Y TIEMPO LOCAL
	time_t t;
	t = time(0);// fecha actual
	struct tm* f;// puntero de variable fecha, un puntero es una variable que representa la posición (más que el valor) de otro dato, tal como una variable o un elemento de un array.
	f = localtime(&t);


menu1:
	opcion_elegida = menu_opciones_principal();

	switch (opcion_elegida)
	{

// ELEMENTOS DEL MENU DE OPCIONES PRINCIPAL
	// 1 - ESTADO DE CUENTA	
	case 1:
	{
		system("cls");
		cout << "\n\n\t\tESTADO DE CUENTA\n\t\t================================\n" << endl;// mensaje de acccion a realizar

		cout << "\t\tCuenta N " << numero_cuenta << endl;// aqui iria el nombre que le dimos a la variablecon el numero de cuenta

		cout << "\t\t" << nombre << endl;// un nombre ramdom o el nombre del lic ya que seria innesesario pedir el nombre si ya posee una cuenta

		cout << "\t\tFecha: " << f->tm_mday << "/ " << f->tm_mon + 1 << "/ " << f->tm_year + 1900 << endl;// finaliza la accion de fecha

		cout << "\t\tDinero en la cuenta: $ " << fondos << endl;

		cout << "\t\tUltima acci\xA2n:  Estado de cuenta "
			<< "Fecha: " << f->tm_mday << "/ " << f->tm_mon + 1 << "/ " << f->tm_year + 1900 << " Hora: " << f->tm_hour << ":" << f->tm_min << ":" << f->tm_sec << endl;// sorry no se me ocurrio nada mas en esta parte

		_getch();
		system("cls");


		opcion_elegida2 = menu_opciones_continuar();
		switch (opcion_elegida2)
		{
		case 1:
		{
			system("cls");

			cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
			presioneunatecla();

		}break;//fin del casp1.1
		case 2:
		{
			system("cls");// se borra el menu en pantalla
			goto menu1;

		}break;//fin del caso 1.2

		}
	}break;//fin del caso 1

	// 2 - DEPOSITAR
	case 2:
	{
		system("cls");
		cout << "\n\n\t\tDEPOSITAR\n\t\t================================\n" << endl;
		// Se sugiere introducir el resto de datos aqui, o hacer cambios segun se necesite

		cout << "\t\tIngrese la cantidad a agregar: $ ";
		cin >> agregarsaldodeposito;
		nuevo_fondo = fondos + agregarsaldodeposito;
		cout << "\t\tNuevo saldo en cuenta: $ " << nuevo_fondo << endl;
		// aqui saldra la nueva cantidad en cuenta

		fondos = nuevo_fondo;
		// para poder volver al menu de inicio correctamente
		_getch();
		system("cls");
		goto menu1;

	}break;//fin del caso 2

	// 3 - RETIRAR
	case 3:
	{
		system("cls");
		cout << "\n\n\t\tRETIRAR\n\t\t================================\n" << endl;
		cout << "\n\t\tDigite la cantidad a retirar: $ ";
	retirocin:
		cin >> retirofondo;
		if (retirofondo > 5000)
		{
			system("cls");
			cout << "\t\tLa cantidad ingresada es mayor a 5000, digite otra cantidad";
			// comprueba la cantidad si es mayor no dejara hacer el retiro, y si es menor se hara facilmente el retiro.
			goto retirocin;
		}
		nuevo_fondo = fondos - retirofondo;
		cout << "\n\t\tCantidad en cuenta despues del retiro: $ " << nuevo_fondo << endl;
		// se resta el nuevofondo inicial y queda el total de cuenta

		fondos = nuevo_fondo;

		// para poder volver al menu de inicio correctamente
		_getch();// sustituye a system("pause) y no muestra el mensaje de presione otra tecla


		system("cls");
		goto menu1;

	}	break;//fin del caso 3

	// 4 - PAGO DE RECIBOS
	case 4:
	{	
		system("cls");
		opcion4 = menu_opciones_caso4();
		switch (opcion4) {

		// 4.1 - PAGO DE RECIBO PENDIENTE
		case 1:
		{
			system("cls");
			cout << "\n\n\t\tPAGO DE RECIBO PENDIENTE\n\t\t================================\n" << endl;
			factura = 99.99;// CANTIDAD DE FACTURA FALSA
			nuevo_fondo = fondos - factura;

			// IF QUE HACE MOSTRAR QUE SE HA PAGADO EL RECIBO, Y LO MARCA COMO YA PAGADO
			if (pagoFactura == false)
			{
				cout << "\n\n\t\tSe a realizado el pago de su factura pendiente con un monto de: " << factura << endl;
				cout << "\t\tSu nuevo saldo es: " << nuevo_fondo << endl;
				cout << "\n\t\tSu proxima factura pendiente esta programada para: " << f->tm_mday << "/ " << f->tm_mon + 2 << "/ " << f->tm_year + 1900 << endl;
				fondos = nuevo_fondo;
				pagoFactura = true;
				_getch();
				system("cls");
				opcion_elegida2 = menu_opciones_continuar();
				switch (opcion_elegida2)
				{
				case 1:
				{
					system("cls");

					cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
					presioneunatecla();

				}break;//fin del casp1.1
				case 2:
				{
					system("cls");// se borra el menu en pantalla
					goto menu1;

				}	break;//fin del caso 4.2.1

				}
			}
			else
			{
				system("cls");
				cout << "\n\n\t\tPAGO DE RECIBO PENDIENTE\n\t\t================================\n" << endl;
				cout << "\n\t\tNo posee facturas de credito pendientes\n";

				cout << "\t\tGracias por realizar el pago de sus facturas a tiempo.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
				_getch();
				system("cls");//borrar la pantalla
				goto menu1;

			}

		}	break;//fin del caso 4.1

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
			nuevo_fondo = fondos - factura;
			system("cls");
			cout << "\n\n\t\tSe ha realizado un pago a " << empresanombre << " por la suma de $ " << factura << endl;
			cout << "\t\tSu nuevo saldo es de $ " << nuevo_fondo << endl;
			fondos = nuevo_fondo;

			_getch();
			goto menu1;
		}break;//fin del caso 4.2

		// 4.3 - VOLVER AL MENU PRINCIPAL
		case 3:
		{
			system("cls");
			goto menu1;

		}break;//fin del caso 4.3
		}//fin del switch dentro del caso 4
	}break;//fin del caso 4

	// 5 - REMESAS
	case 5:
	{
		opcion_elegida2 = menu_opciones_caso5();
		switch (opcion_elegida2)
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
			while (codigoremesarecibir_contadordigitos > 0)
			{
				codigoremesarecibir_contadordigitos = codigoremesarecibir_contadordigitos / 10;

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
				nuevo_fondo = fondos + 100;
				fondos = nuevo_fondo;
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
			opcion_elegida2 = menu_opciones_continuar();
			switch (opcion_elegida2)
			{
			case 1:
			{
				system("cls");

				cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
				presioneunatecla();

			}break;//fin del casp1.1
			case 2:
			{
				system("cls");// se borra el menu en pantalla
				goto menu1;

			}break;//fin del caso 1.2

			}

		}//fin del caso 5.1

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
			opcion_elegida2 = menu_opciones_USAoCAN();
			switch (opcion_elegida2)
			{
			case 1:
			{

				system("cls");
				cout << "\n\n\t\tUsted ha decidido enviar $" << cantidadremesaenviar << " a Estados Unidos." << endl;

				_getch();
				system("cls");
				opcion4 = menu_opciones_SiNo();
				switch (opcion4) {
				case 1:
					{
					system("cls");
					cout << "\n\n\t\tDe acuerdo." << endl;
					cout << "\t\tUsted ha enviado $ " << cantidadremesaenviar << " hacia Estados Unidos." << endl;
					cout << "\t\tEl codigo de remesa es: 1234-567-890" << endl;
					nuevo_fondo = fondos - cantidadremesaenviar;
					fondos = nuevo_fondo;
					cout << "\t\tSu saldo actual es $ " << fondos << endl;

					_getch();

					system("cls");		// se borra el menu en pantalla
					goto menu1;

					}break;//si enviar  
				case 2:
				{
					system("cls");
					cout << "\n\n\t\tUsted no ha aceptado el envio de esta remesa." << endl;
					cout << "\n\nRegresara al principio de la opcion de Envio de Remesas." << endl;
					_getch();
					system("cls");		// se borra el menu en pantalla
					goto cantidadremesaenviarcin;
					break;
				}break;//no enviar
				}

			}break;//fin de enviar remesa a usa

			case 2:
			{
				system("cls");
				cout << "\n\n\t\tUsted ha decidido enviar $" << cantidadremesaenviar << " a Canada." << endl;

				_getch();
				system("cls");
				opcion4 = menu_opciones_SiNo();
				switch (opcion4) {
				case 1:
				{
					system("cls");
					cout << "\n\n\t\tDe acuerdo." << endl;
					cout << "\t\tUsted ha enviado $ " << cantidadremesaenviar << " hacia Canada." << endl;
					cout << "\t\tEl codigo de remesa es: 1234-567-890" << endl;
					nuevo_fondo = fondos - cantidadremesaenviar;
					fondos = nuevo_fondo;
					cout << "\t\tSu saldo actual es $ " << fondos << endl;

					_getch();

					system("cls");		// se borra el menu en pantalla
					goto menu1;

				}break;//si enviar  
				case 2:
				{
					system("cls");
					cout << "\n\n\t\tUsted no ha aceptado el envio de esta remesa." << endl;
					cout << "\n\nRegresara al principio de la opcion de Envio de Remesas." << endl;
					_getch();
					system("cls");		// se borra el menu en pantalla
					goto cantidadremesaenviarcin;
					break;
				}break;//no enviar
				}


			}break;//fin enviar remesa a canada
			}

		}break;//fin del caso 5.2
		case 3:
		{
			system("cls"); goto menu1;

		}break;//fin del caso 5.3

		}

	}break;//fin del caso 5

	// 6 - SALIR
	case 6:
	{
		system("cls");
		cout << "\n\t\tGracias por haber hecho uso de este servicio.\n\t\t\t\tLO ESPERAMOS PRONTO" << endl;
		_getch();
		presioneunatecla();
		break;
	}break;//fin del caso 6

	}//fin de// fin del switch de opciones
}