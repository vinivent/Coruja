#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX
const int buttonPin2 = 4;
const int buttonPin3 = 5;
int buttonState2 = 0;
int buttonState3 = 0;
int index = 0;
char messages[] = {'0', '1', '2', '3'};

void setup() {
  mySerial.begin(9600);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void loop() {
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == HIGH) {
    mySerial.write(messages[index]);
    index = (index + 1) % 4; // Atualiza o índice, volta para 0 se atingir 4
    delay(500);
  }

  buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 == HIGH) {
    mySerial.write('E');
    delay(500);
  }
}
