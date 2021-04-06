// =================== Juggle White Bnf ===================

void juggle_white()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
  int start_hue;
  int delta_hue = 25;
  start_hue = -1 * millis() / 10;
  for (int i = 0; i < 6; i++)
  {
    leds[beatsin16(i + determine_speed_juggle(), 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
    start_hue += delta_hue;
  }
}

// =================== Juggle Rainbow Bnf ===================

void juggle_rainbow()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
  int start_hue;
  int delta_hue = 25;
  start_hue = -1 * millis() / 10;
  for (int i = 0; i < 6; i++)
  {

    leds[beatsin16(i + determine_speed_juggle(), 0, NUM_LEDS - 1)] |= CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  }
}

int determine_length_juggle()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 5;
    break;
  case 100:
    return 50;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 10;
    break;
  case 250:
    return 10;
    break;
  case 300:
    return 7;
    break;
  case 400:
    return 5;
    break;
  case 500:
    return 2;
    break;
  default:
    break;
  }
}
int determine_speed_juggle()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 6;
    break;
  case 100:
    return 6;
    break;
  case 150:
    return 2;
    break;
  case 200:
    return 2;
    break;
  case 250:
    return 2;
    break;
  case 300:
    return 20;
    break;
  case 400:
    return 20;
    break;
  case 500:
    return 10;
    break;
  default:
    break;
  }
}

// =================== Juggle White One Direction ===================

// void juggle_white_one_way()
// {
//   fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
//   for (int i = 0; i < determine_speed_juggle(); i++)
//   {
//     uint8_t u = beat88(i + determine_speed_juggle(), 0); //BPM will allow you to adjust the speed the dot is moving.
//     uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
//     leds[pos_1] |= CHSV(255, 0, 255);
//   }
// }

void juggle_white_one_way()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle_one_way());
  int start_hue;
  int delta_hue = 25;
  start_hue = -1 * millis() / 10;
  for (int i = 0; i < 6; i++)
  {
    uint8_t u = beat88(i + determine_speed_juggle_one_way(), 0);
    uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
    leds[pos_1] |= CHSV(start_hue, 0, 255);
    start_hue += delta_hue;
  }
}

// void juggle_white_one_way()
// {
//   static int last_pos = 0;

//   for (int i = 0; i < 8; i++)
//   {
//     uint8_t u = beat8(i + 8, 0); //BPM will allow you to adjust the speed the dot is moving.
//     uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
//     fadeToBlackBy(leds, NUM_LEDS, 500);
//     while (last_pos != pos)
//     {
//       if (last_pos < pos)
//       {
//         last_pos++;
//       }
//       else
//       {
//         last_pos = 0;
//       }

//       // leds[last_pos] += CHSV(255, 0, 255);
//       leds[last_pos] |= CHSV(255, 0, 255);
//       // FastLED.show();
//       // leds[last_pos] = CHSV(0, 0, 0);
//       // FastLED.show();
//     }
//   }
// }

// =================== Juggle Rainbow One Direction ===================

// void juggle_rainbow_one_way()
// {
//   fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
//   int start_hue;
//   int delta_hue = 25;
//   start_hue = -1 * millis() / 10;
//   for (int i = 0; i < determine_speed_juggle(); i++)
//   {
//     uint8_t u = beat8(i + determine_speed_juggle(), 0);
//     uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
//     leds[pos_1] |= CHSV(start_hue, 255, 255);
//     start_hue += delta_hue;
//   }
// }
void juggle_rainbow_one_way()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle_one_way());
  int start_hue;
  int delta_hue = 25;
  start_hue = -1 * millis() / 10;
  for (int i = 0; i < 6; i++)
  {
    uint8_t u = beat88(i + determine_speed_juggle_one_way(), 0);
    uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
    leds[pos_1] |= CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  }
}
// =================== Juggle All Rainbow One Direction ===================

// void juggle_rainbow_one_way()
// {
//   fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
//   int start_hue;
//   int delta_hue = 25;
//   start_hue = -1 * millis() / 10;
//   for (int i = 0; i < determine_speed_juggle(); i++)
//   {
//     uint8_t u = beat8(i + determine_speed_juggle(), 0);
//     uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
//     leds[pos_1] |= CHSV(start_hue, 255, 255);
//     start_hue += delta_hue;
//   }
// }
// void juggle_all_rainbow_one_way()
// {
//   fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle_one_way());
//   int start_hue;
//   int delta_hue = 1;
//   start_hue = -1 * millis() / 10;
//   for (int i = 0; i < 6; i++)
//   {
//     uint8_t u = beat88(i + determine_speed_juggle_one_way(), 0);
//     uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
//     leds[pos_1] |= CHSV(start_hue, 255, 255);
//     start_hue += delta_hue;
//   }
// }

int determine_length_juggle_one_way()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 5;
    break;
  case 100:
    return 50;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 10;
    break;
  case 250:
    return 10;
    break;
  case 300:
    return 7;
    break;
  case 400:
    return 5;
    break;
  case 500:
    return 2;
    break;
  default:
    break;
  }
}
int determine_speed_juggle_one_way()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 20;
    break;
  case 100:
    return 20;
    break;
  case 150:
    return 15;
    break;
  case 200:
    return 15;
    break;
  case 250:
    return 15;
    break;
  case 300:
    return 20;
    break;
  case 400:
    return 20;
    break;
  case 500:
    return 10;
    break;
  default:
    break;
  }
}