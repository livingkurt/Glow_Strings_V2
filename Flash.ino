// =================== Flash White ===================

void flash()
{
  uint8_t strobe = 10; // controls the interval between strobe flashes
  uint8_t gap = 30;    // controls the interval between strobe flashes

  if ((millis() / strobe) % 2)
  {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
  else if ((millis() / gap) % 2)
  {
    fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
  }
}

// =================== Flash White ===================

// void flash_white()
// {
//   int rate = 10;
//   int strobe = 10;
//   int gap = 30;
//   fill_solid(leds, NUM_LEDS, CHSV(255, 0, 255));
//   FastLED.delay(strobe);
//   FastLED.show();
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.delay(gap);
//   FastLED.show();
// }
void flash_white()
{
  uint8_t strobe = 10;
  uint8_t gap = 30;

  if ((millis() / strobe) % 2)
  {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
  else if ((millis() / gap) % 2)
  {
    fill_solid(leds, NUM_LEDS, CHSV(255, 0, determine_brightness_of_white()));
  }
}

// =================== Flash Red ===================

// void flash_red()
// {
//   int rate = 10;
//   int strobe = 10;
//   int gap = 30;
//   fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
//   FastLED.delay(strobe);
//   FastLED.show();
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.delay(gap);
//   FastLED.show();
// }
void flash_red()
{
  uint8_t strobe = 10; // controls the interval between strobe flashes
  uint8_t gap = 30;    // controls the interval between strobe flashes

  if ((millis() / strobe) % 2)
  {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
  else if ((millis() / gap) % 2)
  {
    fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
  }
}

// =================== Flash Random Color ===================

// void flash_random_color()
// {
//   int rate = 10;
//   int strobe = 10;
//   int gap = 30;
//   fill_solid(leds, NUM_LEDS, CHSV(flash_random_color_random_color, 255, 255));
//   FastLED.delay(strobe);
//   FastLED.show();
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.delay(gap);
//   FastLED.show();
// }
int flash_random_color_color = random(255);
void flash_random_color()
{
  uint8_t strobe = 10; // controls the interval between strobe flashes
  uint8_t gap = 30;    // controls the interval between strobe flashes

  if ((millis() / strobe) % 2)
  {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
  else if ((millis() / gap) % 2)
  {
    fill_solid(leds, NUM_LEDS, CHSV(gCurrentHueNumber, gCurrentSaturationNumber, gCurrentValueNumber));
  }
}

// =================== Flash Colors ===================

// int flash_random_color_color = random(255);
// void flash_colors()
// {
//   uint8_t strobe = 10; // controls the interval between strobe flashes
//   uint8_t gap = 30;    // controls the interval between strobe flashes
//   CRGB startColor(CRGB::Blue);
//   CRGB endColor(CRGB::Red);
//   CRGBPalette16 myPalette(startColor, endColor, startColor);

//   // // Start with the color at the beginning of the palette,
//   // // and choose colors from along the palette moving by a few
//   // // palette slots per pixel.
//   // static uint8_t startIndex = 0;
//   // startIndex = -1 * millis() / 10;

//   // for (int i = 0; i < NUM_LEDS; i++)
//   // {
//   //   leds[i] = ColorFromPalette(myPalette, startIndex, 255, LINEARBLEND);
//   //   startIndex += 10;
//   // };

//   if ((millis() / strobe) % 2)
//   {
//     fill_solid(leds, NUM_LEDS, CRGB::Black);
//   }
//   else if ((millis() / gap) % 2)
//   {
//     // fill_solid(leds, NUM_LEDS, CHSV(flash_random_color_color, 255, 255));
//     fill_palette(leds, NUM_LEDS, myPalette, 10, blendingType);
//   }
// }

// =================== Flash Red and Blue ===================

// void flash_red_and_blue()
// {
//   int rate = 10;
//   int strobe = 10;
//   int gap = 30;
//   fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
//   FastLED.delay(strobe);
//   FastLED.show();
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.delay(gap);
//   FastLED.show();
//   fill_solid(leds, NUM_LEDS, CHSV(160, 255, 255));
//   FastLED.delay(strobe);
//   FastLED.show();
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.delay(gap);
//   FastLED.show();
// }
int flash_red_and_blue_num = 0;
void flash_red_and_blue()
{
  uint8_t strobe = 10;
  uint8_t gap = 30;
  CRGB color = CRGB::Red;

  if ((millis() / strobe) % 2)
  {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
  else if ((millis() / gap) % 2)
  {
    if (flash_red_and_blue_num == 0)
    {
      color = CRGB::Blue;
      flash_red_and_blue_num = 1;
    }
    else if (flash_red_and_blue_num == 1)
    {
      color = CRGB::Red;
      flash_red_and_blue_num = 0;
    }
    fill_solid(leds, NUM_LEDS, color);
  }
}

// =================== Flash Rainbow ===================

// void flash_rainbow()
// {
//   int rate = 10;
//   int strobe = 10;
//   int gap = 30;

//   int start_hue;
//   int delta_hue = 5;

//   start_hue = -1 * millis() / rate;
//   for (int i = 0; i < NUM_LEDS; i++)
//   {
//     leds[i] = CHSV(start_hue, 255, 255);
//     start_hue += delta_hue;
//   };
//   FastLED.delay(strobe);
//   FastLED.show();
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.delay(gap);
//   FastLED.show();
// }

void flash_rainbow()
{
  uint8_t strobe = 10; // controls the interval between strobe flashes
  uint8_t gap = 30;    // controls the interval between strobe flashes
  int rate = 10;
  int start_hue;
  int delta_hue = 5;
  start_hue = -1 * millis() / rate;

  if ((millis() / strobe) % 2)
  {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  }
  else if ((millis() / gap) % 2)
  {
    // fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
    for (int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = CHSV(start_hue, 255, 255);
      start_hue += delta_hue;
    };
  }
}

// =================== Flash White Ramp ===================

void flash_white_ramp()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;
  fill_solid(leds, NUM_LEDS, CHSV(255, 0, determine_brightness_of_white()));
  FastLED.delay(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.delay(beatsin16(10, 5, 200));
  FastLED.show();
}

// void flash_white_ramp()
// {
//   uint8_t strobe = 10;                 // controls the interval between strobe flashes
//   uint8_t gap = beatsin16(10, 5, 200); // controls the interval between strobe flashes

//   if ((millis() / strobe) % 2)
//   {
//     fill_solid(leds, NUM_LEDS, CRGB::Black);
//   }
//   else if ((millis() / gap) % 2)
//   {
//     fill_solid(leds, NUM_LEDS, CHSV(255, 0, 150));
//   }
// }

// =================== Flash All Rainbow Ramp ===================

// void flash_all_rainbow_ramp()
// {
//   int rate = 10;
//   int strobe = 10;
//   int gap = 30;
//   int start_hue;
//   int delta_hue = 5;

//   start_hue = -1 * millis() / rate;
//   fill_solid(leds, NUM_LEDS, CHSV(start_hue, 255, 255));
//   FastLED.delay(strobe);
//   FastLED.show();
//   fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
//   FastLED.delay(beatsin16(10, 5, 200));
//   FastLED.show();
//   start_hue += delta_hue;
// }

int flash_all_rainbow_ramp_num = 0;

void flash_all_rainbow_ramp()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;
  // int start_hue;
  // int delta_hue = 5;

  // start_hue = -1 * millis() / rate;
  fill_solid(leds, NUM_LEDS, CHSV(flash_all_rainbow_ramp_num, 255, 255));
  FastLED.delay(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.delay(beatsin16(10, 5, 200));
  FastLED.show();
  // start_hue += delta_hue;
  flash_all_rainbow_ramp_num += 20;
}

// void flash_all_rainbow_ramp()
// {
//   uint8_t strobe = 10;                 // controls the interval between strobe flashes
//   uint8_t gap = beatsin16(10, 5, 200); // controls the interval between strobe flashes
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 5;
//   start_hue = -1 * millis() / rate;

//   if ((millis() / strobe) % 2)
//   {
//     fill_solid(leds, NUM_LEDS, CRGB::Black);
//   }
//   else if ((millis() / gap) % 2)
//   {
//     // fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
//     fill_solid(leds, NUM_LEDS, CHSV(start_hue, 255, 255));
//   }
// }

// =================== Flash Rainbow Ramp ===================

void flash_rainbow_ramp()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;
  int start_hue;
  int delta_hue = 5;

  start_hue = -1 * millis() / rate;
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  };
  FastLED.delay(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.delay(beatsin16(10, 5, 200));
  FastLED.show();
}

// void flash_rainbow_ramp()
// {
//   uint8_t strobe = 10;                 // controls the interval between strobe flashes
//   uint8_t gap = beatsin16(10, 5, 200); // controls the interval between strobe flashes
//   int rate = 10;
//   int start_hue;
//   int delta_hue = 5;
//   start_hue = -1 * millis() / rate;

//   if ((millis() / strobe) % 2)
//   {
//     fill_solid(leds, NUM_LEDS, CRGB::Black);
//   }
//   else if ((millis() / gap) % 2)
//   {
//     // fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255));
//     for (int i = 0; i < NUM_LEDS; i++)
//     {
//       leds[i] = CHSV(start_hue, 255, 255);
//       start_hue += delta_hue;
//     };
//   }
// }
