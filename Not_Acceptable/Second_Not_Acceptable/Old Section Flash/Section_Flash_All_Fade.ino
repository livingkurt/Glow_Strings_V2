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
  hold(strobe);
  FastLED.show();
  fill_solid(leds + row * rand, row, CHSV(0, 0, 0));
  hold(gap);
  FastLED.show();
  start_hue += delta_hue;
}