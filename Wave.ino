// =================== Wave White ===================

// void wave_white()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   static int last_pos = 0;
//   start_hue = -1 * millis() / rate;
//   uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
//   while (last_pos != pos)
//   {
//     if (last_pos < pos)
//     {
//       last_pos++;
//     }
//     else
//     {
//       last_pos = 0;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     leds[last_pos] += CHSV(255, 0, 200);
//   }
//   start_hue += delta_hue;
// }

uint16_t wave_white_pos = 0;

void wave_white()
{
  int rand_length = NUM_LEDS - 1;
  EVERY_N_MILLISECONDS(determine_ms_wave())
  {
    rand_length = random(NUM_LEDS);
  }
  int speed = random(5);
  static int last_wave_white_pos = 0;
  if (wave_white_pos >= rand_length)
  {
    wave_white_pos = 0;
  }
  else
  {
    wave_white_pos += determine_rate_wave();
  }
  while (last_wave_white_pos != wave_white_pos)
  {
    if (last_wave_white_pos < wave_white_pos)
    {
      last_wave_white_pos++;
    }
    else
    {
      last_wave_white_pos = 0;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    }
    // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_wave_white_pos] = CHSV(255, 0, determine_brightness_of_white());
  }
  FastLED.delay(random(speed));
}

// =================== Wave Rainbow ===================

// void wave_all_rainbow()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 100;
//   static int last_pos = 0;
//   start_hue = -1 * millis() / rate;
//   uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
//   while (last_pos != pos)
//   {
//     if (last_pos < pos)
//     {
//       last_pos++;
//     }
//     else
//     {
//       last_pos = 0;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     leds[last_pos] += CHSV(start_hue, 255, 255);
//   }
//   start_hue += delta_hue;
// }

uint16_t wave_rainbow_pos = 0;

void wave_all_rainbow()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 100;
  start_hue = -1 * millis() / rate;
  int rand_length = NUM_LEDS - 1;
  EVERY_N_MILLISECONDS(determine_ms_wave())
  {
    rand_length = random(NUM_LEDS);
  }
  int speed = random(5);
  static int last_wave_rainbow_pos = 0;
  if (wave_rainbow_pos >= rand_length)
  {
    wave_rainbow_pos = 0;
  }
  else
  {
    wave_rainbow_pos += determine_rate_wave();
  }
  while (last_wave_rainbow_pos != wave_rainbow_pos)
  {
    if (last_wave_rainbow_pos < wave_rainbow_pos)
    {
      last_wave_rainbow_pos++;
    }
    else
    {
      last_wave_rainbow_pos = 0;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    }
    // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_wave_rainbow_pos] = CHSV(start_hue, 255, 255);
  }
  FastLED.delay(random(speed));
  start_hue += delta_hue;
}

// =================== Wave White Shooting Star ===================

// void wave_white_shooting_star()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   static int last_pos = 0;
//   start_hue = -1 * millis() / rate;

//   uint8_t u = beat8(random(10), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
//   while (last_pos != pos)
//   {
//     if (last_pos < pos)
//     {
//       last_pos++;
//     }
//     else
//     {
//       last_pos = 0;
//       // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     fadeToBlackBy(leds, NUM_LEDS, 100); //change fadeby to smaller or larger number to adjust the length of the tail.
//     leds[last_pos] += CHSV(255, 0, 200);
//   }
//   start_hue += delta_hue;
// }

uint16_t wave_white_shooting_star_pos = 0;

