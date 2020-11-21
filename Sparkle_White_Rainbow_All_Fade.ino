

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
  // leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  // leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  // leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  // leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  // leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  // leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  // leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  // leds[random16(NUM_LEDS)] = CHSV(255, 0, 255);
  FastLED.show();
  hold(strobe);
  // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to Off.
  // FastLED.show();
  // hold(gap);

  fill_solid(leds, NUM_LEDS, CHSV(start_hue, 255, 200)); // Set all to red.
  FastLED.show();
  start_hue += delta_hue;
}