int led_vermelho = 8;
int led_amarelo = 9;
int led_verde = 10;

void setup() {
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
}

void loop() {
  digitalWrite(led_vermelho,HIGH);
  delay (3000);
  digitalWrite(led_vermelho,LOW);
  digitalWrite(led_amarelo,HIGH);
  delay (3000);
  digitalWrite(led_amarelo,LOW);
  digitalWrite(led_verde,HIGH);
  delay (3000);
  digitalWrite(led_verde,LOW);

}
