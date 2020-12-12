// =================== Sparkle White ===================

void sparkle_white()
{
  int strobe = 4;
  int gap = 5;
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  FastLED.show();
  FastLED.delay(strobe);
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to Off.
  FastLED.show();
  FastLED.delay(gap);
}

// =================== Sparkle Rainbow All Fade ===================

void sparkle_rainbow_all_fade()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 5;
  start_hue = -1 * millis() / rate;
  int strobe = 20;
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, 255, random(0, 255));
  FastLED.show();
  FastLED.delay(strobe);
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to Off.
  FastLED.show();
  start_hue += delta_hue;
}

// =================== Sparkle Rainbow Random ===================

void sparkle_rainbow_random()
{
  int rate = 10;
  int strobe = 20;
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(random(0, 255), 255, random(0, 255));
  FastLED.show();
  FastLED.delay(strobe);
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to Off.
  FastLED.show();
}

// =================== Sparkle Rainbow Saturation ===================

void sparkle_rainbow_saturation()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 5;
  start_hue = -1 * millis() / rate;
  int strobe = 20;
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  leds[random16(NUM_LEDS)] = CHSV(start_hue, random(127, 255), random(0, 255));
  FastLED.show();
  FastLED.delay(strobe);
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to Off.
  FastLED.show();
  start_hue += delta_hue;
}

// =================== Sparkle White Rainbow All Fade ===================

void sparkle_white_rainbow_all_fade()
{
  // int strobe = 20;
  int rate = 10;
  int start_hue;
  int delta_hue = 20;
  delta_hue = 20;
  start_hue = -1 * millis() / rate;
  int strobe = 4;
  int gap = 5;
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  FastLED.show();
  FastLED.delay(strobe);
  fill_solid(leds, NUM_LEDS, CHSV(start_hue, 255, 200)); // Set all to red.
  FastLED.show();
  start_hue += delta_hue;
}