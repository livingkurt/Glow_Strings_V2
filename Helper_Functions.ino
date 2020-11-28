void load_setting()
{
  determine_state(EEPROM.read(0));
  gCurrentModeNumber = EEPROM.read(1);
  gCurrentHueNumber = EEPROM.read(2);
  autoplay = EEPROM.read(3);
  Serial.println(state);
}

int forwards(int length, int placement, int pos)
{
  return (length * placement) + pos;
}

int backwards(int length, int placement, int pos)
{
  return length * placement - 1 - pos;
}

void hold(int period)
{
  unsigned long time_now = 0;
  time_now = millis();
  while (millis() < time_now + period)
  {
    // FastLED.show();
  }
}

void decide_autoplay()
{
  if (autoplay)
  {
    autoplay = false;
    Serial.println("Autoplay Off");
    EEPROM.write(3, 0);
  }
  else
  {
    autoplay = true;
    Serial.println("Autoplay On");
    EEPROM.write(3, 1);
  }
}
void decide_random_interval()
{
  if (random_interval)
  {
    random_interval = false;
    Serial.println("Random Intverval Off");
    EEPROM.write(4, 0);
  }
  else
  {
    random_interval = true;
    Serial.println("Intverval On");
    EEPROM.write(4, 1);
  }
}

void determine_state(int state)
{
  if (state == 0)
  {
    state = "modes";
  }
  else if (state == 1)
  {
    state = "party_modes";
  }
  else if (state == 2)
  {
    state = "colors";
  }
  else if (state == 3)
  {
    state = "colors";
  }
  else
  {
    state = "modes";
  }
  return state;
  Serial.println(state);
}
