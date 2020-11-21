

void shooting_star_white_bnf()
{
  fadeToBlackBy(leds, NUM_LEDS, 30);
  leds[beatsin16(30, 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
}