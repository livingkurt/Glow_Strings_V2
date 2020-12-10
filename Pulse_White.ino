
void pulse_white()
{
  int strobe = 10;
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, beatsin16(10, 50, 200))); // Set all to Off.
  // fill_solid(leds, NUM_LEDS, CHSV(255, 0, 255)); // Set all to Off.
  FastLED.show();
}