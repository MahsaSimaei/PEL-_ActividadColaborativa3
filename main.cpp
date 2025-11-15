#include <iostream>
#include <string>
#include "Vector.h"
#include "Cancion.h"
#include "Dynarray.h"
#include "Titulo.h"

using namespace std;

// Prototipos de funciones para el menú
void cargarCancionesEjemplo(Vector<Cancion>& canciones);
void buscarCancionPorTitulo(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorAlbum(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorGrupo(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorGenero(const Vector<Cancion>& canciones, const string& input);
void mostrarTodasLasCanciones(const Vector<Cancion>& canciones);

// --- Prototipos MÓDULO TÍTULOS (Tu Lógica en Funciones Helper) ---
void cargarTitulosEjemplo(Dynarray<Titulo>& titulos);
void buscarTituloPorNombre(const Dynarray<Titulo>& titulos, const string& input);
void buscarTituloPorGenero(const Dynarray<Titulo>& titulos, const string& input);
void buscarTituloPorCalidad(const Dynarray<Titulo>& titulos, const string& input);
void mostrarTitulos(const Dynarray<Titulo>& titulos);
void alquilarTitulo(Dynarray<Titulo>& titulos, const string& input); // No-const, porque modifica

// --- PROTOTIPO MENÚ ---
void menu(Vector<Cancion>& canciones, Dynarray<Titulo>& titulos);

int main() {
    Vector<Cancion> canciones;
    Dynarray<Titulo> titulos;

    cargarCancionesEjemplo(canciones);
    cargarTitulosEjemplo(titulos);

    menu(canciones, titulos);

    return 0;
}

// Función para cargar canciones de ejemplo
void cargarCancionesEjemplo(Vector<Cancion>& canciones) {
    canciones.push_back(Cancion("Yesterday", "Help!", "The Beatles", "Rock"));
    canciones.push_back(Cancion("Thriller", "Thriller", "Michael Jackson", "Pop"));
    canciones.push_back(Cancion("Take Five", "Time Out", "The Dave Brubeck Quartet", "Jazz"));
    canciones.push_back(Cancion("Shape of You", "Divide", "Ed Sheeran", "Pop"));
    canciones.push_back(Cancion("Bohemian Rhapsody", "A Night at the Opera", "Queen", "Rock"));
}

void buscarCancionPorTitulo(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Canción por Título: '" << input << "' ---" << endl;
    bool encontrado = false;
    // Usamos size() y operator[] de Vector<T>
    for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
        const Cancion& c = canciones[i];
        if (c.getTitulo().find(input) != string::npos) { // búsqueda por subcadena como buscarTituloPorNombre
            c.toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron canciones con ese título o parte del título." << endl;
    }
    cout << "---------------------------------" << endl;
}

void buscarCancionPorAlbum(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Canción por Álbum: '" << input << "' ---" << endl;
    bool encontrado = false;
    // Basado en buscarTituloPorGenero (comparación exacta) se usa igualdad,
    // pero se puede cambiar a find() si prefieres búsqueda parcial.
    for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
        const Cancion& c = canciones[i];
        if (c.getAlbum() == input) {
            c.toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron canciones de ese álbum." << endl;
    }
    cout << "---------------------------------" << endl;
}

void buscarCancionPorGrupo(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Canción por Grupo: '" << input << "' ---" << endl;
    bool encontrado = false;
    for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
        const Cancion& c = canciones[i];
        if (c.getGrupo() == input) {
            c.toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron canciones de ese grupo." << endl;
    }
    cout << "---------------------------------" << endl;
}

void buscarCancionPorGenero(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Canción por Género: '" << input << "' ---" << endl;
    bool encontrado = false;
    for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
        const Cancion& c = canciones[i];
        if (c.getGenero() == input) {
            c.toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron canciones de ese género." << endl;
    }
    cout << "---------------------------------" << endl;
}

void mostrarTodasLasCanciones(const Vector<Cancion>& canciones) {
    cout << "--- MOSTRANDO TODAS LAS CANCIONES ---" << endl;
    if (canciones.size() == 0) {
        cout << "No hay canciones cargadas." << endl;
    } else {
        for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
            cout << "---------------------------------" << endl;
            canciones[i].toString();
        }
    }
    cout << "---------------------------------" << endl;
}

// Función para cargar títulos de películas/series de ejemplo
void cargarTitulosEjemplo(Dynarray<Titulo>& titulos) {
    // Usamos 'push_back'
    titulos.push_back(Titulo("Inception", "pelicula", "Sci-Fi", "UHD", true, true, 2.99f));
    titulos.push_back(Titulo("Breaking Bad", "serie", "Drama", "FHD", true, false, 0.0f));
    titulos.push_back(Titulo("Interstellar", "pelicula", "Sci-Fi", "FHD", true, false, 0.0f));
    titulos.push_back(Titulo("Friends", "serie", "Comedia", "FHD", true, false, 0.0f));
    titulos.push_back(Titulo("Avengers: Endgame", "pelicula", "Accion", "UHD", true, true, 2.99f));
}

void buscarTituloPorNombre(const Dynarray<Titulo>& titulos, const string& input) {
    cout << "--- Buscando por Titulo: '" << input << "' ---" << endl;
    bool encontrado = false;
    // Usamos 'get_size()' y 'operator[]' del Dynarray genérico
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        if (titulos[i].getNombre().find(input) != string::npos) {
            cout << titulos[i].toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron titulos con ese nombre." << endl;
    }
    cout << "---------------------------------" << endl;
}

void buscarTituloPorGenero(const Dynarray<Titulo>& titulos, const string& input) {
    cout << "--- Buscando por Genero: '" << input << "' ---" << endl;
    bool encontrado = false;
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        if (titulos[i].getGenero() == input) {
            cout << titulos[i].toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron titulos de ese genero." << endl;
    }
    cout << "---------------------------------" << endl;
}

void buscarTituloPorCalidad(const Dynarray<Titulo>& titulos, const string& input) {
    cout << "--- Buscando por Calidad: '" << input << "' ---" << endl;
    bool encontrado = false;
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        if (titulos[i].getCalidad() == input) {
            cout << titulos[i].toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron titulos con esa calidad." << endl;
    }
    cout << "---------------------------------" << endl;
}

void mostrarTitulos(const Dynarray<Titulo>& titulos) {
    cout << "--- MOSTRANDO CATALOGO COMPLETO ---" << endl;
    if (titulos.get_size() == 0) {
        cout << "El catalogo esta vacio." << endl;
    }
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        cout << "---------------------------------" << endl;
        cout << titulos[i].toString();
    }
    cout << "---------------------------------" << endl;
}

void alquilarTitulo(Dynarray<Titulo>& titulos, const string& input) {
    cout << ">>> Intentando alquilar '" << input << "'..." << endl;
    bool encontrado = false;
    // Usamos 'operator[]' para obtener una REFERENCIA y poder modificar
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        if (titulos[i].getNombre() == input) {
            encontrado = true;
            if (titulos[i].isDisponible()) {
                titulos[i].setDisponibilidad(false); // ¡Modificado!
                cout << "  [EXITO] Titulo '" << input << "' alquilado correctamente." << endl;
                if (titulos[i].isRequierePagoExtra()) {
                    cout << "  [AVISO] Este titulo requiere un pago extra de "
                              << titulos[i].getPrecioAlquiler() << endl;
                }
            } else {
                cout << "  [ERROR] El titulo '" << input << "' se encontro, pero no esta disponible." << endl;
            }
            break; // Salimos del bucle
        }
    }
    if (!encontrado) {
        cout << "  [ERROR] El titulo '" << input << "' no se encontro en el catalogo." << endl;
    }
}


