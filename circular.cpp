#include <iostream>
using namespace std;

class Nodo {
public:
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(NULL) {}
};

class ListaCircular {
private:
    Nodo* cabeza;

public:
    ListaCircular() : cabeza(NULL) {}

    void insertar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            nuevoNodo->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            Nodo* ultimo = cabeza;
            while (ultimo->siguiente != cabeza) {
                ultimo = ultimo->siguiente;
            }
            nuevoNodo->siguiente = cabeza;
            ultimo->siguiente = nuevoNodo;
        }
    }

    void imprimir() {
        if (!cabeza) {
            cout << "La lista está vacía." << endl;
            return;
        }
        Nodo* actual = cabeza;
        do {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        } while (actual != cabeza);
        cout << endl;
    }

    int buscar(int valor) {
        if (!cabeza) {
            return -1;
        }
        Nodo* actual = cabeza;
        int posicion = 0;
        do {
            if (actual->dato == valor) {
                return posicion;
            }
            actual = actual->siguiente;
            posicion++;
        } while (actual != cabeza);
        return -1;
    }

    void eliminar(int valor) {
        if (!cabeza) {
            return;
        }
        Nodo* actual = cabeza;
        Nodo* anterior = NULL;
        do {
            if (actual->dato == valor) {
                if (actual == cabeza) {
                    Nodo* ultimo = cabeza;
                    while (ultimo->siguiente != cabeza) {
                        ultimo = ultimo->siguiente;
                    }
                    cabeza = cabeza->siguiente;
                    ultimo->siguiente = cabeza;
                } else {
                    anterior->siguiente = actual->siguiente;
                }
                delete actual;
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        } while (actual != cabeza);
    }

    void buscarYCambiar(int valorBuscado, int nuevoValor) {
        int posicion = buscar(valorBuscado);
        if (posicion != -1) {
            Nodo* actual = cabeza;
            for (int i = 0; i < posicion; i++) {
                actual = actual->siguiente;
            }
            actual->dato = nuevoValor;
        }
    }
};

int main() {
    ListaCircular lista;

    cout << "Ingrese elementos a la lista (ingrese 0 para terminar):" << endl;
    int elemento;
    while (true) {
        cin >> elemento;
        if (elemento == 0) {
            break;
        }
        lista.insertar(elemento);
    }

    cout << "Lista Circular: ";
    lista.imprimir();

    int opcion;
    while (true) {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Imprimir posición de un dato" << endl;
        cout << "2. Buscar un dato" << endl;
        cout << "3. Eliminar un dato" << endl;
        cout << "4. Buscar y cambiar un dato" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        if (opcion == 0) {
            break;
        }

        switch (opcion) {
            case 1:
                cout << "Ingrese el dato a buscar: ";
                cin >> elemento;
                cout << "Posición: " << lista.buscar(elemento) << endl;
                break;
            case 2:
                cout << "Ingrese el dato a buscar: ";
                cin >> elemento;
                if (lista.buscar(elemento) != -1) {
                    cout << "El dato existe en la lista." << endl;
                } else {
                    cout << "El dato no existe en la lista." << endl;
                }
                break;
            case 3:
                cout << "Ingrese el dato a eliminar: ";
                cin >> elemento;
                lista.eliminar(elemento);
                cout << "Dato eliminado." << endl;
                break;
            case 4:
                int nuevoElemento;
                cout << "Ingrese el dato a buscar y cambiar: ";
                cin >> elemento;
                cout << "Ingrese el nuevo dato: ";
                cin >> nuevoElemento;
                lista.buscarYCambiar(elemento, nuevoElemento);
                cout << "Dato cambiado." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }

        cout << "Lista Circular: ";
        lista.imprimir();
    }

    return 0;
}

