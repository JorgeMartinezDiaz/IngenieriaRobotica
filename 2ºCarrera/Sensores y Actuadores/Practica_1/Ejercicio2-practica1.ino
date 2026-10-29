const int ledPin = 9;
const int ledPin2 = 10;

void setup() {
  pinMode(ledPin, OUTPUT); // Configura el pin como salida
  pinMode(ledPin2, OUTPUT); // Configura el pin como salida

}

void loop() {
  
  //brillar 1 y atenuar 2
  
  for (int brillo = 0; brillo <= 255; brillo++){
      analogWrite(ledPin, brillo);
      analogWrite(ledPin2, 255 - brillo);
      delay(50);
  }
  
//brillar 2 y atenuar 1
  
  for (int brillo = 255; brillo >= 0; brillo--){
      analogWrite(ledPin, brillo);
      analogWrite(ledPin2, 255 - brillo);
      delay(50);
    }
}
