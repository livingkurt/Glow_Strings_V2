// void wave_white()
// {
//   int rand = random(10);
//   int strobe = rand;
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     leds[i] = CHSV(255, 0, 255);
//     FastLED.show();
//     FastLED.delay(strobe);
//   }
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
// }

// void shooting_star_white_bnf()
// {
//   fadeToBlackBy(leds, NUM_LEDS, determine_speed());
//   leds[beatsin16(determine_length(), 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
// }

// void wave_white()
// {
//   // a colored dot sweeping back and forth, with fading trails
//   fadeToBlackBy(leds, NUM_LEDS, 30);
//   int pos = beat8(30) % NUM_LEDS - 1;
//   static int prevpos = 0;
//   int start_index;
//   start_index = -1 * millis() / 10;
//   CRGB color = ColorFromPalette(RainbowColors_p, start_index, 255, LINEARBLEND);
//   if (pos < prevpos)
//   {
//     fill_solid(leds + pos, (prevpos - pos) + 1, color);
//   }
//   else
//   {
//     fill_solid(leds + prevpos, (pos - prevpos) + 1, color);
//   }
//   start_index += 10;
//   prevpos = pos;
// }

// void wave_white()
// {
//   // a colored dot sweeping back and forth, with fading trails
//   fadeToBlackBy(leds, NUM_LEDS, 30);
//   uint8_t pos = beat8(20, NUM_LEDS); //BPM will allow you to adjust the speed the dot is moving.
//   static int prevpos = 0;
//   // int start_index;
//   // start_index = -1 * millis() / 10;
//   // CRGB color = ColorFromPalette(palettes[currentPaletteIndex], start_index, 255, blendMode == 0 ? NOBLEND : LINEARBLEND);

//   if (pos < prevpos)
//   {
//     fill_solid(leds + pos, (prevpos - pos) + 1, CHSV(255, 0, 255));
//   }
//   else
//   {
//     fill_solid(leds + prevpos, (pos - prevpos) + 1, CHSV(255, 0, 255));
//   }
//   // start_index += 10;
//   prevpos = pos;
// }

void wave_white()
{
  // a colored dot going in one direction with fading tail
  int rand = random(10);
  int speed = rand;
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
  // leds[pos - NUM_LEDS] = CRGB::Black;
  // FastLED.show();
  // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  // FastLED.show();
}