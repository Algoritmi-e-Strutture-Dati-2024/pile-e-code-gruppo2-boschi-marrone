#include <iostream>
#include "ListaPuntatori.cpp" // Assicurati di includere la tua classe ListaPuntatori

template <typename T>
class Coda {
private:
ListaPuntatori<T> lista;

public:
// Aggiunge un elemento alla fine della coda
void enqueue(T elem) {
lista.inslista(elem, lista.lunghezza() + 1); // Aggiungi alla fine della lista
}

// Rimuove l'elemento in testa alla coda e lo restituisce
T dequeue() {
if (isEmpty()) {
std::cout << "Errore: coda vuota." << std::endl;
return T();
}
T frontElem = lista.leggilista(1); // Otteniamo l'elemento in testa
lista.canclista(1); // Rimuoviamo l'elemento in testa
return frontElem;
}

// Restituisce l'elemento in testa alla coda senza rimuoverlo
T front() {
if (isEmpty()) {
std::cout << "Errore: coda vuota." << std::endl;
return T();
}
return lista.leggilista(1); // L'elemento in testa è in posizione 1
}

// Restituisce true se la coda è vuota, altrimenti false
bool isEmpty() const {
return lista.listavuota();
}

// Restituisce il numero di elementi nella coda
int size() const {
return lista.lunghezza();
}
};


