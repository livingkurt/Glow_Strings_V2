
void pulse_white()
{
  int strobe = 10;
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, beatsin16(10, 50, 150))); // Set all to Off.
  FastLED.delay(strobe);
  FastLED.show();
}