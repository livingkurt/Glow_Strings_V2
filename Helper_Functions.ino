void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
  Serial.println({gCurrentPatternNumber});
}

void nextHue()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentHueNumber = (gCurrentHueNumber + 15) % 255;
  Serial.println({gCurrentHueNumber});
}

void nextSaturation()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentSaturationNumber = (gCurrentSaturationNumber - 15) % 255;
  Serial.println({gCurrentSaturationNumber});
}

void nextValue()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentValueNumber = (gCurrentValueNumber - 15) % 255;
  Serial.println({gCurrentValueNumber});
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

void flash(int color, int sat, int value)
{
  int gap = 200;
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
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
  }
  else
  {
    autoplay = true;
    Serial.println("Autoplay On");
  }
}