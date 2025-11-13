#include <iostream>
#include <string>
#include "Vector.h"
#include "Cancion.h"
#include "DynarrayPEL.h"
#include "Titulo.h"

using namespace std;

// Prototipos de funciones para el menú
void cargarCancionesEjemplo(Vector<Cancion>& canciones);
void buscarCancionPorTitulo(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorAlbum(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorGrupo(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorGenero(const Vector<Cancion>& canciones, const string& input);
void mostrarTodasLasCanciones(const Vector<Cancion>& canciones);

// --- PROTOTIPO MENÚ ---
void menu(Vector<Cancion>& canciones, DynarrayPEL<Titulo>& titulos);

int main() {
    Vector<Cancion> canciones;
    DynarrayPEL titulos;

    cargarCancionesEjemplo(canciones);
    titulos.agregarTitulo(Titulo("Inception", "pelicula", "Sci-Fi", "UHD", true, true, 2.99f));
    titulos.agregarTitulo(Titulo("Breaking Bad", "serie", "Drama", "FHD", true, false, 0.0f));
    titulos.agregarTitulo(Titulo("Interstellar", "pelicula", "Sci-Fi", "FHD", true, false, 0.0f));
    titulos.agregarTitulo(Titulo("Friends", "serie", "Comedia", "FHD", true, false, 0.0f));
    titulos.agregarTitulo(Titulo("Avengers: Endgame", "pelicula", "Accion", "UHD", true, true, 2.99f));


    menu(canciones, titulos);

    return 0;
}

// Función para cargar canciones de ejemplo
void cargarCancionesEjemplo(Vector<Cancion>& canciones) {
    canciones.agregar(Cancion("Yesterday", "Help!", "The Beatles", "Rock"));
    canciones.agregar(Cancion("Thriller", "Thriller", "Michael Jackson", "Pop"));
    canciones.agregar(Cancion("Take Five", "Time Out", "The Dave Brubeck Quartet", "Jazz"));
    canciones.agregar(Cancion("Shape of You", "Divide", "Ed Sheeran", "Pop"));
    canciones.agregar(Cancion("Bohemian Rhapsody", "A Night at the Opera", "Queen", "Rock"));
}

void buscarCancionPorTitulo(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Cancion por Titulo: '" << input << "' ---" << endl;
    cout << "(Logica del modulo de musica no implementada)" << endl;
}
void buscarCancionPorAlbum(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Cancion por Album: '" << input << "' ---" << endl;
    cout << "(Logica del modulo de musica no implementada)" << endl;
}
void buscarCancionPorGrupo(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Cancion por Grupo: '" << input << "' ---" << endl;
    cout << "(Logica del modulo de musica no implementada)" << endl;
}
void buscarCancionPorGenero(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Cancion por Genero: '" << input << "' ---" << endl;
    cout << "(Logica del modulo de musica no implementada)" << endl;
}
void mostrarTodasLasCanciones(const Vector<Cancion>& canciones) {
    cout << "--- MOSTRANDO TODAS LAS CANCIONES ---" << endl;
    cout << "(Logica del modulo de musica no implementada)" << endl;
}


// Función del menú principal
void menu(Vector<Cancion>& canciones, DynarrayPEL& titulos) {
    int opcion = 0;
    do {
        cout << "------------------------------\n";
        cout << "     SISTEMA DE CATÁLOGO\n";
        cout << "------------------------------\n";
        cout << "1. Buscar canción por título\n";
        cout << "2. Buscar canción por álbum\n";
        cout << "3. Buscar canción por grupo\n";
        cout << "4. Buscar canción por género\n";
        cout << "5. Mostrar todas las canciones\n";
        cout << "6. Buscar película/serie por título\n";
        cout << "7. Buscar película/serie por género\n";
        cout << "8. Buscar película/serie por calidad\n";
        cout << "9. Mostrar todas las películas/series\n";
        cout << "10. Alquilar película/serie\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        string input;
        switch (opcion) {
            case 1:
                cout << "Ingrese el título o parte del título: ";
                getline(cin, input);
                canciones.buscarPorTitulo(input);
                break;
            case 2:
                cout << "Ingrese el álbum: ";
                getline(cin, input);
                canciones.buscarPorAlbum(input);
                break;
            case 3:
                cout << "Ingrese el grupo: ";
                getline(cin, input);
                canciones.buscarPorGrupo(input);
                break;
            case 4:
                cout << "Ingrese el género: ";
                getline(cin, input);
                canciones.buscarPorGenero(input);
                break;
            case 5:
                canciones.mostrarCanciones();
                break;
            case 6:
                cout << "Ingrese el nombre o parte del nombre: ";
                getline(cin, input);
                titulos.buscarPorTitulo(input);
                break;
            case 7:
                cout << "Ingrese el género: ";
                getline(cin, input);
                titulos.buscarPorGenero(input);
                break;
            case 8:
                cout << "Ingrese la calidad (FHD/UHD): ";
                getline(cin, input);
                titulos.buscarPorCalidad(input);
                break;
            case 9:
                titulos.mostrarTitulos();
                break;
            case 10:
                cout << "Ingrese el nombre del título a alquilar: ";
                getline(cin, input);
                titulos.alquilarTitulo(input);
                break;
            case 0:
                cout << "¡Adiós!\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo.\n";
        }
        cout << endl;
    } while (opcion != 0);
}