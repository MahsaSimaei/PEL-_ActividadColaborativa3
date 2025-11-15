#ifndef PEL__ACTIVIDADCOLABORATIVA3_CANCION_H
#define PEL__ACTIVIDADCOLABORATIVA3_CANCION_H
#include <string>
#include "Vector.h"

class Cancion {
private:
    std::string titulo;
    std::string album;
    std::string grupo;
    std::string genero;

    Vector<std::string> canciones;

public:
    // Constructores
    Cancion() : titulo(""), album(""), grupo(""), genero("") {}
    Cancion(std::string titulo, std::string album, std::string grupo, std::string genero)
        : titulo(std::move(titulo)), album(std::move(album)), grupo(std::move(grupo)), genero(std::move(genero)) {}

    // Método para agregar canciones
    void agregar(const std::string& cancion) {
        canciones.push_back(cancion);
    }

    // Método para ver si hay canción
    bool existe(const std::string &cancion) const {
        for (int i = 0; i < canciones.size(); i++) {
            if (canciones.at(i) == cancion) {
                return true;
            }
        }
        return false;
    }

    // Getters (marcados como const para poder usarlos sobre objetos const)
    std::string getTitulo() const {
        return titulo;
    }
    std::string getAlbum() const {
        return album;
    }
    std::string getGrupo() const {
        return grupo;
    }
    std::string getGenero() const {
        return genero;
    }

    // To String (const para poder llamarlo sobre referencias const)
    void toString() const {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "🎵📀 " << titulo << " 📀🎵" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << " Album:   " << album << std::endl;
        std::cout << " Grupo:    " << grupo << std::endl;
        std::cout << " Género:   " << genero << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "🎧 Lista de canciones:" << std::endl;

        for (std::size_t i = 0; i < static_cast<std::size_t>(canciones.size()); i++) {
            std::cout << "   🎶 #" << i + 1 << " - " << canciones.at(static_cast<int>(i)) << std::endl;
        }

        std::cout << "------------------------------------" << std::endl;
    }
};

#endif //PEL__ACTIVIDADCOLABORATIVA3_CANCION_H