// =================== Juggle White Bnf ===================

void juggle_white()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
  int start_hue;
  int delta_hue = 25;
  start_hue = -1 * millis() / 10;
  for (int i = 0; i < 6; i++)
  {
    leds[beatsin16(i + 6, 0, NUM_LEDS - 1)] |= CHSV(255, 0, 255);
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

    leds[beatsin16(i + 6, 0, NUM_LEDS - 1)] |= CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  }
}

// =================== Juggle White One Direction ===================

// void juggle_white_one_way()
// {
//   fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
//   for (int i = 0; i < determine_speed_juggle(); i++)
//   {
//     uint8_t u;
//     u = beat8(i + determine_speed_juggle(), 0); //BPM will allow you to adjust the speed the dot is moving.
//     uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
//     leds[pos_1] |= CHSV(255, 0, 255);
//   }
// }
void juggle_white_one_way()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
  for (int i = 0; i < determine_speed_juggle(); i++)
  {

    uint8_t u = beat8(i + determine_speed_juggle(), 0); //BPM will allow you to adjust the speed the dot is moving.
    uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
    leds[pos_1] |= CHSV(255, 0, 255);
  }
}

// =================== Juggle Rainbow One Direction ===================

void juggle_rainbow_one_way()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_juggle());
  int start_hue;
  int delta_hue = 25;
  start_hue = -1 * millis() / 10;
  for (int i = 0; i < determine_speed_juggle(); i++)
  {
    uint8_t u;
    u = beat8(i + determine_speed_juggle(), 0);
    uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
    leds[pos_1] |= CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  }
}

int determine_length_juggle()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 30;
    break;
  case 100:
    return 20;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 7;
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
    return 30;
    break;
  case 150:
    return 10;
    break;
  case 200:
    return 30;
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