
// =================== Pulse White ===================

void pulse_white()
{
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, beatsin16(10, 50, 200))); // Set all to Off.
  FastLED.show();
}

// =================== Pulse All Rainbow ===================

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

// =================== Pulse Desaturated Rainbow ===================

void pulse_desaturated_rainbow()
{
  int rate = 20;
  int start_hue;
  int delta_hue = 5;
  start_hue = -1 * millis() / rate;
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(start_hue, beatsin16(10, 50, 255), 255);
    start_hue += delta_hue;
  };
}
