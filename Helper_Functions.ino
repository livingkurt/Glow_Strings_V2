void load_setting()
{
  determine_state(EEPROM.read(0));
  gCurrentModeNumber = EEPROM.read(1);
  gCurrentPartyModeNumber = EEPROM.read(2);
  gCurrentAllModeNumber = EEPROM.read(3);
  autoplay = EEPROM.read(4);
  random_interval = EEPROM.read(5);
  gCurrentHueNumber = EEPROM.read(6);
  gCurrentSaturationNumber = EEPROM.read(7);
  gCurrentValueNumber = EEPROM.read(8);
}
void reset_setting()
{
  EEPROM.write(0, 0);
  EEPROM.write(1, 0);
  EEPROM.write(2, 0);
  EEPROM.write(3, 0);
  EEPROM.write(4, 1);
  EEPROM.write(5, 1);
  EEPROM.write(6, 0);
  EEPROM.write(7, 254);
  EEPROM.write(8, 254);
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
    state = "all_modes";
  }
  // else
  // {
  //   state = "modes";
  // }
  return state;
  Serial.println(state);
}
int determine_state_number(long state)
{
  if (state = "modes")
  {
    return 0;
  }
  else if (state = "party_modes")
  {
    return 1;
  }
  else if (state = "colors")
  {
    return 2;
  }
  else if (state = "all_modes")
  {
    return 3;
  }
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
