

// void shooting_star_white_bnf()
// {
//   fadeToBlackBy(leds, NUM_LEDS, determine_length());
//   leds[beatsin8(determine_speed(), 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
// }  // fadeToBlackBy(leds, NUM_LEDS, 30);
// leds[beatsin16(15, 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);

void shooting_star_white_bnf()
{
  fadeToBlackBy(leds, NUM_LEDS, 20);
  int pos = beatsin16(13, 0, NUM_LEDS - 1);
  leds[pos] += CHSV(255, 0, 255);
}
