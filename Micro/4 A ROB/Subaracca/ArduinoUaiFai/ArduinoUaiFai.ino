#include <WiFiNINA.h>
#include <Wire.h>

char ssid[] = "Prandi_Wifi";     // SSID della tua rete WiFi
char password[] = "Perlina2006"; // Password della tua rete WiFi
WiFiServer server(8888);  // Porta del server

// Define the pins for each command
const int pinW = 2;
const int pinA = 4;
const int pinS = 3;
const int pinD = 5;

void setup() {
  // Initialize Serial
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for the serial port to be available
  }

  // Initialize WiFi
  Serial.print("Connecting to WiFi...");
  while (WiFi.begin(ssid, password) != WL_CONNECTED) {
    delay(1000);
    Serial.println("Trying to connect...");
  }
  Serial.println("Connected to WiFi!");

  // Start the server
  server.begin();
  Serial.println("Server started!");

  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // Initialize I2C
  Wire.begin(); // Join I2C bus as master

  // Initialize pins as outputs
  pinMode(pinW, OUTPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinS, OUTPUT);
  pinMode(pinD, OUTPUT);
}

void loop() {
  // Check for client connections
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Client connected");

    // Read data from client
    while (client.connected()) {
      if (client.available()) {
        String data = client.readStringUntil('\n');
        Serial.println("Received data: " + data);

        // Set the corresponding pin high based on received data
        if (data.length() > 0) {
          char command = data.charAt(0);

          // Reset all pins to LOW
          digitalWrite(pinW, LOW);
          digitalWrite(pinA, LOW);
          digitalWrite(pinS, LOW);
          digitalWrite(pinD, LOW);

          // Set the appropriate pin high
          switch (command) {
            case 'W':
              digitalWrite(pinW, HIGH);
              break;
            case 'A':
              digitalWrite(pinA, HIGH);
              break;
            case 'S':
              digitalWrite(pinS, HIGH);
              break;
            case 'D':
              digitalWrite(pinD, HIGH);
              break;
            case 'Q':
              digitalWrite(pinW, LOW);
              digitalWrite(pinA, LOW);
              digitalWrite(pinS, LOW);
              digitalWrite(pinD, LOW);
            default:
              Serial.println("Unknown command");
              break;
          }
        }

        if (data.charAt(0) == 'E') {
          client.stop();
          Serial.println("Client disconnected");
        }
      }
    }
  }

  delay(100); // Small delay to avoid flooding with requests
}