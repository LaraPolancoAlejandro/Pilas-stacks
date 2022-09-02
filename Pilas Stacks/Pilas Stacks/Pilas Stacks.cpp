/*Este programa tiene la finalidad de agregar cuantos numeros quieras a una pila para poder sacarlos en orden inverso, y desplegar todo el contenido mediantes pops
Creado por Alejandro Lara ID:1106231
*/

#include <conio.h>//sirve para el _getch()
#include <iostream>//cin y cout
#include <string>//para mi try-catch
#include <windows.h>//colores

using namespace std;

bool menuout = true; //para escapar del bucle
string Menu; //guarda input del usuario en su eleccion del menu.
int Num; //sirve para entrar y sacar numeros de la pila
bool aux; //variable para salir del try-catch
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);//variable para colores.
int dato;//almacena los datos de la pila.
struct Pila { //Creacion de nodo
	int dato;
	Pila* next; //apunta al siguiente nodo de la pila
};
void ReadKey();//Espera que el usuario introduzca un valor.
void Color(int color); //Colorea el texto.
void BorrarConsola();//Limpia la consola.
void titulo();//Despliega el titulo.
void AgregarPila(Pila*&, int);//funcion push
void BorrarPila(Pila*&, int);//funcion pop
void MostrarPila(Pila*&, int);//despliega toda el contenido de la pila
void MensajePilaVacia();//mensaje para indicar que la pila esta vacia
void menu();//despliega menu con todas las opciones que tiene el programa
void Error1();//mensaje de error1
void Error2();//mensaje de rror2
void menu() {
	Pila* pila = NULL; //apunta el nodo de la pila a NULL
	do {
		titulo();
		cout << " Pulse la opcion que desea ejecutar: ";
		cin >> Menu;
		if (Menu == "E" || Menu == "e") {
			cin.exceptions(istream::failbit);// capta bits fallidos
			do {
				try {
					BorrarConsola();
					titulo();
					cout << " Ingresa  el numero que deseas introducir a la pila: ";
					cin >> Num;
					AgregarPila(pila, Num);
					Color(2); cout << "\n Operacion completada, el numero "; Color(6); cout << Num; Color(2); cout << " ha sido ingresado a la pila" << endl; Color(7);
					aux = true;
					cout << "\n Presiona cualquier tecla para continuar...";
					ReadKey();
				}
				//capta si hubo algun error y pide introducir datos validos
				catch (exception fail) { 
					aux = false;
					Error2();
					ReadKey();
					cin.clear(); //borra la entrada
					string tmp;
					getline(cin, tmp);
				}
			} while (aux == false); //saca del bucle
			BorrarConsola();
		}
		else if (Menu == "S" || Menu == "s") {
			if (pila == NULL) {
				BorrarConsola();
				titulo();
				MensajePilaVacia();
				ReadKey();
				BorrarConsola();
			}
			else {
				BorrarConsola();
				titulo();
				cout << " Se elimino el siguiente numero de la pila:\n" << endl;
				BorrarPila(pila, Num);
				ReadKey();
				BorrarConsola();
			}
		}
		else if (Menu == "D" || Menu == "d") {
			MostrarPila(pila, Num);
		}
		else if (Menu == "X" || Menu == "x") {
			exit(EXIT_SUCCESS);
		}
		else {
			menuout = false;
			Error1();
			ReadKey();
			BorrarConsola();
		}
	} while (menuout = true);
}
int main() {
	menu();
}
void BorrarPila(Pila*& Nodo, int N) {
	Pila* aux = Nodo; //se crea variable auxiliar de tipo Pila y se apunta al nodo
	N = aux->dato; //guardamos el valor que queremos eliminar
	Nodo = aux->next; //hacemos que la pila apunte al proximo nodo para que permita eliminar
	delete aux; //borramos el numero
	Num = N; //Solo es estetica para desplegar el numero que se borró
	Color(6); cout << "  " << Num <<endl; Color(7);
}
void AgregarPila(Pila*& Nodo, int N) {
	Pila* Stack = new Pila(); //Reserva memoria para el nodo
	Stack->dato = N; //el dato del nodo se vuelve el numero que queramos
	Stack->next = Nodo; //hace que el nodo apunte a la proxima pila para permitir meter
	Nodo = Stack;  //la pila apunta al nodo
}
void MostrarPila(Pila*& Nodo, int N) {
	BorrarConsola();
	titulo();
	if (Nodo == NULL) //en caso de la pila no estar modificada
	{
		Color(4); cout << "\n Empty Stack" << endl; Color(7);
	}
	else { // haces pops hasta que la pila se quede vacia
		cout << " La pila almacenaba los siguientes numeros: \n" << endl;
		while (Nodo != NULL) {
			BorrarPila(Nodo, Num);
		}
	}
	ReadKey();
	BorrarConsola();
}
void ReadKey() {
	_getch();
}
void Color(int color) {//funcion para dar colores a las letras

	SetConsoleTextAttribute(h, color);
}
void BorrarConsola() {
	system("cls");
}
void titulo() {
	cout << "\n BIENVENIDO A STACKS\n" << endl;
	cout << "\n Para continuar debes elegir que quieres hacer en la pila.\n" << endl;
	cout << " Pulsa \"E\" para realizar la funcion de push." << endl;
	cout << " Pulsa \"S\" para realizar la funcion de pop." << endl;
	cout << " Pulsa \"D\" para realizar la funcion de desplegar." << endl;
	cout << " Pulsa \"X\" para salir de la aplicacion.\n" << endl;
}
void MensajePilaVacia() {
	Color(4); cout << "\n Empty Stack" << endl; Color(7);
}
void Error1()
{
	Color(4); cout << endl << " Solo estan permitidas las entradas mostradas en el menu" << endl << endl; Color(7);
}
void Error2()
{
	Color(4); cout << endl << " Solo estan permitidos valores numericos" << endl << endl; Color(7);
}
