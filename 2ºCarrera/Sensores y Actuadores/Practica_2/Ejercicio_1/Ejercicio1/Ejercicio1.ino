// Pines:

const int redPin = 9;
const int greenPin = 11;
const int bluePin = 10;

void setColor(bool red, bool green, bool blue) {
    if (red)
        digitalWrite(redPin, LOW);
    else 
        digitalWrite(redPin, HIGH);

    if (green) 
        digitalWrite(greenPin, LOW);
    else 
        digitalWrite(greenPin, HIGH);

    if (blue) 
        digitalWrite(bluePin, LOW);
    else 
        digitalWrite(bluePin, HIGH);
}

void setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

/*
0 -> LOW
1 -> HIGH
*/
void loop() {
    // LED apagado
    setColor(0, 0, 0);
    delay(1000);

    // Rojo
    setColor(1, 0, 0);
    delay(1000);

    // Verde
    setColor(0, 0, 1);
    delay(1000);

    // Azul
    setColor(0, 1, 0);
    delay(1000);

    // Cian
    setColor(0, 1, 1);
    delay(1000);
}
