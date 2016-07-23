const int BUZZER_PIN = 3, BUTTON_PIN = 2;
int frequency;

void setup()
{    
  frequency = 1;
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, OUTPUT);
}

void loop()
{
  if (digitalRead(BUTTON_PIN) == HIGH)
  {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(frequency++);
    digitalWrite(BUZZER_PIN, LOW);
    delay(frequency);
  }
  else
    digitalWrite(BUZZER_PIN, LOW);
}
