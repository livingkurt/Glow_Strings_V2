

void shooting_star_white_mirror()
{
  fadeToBlackBy(leds, NUM_LEDS, determine_length_shooting_star_mirror()); //change fadeby to smaller or larger number to adjust the length of the tail.
  uint8_t u;
  u = beat8(determine_speed_shooting_star_mirror(), 0); //BPM will allow you to adjust the speed the dot is moving.
  // Forward
  uint16_t pos_1 = map(u, 0, 255, 0, NUM_LEDS - 1);
  // Backward
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS - 1, 0);
  leds[pos_1] = CRGB::White;
  leds[pos_2] = CRGB::White;
  FastLED.show();
}

int determine_length_shooting_star_mirror()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 10;
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
int determine_speed_shooting_star_mirror()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 60;
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