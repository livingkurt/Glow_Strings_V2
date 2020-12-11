

// void shooting_star_white()
// {
//   // fadeToBlackBy(leds, NUM_LEDS, 30); //change fadeby to smaller or larger number to adjust the length of the tail.
//   // int rate = 10;
//   // uint8_t u = beat8(50, 0); //BPM will allow you to adjust the speed the dot is moving.
//   // uint16_t pos = map(u, 0, 255, 0, NUM_LEDS);
//   // int start_hue;
//   // int delta_hue = 5;
//   // start_hue = -1 * millis() / rate;
//   // leds[pos] = CHSV(start_hue, 255, 255);
//   // FastLED.show();
//   // start_hue += delta_hue;
//   fadeToBlackBy(leds, NUM_LEDS, 30);
//   int pos1 = beatsin16(28, 0, NUM_LEDS);
//   int pos2 = beatsin16(23, 0, NUM_LEDS);
//   leds[(pos1 + pos2) / 2] += CHSV(255, 0, 255);
// }

// void shooting_star_white()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   start_hue = -1 * millis() / rate;
//   fadeToBlackBy(leds, NUM_LEDS, determine_length()); //change fadeby to smaller or larger number to adjust the length of the tail.
//   uint8_t u;
//   u = beat8(determine_speed(), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
//   leds[pos_1] = CHSV(start_hue, 0, 255);
//   FastLED.show();
//   start_hue += delta_hue;
// }

// uint16_t pos = 0;

// void shooting_star_white()
// {
//   fadeToBlackBy(leds, NUM_LEDS, 50);
//   if (pos >= NUM_LEDS - 1)
//   {
//     pos = 0;
//   }
//   else
//   {
//     pos++;
//   }
//   leds[pos] = CHSV(255, 0, 255);
//   FastLED.show();
// }
void shooting_star_white()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    fadeToBlackBy(leds, NUM_LEDS, 50);
    leds[i] += CHSV(255, 0, 255);
    FastLED.show();
  }
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.show();
}