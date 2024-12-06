#include <iostream>
#include "Pila.cpp"
#include "Coda.cpp"

int main() {
// Test della Pila
std::cout << "Test Pila:" << std::endl;
Pila<int> pila;

pila.push(10);
pila.push(20);
pila.push(30);

std::cout << "Top della pila: " << pila.top() << std::endl; // Dovrebbe essere 30
std::cout << "Pop dalla pila: " << pila.pop() << std::endl; // Dovrebbe essere 30
std::cout << "Pop dalla pila: " << pila.pop() << std::endl; // Dovrebbe essere 20
std::cout << "Pop dalla pila: " << pila.pop() << std::endl; // Dovrebbe essere 10
std::cout << "La pila è vuota? " << (pila.isEmpty() ? "Sì" : "No") << std::endl; // Dovrebbe essere Sì

// Test della Coda
std::cout << "\nTest Coda:" << std::endl;
Coda<int> coda;

coda.enqueue(100);
coda.enqueue(200);
coda.enqueue(300);

std::cout << "Front della coda: " << coda.front() << std::endl; // Dovrebbe essere 100
std::cout << "Dequeue dalla coda: " << coda.dequeue() << std::endl; // Dovrebbe essere 100
std::cout << "Dequeue dalla coda: " << coda.dequeue() << std::endl; // Dovrebbe essere 200
std::cout << "Dequeue dalla coda: " << coda.dequeue() << std::endl; // Dovrebbe essere 300
std::cout << "La coda è vuota? " << (coda.isEmpty() ? "Sì" : "No") << std::endl; // Dovrebbe essere Sì

return 0;
}
