void handle_mode_change()
{
  // Call the current pattern function once, updating the 'leds' array
  gModes[gCurrentModeNumber]();
  // gModes[random(num_modes)]();
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (autoplay)
  {
    EVERY_N_SECONDS(INTERVAL)
    {
      nextMode(); // change patterns periodically
    }
  }
}

void handle_all_mode_change()
{
  // Call the current pattern function once, updating the 'leds' array
  gAllModes[gCurrentAllModeNumber]();
  // gModes[random(num_modes)]();
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (autoplay)
  {
    EVERY_N_SECONDS(INTERVAL)
    {
      nextAllMode(); // change patterns periodically
    }
  }
}
void handle_party_mode_change()
{
  // Call the current pattern function once, updating the 'leds' array
  gPartyModes[gCurrentPartyModeNumber]();
  // gModes[random(num_modes)]();
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (random_interval)
  {

    EVERY_N_SECONDS(random(1, 5))
    {
      nextPartyMode(); // change patterns periodically
    }
  }
  else
  {
    EVERY_N_SECONDS(INTERVAL)
    {
      nextPartyMode(); // change patterns periodically
    }
  }
}

void enter_sleep()
{
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
  FastLED.show();
}