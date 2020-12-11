// =================== Split Shooting Star White ===================

void split_shooting_star_white()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_split_shooting_star()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u;
  u = beat8(determine_speed_split_shooting_star(), 0); //BPM will allow you to adjust the speed the dot is moving.
  // Forward 1/6
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS / 6);
  // Backward 2/6
  uint16_t pos_2 = map(u, 0, 255, (NUM_LEDS / 6) * 2, 0);
  // Forward 3/6
  uint16_t pos_3 = map(u, 0, 255, (NUM_LEDS / 6), (NUM_LEDS / 6) * 3);
  // Backward 4/6
  uint16_t pos_4 = map(u, 0, 255, (NUM_LEDS / 6) * 4, (NUM_LEDS / 6) * 2);
  // Forward 5/6
  uint16_t pos_5 = map(u, 0, 255, (NUM_LEDS / 6) * 3, (NUM_LEDS / 6) * 5);
  // Backward 6/6
  uint16_t pos_6 = map(u, 0, 255, NUM_LEDS - 1, (NUM_LEDS / 6) * 4);

  leds[pos_1] = CHSV(255, 0, 255);
  leds[pos_2] = CHSV(255, 0, 255);
  leds[pos_3] = CHSV(255, 0, 255);
  leds[pos_4] = CHSV(255, 0, 255);
  leds[pos_5] = CHSV(255, 0, 255);
  leds[pos_6] = CHSV(255, 0, 255);
  FastLED.show();
}

// =================== Split Shooting Star Rainbow ===================

void split_shooting_star_rainbow()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  start_hue = -1 * millis() / rate;
  fadeToBlackBy(leds, NUM_LEDS, determine_length_split_shooting_star()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u;
  u = beat8(determine_speed_split_shooting_star(), 0); //BPM will allow you to adjust the speed the dot is moving.
  // Forward 1/6
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS / 6);
  // Backward 2/6
  uint16_t pos_2 = map(u, 0, 255, (NUM_LEDS / 6) * 2, 0);
  // Forward 3/6
  uint16_t pos_3 = map(u, 0, 255, (NUM_LEDS / 6), (NUM_LEDS / 6) * 3);
  // Backward 4/6
  uint16_t pos_4 = map(u, 0, 255, (NUM_LEDS / 6) * 4, (NUM_LEDS / 6) * 2);
  // Forward 5/6
  uint16_t pos_5 = map(u, 0, 255, (NUM_LEDS / 6) * 3, NUM_LEDS - 1);
  // Backward 6/6
  uint16_t pos_6 = map(u, 0, 255, NUM_LEDS - 1, (NUM_LEDS / 6) * 4);

  leds[pos_1] = CHSV(start_hue, 255, 255);
  leds[pos_2] = CHSV(start_hue, 255, 255);
  leds[pos_3] = CHSV(start_hue, 255, 255);
  leds[pos_4] = CHSV(start_hue, 255, 255);
  leds[pos_5] = CHSV(start_hue, 255, 255);
  leds[pos_6] = CHSV(start_hue, 255, 255);
  FastLED.show();
  start_hue += delta_hue;
}

int determine_length_split_shooting_star()
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
int determine_speed_split_shooting_star()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 50;
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