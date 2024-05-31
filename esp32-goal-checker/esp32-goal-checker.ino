#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "*******";
const char* password = "*********";

const char* serverName = "http://192.168.1.112:5000/recebedor";

const int trigPin = 4;
const int echoPin = 2;

const int goalSize = 40;

long getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) / 29.1;
  return distance;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }

  Serial.println("Conectado ao WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverName);

    long distance = getDistance();
    Serial.println(distance);
    if (distance < goalSize) {
      String httpRequestData = "status=1";
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      int httpResponseCode = http.POST(httpRequestData);
      http.end();
      delay(3000);
    }
  } else {
    Serial.println("Erro na conexão WiFi");
  }
}
