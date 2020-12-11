// =================== Flash White ===================

void flash_white()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;
  fill_solid(leds, NUM_LEDS, CHSV(255, 0, 255));
  hold(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  hold(gap);
  FastLED.show();
}

// =================== Flash Red ===================

void flash_red()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;
  fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
  hold(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  hold(gap);
  FastLED.show();
}

// =================== Flash Blue ===================

void flash_blue()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;
  fill_solid(leds, NUM_LEDS, CHSV(160, 255, 255));
  hold(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  hold(gap);
  FastLED.show();
}

// =================== Flash Red and Blue ===================

void flash_red_and_blue()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;
  fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
  hold(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(160, 255, 255));
  hold(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  hold(gap);
  FastLED.show();
}

// =================== Flash Rainbow ===================

void flash_rainbow()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;

  int start_hue;
  int delta_hue = 5;

  start_hue = -1 * millis() / rate;
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  };
  hold(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  hold(gap);
  FastLED.show();
}
