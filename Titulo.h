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
    Titulo()
        : nombre("N/A"), tipo("N/A"), genero("N/A"), calidad("FHD"),
          disponible(false), requierePagoExtra(false), precioAlquiler(0.0f) {}

    Titulo(std::string nombre, std::string tipo, std::string genero,
           std::string calidad, bool disponible, bool requierePagoExtra, float precioAlquiler)
        : nombre(nombre), tipo(tipo), genero(genero), calidad(calidad),
          disponible(disponible), requierePagoExtra(requierePagoExtra), precioAlquiler(precioAlquiler) {}
    std::string getNombre() const { return nombre; }
    std::string getTipo() const { return tipo; }
    std::string getGenero() const { return genero; }
    std::string getCalidad() const { return calidad; }
    bool isDisponible() const { return disponible; }
    bool isRequierePagoExtra() const { return requierePagoExtra; }
    float getPrecioAlquiler() const { return precioAlquiler; }

    void setNombre(std::string nombre) { this->nombre = nombre; }
    void setDisponibilidad(bool disponible) { this->disponible = disponible; }

    std::string toString() const {
        std::stringstream ss;
        ss << "Titulo: " << this->nombre << " (" << this->tipo << ")" << std::endl;
        ss << "  Genero: " << this->genero << std::endl;
        ss << "  Calidad: " << this->calidad << std::endl;
        ss << "  Disponible: " << (this->disponible ? "Si" : "No") << std::endl;
        if (this->requierePagoExtra) {
            ss << "  Precio Alquiler: " << this->precioAlquiler << " (Pago Extra)" << std::endl;
        } else {
            ss << "  Precio Alquiler: Incluido en tarifa" << std::endl;
        }
        return ss.str();
    }
};


#endif //PEL__ACTIVIDADCOLABORATIVA3_TITULO_H