#define RELAY_PIN 13  // Pin para controlar el relé
#define CONTROL_PIN 7 // Pin para recibir señal del ESP32

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(CONTROL_PIN, INPUT);
  digitalWrite(RELAY_PIN, HIGH);  // Relé apagado inicialmente
}

void loop() {
  int signal = digitalRead(CONTROL_PIN);

  if (signal == HIGH) {
    digitalWrite(RELAY_PIN, LOW);  // Activar el relé (enciende la bomba)
    Serial.println("Bomba activada");
  } else {
    digitalWrite(RELAY_PIN, HIGH); // Desactivar el relé (apaga la bomba)
    Serial.println("Bomba desactivada");
  }

  delay(500);  // Pequeño retraso para evitar problemas de lectura
}
