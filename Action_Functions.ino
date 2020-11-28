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
  EEPROM.write(2, gCurrentAllModeNumber);
}

void nextHue()
{
  gCurrentHueNumber = (gCurrentHueNumber + 15) % 255;
  Serial.println({gCurrentHueNumber});
  EEPROM.write(3, gCurrentHueNumber);
}

// void nextSaturation()
// {
//   // add one to the current pattern number, and wrap around at the end
//   gCurrentSaturationNumber = (gCurrentSaturationNumber - 15) % 255;
//   Serial.println({gCurrentSaturationNumber});
// }

// void nextValue()
// {
//   // add one to the current pattern number, and wrap around at the end
//   gCurrentValueNumber = (gCurrentValueNumber - 15) % 255;
//   Serial.println({gCurrentValueNumber});
// }

void flash(int color, int sat)
{
  int gap = 200;
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, 255)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, 255)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, 255)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();

  // since_press += 1;
  return;
}