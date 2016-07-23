#define PHOTOCELL_PIN A0

/*
 * Number of LEDs taking a pin slot.
 */
const int NUMBER_OF_LEDS = 8;

/* 
 * Available LED colors.
 */
typedef enum 
{
  RED, 
  GREEN, 
  YELLOW
} Color;

typedef struct 
{
  int pin;
  Color color;
} LightEmittingDiode;

LightEmittingDiode newLED(int pin, Color color)
{
  LightEmittingDiode led;
  led.pin = pin;
  led.color = color;
  return led;
}

LightEmittingDiode ledCollection[NUMBER_OF_LEDS];
const Color LED_COLORS[] = {RED, RED, GREEN, GREEN, YELLOW, YELLOW, RED, RED};

void toggleLED(int pin, bool on)
{
  digitalWrite(pin, on ? HIGH : LOW);
}

void setup() 
{
  int i;
  for (i = 0; i < NUMBER_OF_LEDS; i++)
  {
    ledCollection[i] = newLED(i + 2, LED_COLORS[i]);
    pinMode(i + 2, OUTPUT);
  }
}

void loop() 
{
  int sensorValue = analogRead(PHOTOCELL_PIN);
  int ledLevel = map(sensorValue, 500, 1023, 0, NUMBER_OF_LEDS);
  int i;
  for (i = 0; i < NUMBER_OF_LEDS; i++)
  {
    if (i < ledLevel)
      toggleLED(ledCollection[i].pin, true);
    else
      toggleLED(ledCollection[i].pin, false);
  }
}
