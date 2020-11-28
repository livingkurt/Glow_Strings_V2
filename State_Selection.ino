

void state_selection()
{
  fill_solid(leds, NUM_LEDS, CHSV(gCurrentStateHueNumber, 255, 255));
  FastLED.show();
}