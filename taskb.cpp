#include <DHT.h>
#include <LiquidCrystal.h> // If using LCD without I2C

#define DHTPIN 2           // Pin where DHT sensor data is connected
#define DHTTYPE DHT11      // DHT11 or DHT22
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  // Adjust pins according to your setup

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);        // Initialize 16x2 LCD
  lcd.print("Temp & Humid"); 
  delay(2000);
}

void loop() {
  // Read temperature and humidity
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Check if any reads failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Display on serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Hum: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(2000);  // Wait for 2 seconds before the next reading
}