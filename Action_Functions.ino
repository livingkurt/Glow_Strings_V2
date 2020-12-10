void nextState()
{
  gCurrentStateNumber = (gCurrentStateNumber + 1) % ARRAY_SIZE(states);
  Serial.println(gCurrentStateNumber);
  gCurrentStateHueNumber = state_colors[gCurrentStateNumber];
  Serial.println(gCurrentStateHueNumber);
  // EEPROM.write(0, gCurrentStateNumber);
  EEPROM.write(0, gCurrentStateHueNumber);
}
void nextSetting()
{
  gCurrentSettingNumber = (gCurrentSettingNumber + 1) % ARRAY_SIZE(settings);
  Serial.println(gCurrentSettingNumber);
  gCurrentSettingHueNumber = setting_colors[gCurrentSettingNumber];
  Serial.println(gCurrentSettingHueNumber);
  // EEPROM.write(0, gCurrentSettingNumber);
  // EEPROM.write(0, gCurrentSettingHueNumber);
}
void nextInterval()
{
  gCurrentIntervalNumber = (gCurrentIntervalNumber + 1) % ARRAY_SIZE(intervals);
  Serial.println(gCurrentIntervalNumber);
  gCurrentIntervalValueNumber = interval_colors[gCurrentIntervalNumber];
  Serial.println(gCurrentIntervalValueNumber);
  // EEPROM.write(0, gCurrentSettingNumber);
  // EEPROM.write(0, gCurrentSettingHueNumber);
}
void nextMode()
{
  gCurrentModeNumber = random_order ? random(num_modes) : (gCurrentModeNumber + 1) % ARRAY_SIZE(gModes);
  Serial.println(gCurrentModeNumber);
  EEPROM.write(1, gCurrentModeNumber);
}
void nextPartyMode()
{
  gCurrentPartyModeNumber = random_order ? random(num_party_modes) : (gCurrentPartyModeNumber + 1) % ARRAY_SIZE(gPartyModes);
  Serial.println(gCurrentPartyModeNumber);
  EEPROM.write(2, gCurrentPartyModeNumber);
}
void nextAllMode()
{
  gCurrentAllModeNumber = random_order ? random(num_all_modes) : (gCurrentAllModeNumber + 1) % ARRAY_SIZE(gAllModes);
  Serial.println(gCurrentAllModeNumber);
  EEPROM.write(3, gCurrentAllModeNumber);
}

void decide_autoplay()
{
  if (autoplay)
  {
    autoplay = 0;
    Serial.println("Autoplay Off");
    EEPROM.write(4, 0);
    flash(160, 255, 255);
  }
  else
  {
    autoplay = 1;
    Serial.println("Autoplay On");
    EEPROM.write(4, 1);
    flash(96, 255, 255);
  }
}
void decide_random_order()
{
  if (random_order)
  {
    random_order = 0;
    Serial.println("Random Intverval Off");
    EEPROM.write(5, 0);
    flash(160, 255, 255);
  }
  else
  {
    random_order = 1;
    Serial.println("Intverval On");
    EEPROM.write(5, 1);
    flash(96, 255, 255);
  }
}
void decide_random_interval()
{
  if (random_interval)
  {
    random_interval = 0;
    Serial.println("Random Intverval Off");
    EEPROM.write(5, 0);
    flash(160, 255, 255);
  }
  else
  {
    random_interval = 1;
    Serial.println("Intverval On");
    EEPROM.write(5, 1);
    flash(96, 255, 255);
  }
}

void nextHue()
{
  gCurrentHueNumber = (gCurrentHueNumber + 15) % 255;
  Serial.println(gCurrentHueNumber);
  EEPROM.write(6, gCurrentHueNumber);
}

void nextSaturation()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentSaturationNumber = (gCurrentSaturationNumber - 51) % 255;
  Serial.println(gCurrentSaturationNumber);
  EEPROM.write(7, gCurrentSaturationNumber);
}

void nextValue()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentValueNumber = (gCurrentValueNumber - 51) % 255;
  Serial.println(gCurrentValueNumber);
  EEPROM.write(8, gCurrentValueNumber);
}
