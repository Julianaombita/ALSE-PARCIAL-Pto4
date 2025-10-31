#include "DispositivoInteligente.h"

int DispositivoInteligente::nextId = 1;

DispositivoInteligente::DispositivoInteligente(const std::string& n, bool e, float c)
: id(nextId++), nombre(n), estado(e), consumoEnergia(c),
  controlRemotoBloqueado(false), energiaAcumulada(0.0f) {}

void DispositivoInteligente::encender()  { estado = true;  }

void DispositivoInteligente::apagar()    { estado = false; }

float DispositivoInteligente::medirConsumo(float horas) {
    float energia = consumoEnergia * horas; // W·h
    energiaAcumulada += energia;
    return energia;
}

void DispositivoInteligente::bloquearControlRemoto() {
    controlRemotoBloqueado = !controlRemotoBloqueado;
}

int  DispositivoInteligente::getId() const { return id; }

const std::string& DispositivoInteligente::getNombre() const { return nombre; }

float DispositivoInteligente::getEnergiaAcumulada() const { return energiaAcumulada; }

float DispositivoInteligente::getConsumoWPorHora() const { return consumoEnergia; }

bool DispositivoInteligente::estaEncendido() const { return estado; }
