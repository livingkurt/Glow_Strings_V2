// =================== Cycle Rainbow ===================

void cycle_rainbow()
{
  int start_index;
  start_index = -1 * millis() / 10;
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CHSV(start_index, 255, 255);
    start_index += 5;
  };
}

// =================== Cycle Gradient ===================

void cycle_gradient()
{

  // Define a color palette pre-filled with a gradient
  // that goes from startColor, to endColor (in the middle),
  // and back to startColor.
  CRGB startColor(CRGB::Blue);
  CRGB endColor(CRGB::Red);
  CRGBPalette16 myPalette(startColor, endColor, startColor);

  // Start with the color at the beginning of the palette,
  // and choose colors from along the palette moving by a few
  // palette slots per pixel.
  static uint8_t startIndex = 0;
  startIndex = -1 * millis() / 10;

  uint8_t incrementIndex = 128 / NUM_LEDS;

  fill_palette(leds, NUM_LEDS,
               startIndex, incrementIndex,
               myPalette,
               255, //full brightness
               LINEARBLEND);

  FastLED.show();
  startIndex += 50; // start further down the color palette each time.
}

// =================== Cycle Red and Blue ===================

void cycle_red_and_blue()
{

  // Define a color palette pre-filled with a gradient
  // that goes from startColor, to endColor (in the middle),
  // and back to startColor.
  CRGB startColor(CRGB::Blue);
  CRGB endColor(CRGB::Red);
  CRGBPalette16 myPalette(startColor, endColor, startColor);

  // Start with the color at the beginning of the palette,
  // and choose colors from along the palette moving by a few
  // palette slots per pixel.
  static uint8_t startIndex = 0;
  startIndex = -1 * millis() / 10;

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = ColorFromPalette(myPalette, startIndex, 255, LINEARBLEND);
    startIndex += 50;
  };
  FastLED.show();
}

// =================== Cycle Purple and Black ===================

void cycle_purple_and_black()
{

  // Define a color palette pre-filled with a gradient
  // that goes from startColor, to endColor (in the middle),
  // and back to startColor.
  CRGB startColor(CRGB::Black);
  CRGB endColor(CRGB::Purple);
  CRGBPalette16 myPalette(startColor, endColor, startColor);

  // Start with the color at the beginning of the palette,
  // and choose colors from along the palette moving by a few
  // palette slots per pixel.
  static uint8_t startIndex = 0;
  startIndex = -1 * millis() / 10;

  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = ColorFromPalette(myPalette, startIndex, 255, LINEARBLEND);
    startIndex += 50;
  };
  FastLED.show();
}