#include <WiFi.h>
#include <Adafruit_NeoPixel.h>
#include <OSCMessage.h>
#include <WiFiUdp.h>

// Wi-Fi credentials
const char* ssid = "SDABroadcast";
const char* password = "yaytheatre";
int cameraNum = 1;

// NeoPixel definitions
#define NEOPIXEL_PIN   0
#define NUM_PIXELS     1
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// UDP and OSC configurations
WiFiUDP Udp;
const unsigned int localPort = 8888;  // Local port to listen on

// OSC paths with a variable at the end

std::string programPath = "/atem/program";
std::string previewPath = "/atem/preview";

bool programOn = false;  // true if program is "1", false otherwise
bool previewOn = false;  // true if preview is "1", false otherwise
bool cantconnect = false;  // true if preview is "1", false otherwise

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);

  int connectionAttempts = 0;
  while (WiFi.status() != WL_CONNECTED && connectionAttempts < 30) { // Tries to connect for approximately 20 seconds
    delay(1000);
    Serial.println("Connecting to WiFi...");
    connectionAttempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
  } else {
    Serial.println("Failed to connect to WiFi after 30 attempts");
    cantconnect = true;
    strip.setPixelColor(0, strip.Color(0, 0, 255));
    strip.show();
    }

  // Start UDP
  Udp.begin(localPort);

  // Initialize NeoPixel
  strip.begin();
  strip.show();
}

void loop() {
    // Process all available OSC messages
    int packetSize;
    while ((packetSize = Udp.parsePacket()) > 0) {
        OSCMessage oscMsg;
        char oscAddress[50];  // Buffer to store the OSC address
        while (packetSize--) {
            oscMsg.fill(Udp.read());
        }

        // Extract and print the OSC address
        oscMsg.getAddress(oscAddress, 0, 50);
        Serial.print("Received OSC message: ");
        Serial.println(oscAddress);

        // Check for /atem/program address
        if (oscMsg.fullMatch(programPath.c_str())) {
            int arg = oscMsg.getInt(0);
            programOn = (arg == cameraNum);  // Check if the value is '4'
            Serial.print("Program value: ");
            Serial.println(arg);
        }
        
        // Check for /atem/preview address
        else if (oscMsg.fullMatch(previewPath.c_str())) {
            int arg = oscMsg.getInt(0);
            previewOn = (arg == cameraNum);  // Check if the value is '4'
            Serial.print("Preview value: ");
            Serial.println(arg);
        }
    }

    // Update the NeoPixel color based on the received messages
    if (programOn) {
        strip.setPixelColor(0, strip.Color(40, 0, 0)); // Red for program
        Serial.println("Set color: Red for program");
    } else if (previewOn) {
        strip.setPixelColor(0, strip.Color(0, 40, 0)); // Green for preview
        Serial.println("Set color: Green for preview");
    } 

    // Only set to off if neither flag is true
    if (cantconnect) {
        strip.setPixelColor(0, strip.Color(0, 0, 255)); // Green for preview
        Serial.println("Set color: Blue for can't connect");
    } else if (!programOn && !previewOn) {
        strip.setPixelColor(0, strip.Color(0, 0, 0));   // Off if neither
        Serial.println("Set color: Off");
    }

    strip.show(); // Update the NeoPixel color
}