void wave_white_shooting_star()
{
  int rand_length = NUM_LEDS - 1;
  EVERY_N_MILLISECONDS(determine_ms_wave())
  {
    rand_length = random(NUM_LEDS);
  }
  int speed = random(10);
  static int last_wave_white_shooting_star_pos = 0;
  if (wave_white_shooting_star_pos >= rand_length)
  {
    wave_white_shooting_star_pos = 0;
  }
  else
  {
    wave_white_shooting_star_pos += determine_rate_wave();
  }
  while (last_wave_white_shooting_star_pos != wave_white_shooting_star_pos)
  {
    if (last_wave_white_shooting_star_pos < wave_white_shooting_star_pos)
    {
      last_wave_white_shooting_star_pos++;
    }
    else
    {
      last_wave_white_shooting_star_pos = 0;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    }
    fadeToBlackBy(leds, NUM_LEDS, determine_length_wave()); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_wave_white_shooting_star_pos] = CHSV(255, 0, 255);
  }
  FastLED.delay(random(speed));
}
// =================== Wave Rainbow Shooting Star ===================

// void wave_rainbow_shooting_star()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   static int last_pos = 0;
//   start_hue = -1 * millis() / rate;

//   uint8_t u = beat8(random(10), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos = map(u, 0, 255, 0, NUM_LEDS - 1);
//   while (last_pos != pos)
//   {
//     if (last_pos < pos)
//     {
//       last_pos++;
//     }
//     else
//     {
//       last_pos = 0;
//       // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     fadeToBlackBy(leds, NUM_LEDS, 100); //change fadeby to smaller or larger number to adjust the length of the tail.
//     leds[last_pos] += CHSV(start_hue, 255, 255);
//   }
//   start_hue += delta_hue;
// }

uint16_t wave_rainbow_shooting_star_pos = 0;

void wave_rainbow_shooting_star()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  int rand_length = NUM_LEDS - 1;
  start_hue = -1 * millis() / rate;
  EVERY_N_MILLISECONDS(determine_ms_wave())
  {
    rand_length = random(NUM_LEDS);
  }
  int speed = random(10);
  static int last_wave_rainbow_shooting_star_pos = 0;
  if (wave_rainbow_shooting_star_pos >= rand_length)
  {
    wave_rainbow_shooting_star_pos = 0;
  }
  else
  {
    wave_rainbow_shooting_star_pos += determine_rate_wave();
  }
  while (last_wave_rainbow_shooting_star_pos != wave_rainbow_shooting_star_pos)
  {
    if (last_wave_rainbow_shooting_star_pos < wave_rainbow_shooting_star_pos)
    {
      last_wave_rainbow_shooting_star_pos++;
    }
    else
    {
      last_wave_rainbow_shooting_star_pos = 0;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    }
    fadeToBlackBy(leds, NUM_LEDS, determine_length_wave()); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_wave_rainbow_shooting_star_pos] = CHSV(start_hue, 255, 255);
  }
  FastLED.delay(random(speed));
  //   start_hue += delta_hue;
}

int determine_ms_wave()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 100;
    break;
  case 100:
    return 50;
    break;
  case 150:
    return 150;
    break;
  case 200:
    return 150;
    break;
  case 250:
    return 150;
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

int determine_rate_wave()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 1;
    break;
  case 100:
    return 50;
    break;
  case 150:
    return 5;
    break;
  case 200:
    return 5;
    break;
  case 250:
    return 5;
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

int determine_length_wave()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 200;
    break;
  case 100:
    return 50;
    break;
  case 150:
    return 150;
    break;
  case 200:
    return 150;
    break;
  case 250:
    return 150;
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

// =================== Wave White Mirror ===================

// void wave_white_mirror()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   static int last_pos_1 = NUM_LEDS / 2;
//   static int last_pos_2 = NUM_LEDS / 2;
//   start_hue = -1 * millis() / rate;
//   uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos_2 = map(u, 0, 255, NUM_LEDS / 2, 0);
//   uint16_t pos_1 = map(u, 0, 255, NUM_LEDS / 2, NUM_LEDS - 1);
//   while (last_pos_1 != pos_1)
//   {
//     if (last_pos_1 < pos_1)
//     {
//       last_pos_1++;
//     }
//     else
//     {
//       last_pos_1 = NUM_LEDS / 2;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     if (last_pos_2 > pos_2)
//     {
//       last_pos_2--;
//     }
//     else
//     {
//       last_pos_2 = NUM_LEDS / 2;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     leds[last_pos_1] += CHSV(255, 0, 200);
//     leds[last_pos_2] += CHSV(255, 0, 200);
//   }
//   start_hue += delta_hue;
// }

