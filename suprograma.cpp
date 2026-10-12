#include <iostream>
#include <string>

using namespace std;

// Estructura del nodo: una letra por nodo
struct correo {
    char letra;
    correo* sig;
};

// SUBPROGRAMA SI-SI (Función booleana)

bool EVALUAR_CORREO(correo* cab) {
    // Si la lista está vacía o tiene menos de 4 nodos, no puede terminar en ".com"
    if (cab == nullptr) return false;

   
    correo* p1 = nullptr; // Antepenúltimo 
    correo* p2 = nullptr; // Penúltimo     
    correo* p3 = nullptr; // Último       
    correo* p4 = nullptr; // Actual        

    // Recorremos la lista desplazando los punteros paso a paso
    correo* aux = cab;
    while (aux != nullptr) {
        p1 = p2;
        p2 = p3;
        p3 = p4;
        p4 = aux;
        aux = aux->sig;
    }

    // Si p1 sigue siendo nullptr, la lista tiene menos de 4 elementos
    if (p1 == nullptr) return false;

    // Verificamos si los últimos 4 caracteres forman exactamente ".com"
    if (p1->letra == '.' && p2->letra == 'c' && 
        p3->letra == 'o' && p4->letra == 'm') {
        return true;
    }

    return false;
}

// FUNCIONES AUXILIARES PARA PRUEBAS
void insertarLetra(correo* &cab, char letra) {
    correo* nuevo = new correo();
    nuevo->letra = letra;
    nuevo->sig = nullptr;

    if (cab == nullptr) {
        cab = nuevo;
    } else {
        correo* aux = cab;
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

correo* crearListaDesdeString(string texto) {
    correo* cab = nullptr;
    for (char c : texto) {
        insertarLetra(cab, c);
    }
    return cab;
}

void imprimirLista(correo* cab) {
    correo* aux = cab;
    while (aux != nullptr) {
        cout << aux->letra;
        aux = aux->sig;
    }
    cout << endl;
}

int main() {
    // Caso 1: Correo que SÍ termina en .com -> Debe retornar TRUE
    correo* c1 = crearListaDesdeString("juan.perez@gmail.com");
    cout << "Correo: ";
    imprimirLista(c1);
    cout << "Resultado: " << (EVALUAR_CORREO(c1) ? "TRUE" : "FALSE") << endl << endl;

    // Caso 2: Correo que NO termina en .com (termina en .com.co) -> Debe retornar FALSE
    correo* c2 = crearListaDesdeString("maria@empresa.com.co");
    cout << "Correo: ";
    imprimirLista(c2);
    cout << "Resultado: " << (EVALUAR_CORREO(c2) ? "TRUE" : "FALSE") << endl << endl;

    // Caso 3: Correo corto -> Debe retornar FALSE
    correo* c3 = crearListaDesdeString("a@b");
    cout << "Correo: ";
    imprimirLista(c3);
    cout << "Resultado: " << (EVALUAR_CORREO(c3) ? "TRUE" : "FALSE") << endl << endl;

    return 0;
}