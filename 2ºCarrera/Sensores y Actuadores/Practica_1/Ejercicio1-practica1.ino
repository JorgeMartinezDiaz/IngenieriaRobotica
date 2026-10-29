const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT); // Configura el pin como salida
}

void loop() {

  // brillar
  
  for (int brillo = 0; brillo <= 255; brillo++){
      analogWrite(ledPin, brillo);
      delay(50);
  }
  
// atenuar 
  
  for (int brillo = 255; brillo >= 0; brillo--){
      analogWrite(ledPin, brillo);
      delay(50);
    }
}
