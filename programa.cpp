#include <iostream>

using namespace std;

// Estructura del nodo: contiene un número entero
struct serie {
    int dato;
    serie* sig;
};

// SUBPROGRAMA SI-NO (Procedimiento)

void EVALUAR_NUMEROS(serie* cab, int Z) {
    // Validación: si Z es 0, no se puede dividir por cero
    if (Z == 0) {
        cout << "Error: Z no puede ser 0 (division por cero)." << endl;
        return;
    }

    int contador = 0;
    serie* aux = cab;

    // Recorremos la lista para contar los múltiplos
    while (aux != nullptr) {
        if (aux->dato % Z == 0) {
            contador++;
        }
        aux = aux->sig;
    }

    // Imprimimos el resultado directamente (característica de los procedimientos SI-NO)
    cout << "Cantidad de numeros multiplos de " << Z << ": " << contador << endl;
}

// FUNCIONES AUXILIARES PARA PRUEBAS
void insertarNumero(serie* &cab, int valor) {
    serie* nuevo = new serie();
    nuevo->dato = valor;
    nuevo->sig = nullptr;

    if (cab == nullptr) {
        cab = nuevo;
    } else {
        serie* aux = cab;
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void imprimirLista(serie* cab) {
    serie* aux = cab;
    cout << "[ ";
    while (aux != nullptr) {
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << "]" << endl;
}

int main() {
    serie* lista1 = nullptr;
    insertarNumero(lista1, 10);
    insertarNumero(lista1, 3);
    insertarNumero(lista1, 25);
    insertarNumero(lista1, 7);
    insertarNumero(lista1, 50);

    cout << "Lista 1: ";
    imprimirLista(lista1);
    EVALUAR_NUMEROS(lista1, 5); // Debe contar 3 múltiplos (10, 25, 50)

    return 0;
}