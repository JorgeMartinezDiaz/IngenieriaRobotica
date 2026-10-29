const int redPin = 9;   // Pin rojo
const int greenPin = 10; // Pin verde
const int bluePin = 11;  // Pin azul

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void setColorIntensity(int redValue, int greenValue, int blueValue) {
  
  // Inversión para ánodo común (255 - valor)
  analogWrite(redPin, 255 - redValue);
  analogWrite(greenPin, 255 - greenValue);
  analogWrite(bluePin, 255 - blueValue);
}

void loop() {
  // Naranja
  setColorIntensity(255, 100, 0);
  delay(1000);

  // Amarillo
  setColorIntensity(255, 255, 0);
  delay(1000);

  // Cian
  setColorIntensity(0, 255, 255);
  delay(1000);

  // Magenta
  setColorIntensity(255, 0, 255);
  delay(1000);

  // Blanco
  setColorIntensity(255, 255, 255);
  delay(1000);
  // Apagado
  setColorIntensity(0, 0, 0);
  delay(1000);
}