uint16_t wave_white_mirror_pos_1 = NUM_LEDS / 2 - 1;
uint16_t wave_white_mirror_pos_2 = NUM_LEDS / 2 + 1;

void wave_white_mirror()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  int rand_length = NUM_LEDS - 1;
  start_hue = -1 * millis() / rate;
  EVERY_N_MILLISECONDS(determine_ms_wave_mirror())
  {
    rand_length = random(NUM_LEDS / 2 - 1);
  }
  int speed = random(5, 20);
  static int last_wave_white_mirror_pos_1 = NUM_LEDS / 2 - 1;
  static int last_wave_white_mirror_pos_2 = NUM_LEDS / 2 + 1;
  if (wave_white_mirror_pos_1 > rand_length)
  {
    wave_white_mirror_pos_1 = NUM_LEDS / 2 - 1;
    // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    // FastLED.show();
  }
  else
  {
    wave_white_mirror_pos_1 -= determine_rate_wave_mirror();
  }
  if (wave_white_mirror_pos_2 > rand_length)
  {
    wave_white_mirror_pos_2 = NUM_LEDS / 2 + 1;
    // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    // FastLED.show();
  }
  else
  {
    wave_white_mirror_pos_2 += determine_rate_wave_mirror();
  }
  while (last_wave_white_mirror_pos_1 != wave_white_mirror_pos_1)
  {
    if (last_wave_white_mirror_pos_1 > wave_white_mirror_pos_1)
    {
      last_wave_white_mirror_pos_1--;
      // last_wave_white_mirror_pos_2++;
    }
    else
    {
      last_wave_white_mirror_pos_1 = NUM_LEDS / 2 - 1;
      // last_wave_white_mirror_pos_2 = NUM_LEDS / 2;
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
    }
    // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_wave_white_mirror_pos_1] = CHSV(255, 0, determine_brightness_of_white());
    // leds[last_wave_white_mirror_pos_2] = CHSV(255, 0, determine_brightness_of_white());
  }
  // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
  while (last_wave_white_mirror_pos_2 != wave_white_mirror_pos_2)
  {
    if (last_wave_white_mirror_pos_2 < wave_white_mirror_pos_2)
    {
      last_wave_white_mirror_pos_2++;
    }
    else
    {
      last_wave_white_mirror_pos_2 = NUM_LEDS / 2 + 1;
      // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      // FastLED.show();
    }
    // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_wave_white_mirror_pos_2] = CHSV(255, 0, determine_brightness_of_white());
  }
  // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
  // leds[wave_white_mirror_pos_1] = CHSV(start_hue, 0, 255);
  // leds[wave_white_mirror_pos_2] = CHSV(start_hue, 0, 255);
  FastLED.delay(random(speed));
  //   start_hue += delta_hue;
}

// =================== Wave Rainbow Mirror ===================

// void wave_rainbow_mirror()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   static int last_pos_1 = NUM_LEDS / 2;
//   static int last_pos_2 = NUM_LEDS / 2;
//   start_hue = -1 * millis() / rate;
//   uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos_2 = map(u, 0, 255, NUM_LEDS / 2, 0);
//   uint16_t pos_1 = map(u, 0, 255, NUM_LEDS / 2, NUM_LEDS - 1);
//   while (last_pos_1 != pos_1)
//   {
//     if (last_pos_1 < pos_1)
//     {
//       last_pos_1++;
//     }
//     else
//     {
//       last_pos_1 = NUM_LEDS / 2;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     if (last_pos_2 > pos_2)
//     {
//       last_pos_2--;
//     }
//     else
//     {
//       last_pos_2 = NUM_LEDS / 2;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     leds[last_pos_1] += CHSV(start_hue, 255, 255);
//     leds[last_pos_2] += CHSV(start_hue, 255, 255);
//   }
//   start_hue += delta_hue;
// }

