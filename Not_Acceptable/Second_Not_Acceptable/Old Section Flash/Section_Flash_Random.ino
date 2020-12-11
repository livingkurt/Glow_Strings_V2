void section_flash_random()
{
  int rate = 10;
  int split_value = 5;
  int row = NUM_LEDS / split_value;
  int strobe = 0.5;
  int gap = 40;
  int rand = random(split_value);
  fill_solid(leds + row * rand, row, CHSV(random(255), 255, 255));
  hold(strobe);
  FastLED.show();
  fill_solid(leds + row * rand, row, CHSV(0, 0, 0));
  hold(gap);
  FastLED.show();
}