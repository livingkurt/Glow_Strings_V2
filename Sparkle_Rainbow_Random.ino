

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
  hold(strobe);
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to Off.
  FastLED.show();
}