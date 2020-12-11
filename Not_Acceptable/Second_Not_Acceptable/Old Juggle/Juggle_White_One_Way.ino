void juggle_white_one_way()
{
  fadeToBlackBy(leds, NUM_LEDS, 20);
  for (int i = 0; i < 6; i++)
  {
    uint8_t u;
    u = beat8(i + 6, 0); //BPM will allow you to adjust the speed the dot is moving.
    uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
    leds[pos_1] |= CHSV(255, 0, 255);
  }
}