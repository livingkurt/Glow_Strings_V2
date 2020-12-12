

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