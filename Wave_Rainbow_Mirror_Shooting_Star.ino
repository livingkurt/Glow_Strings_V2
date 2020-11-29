void wave_rainbow_mirror_shooting_star()
{
  int rate = 10;
  int rand = random(10);
  int rand_length = random(NUM_LEDS);
  int split_value = 2;
  int row = NUM_LEDS / split_value;
  int strobe = rand;
  int start_hue;
  int delta_hue = 3;
  start_hue = -1 * millis() / rate;
  for (int i = 0; i < row; i++)
  {
    leds[(row) + i] = CHSV(start_hue, 255, 255);
    leds[row - 1 - i] = CHSV(start_hue, 255, 255);
    FastLED.delay(strobe);
    fadeToBlackBy(leds, NUM_LEDS, 100);
    FastLED.show();
    start_hue += delta_hue;
  }
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.show();
}