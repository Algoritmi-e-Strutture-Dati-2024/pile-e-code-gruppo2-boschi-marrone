1.
#include <iostream>
#include "ListaPuntatori.cpp" // Assicurati di includere la tua classe ListaPuntatori

template <typename T>
class Pila {
private:
ListaPuntatori<T> lista;

public:
// Aggiunge un elemento alla pila
void push(T elem) {
lista.inslista(elem, 1); // Inserisce in testa, quindi l'elemento viene messo in cima alla pila
}

// Rimuove l'elemento in cima alla pila e lo restituisce
T pop() {
if (isEmpty()) {
std::cout << "Errore: pila vuota." << std::endl;
return T();
}
T topElem = lista.leggilista(1); // Otteniamo l'elemento in cima
lista.canclista(1); // Rimuoviamo l'elemento in cima
return topElem;
}

// Restituisce l'elemento in cima alla pila senza rimuoverlo
T top() {
if (isEmpty()) {
std::cout << "Errore: pila vuota." << std::endl;
return T();
}
return lista.leggilista(1); // L'elemento in cima è in posizione 1
}

// Restituisce true se la pila è vuota, altrimenti false
bool isEmpty() const {
return lista.listavuota();
}

// Restituisce il numero di elementi nella pila
int size() const {
return lista.lunghezza();
}
};


