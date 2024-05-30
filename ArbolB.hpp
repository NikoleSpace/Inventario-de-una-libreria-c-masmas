#ifndef __ARBOLB_HPP__
#define __ARBOLB_HPP__

template <class T>
class Nodo {
public:
    T elemento;
    Nodo* izq;
    Nodo* der;
};

template <class T>
class ArbolB {
    Nodo<T>* raiz;
    void(*procesar)(T); //Puntero a funcion

private:
    bool _insertar(Nodo<T>*& nodo, T e) {
        if (nodo == nullptr) {
            nodo = new Nodo<T>();
            nodo->elemento = e;
            nodo->izq = nodo->der = nullptr;
        }
        else if (e < nodo->elemento) {
            return _insertar(nodo->izq, e);
        }
        else if (e >= nodo->elemento) {
            return _insertar(nodo->der, e);
        }
        return true;
    }
    void _enOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        _enOrden(nodo->izq);
        procesar(nodo->elemento);
        _enOrden(nodo->der);
    }

    void _preOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        procesar(nodo->elemento);
        _preOrden(nodo->izq);
        _preOrden(nodo->der);
    }

    void _postOrden(Nodo<T>* nodo) {
        if (nodo == nullptr) return;
        _postOrden(nodo->izq);
        _postOrden(nodo->der);
        procesar(nodo->elemento);
    }
    bool _vacio() {
        return raiz == nullptr;
    }
    int _cantidad(Nodo<T>* nodo) {
        if (nodo == nullptr)
            return 0;
        else {
            int ci, cd;
            ci = _cantidad(nodo->izq);
            cd = _cantidad(nodo->der);
            return 1 + ci + cd;
        }
    }
    int _altura(Nodo<T>* nodo) {
        if (nodo == nullptr)
            return 0;
        else {
            int ai, ad;
            ai = 1 + _altura(nodo->izq);
            ad = 1 + _altura(nodo->der);
            return ai > ad ? ai : ad;
        }
    }

public:
    ArbolB(void(*otroPunteroAFuncion)(T)) {
        this->procesar = otroPunteroAFuncion;
        raiz = nullptr;
    }
    bool insertar(T e) {
        return _insertar(raiz, e);
    }
    void enOrden() {
        _enOrden(raiz);
    }
    void preOrden() {
        _preOrden(raiz);
    }
    void postOrden() {
        _postOrden(raiz);
    }
    int cantidad() {
        return _cantidad(raiz);
    }
    int altura() {
        return _altura(raiz);
    }
};

#endif


