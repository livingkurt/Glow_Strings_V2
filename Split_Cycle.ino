// =================== Split Rainbow 2 ===================

void split_cycle_rainbow_2()
{
  int rate = 10;
  int split_value = 2;
  int row = NUM_LEDS / split_value;
  int start_hue;
  int delta_hue = 5;

  start_hue = -1 * millis() / rate;
  for (int i = 0; i < row; i++)
  {
    leds[i] = CHSV(start_hue, 255, 255);
    leds[NUM_LEDS - 1 - i] = CHSV(start_hue, 255, 255);
    start_hue += delta_hue;
  };
  FastLED.show();
}

// =================== Split Red and Blue 2 ===================

void split_cycle_red_and_blue()
{

  // Define a color palette pre-filled with a gradient
  // that goes from startColor, to endColor (in the middle),
  // and back to startColor.
  int split_value = 2;
  int split = NUM_LEDS / split_value;
  CRGB startColor(CRGB::Blue);
  CRGB endColor(CRGB::Red);
  CRGBPalette16 myPalette(startColor, endColor, startColor);

  // Start with the color at the beginning of the palette,
  // and choose colors from along the palette moving by a few
  // palette slots per pixel.
  static uint8_t startIndex = 0;
  startIndex = -1 * millis() / 10;

  for (int i = 0; i < split; i++)
  {
    leds[i] = ColorFromPalette(myPalette, startIndex, 255, LINEARBLEND);
    leds[NUM_LEDS - 1 - i] = ColorFromPalette(myPalette, startIndex, 255, LINEARBLEND);
    startIndex += 10;
  };
  FastLED.show();
}