const int RED_PIN = 4, GREEN_PIN = 3, BLUE_PIN = 2;

/*
 * Sets the RGB value for the LED
 */
void setColor(unsigned char red, unsigned char green, unsigned char blue)
{ 
  analogWrite(RED_PIN, red); 
  analogWrite(GREEN_PIN, green); 
  analogWrite(BLUE_PIN, blue); 
}

void setup()
{ 
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT); 
  pinMode(BLUE_PIN, OUTPUT);
} 

void loop()
{ 
  int i;
  for (i = 0; i < 256; i++)
  {
    setColor(i, i, i);
    delay(5);
  }
} 

