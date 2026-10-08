//! include/led.h

#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led
{
private: // e necessario privar objetos para evitar crash
    // atributos/variaveis
    uint8_t _pinoLed; // usar o underscore antes significa que é um atributo
    bool _estadoLed = 0;
    bool _estaPiscando = false;
    uint32_t _tempoAcaoAnterior_ms = 0;
    uint32_t tempoEsperaAlternar_ms = 0;

public:
    // tem que sempre ter o nome da classe
    //  consultor / a funcao mais importante que abrira caminho para as outras
    Led(uint8_t pino);

    // metodos/funcoes
    void ligar();
    void atualizar();
    void iniciar();
    void desligar();
    void ativarPiscar(uint32_t tempoEspera_ms = 500);
    void desativarPiscar();
    void alternar();

    uint8_t getPinoLed();

    void setEstadoLed(bool estado);
};

#endif