

void shooting_star_white()
{
  // fadeToBlackBy(leds, NUM_LEDS, 30); //change fadeby to smaller or larger number to adjust the length of the tail.
  // int rate = 10;
  // uint8_t u = beat8(50, 0); //BPM will allow you to adjust the speed the dot is moving.
  // uint16_t pos = map(u, 0, 255, 0, NUM_LEDS);
  // int start_hue;
  // int delta_hue = 5;
  // start_hue = -1 * millis() / rate;
  // leds[pos] = CHSV(start_hue, 255, 255);
  // FastLED.show();
  // start_hue += delta_hue;
  fadeToBlackBy(leds, NUM_LEDS, 30);
  int pos1 = beatsin16(28, 0, NUM_LEDS);
  int pos2 = beatsin16(23, 0, NUM_LEDS);
  leds[(pos1 + pos2) / 2] += CHSV(255, 0, 255);
}