// Función del menú principal
void menu(Vector<Cancion>& canciones, Dynarray<Titulo>& titulos) {
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
                buscarCancionPorTitulo(canciones, input);
                break;
            case 2:
                cout << "Ingrese el álbum: ";
                getline(cin, input);
                buscarCancionPorAlbum(canciones, input);
                break;
            case 3:
                cout << "Ingrese el grupo: ";
                getline(cin, input);
                buscarCancionPorGrupo(canciones, input);
                break;
            case 4:
                cout << "Ingrese el género: ";
                getline(cin, input);
                buscarCancionPorGenero(canciones, input);
                break;
            case 5:
                mostrarTodasLasCanciones(canciones);
                break;
            case 6:
                cout << "Ingrese el nombre o parte del nombre: ";
                getline(cin, input);
                buscarTituloPorNombre(titulos, input);
                break;
            case 7:
                cout << "Ingrese el género: ";
                getline(cin, input);
                buscarTituloPorGenero(titulos, input);
                break;
            case 8:
                cout << "Ingrese la calidad (FHD/UHD): ";
                getline(cin, input);
                buscarTituloPorCalidad(titulos, input);
                break;
            case 9:
                mostrarTitulos(titulos);
                break;
            case 10:
                cout << "Ingrese el nombre del título a alquilar: ";
                getline(cin, input);
                alquilarTitulo(titulos, input);
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