#include <Wire.h>              //Include the Wire library for I2C communication
#include <LiquidCrystal_I2C.h> //Include the LiquidCrystal_I2C library for LCD display

intmoisture = A0; // Define Pin number for the Sensor
LiquidCrystal_I2Clcd(0x27, 16, 2);

voidsetup()
{
    Serial.begin(9600); // Start the serial communication with a baud rate of 9600
    lcd.init();         // initializethelcd
    lcd.backlight();    // TurnontheLCDscreenbacklight
}

voidloop()
{
    float Moist = analogRead(moisture); // read moisture level value
    lcd.clear();                        // Clear the LCDdisplay
    lcd.setCursor(0, 1);                // Set the cursor
    lcd.print("Moisture:");
    lcd.print((Moist / 750) * 100); // Print the moisture % value
    lcd.print("%");
}