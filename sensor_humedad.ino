// Example DHT humidity/temperature sensors


#include "DHT.h"

#define DHTPIN D0     // what pin we're connected to


#define DHTTYPE DHT11   // 

#include <Wire.h>  
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x3F, 16, 2);
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("DHT-11 test!");
lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight 
  dht.begin();

}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  lcd.setCursor(0, 0);
  lcd.print("temp"); // Start Print text to Line 1
  lcd.setCursor(5, 0);
  lcd.print(t); 
  lcd.setCursor(0, 1);      
  lcd.print("humedad"); // Start Print Test to Line 2
  lcd.setCursor(7,1);
  lcd.print(h); 
 
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C ");
}
