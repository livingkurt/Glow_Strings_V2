void juggle_rainbow_one_way()
{
  fadeToBlackBy(leds, NUM_LEDS, 20);
  int start_hue;
  int delta_hue = 25;
  start_hue = -1 * millis() / 10;
  for (int i = 0; i < 6; i++)
  {
    uint8_t u;
    u = beat8(i + 6, 0);
    uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
    leds[pos_1] |= CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  }
}