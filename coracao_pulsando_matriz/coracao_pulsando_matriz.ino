#include "LedControl.h" //Inclui a biblioteca para controle da matriz de LED
//#include "binary.h" //Inclui a biblioteca para auxiliar na definição de constantes binárias




#define PinCS 10;  //Define que o Pino CS do módulo está conectado com a porta digital 11 do Arduino
#define PinCLK 11; //Define que o Pino CLK do módulo está conectado com a porta digital 11 do Arduino
#define PinDin 12; //Define que o Pino Din do módulo está conectado com a porta digital 12 do Arduino




LedControl lc = LedControl(12, 11, 10, 1); //Objeto que passa como parâmetros os pinos do Arduino conectados e o número de displays usados




/*Função responsável por fazer o desenho que será mostrado no display




  lc.setRow(x,y,b) onde x= numero da coluna, y = numero da linha e B = numero binario que pode ser obtido
  no site:https://embed.plnkr.co/3VUsekP3jC5xwSIQDVHx
*/




void desenho2() {
  lc.setColumn(0,0, B00001000);
  lc.setColumn(0,1, B00011100);
  lc.setColumn(0,2, B00111110);
  lc.setColumn(0,3, B01111111);
  lc.setColumn(0,4, B01111111);
  lc.setColumn(0,5, B01110111);
  lc.setColumn(0,6, B00100010);
  lc.setColumn(0,7, B00000000);
}
void desenho1() {
  lc.setColumn(0,1, B00001000);
  lc.setColumn(0,2, B00011100);
  lc.setColumn(0,3, B00111110);
  lc.setColumn(0,4, B00111110);
  lc.setColumn(0,5, B00010100);
  lc.setColumn(0,6, B00000000);
}
void contornocoracao() {
  lc.setColumn(0,0, B00001000);
  lc.setColumn(0,1, B00010100);
  lc.setColumn(0,2, B00100010);
  lc.setColumn(0,3, B01000001);
  lc.setColumn(0,4, B01001001);
  lc.setColumn(0,5, B01010101);
  lc.setColumn(0,6, B00100010);
  lc.setColumn(0,7, B00000000);
}




void setup() {
  lc.shutdown(0, false); //Inicia o módulo
  lc.setIntensity(0, 2); //Define a itensidade de brilho do display
  lc.clearDisplay(0);  //Limpa a tela do display
}




void loop() {
  desenho1(); // chamada da função de desenho
  delay(300); // delay de 5 segundos
  desenho2(); // chamada da função de desenho
  delay(500); // delay de 5 segundos
  lc.clearDisplay(0); //limpeza do display
  delay(1000); // delay de 1 segundo até que se tenha uma nova repetição
}















