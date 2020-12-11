void load_setting()
{
  // State
  state = determine_state(EEPROM.read(0));
  // Modes
  gCurrentModeNumber = EEPROM.read(1);
  gCurrentPartyModeNumber = EEPROM.read(2);
  gCurrentAllModeNumber = EEPROM.read(3);
  // Colors
  gCurrentHueNumber = EEPROM.read(4);
  gCurrentSaturationNumber = EEPROM.read(6);
  gCurrentValueNumber = EEPROM.read(5);
  // Settings
  autoplay = EEPROM.read(7);
  random_order = EEPROM.read(8);
  random_interval = EEPROM.read(9);

  interval = EEPROM.read(10);
  save_settings = EEPROM.read(11);
}
void reset_setting()
{

  // State
  gCurrentStateNumber = 0; // EPPROM 0
  // Modes
  gCurrentStateHueNumber = 0;  // EPPROM 0
  gCurrentModeNumber = 0;      // EPPROM 1
  gCurrentPartyModeNumber = 0; // EPPROM 2
  gCurrentAllModeNumber = 0;   // EPPROM 3
  // Colors
  gCurrentHueNumber = 0;          // EPPROM 4
  gCurrentSaturationNumber = 255; // EPPROM 5
  gCurrentValueNumber = 255;      // EPPROM 6
  // Settings
  autoplay = 1;        // EPPROM 7
  random_order = 0;    // EPPROM 8
  random_interval = 0; // EPPROM 9
  interval = 60;       // EPPROM 10
  save_settings = 1;   // EPPROM 10

  for (int i = 0; i < EEPROM.length(); i++)
  {
    EEPROM.write(i, 0);
  }
  void (*resetFunc)(void) = 0; //declare reset function at address 0
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

int determine_length()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 30;
    break;
  case 100:
    return 20;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 7;
    break;
  case 300:
    return 7;
    break;
  case 400:
    return 5;
    break;
  case 500:
    return 2;
    break;
  default:
    break;
  }
}
int determine_speed()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 30;
    break;
  case 100:
    return 30;
    break;
  case 150:
    return 30;
    break;
  case 200:
    return 30;
    break;
  case 300:
    return 20;
    break;
  case 400:
    return 20;
    break;
  case 500:
    return 10;
    break;
  default:
    break;
  }
}
int determine_strobe()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 10;
    break;
  case 100:
    return 7;
    break;
  case 150:
    return 5;
    break;
  case 200:
    return 3;
    break;
  case 300:
    return 2;
    break;
  case 400:
    return 1;
    break;
  case 500:
    return 0;
    break;
  default:
    break;
  }
}