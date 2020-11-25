void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
  // Serial.println(gPatterns[gCurrentPatternNumber]);
}

void nextHue()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentHueNumber = (gCurrentHueNumber + 15) % 255;
  // Serial.println({gCurrentHueNumber});
}

// void nextSaturation()
// {
//   // Serial.println(state);
//   // if (state == "saturation")
//   // {
//   //   gCurrentSaturationNumber = (gCurrentSaturationNumber - 85) % 255;
//   //   Serial.println({gCurrentSaturationNumber});
//   // }
// }

// void nextValue()
// {
//   // Serial.println(state);
//   // if (state == "value")
//   // {
//   //   gCurrentValueNumber = (gCurrentValueNumber - 85) % 255;
//   //   Serial.println({gCurrentValueNumber});
//   // }
// }

int forwards(int length, int placement, int pos)
{
  return (length * placement) + pos;
}

int backwards(int length, int placement, int pos)
{
  return length * placement - 1 - pos;
}

void hold(int period)
{
  unsigned long time_now = 0;
  time_now = millis();
  while (millis() < time_now + period)
  {
    // FastLED.show();
  }
}

void flash(int color, int sat, int value)
{
  int gap = 200;
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();

  // since_press += 1000;
  return;
}

// void flash(uint8_t color, uint8_t sat, uint8_t value)
// {
//   for (uint8_t i = 0; i < 5; i++)
//   {
//     for (uint8_t j = 0; j < 200; j++)
//     {
//       if (j < 100)
//       {
//         // write_frame(0, 0, 0);
//         fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
//         FastLED.show();
//       }
//       else
//       {
//         // write_frame(r, g, b);
//         fill_solid(leds, NUM_LEDS, CHSV(color, sat, value)); // Set all to red.
//         FastLED.show();
//       }
//     }
//   }
//   // since_press += 100;
// }

void decide_autoplay()
{
  if (autoplay)
  {
    autoplay = false;
    Serial.println("Autoplay Off");
  }
  else
  {
    autoplay = true;
    Serial.println("Autoplay On");
  }
}