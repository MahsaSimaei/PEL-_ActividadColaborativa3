//
// Created by Medias on 10/11/2025.
//

#ifndef VECTOR_H
#define VECTOR_H

// Clase Vector para almacenar elementos de tipo T en un arreglo dinámico.

// Definición de la clase plantilla (genérica).
template <typename T>
class Vector {
private:
    T* v_;        // Puntero al inicio del bloque de memoria reservado.
    T* space_;    // Puntero al siguiente espacio disponible (fin de los elementos válidos).
    T* last_;     // Puntero al final del bloque de memoria reservado (capacidad total).

    // Función privada para comprobar si el índice está dentro del rango válido.
    // Si no lo está, imprime un error y termina el programa.
    void bounds_check(int i) const {
        if (i >= size()) {
            throw std::out_of_range("Índice fuera de rango");
        }
    }

public:
    // Constructor por defecto: vector vacío (sin memoria reservada).
    Vector() {
        v_=space_=last_=nullptr;

    }
    // Constructor de copia: crea una copia exacta de otro vector.
    Vector(const Vector<T>& v)
        : v_(nullptr), space_(nullptr), last_(nullptr) {
        int cp = v.capacity(); // Capacidad del vector original.
        if (cp > 0) {
            v_ = new T[cp]; // Reservamos memoria suficiente.
            // Copiamos los elementos existentes.
            for (int i = 0; i < v.size(); ++i)
                v_[i] = v.v_[i];
            space_ = v_ + v.size(); // Apunta luego del último elemento copiado.
            last_  = v_ + cp;       // Apunta al final del bloque reservado.
        }
    }

    // Operador de asignación: copia los datos de otro vector a este.
    Vector& operator=(const Vector<T>& rhs) {
        if (this != &rhs) { // Evita auto-asignación.
            T* aux_v = nullptr;
            T* aux_space = nullptr;
            T* aux_last = nullptr;
             int cp = rhs.capacity();
            if (cp > 0) {
                aux_v = new T[cp]; // Reserva memoria.
                for ( int i = 0; i < rhs.size(); ++i)
                    aux_v[i] = rhs.v_[i]; // Copia elementos.
                aux_space = aux_v + rhs.size();
                aux_last = aux_v + cp;
            }
            delete[] v_; // Libera memoria antigua.
            v_ = aux_v;
            space_ = aux_space;
            last_ = aux_last;
        }
        return *this;
    }

    // Destructor: libera la memoria reservada al destruir el vector.
    ~Vector() { delete[] v_; }

    // Función que devuelve cuántos elementos hay actualmente en el vector.
     int size() const { return (int)(space_ - v_); }

    // Función que devuelve la capacidad total del vector (cuántos elementos caben sin redimensionar).
     int capacity() const { return (int)(last_ - v_); }

    // Función que indica si el vector está vacío (sin elementos).
    bool empty() const { return v_ == space_; }

    // Operador []: acceso rápido (sin comprobación de rango) a los elementos.
    T& operator[](int i) { return v_[i]; }
    const T& operator[](int i) const { return v_[i]; }

    // Método at: acceso seguro (con comprobación de rango) a los elementos.
    T& at(int i) { bounds_check(i); return v_[i]; }
    const T& at(int i) const { bounds_check(i); return v_[i]; }

    // Funciones tipo "iterador": devuelven punteros al principio y al final de los datos válidos.
    T* begin() { return v_; }
    const T* begin() const { return v_; }
    T* end() { return space_; }
    const T* end() const { return space_; }

    // Agrega un elemento al final del vector. Redimensiona si no hay espacio.
    void push_back(const T& val) {
        if (space_ == last_) {
            // No hay espacio: hay que reservar más memoria.
            int cp = capacity(); // Capacidad actual.
            int new_cp = (cp == 0) ? 2 : 2 * cp; // Duplicamos o asignamos 2 si está vacío.
            T* new_block = new T[new_cp]; // Reservamos nuevo bloque.
            // Copiamos los elementos existentes al nuevo bloque.
            for (int i = 0; i < cp; ++i)
                new_block[i] = v_[i];
            new_block[cp] = val; // Añadimos el nuevo elemento.
            delete[] v_; // Liberamos memoria antigua.
            v_ = new_block;
            space_ = new_block + cp + 1; // Actualizamos puntero de fin de datos.
            last_ = new_block + new_cp;  // Actualizamos puntero de capacidad.
        } else {
            // Hay espacio disponible, sólo agregamos.
            *space_ = val;
            ++space_; // Avanzamos puntero de fin de datos.
        }
    }
    // Elimina el último elemento si el vector no está vacío.
    void pop_back() {
        if (empty()) throw std::out_of_range("pop_back() en un array vacío");
        --size; // o --space_; según la clase
    }

    // Elimina el elemento en el índice index.
    void remove_at(int index) {
        bounds_check(index);
        for (int i = index; i < size() - 1; ++i)
            v_[i] = v_[i+1];
        --space_;
    }

    // Busca el vector, devuelve índice o -1 si no está.
    int find(const T& value) const {
        for (int i = 0; i < size(); ++i)
            if (v_[i] == value) return i;
        return -1;
    }

    //  Inserta valor en la posición dada, desplazando el resto.
    void insert(int pos, const T& value) {
        if (pos < 0 || pos > size()) throw std::out_of_range("Índice fuera de rango");
        if (space_ == last_) {
            int cp = capacity();
            int new_cp = (cp == 0) ? 2 : 2 * cp;
            T* new_block = new T[new_cp];
            // copy elements up to pos
            for(int i=0;i<pos;++i) new_block[i]=v_[i];
            new_block[pos]=value;
            for(int i=pos;i<size();++i) new_block[i+1]=v_[i];
            delete[] v_;
            v_=new_block;
            space_=new_block+size()+1;
            last_=new_block+new_cp;
        } else {
            for(int i=size();i>pos;--i)
                v_[i]=v_[i-1];
            v_[pos]=value;
            ++space_;
        }
    }
};
#endif //VECTOR_H
