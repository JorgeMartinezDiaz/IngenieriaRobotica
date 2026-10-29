// Pines pulsador y leds:

const byte botonPin = 2;
const unsigned long retardoTarea = 1000;
const unsigned long tiempoAntirrebote = 100; // milisegundos

// Variables:

volatile unsigned int contadorInterrupciones = 0;
volatile unsigned long ultimaPulsacion = 0;
volatile bool primeraPulsacion = true;
unsigned long ultimaLectura = 0;

void interrupcionBoton() {
  const unsigned long ahora = millis();
  // Zona muerta tras cada pulsacion aceptada.
  if (primeraPulsacion || ahora - ultimaPulsacion >= tiempoAntirrebote) {
    contadorInterrupciones++;
    ultimaPulsacion = ahora;
    primeraPulsacion = false;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(botonPin, INPUT); // Pull-up EXTERNA de 10 kohm.
  attachInterrupt(digitalPinToInterrupt(botonPin), interrupcionBoton, FALLING);
}

void loop() {
  noInterrupts();
  unsigned long lectura = contadorInterrupciones;
  interrupts();

  if (lectura != ultimaLectura) {
    Serial.print("Pulsaciones detectadas: ");
    Serial.println(lectura);
    ultimaLectura = lectura;
  }
  delay(retardoTarea); // La ISR sigue atendiendo durante esta espera.
}
