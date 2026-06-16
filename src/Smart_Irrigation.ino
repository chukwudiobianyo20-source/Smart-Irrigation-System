#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHT11_PIN 8
DHT dht11(DHT11_PIN, DHT11);

int relay = 13;
int moisture = A0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    Serial.begin(9600);
    dht11.begin();
    pinMode(relay, OUTPUT);
    lcd.init();
    lcd.backlight();
}

void loop()
{
    float Moist = analogRead(moisture);
    float humidity = dht11.readHumidity();
    float tempC = dht11.readTemperature();

    if (isnan(humidity) || isnan(tempC))
    {
        Serial.println("Failed to read from DHT11 sensor!");
    }
    else
    {
        // Main irrigation logic
        if (humidity <= 70 && Moist <= 225)
        {
            digitalWrite(relay, HIGH);
        }
        else
        {
            digitalWrite(relay, LOW);
        }

        // Emergency irrigation
        if (Moist <= 150)
        {
            digitalWrite(relay, HIGH);
        }

        // Display data on LCD
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Humidity:");
        lcd.print(humidity);
        lcd.print("%");
        lcd.setCursor(0, 1);
        lcd.print("Moisture:");
        lcd.print((Moist / 750) * 100);
        lcd.print("%");

        // Serial output
        Serial.print("Humidity:");
        Serial.print(humidity, 2);
        Serial.print("%|");
        Serial.print("Moisture:");
        Serial.println((Moist / 750) * 100);
    }

    delay(1000);
}