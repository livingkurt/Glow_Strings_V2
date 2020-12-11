void pulse_rainbow()
{
  int strobe = 10;
  int start_hue;
  int rate = 50;
  int delta_hue = 5;
  start_hue = -1 * millis() / rate;
  fill_solid(leds, NUM_LEDS, CHSV(start_hue, 255, beatsin16(10, 50, 255))); // Set all to Off.
  FastLED.show();
  start_hue += delta_hue;
}