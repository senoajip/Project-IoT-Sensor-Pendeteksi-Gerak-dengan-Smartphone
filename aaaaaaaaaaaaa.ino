#define BLYNK_PRINT Serial  
#include <ESP8266WiFi.h>     
#include <BlynkSimpleEsp8266.h>

char auth[] = "XEdeEqXER6RdXVe7q-mkdUlRMZ35D7sk";
char ssid[] = "HaDi";
char pass[] = "12345678";

int Status = 12;  // Digital pin D6
int sensor = 13;  // Digital pin D7

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(Status, OUTPUT);  // declare LED as output
}

void loop() {
  long state = digitalRead(sensor);
    if(state == HIGH) {
      digitalWrite (Status, HIGH);
      Serial.println("Ada gerakan");
      Blynk.notify("ada gerakan loh");
      delay(1000);
    }
  else {
    Serial.println("Tidak ada gerakan");
    digitalWrite(Status, LOW);
    delay(1000);
  }
  Blynk.run(); 
}
