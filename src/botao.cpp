//? .src/botao.cpp

#include "botao.h"

Botao::Botao(uint8_t pino) : _pinBotao(pino)
{
    // _pinBotao = pino; (nao recomendado)
}

void Botao::iniciar()
{
    pinMode(_pinBotao, INPUT_PULLUP);
}

void Botao::atualizar()
{
    //? clausula de guarda (pesquisar)

    _pressionou = false;
    _soltou = false;

    _estadoAtualBotao = digitalRead(_pinBotao);

    if (_estadoAtualBotao != _estadoAnteriorBotao)
    {
     _estadoAnteriorBotao = _estadoAtualBotao;
     _ultimaMudanca_ms = millis();
     return;
    }

    if(tempoDecorrido() < _tempoDebounce_ms) return;

    if(_estadoAtualBotao == _estadoAnteriorBotao) return;

    _estadoAnteriorBotao = _estadoAtualBotao;

    const bool botaoPressionado = !_estadoAtualBotao;

    botaoPressionado
        ? _pressionou = true
        : _soltou = true;
}

// void Botao::atualizar()
// {
//     _estadoAtualBotao = digitalRead(_pinBotao);

//     _pressionou = false;
//     _soltou = false;

//     if (_estadoAtualBotao != _estadoAnteriorBotao)
//     {
//         _estadoAnteriorBotao = _estadoAtualBotao;

//         _ultimaMudanca_ms = millis();
//     }

//     else if (tempoDecorrido() > _tempoDebounce_ms)
//     {
//         const bool acaoExecutado = (_estadoUltimaAcao == _estadoAtualBotao);

//         if(!acaoExecutado)
//         {
//             _estadoUltimaAcao = _estadoAtualBotao;

//             const bool botaoPressionado = !_estadoAtualBotao;

//             botaoPressionado
//             ? _pressionou = true
//             : _soltou = true;
//             // deixando explicito que o botao foi pressionado.

//             /* sem ternario:
//             if(botaoPressionado)
//             {
//                 _pressionou = true;
//             }

//             else
//             {
//                 _soltou = true;
//             }
//             */
//         }
//     }
// }

bool Botao::pressionou()
{
    return _pressionou;
}

bool Botao::soltou()
{
    return _soltou;
}

uint32_t Botao::tempoDecorrido()
{
    return millis() - _ultimaMudanca_ms;
}