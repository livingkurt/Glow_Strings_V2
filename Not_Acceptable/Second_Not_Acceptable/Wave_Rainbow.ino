

// void wave_rainbow_split_2()
// {

//   int rate = 10;
//   int rand = random(10);
//   int strobe = rand;
//   int half = NUM_LEDS / 2;
//   int start_hue;
//   int delta_hue = 3;
//   start_hue = -1 * millis() / rate;
//   for (int i = half; i > 1; i--)
//   {
//     leds[i] += CHSV(start_hue, 255, 255);
//     leds[NUM_LEDS - 1 - i] += CHSV(start_hue, 255, 255);
//     hold(strobe);
//     FastLED.show();
//     start_hue += delta_hue;
//   }
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.show();
// }

// void wave_rainbow()
// {
//   int rand = random(10);
//   int rate = 5;
//   int strobe = rand;
//   int start_hue;
//   int delta_hue = 100;
//   start_hue = -1 * millis() / rate;
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     leds[i] = CHSV(start_hue, 255, 255);
//     FastLED.show();
//     FastLED.delay(strobe);
//   }
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
// }

void wave_rainbow()
{
  int rate = 10;
  int rand = random(determine_strobe());
  int rand_length = random(NUM_LEDS);
  int strobe = rand;
  int start_hue;
  int delta_hue = 3;
  start_hue = -1 * millis() / rate;
  for (int i = 0; i < rand_length; i++)
  {
    leds[i] += CHSV(start_hue, 255, 255);
    FastLED.delay(strobe);
    // fadeToBlackBy(leds, NUM_LEDS, 50);
    FastLED.show();
    start_hue += delta_hue;
  }
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.show();
}