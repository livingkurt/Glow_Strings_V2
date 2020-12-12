// =================== Wave White ===================

void wave_white()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  static int last_pos = 0;
  start_hue = -1 * millis() / rate;
  uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
  while (last_pos != pos)
  {
    if (last_pos < pos)
    {
      last_pos++;
    }
    else
    {
      last_pos = 0;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    leds[last_pos] += CHSV(255, 0, 255);
  }
  start_hue += delta_hue;
}

// =================== Wave Rainbow ===================

void wave_all_rainbow()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 100;
  static int last_pos = 0;
  start_hue = -1 * millis() / rate;
  uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
  while (last_pos != pos)
  {
    if (last_pos < pos)
    {
      last_pos++;
    }
    else
    {
      last_pos = 0;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    leds[last_pos] += CHSV(start_hue, 255, 255);
  }
  start_hue += delta_hue;
}

// =================== Wave White Mirror ===================

void wave_white_mirror()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  static int last_pos_1 = NUM_LEDS / 2;
  static int last_pos_2 = NUM_LEDS / 2;
  start_hue = -1 * millis() / rate;
  uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS / 2, 0);
  uint16_t pos_1 = map(u, 0, 255, NUM_LEDS / 2, NUM_LEDS - 1);
  while (last_pos_1 != pos_1)
  {
    if (last_pos_1 < pos_1)
    {
      last_pos_1++;
    }
    else
    {
      last_pos_1 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    if (last_pos_2 > pos_2)
    {
      last_pos_2--;
    }
    else
    {
      last_pos_2 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    leds[last_pos_1] += CHSV(255, 0, 255);
    leds[last_pos_2] += CHSV(255, 0, 255);
  }
  start_hue += delta_hue;
}

// =================== Wave Rainbow Mirror ===================

void wave_rainbow_mirror()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  static int last_pos_1 = NUM_LEDS / 2;
  static int last_pos_2 = NUM_LEDS / 2;
  start_hue = -1 * millis() / rate;
  uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS / 2, 0);
  uint16_t pos_1 = map(u, 0, 255, NUM_LEDS / 2, NUM_LEDS - 1);
  while (last_pos_1 != pos_1)
  {
    if (last_pos_1 < pos_1)
    {
      last_pos_1++;
    }
    else
    {
      last_pos_1 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    if (last_pos_2 > pos_2)
    {
      last_pos_2--;
    }
    else
    {
      last_pos_2 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    leds[last_pos_1] += CHSV(start_hue, 255, 255);
    leds[last_pos_2] += CHSV(start_hue, 255, 255);
  }
  start_hue += delta_hue;
}

// =================== Wave White Shooting Star ===================

void wave_white_shooting_star()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  static int last_pos = 0;
  start_hue = -1 * millis() / rate;

  uint8_t u = beat8(random(10), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
  while (last_pos != pos)
  {
    if (last_pos < pos)
    {
      last_pos++;
    }
    else
    {
      last_pos = 0;
      // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      // FastLED.show();
    }
    fadeToBlackBy(leds, NUM_LEDS, 100); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_pos] += CHSV(255, 0, 255);
  }
  start_hue += delta_hue;
}

// =================== Wave Rainbow Shooting Star ===================

void wave_rainbow_shooting_star()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  static int last_pos = 0;
  start_hue = -1 * millis() / rate;

  uint8_t u = beat8(random(10), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
  while (last_pos != pos)
  {
    if (last_pos < pos)
    {
      last_pos++;
    }
    else
    {
      last_pos = 0;
      // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      // FastLED.show();
    }
    fadeToBlackBy(leds, NUM_LEDS, 100); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_pos] += CHSV(start_hue, 255, 255);
  }
  start_hue += delta_hue;
}

// =================== Wave White Shooting Star Mirror ===================

void wave_white_mirror_shooting_star()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  static int last_pos_1 = NUM_LEDS / 2;
  static int last_pos_2 = NUM_LEDS / 2;
  start_hue = -1 * millis() / rate;
  uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS / 2, 0);
  uint16_t pos_1 = map(u, 0, 255, NUM_LEDS / 2, NUM_LEDS - 1);
  while (last_pos_1 != pos_1)
  {
    if (last_pos_1 < pos_1)
    {
      last_pos_1++;
    }
    else
    {
      last_pos_1 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    if (last_pos_2 > pos_2)
    {
      last_pos_2--;
    }
    else
    {
      last_pos_2 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    fadeToBlackBy(leds, NUM_LEDS, 150); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_pos_1] += CHSV(255, 0, 255);
    leds[last_pos_2] += CHSV(255, 0, 255);
  }
  start_hue += delta_hue;
}

// =================== Wave Rainbow Shooting Star Mirror ===================

void wave_rainbow_mirror_shooting_star()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  static int last_pos_1 = NUM_LEDS / 2;
  static int last_pos_2 = NUM_LEDS / 2;
  start_hue = -1 * millis() / rate;
  uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
  uint16_t pos_2 = map(u, 0, 255, NUM_LEDS / 2, 0);
  uint16_t pos_1 = map(u, 0, 255, NUM_LEDS / 2, NUM_LEDS - 1);
  while (last_pos_1 != pos_1)
  {
    if (last_pos_1 < pos_1)
    {
      last_pos_1++;
    }
    else
    {
      last_pos_1 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    if (last_pos_2 > pos_2)
    {
      last_pos_2--;
    }
    else
    {
      last_pos_2 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    fadeToBlackBy(leds, NUM_LEDS, 150); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_pos_1] += CHSV(start_hue, 255, 255);
    leds[last_pos_2] += CHSV(start_hue, 255, 255);
  }
  start_hue += delta_hue;
}