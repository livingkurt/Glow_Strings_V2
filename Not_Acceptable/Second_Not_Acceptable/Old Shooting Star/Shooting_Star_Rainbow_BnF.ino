

void shooting_star_rainbow_bnf()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length());
  int rate = 5;
  int start_hue;
  int delta_hue = 100;
  start_hue = -1 * millis() / rate;
  leds[beatsin8(determine_speed(), 0, NUM_LEDS - 1)] |= CHSV(start_hue, 255, 255);
  start_hue += delta_hue;
}