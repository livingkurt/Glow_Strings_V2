// =================== Section Flash White ===================

void section_flash()
{
  int rate = 10;
  int split_value = 5;
  int row = NUM_LEDS / split_value;
  int strobe = 0.5;
  int gap = 40;
  int rand = random(split_value);
  fill_solid(leds + row * rand, row, CHSV(255, 0, 255));
  FastLED.delay(strobe);
  FastLED.show();
  fill_solid(leds + row * rand, row, CHSV(0, 0, 0));
  FastLED.delay(gap);
  FastLED.show();
}

// =================== Section Flash Random ===================

void section_flash_random()
{
  int rate = 10;
  int split_value = 5;
  int row = NUM_LEDS / split_value;
  int strobe = 0.5;
  int gap = 40;
  int rand = random(split_value);
  fill_solid(leds + row * rand, row, CHSV(random(255), 255, 255));
  FastLED.delay(strobe);
  FastLED.show();
  fill_solid(leds + row * rand, row, CHSV(0, 0, 0));
  FastLED.delay(gap);
  FastLED.show();
}

// =================== Section Flash Rainbow Cycle ===================

void section_flash_rainbow_cycle()
{
  int rate = 10;
  int split_value = 5;
  int row = NUM_LEDS / split_value;
  int strobe = 0.5;
  int gap = 40;
  // int row = 5;
  int start_hue;
  int delta_hue = 5;

  start_hue = -1 * millis() / rate;
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  };
  FastLED.show();
  int rand = random(split_value);
  fill_solid(leds + row * rand, row, CHSV(255, 0, 255));
  FastLED.delay(strobe);
  start_hue += delta_hue;
  FastLED.show();
  fill_solid(leds + row * rand, row, CHSV(0, 0, 0));
  FastLED.delay(gap);
  FastLED.show();
}

// =================== Section Flash Rainbow Cycle Split ===================

void section_flash_rainbow_cycle_split()
{
  int rate = 10;
  int split_value = 5;
  int row = NUM_LEDS / split_value;
  int strobe = 0.5;
  int gap = 40;
  int start_hue;
  int delta_hue = 5;

  start_hue = -1 * millis() / rate;
  for (int i = 0; i < NUM_LEDS / 2; i++)
  {
    leds[i] = CHSV(start_hue, 255, 255);
    leds[NUM_LEDS - 1 - i] = CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  };
  FastLED.show();
  int rand = random(split_value);
  fill_solid(leds + row * rand, row, CHSV(255, 0, 255));
  FastLED.delay(strobe);
  start_hue += delta_hue;
  FastLED.show();
  fill_solid(leds + row * rand, row, CHSV(0, 0, 0));
  FastLED.delay(gap);
  FastLED.show();
}

// =================== Section Flash All Rainbow ===================

void section_flash_all_rainbow()
{
  int rate = 10;
  int split_value = 5;
  int row = NUM_LEDS / split_value;
  int strobe = 0.5;
  int gap = 40;
  // int row = 5;
  int start_hue;
  int delta_hue = 50;

  start_hue = -1 * millis() / rate;
  fill_solid(leds, NUM_LEDS, CHSV(start_hue, 255, 150)); // Set all to red.
  FastLED.show();
  int rand = random(split_value);
  fill_solid(leds + row * rand, row, CHSV(255, 0, 255));
  FastLED.delay(strobe);
  start_hue += delta_hue;
  FastLED.show();
  fill_solid(leds + row * rand, row, CHSV(0, 0, 0));
  FastLED.delay(gap);
  FastLED.show();
}

// =================== Section Flash All Fade ===================

void section_flash_all_fade()
{
  int rate = 10;
  int split_value = 5;
  int row = NUM_LEDS / split_value;
  int strobe = 0.5;
  int gap = 40;
  int rand = random(split_value);
  int start_hue;
  int delta_hue = 5;
  start_hue = -1 * millis() / rate;
  fill_solid(leds + row * rand, row, CHSV(start_hue, 255, 255));
  FastLED.delay(strobe);
  FastLED.show();
  fill_solid(leds + row * rand, row, CHSV(0, 0, 0));
  FastLED.delay(gap);
  FastLED.show();
  start_hue += delta_hue;
}