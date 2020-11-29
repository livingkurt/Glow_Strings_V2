void wave_white()
{
  int rand = random(10);
  int strobe = rand;
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(255, 0, 255);
    FastLED.show();
    FastLED.delay(strobe);
  }
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
}