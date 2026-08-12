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

Adafruit_SSD1306 display1(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

void oled_init()
{
    // Configurar I2C
    Wire.begin(OLED_SDA, OLED_SCL);

    // Inicializar OLED
    if (!display1.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS))
    {
        Serial.println("No se encontro la pantalla OLED");
    }

    // Limpiar pantalla
    display1.clearDisplay();

    // Configurar texto
    display1.setTextSize(2);
    display1.setTextColor(SSD1306_WHITE);
    display1.setCursor(0, 0);

    display1.println("Smart Parking");

    display1.setTextSize(1);
    display1.setCursor(0, 30);
    display1.println("Sistema iniciado");

    display1.display();
}
