

void shooting_star_white_bnf()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_speed());
  leds[beatsin16(determine_length(), 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
}