uint16_t wave_rainbow_mirror_pos_1 = NUM_LEDS / 2;
uint16_t wave_rainbow_mirror_pos_2 = NUM_LEDS / 2;

void wave_rainbow_mirror()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  int rand_length = NUM_LEDS - 1;
  start_hue = -1 * millis() / rate;
  EVERY_N_MILLISECONDS(determine_ms_wave_mirror())
  {
    rand_length = random(NUM_LEDS / 2);
  }
  int speed = random(5, 20);
  static int last_wave_rainbow_mirror_pos_1 = NUM_LEDS / 2;
  static int last_wave_rainbow_mirror_pos_2 = NUM_LEDS / 2;
  if (wave_rainbow_mirror_pos_1 > rand_length)
  {
    wave_rainbow_mirror_pos_1 = NUM_LEDS / 2;
    fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  }
  else
  {
    wave_rainbow_mirror_pos_1 -= determine_rate_wave_mirror();
  }
  if (wave_rainbow_mirror_pos_2 > rand_length)
  {
    wave_rainbow_mirror_pos_2 = NUM_LEDS / 2;
    // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  }
  else
  {
    wave_rainbow_mirror_pos_2 += determine_rate_wave_mirror();
  }
  // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
  leds[wave_rainbow_mirror_pos_1] = CHSV(start_hue, 255, 255);
  leds[wave_rainbow_mirror_pos_2] = CHSV(start_hue, 255, 255);
  FastLED.delay(random(speed));
  //   start_hue += delta_hue;
}

// =================== Wave White Shooting Star Mirror ===================

// void wave_white_mirror_shooting_star()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   static int last_pos_1 = NUM_LEDS / 2;
//   static int last_pos_2 = NUM_LEDS / 2;
//   start_hue = -1 * millis() / rate;
//   uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos_2 = map(u, 0, 255, NUM_LEDS / 2, 0);
//   uint16_t pos_1 = map(u, 0, 255, NUM_LEDS / 2, NUM_LEDS - 1);
//   while (last_pos_1 != pos_1)
//   {
//     if (last_pos_1 < pos_1)
//     {
//       last_pos_1++;
//     }
//     else
//     {
//       last_pos_1 = NUM_LEDS / 2;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     if (last_pos_2 > pos_2)
//     {
//       last_pos_2--;
//     }
//     else
//     {
//       last_pos_2 = NUM_LEDS / 2;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     fadeToBlackBy(leds, NUM_LEDS, 150); //change fadeby to smaller or larger number to adjust the length of the tail.
//     leds[last_pos_1] += CHSV(255, 0, 200);
//     leds[last_pos_2] += CHSV(255, 0, 200);
//   }
//   start_hue += delta_hue;
// }

// uint16_t wave_white_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
// uint16_t wave_white_mirror_shooting_star_pos_2 = NUM_LEDS / 2;

// void wave_white_mirror_shooting_star()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   int rand_length = NUM_LEDS;
//   start_hue = -1 * millis() / rate;
//   EVERY_N_MILLISECONDS(determine_ms_wave_mirror())
//   {
//     rand_length = random(NUM_LEDS / 2);
//   }
//   int speed = random(5, 20);
//   static int last_wave_white_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
//   static int last_wave_white_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
//   if (wave_white_mirror_shooting_star_pos_1 > rand_length)
//   {
//     wave_white_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
//   }
//   else
//   {
//     wave_white_mirror_shooting_star_pos_1 -= determine_rate_wave_mirror();
//   }
//   if (wave_white_mirror_shooting_star_pos_2 > rand_length)
//   {
//     wave_white_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
//   }
//   else
//   {
//     wave_white_mirror_shooting_star_pos_2 += determine_rate_wave_mirror();
//   }
//   fadeToBlackBy(leds, NUM_LEDS, determine_length_wave_mirror()); //change fadeby to smaller or larger number to adjust the length of the tail.
//   leds[wave_white_mirror_shooting_star_pos_1] = CHSV(start_hue, 0, 255);
//   leds[wave_white_mirror_shooting_star_pos_2] = CHSV(start_hue, 0, 255);
//   FastLED.delay(random(speed));
//   //   start_hue += delta_hue;
// }

