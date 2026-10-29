// Pines

const int redPin = 9;
const int greenPin = 11;
const int bluePin = 10;

void setColor(bool red, bool green, bool blue) {

    digitalWrite(redPin, red);
    digitalWrite(greenPin, green);
    digitalWrite(bluePin, blue);
}

void setup() {

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    setColor(0, 0, 0);

    Serial.begin(9600);

    Serial.println("Introduce un color RGB (ejemplo: 101):");
}

void loop() {

    if (Serial.available() > 0) {

        String input = Serial.readStringUntil('\n');
        input.trim();

        if (input.length() == 3 &&
            (input[0] == '0' || input[0] == '1') &&
            (input[1] == '0' || input[1] == '1') &&
            (input[2] == '0' || input[2] == '1')) {

            setColor(
                input[0] == '1',
                input[1] == '1',
                input[2] == '1'
            );
        } else 
            Serial.println("Error: introduce solo tres valores 0 o 1.");  // Mensaje de error
        
        Serial.println("Introduce otro color:"); // Nuevo color para el RGB
    }
}