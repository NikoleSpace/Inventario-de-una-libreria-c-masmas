#include "ArbolB.hpp"
#include <iostream>
#include <string>
using namespace std;

void mostrarLibro(string libro) {
    cout << libro << endl;
}

int main() {
    ArbolB<string> inventario(mostrarLibro);

    // Insertar libros en el inventario
    inventario.insertar("El Principito");
    inventario.insertar("Cien Años de Soledad");
    inventario.insertar("Don Quijote");
    inventario.insertar("La Odisea");
    inventario.insertar("Matar a un Ruiseñor");

    // Mostrar libros en orden alfabético
    cout << "Libros en orden alfabético:" << endl;
    inventario.enOrden();

    // Mostrar libros en preorden
    cout << "\nLibros en preorden:" << endl;
    inventario.preOrden();

    // Mostrar libros en postorden
    cout << "\nLibros en postorden:" << endl;
    inventario.postOrden();

    // Contar cantidad de libros
    cout << "\nCantidad de libros en el inventario: " << inventario.cantidad() << endl;

    // Determinar la altura del árbol
    cout << "Altura del árbol: " << inventario.altura() << endl;

    return 0;
}