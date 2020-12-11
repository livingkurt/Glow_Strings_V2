

// void shooting_star_rainbow()
// {
//   fadeToBlackBy(leds, NUM_LEDS, 30);
//   int rate = 5;
//   int start_hue;
//   int delta_hue = 100;
//   start_hue = -1 * millis() / rate;
//   leds[beatsin16(30, 0, NUM_LEDS - 1)] |= CHSV(start_hue, 255, 255);
//   start_hue += delta_hue;
//   fadeToBlackBy(leds, NUM_LEDS, 30);
//   leds[beat8(50, 0)] |= CHSV(255, 0, 255);
// }

void shooting_star_rainbow()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  start_hue = -1 * millis() / rate;
  fadeToBlackBy(leds, NUM_LEDS, determine_length()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u;
  u = beat8(determine_speed(), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
  leds[pos_1] = CHSV(start_hue, 255, 255);
  FastLED.show();
  start_hue += delta_hue;
}