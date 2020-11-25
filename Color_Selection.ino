

void color_selection()
{
  fill_solid(leds, NUM_LEDS, CHSV(gCurrentHueNumber, 255, 255));
  FastLED.show();
}