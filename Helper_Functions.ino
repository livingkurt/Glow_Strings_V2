void load_setting()
{
  // if (EEPROM.length())
  // {

  state = determine_state(EEPROM.read(0));
  Serial.println("Determine States");
  Serial.println(state);
  gCurrentModeNumber = EEPROM.read(1);
  gCurrentPartyModeNumber = EEPROM.read(2);
  gCurrentAllModeNumber = EEPROM.read(3);
  autoplay = EEPROM.read(4);
  random_interval = EEPROM.read(5);
  gCurrentHueNumber = EEPROM.read(6);
  gCurrentSaturationNumber = EEPROM.read(7);
  gCurrentValueNumber = EEPROM.read(8);
  random_order = EEPROM.read(9);
  interval = EEPROM.read(10);
  // }
}
void reset_setting()
{

  // state = "modes";
  gCurrentStateNumber = 0;        // EPPROM 0
  gCurrentStateHueNumber = 0;     // EPPROM 0
  gCurrentModeNumber = 0;         // EPPROM 1
  gCurrentPartyModeNumber = 0;    // EPPROM 2
  gCurrentAllModeNumber = 0;      // EPPROM 3
  autoplay = 1;                   // EPPROM 4
  random_interval = 1;            // EPPROM 5
  gCurrentHueNumber = 0;          // EPPROM 6
  gCurrentSaturationNumber = 255; // EPPROM 7
  gCurrentValueNumber = 255;      // EPPROM 8
  random_order = 0;               // EPPROM 9
  interval = 0;                   // EPPROM 9
  // EEPROM.write(0, 0);
  // EEPROM.write(1, 0);
  // EEPROM.write(2, 0);
  // EEPROM.write(3, 0);
  // EEPROM.write(4, 1);
  // EEPROM.write(5, 1);
  // EEPROM.write(6, 0);
  // EEPROM.write(7, 254);
  // EEPROM.write(8, 254);
  for (int i = 0; i < EEPROM.length(); i++)
  {
    EEPROM.write(i, 0);
  }
}

int determine_state(int state)
{

  if (state == 0)
  {
    return "modes";
  }
  else if (state == 1)
  {
    return "party_modes";
  }
  else if (state == 2)
  {
    return "colors";
  }
  else if (state == 3)
  {
    return "all_modes";
  }
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
