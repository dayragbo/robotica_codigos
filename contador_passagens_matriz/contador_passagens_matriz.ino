#include <LedControl.h>


// Pinos do MAX7219: DIN, CLK, CS
const int DIN_PIN = 12;
const int CLK_PIN = 11;
const int CS_PIN = 10;


// Pino do sensor IR
const int SENSOR_PIN = 2;


// Criar objeto LedControl para 1 dispositivo
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);


int contador = 0;
bool estadoAnterior = false;


// Números mais grossos e centralizados para matriz 8x8
byte numeros[10][8] = {
  // 0 (vazio)
  {B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000},


  // 1
  {B00011000,
   B00111000,
   B00011000,
   B00011000,
   B00011000,
   B00011000,
   B00111100,
   B00000000},


  // 2
  {B00111100,
   B01000110,
   B00000110,
   B00001100,
   B00110000,
   B01100000,
   B01111110,
   B00000000},


  // 3
  {B00111100,
   B01000110,
   B00000110,
   B00011100,
   B00000110,
   B01000110,
   B00111100,
   B00000000},


  // 4
  {B00001100,
   B00011100,
   B00101100,
   B01001100,
   B01111110,
   B00001100,
   B00001100,
   B00000000},


  // 5
  {B01111110,
   B01100000,
   B01111100,
   B00000110,
   B00000110,
   B01000110,
   B00111100,
   B00000000},


  // 6
  {B00111100,
   B01100000,
   B01111100,
   B01000110,
   B01000110,
   B01000110,
   B00111100,
   B00000000},


  // 7
  {B01111110,
   B00000110,
   B00001100,
   B00011000,
   B00110000,
   B00110000,
   B00110000,
   B00000000},


  // 8
  {B00111100,
   B01000110,
   B01000110,
   B00111100,
   B01000110,
   B01000110,
   B00111100,
   B00000000},


  // 9
  {B00111100,
   B01000110,
   B01000110,
   B00111110,
   B00000110,
   B00001100,
   B00111000,
   B00000000}
};


void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);


  // Inicializa a matriz
  lc.shutdown(0, false);      // Desliga modo economia energia
  lc.setIntensity(0, 8);      // Brilho (0 a 15)
  lc.clearDisplay(0);         // Limpa a matriz
}


void loop() {
  bool estadoAtual = digitalRead(SENSOR_PIN);


  // Detecta borda de subida (passagem do estado baixo para alto)
  if (estadoAtual && !estadoAnterior) {
    contador++;
    if (contador > 9) contador = 1;  // volta para 1 depois de 9
    mostrarNumero(contador);
    Serial.print("Passagem contada: ");
    Serial.println(contador);
  }


  estadoAnterior = estadoAtual;
  delay(50);  // Pequeno delay para evitar múltiplas contagens rápidas
}


void mostrarNumero(int num) {
  lc.clearDisplay(0);


  for (int coluna = 0; coluna < 8; coluna++) {
    byte linhaRotacionada = 0;


    for (int linha = 0; linha < 8; linha++) {
      byte bit = (numeros[num][linha] >> coluna) & 0x01;
      // Invertendo a ordem dos bits E das linhas
      linhaRotacionada |= bit << linha;
    }


    // Inverte a ordem das linhas (colunas da matriz original)
    lc.setRow(0, 7 - coluna, linhaRotacionada);
  }
}



