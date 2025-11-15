#include "RGBLib.h"

RGB::RGB(int pinR, int pinG, int pinB) {
  _pinR = pinR;
  _pinG = pinG;
  _pinB = pinB;
  pinMode(_pinR, OUTPUT);
  pinMode(_pinG, OUTPUT);
  pinMode(_pinB, OUTPUT);
}

void RGB::acender(String cor) {
    bool corEncontrada = false;
    for(int i=0; i<9; i++){
        if(cor.equals(colors[i].name)){
            analogWrite(_pinR, colors[i].red);
            analogWrite(_pinG, colors[i].green);
            analogWrite(_pinB, colors[i].blue);
            corEncontrada = true;
            break;
        }
    }
    if(!corEncontrada){
        digitalWrite(_pinR, 1);
        digitalWrite(_pinG, 0);
        digitalWrite(_pinB, 0);
        delay(1000);
        digitalWrite(_pinR, 0);
        digitalWrite(_pinG, 0);
        digitalWrite(_pinB, 0);
    }
    
}
void RGB::acender(int vermelho, int verde, int azul) {
    analogWrite(_pinR, vermelho);
    analogWrite(_pinG, verde);
    analogWrite(_pinB, azul);
}

void RGB::rave(int ms){
   for(int i=0; i<1785; i++){
    if(i > 1530){ // VERMELHO -> 255, 0, 0
        analogWrite(_pinR, 255);
        analogWrite(_pinG, 0);
        analogWrite(_pinB, 1785-i);
    }
    else if(i > 1275){ // ROXO -> 255, 0, 255
        analogWrite(_pinR, i-1275);
        analogWrite(_pinG, 0);
        analogWrite(_pinB, 255);
    }
    else if(i > 1020){ // AZUL -> 0, 0, 255
        analogWrite(_pinR, 0);
        analogWrite(_pinG, 1275-i);
        analogWrite(_pinB, 255);
    }
    else if(i > 765){ // CIANO -> 0, 255, 255
        analogWrite(_pinR, 0);
        analogWrite(_pinG, 255);
        analogWrite(_pinB, i-765);
    }
    else if(i > 510){ // VERDE -> 0, 255, 0
        analogWrite(_pinR, 765-i);
        analogWrite(_pinG, 255);
        analogWrite(_pinB, 0);
    }
    else if(i > 255){ // AMARELO -> 255, 255, 0
        analogWrite(_pinR, 255);
        analogWrite(_pinG, i-255);
        analogWrite(_pinB, 0);
    }
    else { // VERMELHO -> 255, 0, 0
        analogWrite(_pinR, i);
        analogWrite(_pinG, 0);
        analogWrite(_pinB, 0);
    }
    delay(ms);
   }
}
void RGB::transicao(String cor1, String cor2) {
    int index1 = -1, index2 = -1;

    // ENCONTRA AS CORES NO ARRAY
    for (int i = 0; i < 9; i++) {
        if (cor1.equals(colors[i].name)) index1 = i;
        if (cor2.equals(colors[i].name)) index2 = i;
    }

    // Verifica se as cores foram encontradas
    if (index1 == -1 || index2 == -1) {
        Serial.println("Erro: Cores não encontradas!");
        return;
    }

    // ENCONTRA A DIFERENÇA DE CADA COMPONENTE DAS CORES
    int difVermelho = colors[index2].red - colors[index1].red;
    int difVerde = colors[index2].green - colors[index1].green;
    int difAzul = colors[index2].blue - colors[index1].blue;

    // Transição de cor1 para cor2
    for (int i = 0; i <= 100; i++) {
        analogWrite(_pinR, colors[index1].red + difVermelho * i / 100);
        analogWrite(_pinG, colors[index1].green + difVerde * i / 100);
        analogWrite(_pinB, colors[index1].blue + difAzul * i / 100);

        delay(20);
    }
    // TRANSICAO DE COR2 PARA COR1
      for(int i=100; i>0; i--){
        analogWrite(_pinR, colors[index1].red + difVermelho*i/100);
        analogWrite(_pinG, colors[index1].green + difVerde*i/100);
        analogWrite(_pinB, colors[index1].blue + difAzul*i/100);

        delay(20);
    }
}
