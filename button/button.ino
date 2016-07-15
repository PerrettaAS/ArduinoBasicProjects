/* The number of the push button pin */
const int BUTTON_PIN = 2;

/* The number of the led pin */
const int LED_PIN = 13;

void setup()
{
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  if (digitalRead(BUTTON_PIN) == HIGH)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
}
