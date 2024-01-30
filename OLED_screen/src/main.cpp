#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <bitmaps.hpp>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define TOUCH_PIN 4
#define TOUCH_THRESHOLD 40

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

uint8_t frame_counter = 0u;

void setup()
{
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000); // Pause for 2 seconds
}

void loop()
{
  display.clearDisplay();
  if (touchRead(TOUCH_PIN) < TOUCH_THRESHOLD)
  {
    display.drawBitmap(0, 0, surprised_pikachu, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
  }
  else
  {
    display.drawBitmap(0, 0, pikachu_running_frames[frame_counter++], SCREEN_WIDTH, SCREEN_HEIGHT, 1);

    frame_counter %= 4;
  }
  display.display();
  delay(50);
}
