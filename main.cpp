#include <iostream>
#include <string>
#include <algorithm>  // Para transform, tolower
#include "Vector.h"
#include "Cancion.h"
#include "Dynarray.h"
#include "Titulo.h"

using namespace std;

// === FUNCIONES AUXILIARES ===
std::string capitalizarPrimeraLetra(const std::string& texto) {
    if (texto.empty()) return texto;
    std::string resultado = texto;
    std::transform(resultado.begin(), resultado.end(), resultado.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    resultado[0] = std::toupper(resultado[0]);
    return resultado;
}
std::string toLower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

// Prototipos de funciones para el menu
void cargarCancionesEjemplo(Vector<Cancion>& canciones);
void buscarCancionPorTitulo(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorAlbum(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorGrupo(const Vector<Cancion>& canciones, const string& input);
void buscarCancionPorGenero(const Vector<Cancion>& canciones, const string& input);
void mostrarTodasLasCanciones(const Vector<Cancion>& canciones);

// --- Prototipos MODULO TITULOS (Tu Logica en Funciones Helper) ---
void cargarTitulosEjemplo(Dynarray<Titulo>& titulos);
void buscarTituloPorNombre(const Dynarray<Titulo>& titulos, const string& input);
void buscarTituloPorGenero(const Dynarray<Titulo>& titulos, const string& input);
void buscarTituloPorCalidad(const Dynarray<Titulo>& titulos, const string& input);
void mostrarTitulos(const Dynarray<Titulo>& titulos);
void alquilarTitulo(Dynarray<Titulo>& titulos, const string& input); // No-const, porque modifica

// --- PROTOTIPO MENU ---
void menu(Vector<Cancion>& canciones, Dynarray<Titulo>& titulos);

int main() {
    Vector<Cancion> canciones;
    Dynarray<Titulo> titulos;

    cargarCancionesEjemplo(canciones);
    cargarTitulosEjemplo(titulos);

    menu(canciones, titulos);

    return 0;
}

// Funcion para cargar canciones de ejemplo
void cargarCancionesEjemplo(Vector<Cancion>& canciones) {
    canciones.push_back(Cancion("Yesterday", "Help!", "The Beatles", "Rock"));
    canciones.push_back(Cancion("Thriller", "Thriller", "Michael Jackson", "Pop"));
    canciones.push_back(Cancion("Take Five", "Time Out", "The Dave Brubeck Quartet", "Jazz"));
    canciones.push_back(Cancion("Shape of You", "Divide", "Ed Sheeran", "Pop"));
    canciones.push_back(Cancion("Bohemian Rhapsody", "A Night at the Opera", "Queen", "Rock"));
}

void buscarCancionPorTitulo(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Cancion por Titulo: '" << input << "' ---" << endl;
    bool encontrado = false;
    std::string inputLower = toLower(input);
    for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
        const Cancion& c = canciones[i];
        if (toLower(c.getTitulo()).find(inputLower) != string::npos) {
            c.toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron canciones con ese titulo o parte del titulo." << endl;
    }
    cout << "---------------------------------" << endl;
}

void buscarCancionPorAlbum(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Cancion por Album: '" << input << "' ---" << endl;
    bool encontrado = false;
    string inputNormal = capitalizarPrimeraLetra(input);
    for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
        const Cancion& c = canciones[i];
        if (c.getAlbum() == inputNormal) {
            c.toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron canciones de ese album." << endl;
    }
    cout << "---------------------------------" << endl;
}

void buscarCancionPorGrupo(const Vector<Cancion>& canciones, const string& input) {
    cout << "--- Buscando Cancion por Grupo: '" << input << "' ---" << endl;
    bool encontrado = false;
    string inputNormal = capitalizarPrimeraLetra(input);
    for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
        const Cancion& c = canciones[i];
        if (c.getGrupo() == inputNormal) {
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
    cout << "--- Buscando Cancion por Genero: '" << input << "' ---" << endl;
    bool encontrado = false;
    string inputNormal = capitalizarPrimeraLetra(input);
    for (size_t i = 0; i < static_cast<size_t>(canciones.size()); ++i) {
        const Cancion& c = canciones[i];
        if (c.getGenero() == inputNormal) {
            c.toString();
            encontrado = true;
        }
    }
    if (!encontrado) {
        cout << "No se encontraron canciones de ese genero." << endl;
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

// Funcion para cargar titulos de peliculas/series de ejemplo
void cargarTitulosEjemplo(Dynarray<Titulo>& titulos) {
    titulos.push_back(Titulo("Inception", "pelicula", "Sci-Fi", "UHD", true, true, 2.99f));
    titulos.push_back(Titulo("Breaking Bad", "serie", "Drama", "FHD", true, false, 0.0f));
    titulos.push_back(Titulo("Interstellar", "pelicula", "Sci-Fi", "FHD", true, false, 0.0f));
    titulos.push_back(Titulo("Friends", "serie", "Comedia", "FHD", true, false, 0.0f));
    titulos.push_back(Titulo("Avengers: Endgame", "pelicula", "Accion", "UHD", true, true, 2.99f));
}

void buscarTituloPorNombre(const Dynarray<Titulo>& titulos, const string& input) {
    cout << "--- Buscando por Titulo: '" << input << "' ---" << endl;
    bool encontrado = false;
    std::string inputLower = toLower(input);
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        if (toLower(titulos[i].getNombre()).find(inputLower) != string::npos) {
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
    string inputNormal = capitalizarPrimeraLetra(input);
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        if (titulos[i].getGenero() == inputNormal) {
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
    string inputNormal = capitalizarPrimeraLetra(input);
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        if (titulos[i].getCalidad() == inputNormal) {
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
    string inputNormal = capitalizarPrimeraLetra(input);
    for (size_t i = 0; i < titulos.get_size(); ++i) {
        if (titulos[i].getNombre() == inputNormal) {
            encontrado = true;
            if (titulos[i].isDisponible()) {
                titulos[i].setDisponibilidad(false);
                cout << "  [EXITO] Titulo '" << input << "' alquilado correctamente." << endl;
                if (titulos[i].isRequierePagoExtra()) {
                    cout << "  [AVISO] Este titulo requiere un pago extra de "
                             << titulos[i].getPrecioAlquiler() << endl;
                }
            } else {
                cout << "  [ERROR] El titulo '" << input << "' se encontro, pero no esta disponible." << endl;
            }
            break;
        }
    }
    if (!encontrado) {
        cout << "  [ERROR] El titulo '" << input << "' no se encontro en el catalogo." << endl;
    }
}

// Funcion del menu principal
void menu(Vector<Cancion>& canciones, Dynarray<Titulo>& titulos) {
    int opcion = -1;
    do {
        cout << "------------------------------\n";
        cout << "      SISTEMA DE CATALOGO\n";
        cout << "------------------------------\n";
        cout << "1. Buscar cancion por titulo\n";
        cout << "2. Buscar cancion por album\n";
        cout << "3. Buscar cancion por grupo\n";
        cout << "4. Buscar cancion por genero\n";
        cout << "5. Mostrar todas las canciones\n";
        cout << "6. Buscar pelicula/serie por titulo\n";
        cout << "7. Buscar pelicula/serie por genero\n";
        cout << "8. Buscar pelicula/serie por calidad\n";
        cout << "9. Mostrar todas las peliculas/series\n";
        cout << "10. Alquilar pelicula/serie\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Entrada no valida. Por favor, ingrese SOLO el numero de la opcion.\n\n";
            opcion = -1;  // Aseguramos que no sea 0
            continue;
        }
        cin.ignore(10000, '\n');

        string input;
        switch (opcion) {
            case 1:
                cout << "Ingrese el titulo o parte del titulo: ";
                getline(cin, input);
                buscarCancionPorTitulo(canciones, input);
                break;
            case 2:
                cout << "Ingrese el album: ";
                getline(cin, input);
                buscarCancionPorAlbum(canciones, input);
                break;
            case 3:
                cout << "Ingrese el grupo: ";
                getline(cin, input);
                buscarCancionPorGrupo(canciones, input);
                break;
            case 4:
                cout << "Ingrese el genero: ";
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
                cout << "Ingrese el genero: ";
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
                cout << "Ingrese el nombre del titulo a alquilar: ";
                getline(cin, input);
                alquilarTitulo(titulos, input);
                break;
            case 0:
                cout << "¡Adios!\n";
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
        cout << endl;
    } while (opcion != 0);
}