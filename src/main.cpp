#include <Arduino.h>
#include "led.h"
#include "botao.h"

Led ledVerde(6);
Led ledAmarelo(5);
Led ledVermelho(4);

Botao pinBotaoVerde(15);
Botao pinBotaoAmarelo(17);
Botao pinBotaoVermelho(3);

void setup()
{
  pinBotaoVerde.iniciar();
  pinBotaoAmarelo.iniciar();
  pinBotaoVermelho.iniciar();

  ledVerde.iniciar();
  ledAmarelo.iniciar();
  ledVermelho.iniciar();
}

void loop()
{
  pinBotaoVerde.atualizar();
  pinBotaoAmarelo.atualizar();
  pinBotaoVermelho.atualizar();

  ledVerde.atualizar();
  ledAmarelo.atualizar();
  ledVermelho.atualizar();
  
  if(pinBotaoVerde.pressionou() == true)
  {
    ledVerde.ativarPiscar();
  }
  
  if (pinBotaoAmarelo.pressionou() == true)
  {
    ledAmarelo.ativarPiscar();
  }
  
  if (pinBotaoVermelho.pressionou() == true)
  {
    ledVermelho.ativarPiscar();
  }
}
