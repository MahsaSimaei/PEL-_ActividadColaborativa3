//
// Created by Carmen Bolaños Villarejo on 13/11/25.
//
#include "Dynarray.h" // Incluye el trabajo de tu compañera
#include "Titulo.h"   // Incluye tu clase Titulo
#include <string>
#include <iostream>

/**
 * @class DynarrayPEL
 * @brief Contenedor ESPECIALIZADO para Títulos.
 *
 * Esta clase HEREDA de la plantilla genérica Dynarray<T>
 *
 * Se especializa para que SOLO pueda contener Títulos.
 */
class DynarrayPEL : public Dynarray<Titulo> {

public:
    // El constructor por defecto de Dynarray<Titulo> se llama automáticamente.

    // --- MÉTODOS DE LÓGICA  ---

    /**
     * Simplemente llama al 'push_back' de la clase base.
     */
    void agregarTitulo(const Titulo& t) {
        // 'push_back' es un método heredado de Dynarray
        this->push_back(t);
    }

    /**
      Busca títulos por nombre y muestra los resultados.
     */
    void buscarPorTitulo(const std::string& nombre) const {
        std::cout << "--- Buscando por Titulo: '" << nombre << "' ---" << std::endl;
        bool encontrado = false;
        // 'get_size()' y 'operator[]' son métodos heredados de Dynarray
        for (size_t i = 0; i < this->get_size(); ++i) {
            if ((*this)[i].getNombre().find(nombre) != std::string::npos) {
                std::cout << (*this)[i].toString();
                encontrado = true;
            }
        }
        if (!encontrado) {
            std::cout << "No se encontraron titulos con ese nombre." << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }

    /**
     Busca títulos por género y muestra los resultados.
     */
    void buscarPorGenero(const std::string& genero) const {
        std::cout << "--- Buscando por Genero: '" << genero << "' ---" << std::endl;
        bool encontrado = false;
        for (size_t i = 0; i < this->get_size(); ++i) {
            if ((*this)[i].getGenero() == genero) {
                std::cout << (*this)[i].toString();
                encontrado = true;
            }
        }
        if (!encontrado) {
            std::cout << "No se encontraron titulos de ese genero." << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }

    /**
      Busca títulos por calidad (FHD/UHD) y muestra los resultados.
     */
    void buscarPorCalidad(const std::string& calidad) const {
        std::cout << "--- Buscando por Calidad: '" << calidad << "' ---" << std::endl;
        bool encontrado = false;
        for (size_t i = 0; i < this->get_size(); ++i) {
            if ((*this)[i].getCalidad() == calidad) {
                std::cout << (*this)[i].toString();
                encontrado = true;
            }
        }
        if (!encontrado) {
            std::cout << "No se encontraron titulos con esa calidad." << std::endl;
        }
        std::cout << "---------------------------------" << std::endl;
    }

    /**
      Muestra todos los títulos del catálogo (disponibles o no).
     */
    void mostrarTitulos() const {
        std::cout << "--- MOSTRANDO CATALOGO COMPLETO ---" << std::endl;
        if (this->get_size() == 0) {
            std::cout << "El catalogo esta vacio." << std::endl;
        }
        for (size_t i = 0; i < this->get_size(); ++i) {
            std::cout << "---------------------------------" << std::endl;
            std::cout << (*this)[i].toString();
        }
        std::cout << "---------------------------------" << std::endl;
    }

    /**
      Procesa el alquiler de un título.
     */
    void alquilarTitulo(const std::string& nombre) {
        std::cout << ">>> Intentando alquilar '" << nombre << "'..." << std::endl;
        bool encontrado = false;
        // 'operator[]' (no-const) nos da una referencia para modificar
        for (size_t i = 0; i < this->get_size(); ++i) {
            if ((*this)[i].getNombre() == nombre) {
                encontrado = true;
                if ((*this)[i].isDisponible()) {
                    (*this)[i].setDisponibilidad(false); // Modifica el objeto
                    std::cout << "  [EXITO] Titulo '" << nombre << "' alquilado correctamente." << std::endl;

                    if ((*this)[i].isRequierePagoExtra()) {
                        std::cout << "  [AVISO] Este titulo requiere un pago extra de "
                                  << (*this)[i].getPrecioAlquiler() << std::endl;
                    }
                } else {
                    std::cout << "  [ERROR] El titulo '" << nombre << "' se encontro, pero no esta disponible." << std::endl;
                }
                break;
            }
        }

        if (!encontrado) {
            std::cout << "  [ERROR] El titulo '" << nombre << "' no se encontro en el catalogo." << std::endl;
        }
    }


};



