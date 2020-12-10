

void shooting_star_white_mirror()
{
  fadeToBlackBy(leds, NUM_LEDS, 50); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u;
  u = beat8(20, 0); //BPM will allow you to adjust the speed the dot is moving.
  // Forward
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
  // Backward
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS - 1, 0);
  leds[pos_1] = CRGB::White;
  leds[pos_2] = CRGB::White;
  FastLED.show();
}