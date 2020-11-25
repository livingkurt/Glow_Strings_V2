

void color_selection()
{
  fill_solid(leds, NUM_LEDS, CHSV(gCurrentHueNumber, gCurrentSaturationNumber, gCurrentValueNumber));
  FastLED.show();
}