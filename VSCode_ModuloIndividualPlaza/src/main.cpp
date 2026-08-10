#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA 21
#define OLED_SCL 22

#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

void setup()
{
    Serial.begin(9600);

    // Configurar I2C
    Wire.begin(OLED_SDA, OLED_SCL);

    // Inicializar OLED
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS))
    {
        Serial.println("No se encontro la pantalla OLED");
        while (1);
    }

    // Limpiar pantalla
    display.clearDisplay();

    // Configurar texto
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);

    display.println("Hola!");

    display.setTextSize(1);
    display.setCursor(0, 30);
    display.println("ESP32 funcionando");

    display.display();
}

void loop()
{
}