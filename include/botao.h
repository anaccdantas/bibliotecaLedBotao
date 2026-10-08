//? .include/botao.h

#ifndef BOTAO_H // alguns programadores usam underscore em volta do nome
#define BOTAO_H // do arquivo, i.e __BOTAO_H__

#include <Arduino.h>

class Botao
{
    private: // e ideal identificar os objetos com underscore
    uint8_t _pinBotao;
    bool _estadoAtualBotao;
    bool _estadoAnteriorBotao;
    bool _pressionou = false;
    bool _soltou = false;
    uint32_t _ultimaMudanca_ms = 0;
    uint32_t _tempoDebounce_ms = 20;
    bool _estadoUltimaAcao = HIGH;

    public:
    Botao(uint8_t pino);
    // ~Botao(); - destrutor

    // nao se usa destrutores em programacao de microcalculadores

    void iniciar();
    void atualizar();
    bool pressionou();
    bool soltou();
};

#endif