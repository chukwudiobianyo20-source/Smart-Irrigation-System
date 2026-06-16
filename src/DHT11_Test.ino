#include <DHT.h>               //Include the DHT library
#include <Wire.h>              //Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h> //Include the LiquidCrystal_I2C library for LCD display
#define DHT11_PIN8             // Define the pin number for the DHT11 sensor

DHTdht11(DHT11_PIN, DHT11); // Create a DHT object
LiquidCrystal_I2Clcd(0x27, 16, 2);

voidsetup()
{
    Serial.begin(9600); // Start the serial communication with a baud rate of 9600
    dht11.begin();      // Initialize the sensor
    lcd.init();         // Initialize the lcd
    lcd.backlight();    // Turn on the LCD screen backlight
}

voidloop()
{
    float humidity = dht11.readHumidity(); // Read humidity
    lcd.clear();                           // Clear the LCD display
    lcd.setCursor(0, 0);                   // Set the cursor
    lcd.print("Humidity:");
    lcd.print(humidity); // Print the humidity value
    lcd.print("%");
}