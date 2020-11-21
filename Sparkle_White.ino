

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
  hold(strobe);
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to Off.
  FastLED.show();
  hold(gap);
}
