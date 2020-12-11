

void shooting_star_mirror_white_bnf()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length());
  leds[beatsin8(determine_speed(), 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
  leds[beatsin8(determine_speed(), NUM_LEDS - 1, 0)] |= CHSV(255, 0, 255);
}