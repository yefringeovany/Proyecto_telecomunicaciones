/* Incluimos las librerías necesarias */
#include <WiFi.h>
#include <DHT.h> // Librería para el sensor DHT

/* Definimos las credenciales de la red WiFi */
/* Fernandin pa poner internet y nos va a compartir*/
const char* ssid = "Familia Perez";
const char* pass = "Yefrin2001@M";

/* Definimos el pin de datos para el sensor DHT22 */
#define DHTPIN 5 // Pin D5 del ESP32

/* Definimos el tipo de sensor DHT que estamos usando */
#define DHTTYPE DHT22

/* Creamos una instancia del sensor DHT */
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  /* Iniciamos el terminal Serial para la escritura de algunos parámetros */
  Serial.begin(115200);

  /* Iniciamos el sensor DHT */
  dht.begin();

  /* Iniciamos la conexión a la red WiFi definida */
  WiFi.begin(ssid, pass);
  delay(2000);

  /* En el terminal Serial, indicamos que se está realizando la conexión */
  Serial.print("Se está conectando a la red WiFi denominada ");
  Serial.println(ssid);

  /* Mientras se realiza la conexión a la red, aparecerán puntos, hasta que se realice la conexión */
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  /* Con la conexión ya realizada, imprimimos algunos datos importantes, como la dirección IP asignada al dispositivo */
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  /* Leemos los datos del sensor DHT22 */
  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  /* Comprobamos si la lectura es válida */
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer del sensor DHT!");
    return;
  }

  /* Mostramos los valores leídos en el terminal Serial */
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  /* Hacemos una pausa antes de la siguiente lectura */
  delay(2000);
}
