#ifndef DISPOSITIVO_INTELIGENTE_H
#define DISPOSITIVO_INTELIGENTE_H

#include <string>

/**
 * @brief Representa un dispositivo inteligente del hogar.
 */
class DispositivoInteligente {
private:
    static int nextId;                ///< contador global para IDs
    int id;                           ///< ID único
    std::string nombre;               ///< Nombre del dispositivo
    bool estado;                      ///< true=encendido, false=apagado
    float consumoEnergia;             ///< W/h (vatios por hora)
    bool controlRemotoBloqueado;      ///< bloqueo del control remoto
    float energiaAcumulada;           ///< W·h acumulados

public:
    /**
     * @brief Constructor con todos los atributos excepto el ID (se asigna solo).
     * @param n nombre
     * @param e estado inicial
     * @param c consumo energético en W/h
     */
    DispositivoInteligente(const std::string& n, bool e, float c);

    /** @brief Cambia el estado a encendido. */
    void encender();
    /** @brief Cambia el estado a apagado. */
    void apagar();

    /**
     * @brief Agrega al acumulado la energía consumida durante 'horas'.
     * @param horas tiempo de operación
     * @return energía de ese periodo (W·h)
     */
    float medirConsumo(float horas);

    /** @brief Alterna el bloqueo del control remoto. */
    void bloquearControlRemoto();

    // Métodos de consulta (getters)
    int getId() const;
    const std::string& getNombre() const;
    float getEnergiaAcumulada() const;
    float getConsumoWPorHora() const;
    bool estaEncendido() const;
};

#endif
