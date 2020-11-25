void nextMode()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentModeNumber = (gCurrentModeNumber + 1) % ARRAY_SIZE(gModes);
  Serial.println({gCurrentModeNumber});
  EEPROM.write(1, gCurrentModeNumber);
  // EEPROM.commit();
}
void nextPartyMode()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPartyModeNumber = (gCurrentPartyModeNumber + 1) % ARRAY_SIZE(gPartyModes);
  Serial.println({gCurrentPartyModeNumber});
  EEPROM.write(1, gCurrentPartyModeNumber);
  // EEPROM.commit();
}

void nextHue()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentHueNumber = (gCurrentHueNumber + 15) % 255;
  Serial.println({gCurrentHueNumber});
  EEPROM.write(2, gCurrentHueNumber);
  // EEPROM.commit();
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

  // since_press += 1000;
  return;
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

void load_setting()
{
  determine_state(EEPROM.read(0));
  gCurrentModeNumber = EEPROM.read(1);
  gCurrentHueNumber = EEPROM.read(2);
  autoplay = EEPROM.read(3);
  Serial.println(state);
}

void determine_state(int state)
{
  if (state == 0)
  {
    state = "modes";
  }
  else if (state == 1)
  {
    state = "colors";
  }
  else if (state == 3)
  {
    state = "party_modes";
  }
  else
  {
    state = "modes";
  }
  Serial.println(state);
}

void handle_mode_change()
{
  // Call the current pattern function once, updating the 'leds' array
  gModes[gCurrentModeNumber]();
  // gModes[random(num_modes)]();
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (autoplay)
  {
    EVERY_N_SECONDS(INTERVAL)
    {
      nextMode(); // change patterns periodically
    }
  }
}
void handle_party_mode_change()
{
  // Call the current pattern function once, updating the 'leds' array
  gPartyModes[gCurrentPartyModeNumber]();
  // gModes[random(num_modes)]();
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (autoplay)
  {
    EVERY_N_SECONDS(INTERVAL)
    {
      nextPartyMode(); // change patterns periodically
    }
  }
}