

void shooting_star_rainbow()
{
  fadeToBlackBy(leds, NUM_LEDS, 30);
  int rate = 5;
  int start_hue;
  int delta_hue = 100;
  start_hue = -1 * millis() / rate;
  leds[beatsin16(30, 0, NUM_LEDS - 1)] |= CHSV(start_hue, 255, 255);
  start_hue += delta_hue;
  fadeToBlackBy(leds, NUM_LEDS, 30);
  leds[beat8(50, 0)] |= CHSV(255, 0, 255);
}