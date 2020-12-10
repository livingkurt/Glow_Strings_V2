

// void split_shooting_star_one_way()
// {
//   int rate = 2;
//   int start_hue;
//   int delta_hue = 30;
//   start_hue = -1 * millis() / rate;
//   fadeToBlackBy(leds, NUM_LEDS, 75); //change fadeby to smaller or larger number to adjust the length of the tail.
//   uint8_t u;
//   u = beat8(50, 0); //BPM will allow you to adjust the speed the dot is moving.
//   // Forward 1/6
//   uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS / 10) * 2;
//   // Backward 2/6
//   uint16_t pos_2 = map(u, 0, 255, (NUM_LEDS / 10), (NUM_LEDS / 10) * 3);
//   // Forward 3/6
//   uint16_t pos_3 = map(u, 0, 255, (NUM_LEDS / 10) * 2, (NUM_LEDS / 10) * 4);
//   // Backward 4/6
//   uint16_t pos_4 = map(u, 0, 255, (NUM_LEDS / 10) * 3, (NUM_LEDS / 10) * 5);
//   // Forward 3/6
//   uint16_t pos_3 = map(u, 0, 255, (NUM_LEDS / 10) * 4, (NUM_LEDS / 10) * 6);
//   // Backward 4/6
//   uint16_t pos_4 = map(u, 0, 255, (NUM_LEDS / 10) * 5, (NUM_LEDS / 10) * 7);
//   // Forward 3/6
//   uint16_t pos_3 = map(u, 0, 255, (NUM_LEDS / 10) * 6, (NUM_LEDS / 10) * 8);
//   // Backward 4/6
//   uint16_t pos_4 = map(u, 0, 255, (NUM_LEDS / 10) * 7, (NUM_LEDS / 10) * 9);
//   // Forward 5/6
//   uint16_t pos_5 = map(u, 0, 255, (NUM_LEDS / 10) * 8, NUM_LEDS - 1);
//   // Backward 6/6
//   uint16_t pos_6 = map(u, 0, 255, (NUM_LEDS / 10) * 9, NUM_LEDS - 1);

//   leds[pos_1] = CHSV(start_hue, 255, 255);
//   // leds[pos_2] = CHSV(start_hue, 255, 255);
//   leds[pos_3] = CHSV(start_hue, 255, 255);
//   // leds[pos_4] = CHSV(start_hue, 255, 255);
//   leds[pos_5] = CHSV(start_hue, 255, 255);
//   // leds[pos_6] = CHSV(start_hue, 255, 255);
//   FastLED.show();
//   start_hue += delta_hue;
// }

// void split_shooting_star_one_way()
// {
//   int rate = 2;
//   int start_hue;
//   int delta_hue = 30;
//   start_hue = -1 * millis() / rate;
//   fadeToBlackBy(leds, NUM_LEDS, 75); //change fadeby to smaller or larger number to adjust the length of the tail.
//   uint8_t u;
//   u = beat8(50, 0); //BPM will allow you to adjust the speed the dot is moving.
//   // Forward 1/6
//   uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS / 6 * 2);
//   // Backward 2/6
//   uint16_t pos_2 = map(u, 0, 255, (NUM_LEDS / 6), (NUM_LEDS / 6) * 3);
//   // Forward 3/6
//   uint16_t pos_3 = map(u, 0, 255, (NUM_LEDS / 6) * 2, (NUM_LEDS / 6) * 4);
//   // Backward 4/6
//   uint16_t pos_4 = map(u, 0, 255, (NUM_LEDS / 6) * 3, (NUM_LEDS / 6) * 5);
//   // Forward 5/6
//   uint16_t pos_5 = map(u, 0, 255, (NUM_LEDS / 6) * 4, (NUM_LEDS / 6) * 6 - 1);
//   // Backward 6/6
//   // uint16_t pos_6 = map(u, 0, 255, (NUM_LEDS / 6) * 5, NUM_LEDS - 1);

//   leds[pos_1] = CHSV(start_hue, 255, 255);
//   leds[pos_2] = CHSV(start_hue, 255, 255);
//   leds[pos_3] = CHSV(start_hue, 255, 255);
//   leds[pos_4] = CHSV(start_hue, 255, 255);
//   leds[pos_5] = CHSV(start_hue, 255, 255);
//   // leds[pos_6] = CHSV(start_hue, 255, 255);
//   FastLED.show();
//   start_hue += delta_hue;
// }

void juggle_one_way()
{
  fadeToBlackBy(leds, NUM_LEDS, 20);
  int start_hue;
  int delta_hue = 25;
  start_hue = -1 * millis() / 10;
  for (int i = 0; i < 6; i++)
  {
    uint8_t u;
    u = beat8(i + 6, 0); //BPM will allow you to adjust the speed the dot is moving.
    // Forward 1/6
    uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
    leds[pos_1] |= CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  }
}