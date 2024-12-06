#include <iostream>
#include "Pila.cpp"
#include "Coda.cpp"

// Funzione per controllare se un carattere rappresenta una cifra
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Funzione per convertire manualmente una stringa `char*` in un numero double
double toDouble(const char* t) {
    double result = 0.0;
    double fraction = 0.0;
    int sign = 1;
    bool isFraction = false;
    double divisor = 10.0;

    // Controlla il segno
    if (*t == '-') {
        sign = -1;
        t++;
    }

    // Scorre la stringa per costruire il numero
    while (*t != '\0') {
        if (*t == '.') {
            isFraction = true; // Avvia la parte frazionaria
        } else if (isDigit(*t)) {
            if (isFraction) {
                fraction += (*t - '0') / divisor;
                divisor *= 10.0;
            } else {
                result = result * 10 + (*t - '0');
            }
        }
        t++;
    }

    return sign * (result + fraction);
}

// Funzione per verificare se una stringa rappresenta un numero
bool isNumber(const char* t) {
    if (t == nullptr || *t == '\0') return false;

    int i = 0;
    if (t[i] == '-') i++; // Salta il segno negativo, se presente

    bool hasDigits = false;
    while (t[i] != '\0') {
        if (isDigit(t[i])) {
            hasDigits = true;
        } else if (t[i] == '.' && hasDigits) {
            // Se trova un punto decimale, continua
            hasDigits = false; // Serve almeno una cifra dopo il punto
        } else {
            return false; // Qualsiasi altro carattere rende la stringa non valida
        }
        i++;
    }
    return hasDigits;
}

// Funzione per valutare un'espressione in notazione polacca postfissa
double valuta_polacca(Coda<char*>& post) {
    Pila<double> val; // Pila per i valori

    while (!post.isEmpty()) {
        char* t = post.dequeue(); // Legge l'elemento in testa alla coda

        if (isNumber(t)) {
            // Se `t` è un numero
            val.push(toDouble(t)); // Converte manualmente il numero e lo inserisce nella pila
        } else {
            // Se `t` è un operatore
            double numtop = val.pop(); // Primo valore dalla pila
            double numsuc = val.pop(); // Secondo valore dalla pila
            double ris = 0;

            if (*t == '+') {
                ris = numsuc + numtop;
            } else if (*t == '-') {
                ris = numsuc - numtop;
            } else if (*t == '*') {
                ris = numsuc * numtop;
            } else if (*t == '/') {
                if (numtop == 0) {
                    std::cerr << "Errore: Divisione per zero!" << std::endl;
                    return 0;
                }
                ris = numsuc / numtop;
            } else {
                std::cerr << "Errore: Operatore sconosciuto '" << t << "'" << std::endl;
                return 0;
            }

            val.push(ris); // Inserisce il risultato nella pila
        }
    }

    return val.pop(); // Ritorna il risultato finale
}

// Test della funzione nel main
int main() {
    Coda<char*> post; // Coda per l'espressione postfissa

    // Inseriamo un'espressione in notazione postfissa: "5 1 2 + 4 * + 3 -"
    post.enqueue(const_cast<char*>("5"));
    post.enqueue(const_cast<char*>("1"));
    post.enqueue(const_cast<char*>("2"));
    post.enqueue(const_cast<char*>("+"));
    post.enqueue(const_cast<char*>("4"));
    post.enqueue(const_cast<char*>("*"));
    post.enqueue(const_cast<char*>("+"));
    post.enqueue(const_cast<char*>("3"));
    post.enqueue(const_cast<char*>("-"));

    // Valutiamo l'espressione
    double risultato = valuta_polacca(post);

    // Stampa il risultato
    std::cout << "Risultato dell'espressione postfissa: " << risultato << std::endl;

    return 0;
}


