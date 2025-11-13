//
// Created by Carmen Bolaños Villarejo on 13/11/25.
//
#include <string>
#include <sstream>
#include <iostream>
#ifndef PEL__ACTIVIDADCOLABORATIVA3_TITULO_H
#define PEL__ACTIVIDADCOLABORATIVA3_TITULO_H
/* Almacena toda la información relevante de un título, como su nombre,
* tipo, género, calidad, disponibilidad y precio de alquiler.
*/

class Titulo{
private:
    // --- Atributos ---
    std::string nombre;
    std::string tipo;         // "pelicula" o "serie"
    std::string genero;
    std::string calidad;      //"FHD" o "UHD"
    bool disponible;
    bool requierePagoExtra;
    float precioAlquiler;
public:
    // --- Métodos ---
    Titulo();

    Titulo(std::string nombre, std::string tipo, std::string genero, std::string calidad, bool disponible, bool requierePagoExtra, float precioAlquiler);

    std::string getNombre() const;
    std::string getTipo() const;
    std::string getGenero() const;
    std::string getCalidad() const;
    bool isDisponible() const;
    bool isRequierePagoExtra() const;
    float getPrecioAlquiler() const;

    void setNombre(std::string nombre);
    void setDisponibilidad(bool disponible);

    std::string toString() const;
};


#endif //PEL__ACTIVIDADCOLABORATIVA3_TITULO_H