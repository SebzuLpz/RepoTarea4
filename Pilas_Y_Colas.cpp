#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Nodo {
    int valor;
    int prioridad;

    Nodo(int v, int p) : valor(v), prioridad(p) {}
};

bool operator<(const Nodo& a, const Nodo& b) {
    return a.prioridad > b.prioridad;
}

void agregarANQ(priority_queue<Nodo>& pq, int valor, int prioridad) {
    pq.push(Nodo(valor, prioridad));
    cout << "Nodo agregado: " << valor << " con prioridad " << prioridad << endl;
}

void agregarASP(stack<Nodo>& s, int valor, int prioridad) {
    s.push(Nodo(valor, prioridad));
    cout << "Nodo agregado: " << valor << " con prioridad " << prioridad << endl;
}

void eliminarDeNQ(priority_queue<Nodo>& pq) {
    if (pq.empty()) {
        cout << "Error: La cola de prioridad esta vacia." << endl;
        return;
    }
    cout << "Nodo eliminado: " << pq.top().valor << " con prioridad " << pq.top().prioridad << endl;
    pq.pop();
}

void eliminarDeSP(stack<Nodo>& s) {
    if (s.empty()) {
        cout << "Error: La pila esta vacia." << endl;
        return;
    }
    cout << "Nodo eliminado: " << s.top().valor << " con prioridad " << s.top().prioridad << endl;
    s.pop();
}

void mostrarNQ(priority_queue<Nodo>& pq) {
    if (pq.empty()) {
        cout << "Error: La cola de prioridad esta vacia." << endl;
        return;
}
    cout << "Cola de prioridad: ";
    while (!pq.empty()) {
        cout << "(" << pq.top().valor << ", " << pq.top().prioridad << ") ";
        pq.pop();
    }
    cout << endl;
}

void mostrarSP(stack<Nodo>& s) {
    if (s.empty()) {
        cout << "Error: La pila esta vacia." << endl;
        return;
    }
    cout << "Pila con prioridad: ";
    while (!s.empty()) {
        cout << "(" << s.top().valor << ", " << s.top().prioridad << ") ";
        s.pop();
    }
    cout << endl;
}

int main() {
    priority_queue<Nodo> colaDePrioridad;
    stack<Nodo> pilaConPrioridad;

    int opcion, valor, prioridad;

    while (true) {
        cout << "--- MENU ---\n";
        cout << "1. Agregar nodo a la cola de prioridad\n";
        cout << "2. Agregar nodo a la pila con prioridad\n";
        cout << "3. Eliminar nodo de la cola de prioridad\n";
        cout << "4. Eliminar nodo de la pila con prioridad\n";
        cout << "5. Mostrar cola de prioridad\n";
        cout << "6. Mostrar pila con prioridad\n";
        cout << "7. Salir\n";
        cout << "--- ---- ---\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresa el valor: ";
                cin >> valor;
                cout << "Ingresa la prioridad: ";
                cin >> prioridad;
                agregarANQ(colaDePrioridad, valor, prioridad);
                break;
            case 2:cout << "Ingresa el valor: ";
                cin >> valor;
                cout << "Ingresa la prioridad: ";
                cin >> prioridad;
                agregarASP(pilaConPrioridad, valor, prioridad);
                break;
            case 3:
                eliminarDeNQ(colaDePrioridad);
                break;
            case 4:
                eliminarDeSP(pilaConPrioridad);
                break;
            case 5:
                mostrarNQ(colaDePrioridad);
                break;
            case 6:
                mostrarSP(pilaConPrioridad);
                break;
            case 7:
                cout << "iHasta luego!\n";
                return 0;
            default:
                cout << "Opcion invalida\n";
        }
    }

    return 0;
}