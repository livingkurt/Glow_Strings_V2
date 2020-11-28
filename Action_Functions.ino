void nextState()
{
  gCurrentStateNumber = (gCurrentStateNumber + 1) % ARRAY_SIZE(states);
  Serial.println({gCurrentStateNumber});
  gCurrentStateHueNumber = state_colors[gCurrentStateNumber];
  Serial.println({gCurrentStateHueNumber});
  // EEPROM.write(0, gCurrentStateNumber);
}
void nextMode()
{
  gCurrentModeNumber = (gCurrentModeNumber + 1) % ARRAY_SIZE(gModes);
  Serial.println({gCurrentModeNumber});
  EEPROM.write(1, gCurrentModeNumber);
}
void nextPartyMode()
{
  gCurrentPartyModeNumber = random_interval ? random(num_party_modes) : (gCurrentPartyModeNumber + 1) % ARRAY_SIZE(gPartyModes);
  Serial.println({gCurrentPartyModeNumber});
  EEPROM.write(2, gCurrentPartyModeNumber);
}
void nextAllMode()
{
  gCurrentAllModeNumber = random(num_all_modes) % ARRAY_SIZE(gAllModes);
  Serial.println({gCurrentAllModeNumber});
  EEPROM.write(3, gCurrentAllModeNumber);
}

void nextHue()
{
  gCurrentHueNumber = (gCurrentHueNumber + 15) % 255;
  Serial.println({gCurrentHueNumber});
  EEPROM.write(3, gCurrentHueNumber);
}

void nextSaturation()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentSaturationNumber = (gCurrentSaturationNumber - 51) % 255;
  Serial.println({gCurrentSaturationNumber});
  EEPROM.write(6, gCurrentSaturationNumber);
}

void nextValue()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentValueNumber = (gCurrentValueNumber - 51) % 255;
  Serial.println({gCurrentValueNumber});
  EEPROM.write(7, gCurrentValueNumber);
}
