#ifndef RGBLib_h  // Previne inclusões múltiplas
#define RGBLib_h

#include "Arduino.h"

struct Color { // Estrutura para armazenar nome e valores RGB
  String name;
  int red;
  int green;
  int blue;
};

class RGB {
    public:
        RGB(int pinR, int pinG, int pinB);
        void acender(String cor);
        void acender(int vermelho, int verde, int azul);
        void rave(int ms);
        void transicao(String cor1, String cor2);

    private:
    int _pinR, _pinG, _pinB;
    const Color colors[9] = {
      {"Vermelho", 255, 0, 0},
      {"Laranja", 255, 136, 0},
      {"Amarelo", 255, 255, 0},
      {"Verde", 0, 255, 0},
      {"Ciano", 0, 255, 255},
      {"Azul", 0, 0, 255},
      {"Roxo", 170, 0, 255},
      {"Rosa", 255, 255, 150},
      {"Branco", 255, 255, 255}
    };
};

#endif