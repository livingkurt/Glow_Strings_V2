

void shooting_star_mirror_white_bnf()
{
  fadeToBlackBy(leds, NUM_LEDS, 30);
  leds[beatsin16(30, 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
  leds[beatsin16(30, NUM_LEDS - 1, 0)] |= CHSV(255, 0, 255);
}