uint16_t wave_white_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
uint16_t wave_white_mirror_shooting_star_pos_2 = NUM_LEDS / 2;

void wave_white_mirror_shooting_star()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  int rand_length = NUM_LEDS;
  start_hue = -1 * millis() / rate;
  EVERY_N_MILLISECONDS(determine_ms_wave_mirror())
  {
    rand_length = random(NUM_LEDS / 2);
  }
  int speed = random(5, 20);
  static int last_wave_white_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
  static int last_wave_white_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
  if (wave_white_mirror_shooting_star_pos_1 > rand_length)
  {
    wave_white_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
    // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    // FastLED.show();
  }
  else
  {
    wave_white_mirror_shooting_star_pos_1 -= determine_rate_wave_mirror();
  }
  if (wave_white_mirror_shooting_star_pos_2 > rand_length)
  {
    wave_white_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
    // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
    // FastLED.show();
  }
  else
  {
    wave_white_mirror_shooting_star_pos_2 += determine_rate_wave_mirror();
  }
  while (last_wave_white_mirror_shooting_star_pos_1 != wave_white_mirror_shooting_star_pos_1)
  {
    if (last_wave_white_mirror_shooting_star_pos_1 > wave_white_mirror_shooting_star_pos_1)
    {
      last_wave_white_mirror_shooting_star_pos_1--;
      // last_wave_white_mirror_shooting_star_pos_2++;
    }
    else
    {
      last_wave_white_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
      // last_wave_white_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
      // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      // FastLED.show();
    }
    fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_wave_white_mirror_shooting_star_pos_1] = CHSV(255, 0, 255);
    // leds[last_wave_white_mirror_shooting_star_pos_2] = CHSV(255, 0, 255);
  }
  // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
  while (last_wave_white_mirror_shooting_star_pos_2 != wave_white_mirror_shooting_star_pos_2)
  {
    if (last_wave_white_mirror_shooting_star_pos_2 < wave_white_mirror_shooting_star_pos_2)
    {
      last_wave_white_mirror_shooting_star_pos_2++;
    }
    else
    {
      last_wave_white_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
      // fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      // FastLED.show();
    }
    fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
    leds[last_wave_white_mirror_shooting_star_pos_2] = CHSV(255, 0, 255);
  }
  // fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
  // leds[wave_white_mirror_shooting_star_pos_1] = CHSV(start_hue, 0, 255);
  // leds[wave_white_mirror_shooting_star_pos_2] = CHSV(start_hue, 0, 255);
  FastLED.delay(random(speed));
  //   start_hue += delta_hue;
}

// =================== Wave Rainbow Shooting Star Mirror ===================

// void wave_rainbow_mirror_shooting_star()
// {
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 30;
//   static int last_pos_1 = NUM_LEDS / 2;
//   static int last_pos_2 = NUM_LEDS / 2;
//   start_hue = -1 * millis() / rate;
//   uint8_t u = beat8(random(20), 0); //BPM will allow you to adjust the speed the dot is moving.
//   uint16_t pos_2 = map(u, 0, 255, NUM_LEDS / 2, 0);
//   uint16_t pos_1 = map(u, 0, 255, NUM_LEDS / 2, NUM_LEDS - 1);
//   while (last_pos_1 != pos_1)
//   {
//     if (last_pos_1 < pos_1)
//     {
//       last_pos_1++;
//     }
//     else
//     {
//       last_pos_1 = NUM_LEDS / 2;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     if (last_pos_2 > pos_2)
//     {
//       last_pos_2--;
//     }
//     else
//     {
//       last_pos_2 = NUM_LEDS / 2;
//       fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//       // FastLED.show();
//     }
//     fadeToBlackBy(leds, NUM_LEDS, 150); //change fadeby to smaller or larger number to adjust the length of the tail.
//     leds[last_pos_1] += CHSV(start_hue, 255, 255);
//     leds[last_pos_2] += CHSV(start_hue, 255, 255);
//   }
//   start_hue += delta_hue;
// }

