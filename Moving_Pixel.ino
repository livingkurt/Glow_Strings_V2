// Modification of sinelon() in FastLED's DemoReel100 example
void cd77_sinelon_oneway()
{
  // a colored dot going in one direction with fading tail
  fadeToBlackBy(leds, NUM_LEDS, 500); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u = beat88(10, 0);          //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
  leds[pos] = CRGB::White;
  FastLED.show();
}
