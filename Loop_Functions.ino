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
    Serial.print("Interval ");
    Serial.println(interval);
    Serial.print("Autoplay ");
    Serial.println(autoplay);
    if (interval == 60)
    {
      EVERY_N_SECONDS(60)
      {
        nextMode();
      }
    }
    else if (interval == 30)
    {
      EVERY_N_SECONDS(30)
      {
        nextMode();
      }
    }
    else if (interval == 10)
    {
      EVERY_N_SECONDS(10)
      {
        nextMode();
      }
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
    if (interval == 60)
    {
      EVERY_N_SECONDS(60)
      {
        nextPartyMode();
      }
    }
    else if (interval == 30)
    {
      EVERY_N_SECONDS(30)
      {
        nextPartyMode();
      }
    }
    else if (interval == 10)
    {
      EVERY_N_SECONDS(10)
      {
        nextPartyMode();
      }
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
    if (interval == 60)
    {
      EVERY_N_SECONDS(60)
      {
        nextAllMode();
      }
    }
    else if (interval == 30)
    {
      EVERY_N_SECONDS(30)
      {
        nextAllMode();
      }
    }
    else if (interval == 10)
    {
      EVERY_N_SECONDS(10)
      {
        nextAllMode();
      }
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

void back_choice()
{
  int rate = 10;
  int strobe = 10;
  int gap = 30;
  fill_solid(leds, NUM_LEDS, CHSV(255, 0, 100));
  FastLED.delay(strobe);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.delay(gap);
  FastLED.show();
}
