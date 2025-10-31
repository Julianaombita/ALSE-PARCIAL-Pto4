#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "../include/DispositivoInteligente.h"

int main() {
    // I) Crear contenedor de dispositivos
    std::vector<DispositivoInteligente> hogar;
    hogar.emplace_back("Lampara sala", false, 12.5f);
    hogar.emplace_back("Aire acondicionado", false, 950.0f);
    hogar.emplace_back("Router WiFi", true, 9.0f);

    // II) Simular uso (horas de funcionamiento por intervalo)
    std::vector<std::vector<float>> horas = {
        {1.0f, 0.5f, 2.0f, 0.0f},   // Lámpara
        {0.0f, 1.5f, 0.0f, 2.0f},   // Aire acondicionado
        {1.0f, 1.0f, 1.0f, 1.0f}    // Router
    };

    for (size_t i = 0; i < hogar.size(); ++i) {
        for (float h : horas[i]) {
            if (h > 0.0f) hogar[i].encender();
            float energia = hogar[i].medirConsumo(h);
            if (h > 0.0f) hogar[i].apagar();
            (void)energia; // evita warning
        }
    }

    // III) Generar reporte en archivo de texto
    std::ofstream reporte("reporte_consumo.txt");
    if (reporte.is_open()) {
        reporte << "ID,Nombre,EnergiaTotal_Wh\n";
        for (const auto& d : hogar) {
            reporte << d.getId() << ","
                    << d.getNombre() << ","
                    << std::fixed << std::setprecision(2)
                    << d.getEnergiaAcumulada() << "\n";
        }
        reporte.close();
        std::cout << "Reporte generado: reporte_consumo.txt\n";
    } else {
        std::cerr << "No se pudo crear el archivo de reporte.\n";
    }

    return 0;
}
