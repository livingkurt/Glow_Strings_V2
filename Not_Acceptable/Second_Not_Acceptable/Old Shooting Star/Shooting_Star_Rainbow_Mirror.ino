

void shooting_star_rainbow_mirror()
{

  int rate = 2;
  int start_hue;
  int delta_hue = 30;
  start_hue = -1 * millis() / rate;
  fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star_mirror()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u;
  u = beat8(determine_speed_shooting_star_mirror(), 0); //BPM will allow you to adjust the speed the dot is moving.
  // Forward
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
  // Backward
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS - 1, 0);
  leds[pos_1] = CHSV(start_hue, 255, 255);
  leds[pos_2] = CHSV(start_hue, 255, 255);
  FastLED.show();
  start_hue += delta_hue;
}
