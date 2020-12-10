void handle_mode_change()
{
  gModes[gCurrentModeNumber]();
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (autoplay && random_interval)
  {

    EVERY_N_SECONDS(random(1, 5))
    {
      nextMode();
    }
  }
  else if (autoplay)
  {
    EVERY_N_SECONDS(interval)
    {
      nextMode();
    }
  }
}

void handle_all_mode_change()
{
  gAllModes[gCurrentAllModeNumber]();
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (autoplay && random_interval)
  {

    EVERY_N_SECONDS(random(1, 5))
    {
      nextAllMode();
    }
  }
  else if (autoplay)
  {
    EVERY_N_SECONDS(interval)
    {
      nextAllMode();
    }
  }
}
void handle_party_mode_change()
{
  gPartyModes[gCurrentPartyModeNumber]();
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (autoplay && random_interval)
  {

    EVERY_N_SECONDS(random(1, 5))
    {
      nextPartyMode();
    }
  }
  else if (autoplay)
  {
    EVERY_N_SECONDS(interval)
    {
      nextPartyMode();
    }
  }
}

void enter_sleep()
{
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.show();
}

void color_selection()
{
  fill_solid(leds, NUM_LEDS, CHSV(gCurrentHueNumber, gCurrentSaturationNumber, gCurrentValueNumber));
  FastLED.show();
}

void state_selection()
{
  fill_solid(leds, NUM_LEDS, CHSV(gCurrentStateHueNumber, 255, 255));
  FastLED.show();
}

void setting_selection()
{
  fill_solid(leds, NUM_LEDS, CHSV(gCurrentSettingHueNumber, 255, 255));
  FastLED.show();
}
void interval_selection()
{
  fill_solid(leds, NUM_LEDS, CHSV(255, 255, gCurrentIntervalValueNumber));
  FastLED.show();
}