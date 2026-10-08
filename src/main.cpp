#include <Arduino.h>
#include "led.h"

Led ledVerde(6);
Led ledAmarelo(5);
Led ledVermelho(4);

void setup()
{
  ledVerde.iniciar();
  ledVerde.ativarPiscar();

  ledAmarelo.iniciar();
  ledAmarelo.ativarPiscar(1000);

  ledVermelho.iniciar();
  ledVermelho.ativarPiscar(2000);
}

void loop()
{
  ledVerde.atualizar();
  ledAmarelo.atualizar();
  ledVermelho.atualizar();
}
