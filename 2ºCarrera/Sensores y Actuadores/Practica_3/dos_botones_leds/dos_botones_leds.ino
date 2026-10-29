// Pulsadores y leds:

const byte boton1Pin = 2;
const byte boton2Pin = 3;
const byte led1Pin = 8;
const byte led2Pin = 9;
const unsigned long tiempoAntirrebote = 40;

volatile bool pendiente1 = false;
volatile bool pendiente2 = false;
volatile unsigned long ultimoCambio1 = 0;
volatile unsigned long ultimoCambio2 = 0;

// Estados: 

int estadoEstable1 = HIGH;
int estadoEstable2 = HIGH;
bool led2Encendido = false;

void interrupcionBoton1() {
  ultimoCambio1 = millis();
  pendiente1 = true;
}

void interrupcionBoton2() {
  ultimoCambio2 = millis();
  pendiente2 = true;
}

// Solo valida el nivel cuando han pasado 40 ms sin nuevos flancos.
// La seccion critica evita perder eventos al borrar la marca pendiente.
bool leerEstadoEstable(byte pin, volatile bool &pendiente,
                       volatile unsigned long &ultimoCambio, int &estado) {
  bool listo = false;
  noInterrupts();
  const unsigned long ahora = millis();
  if (pendiente && ahora - ultimoCambio >= tiempoAntirrebote) {
    estado = digitalRead(pin);
    pendiente = false;
    listo = true;
  }
  interrupts();
  return listo;
}

void setup() {
  pinMode(boton1Pin, INPUT); // Cada boton lleva pull-up externa de 10 kohm.
  pinMode(boton2Pin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);

  attachInterrupt(digitalPinToInterrupt(boton1Pin), interrupcionBoton1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(boton2Pin), interrupcionBoton2, CHANGE);

  // Comprueba tambien el estado inicial si se arranca con un boton pulsado.
  noInterrupts();
  ultimoCambio1 = millis();
  ultimoCambio2 = ultimoCambio1;
  pendiente1 = true;
  pendiente2 = true;
  interrupts();
}

void loop() {
  int lectura;
  if (leerEstadoEstable(boton1Pin, pendiente1, ultimoCambio1, lectura)) {
    estadoEstable1 = lectura;
    digitalWrite(led1Pin, estadoEstable1 == LOW ? HIGH : LOW);
  }

  if (leerEstadoEstable(boton2Pin, pendiente2, ultimoCambio2, lectura)) {
    if (estadoEstable2 == HIGH && lectura == LOW) {
      led2Encendido = !led2Encendido;
      digitalWrite(led2Pin, led2Encendido ? HIGH : LOW);
    }
    estadoEstable2 = lectura;
  }
}