uint16_t wave_rainbow_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
uint16_t wave_rainbow_mirror_shooting_star_pos_2 = NUM_LEDS / 2;

void wave_rainbow_mirror_shooting_star()
{
  int rate = 10;
  int start_hue;
  int delta_hue = 30;
  int rand_length = NUM_LEDS;
  start_hue = -1 * millis() / rate;
  EVERY_N_MILLISECONDS(determine_ms_wave_mirror())
  {
    rand_length = random(NUM_LEDS / 2);
  }
  int speed = random(5, 20);
  static int last_wave_rainbow_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
  static int last_wave_rainbow_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
  if (wave_rainbow_mirror_shooting_star_pos_1 > rand_length)
  {
    wave_rainbow_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
  }
  else
  {
    wave_rainbow_mirror_shooting_star_pos_1 -= determine_rate_wave_mirror();
  }
  if (wave_rainbow_mirror_shooting_star_pos_2 > rand_length)
  {
    wave_rainbow_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
  }
  else
  {
    wave_rainbow_mirror_shooting_star_pos_2 += determine_rate_wave_mirror();
  }
  // while (last_wave_rainbow_mirror_shooting_star_pos_1 != wave_rainbow_mirror_shooting_star_pos_1)
  // {
  //   if (last_wave_rainbow_mirror_shooting_star_pos_1 < wave_rainbow_mirror_shooting_star_pos_1)
  //   {
  //     last_wave_rainbow_mirror_shooting_star_pos_1--;
  //     last_wave_rainbow_mirror_shooting_star_pos_2++;
  //   }
  //   else
  //   {
  //     last_wave_rainbow_mirror_shooting_star_pos_1 = NUM_LEDS / 2;
  //     last_wave_rainbow_mirror_shooting_star_pos_2 = NUM_LEDS / 2;
  //     fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  //   }
  //   fadeToBlackBy(leds, NUM_LEDS, 200); //change fadeby to smaller or larger number to adjust the length of the tail.
  //   leds[last_wave_rainbow_mirror_shooting_star_pos_1] = CHSV(start_hue, 255, 200);
  //   leds[last_wave_rainbow_mirror_shooting_star_pos_2] = CHSV(start_hue, 255, 200);
  // }
  fadeToBlackBy(leds, NUM_LEDS, determine_length_wave_mirror()); //change fadeby to smaller or larger number to adjust the length of the tail.
  leds[wave_rainbow_mirror_shooting_star_pos_1] = CHSV(start_hue, 255, 255);
  leds[wave_rainbow_mirror_shooting_star_pos_2] = CHSV(start_hue, 255, 255);
  FastLED.delay(random(speed));
  //   start_hue += delta_hue;
}

int determine_ms_wave_mirror()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 200;
    break;
  case 100:
    return 50;
    break;
  case 150:
    return 300;
    break;
  case 200:
    return 300;
    break;
  case 250:
    return 300;
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

int determine_rate_wave_mirror()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 1;
    break;
  case 100:
    return 50;
    break;
  case 150:
    return 5;
    break;
  case 200:
    return 5;
    break;
  case 250:
    return 5;
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

int determine_length_wave_mirror()
{
  switch (NUM_LEDS)
  {
  case 50:
    return 200;
    break;
  case 100:
    return 50;
    break;
  case 150:
    return 150;
    break;
  case 200:
    return 150;
    break;
  case 250:
    return 150;
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
