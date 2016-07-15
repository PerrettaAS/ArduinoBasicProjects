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
const Color LED_COLORS[] = {YELLOW, RED, GREEN, RED, YELLOW, RED, GREEN, RED};

/*
 * Toggles an individual color on or off.
 */
void toggleColor(Color color, bool on)
{
  int i;
  for (i = 0; i < NUMBER_OF_LEDS; i++)
    if (ledCollection[i].color == color)
      digitalWrite(ledCollection[i].pin, on ? HIGH : LOW);
}

/*
 * Toggles an individual color exclusively on or off.
 */
void toggleExclusiveColor(Color color, bool on)
{
  toggleColor(color, on);
  int i;
  for (i = 0; i < NUMBER_OF_LEDS; i++)
    if (ledCollection[i].color != color)
      digitalWrite(ledCollection[i].pin, on ? LOW : HIGH);
}

/*
 * Toggles all LEDs on or off.
 */
void toggleAll(bool on)
{
  int i;
  for (i = 0; i < NUMBER_OF_LEDS; i++)
    digitalWrite(ledCollection[i].pin, on ? HIGH : LOW);
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
  toggleColor(GREEN, true);
  delay(500);
  toggleColor(YELLOW, true);
  delay(500);
  toggleColor(RED, true);
  delay(500);
  toggleExclusiveColor(YELLOW, false);
  delay(500);
  toggleColor(GREEN, false);
  delay(500);
  toggleExclusiveColor(GREEN, true);
  delay(500);
  toggleExclusiveColor(RED, true);
  delay(500);
  toggleAll(true);
  delay(500);
  toggleAll(false);
  delay(500);
}
