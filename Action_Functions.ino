// State
void nextState()
{
  gCurrentStateNumber = (gCurrentStateNumber + 1) % ARRAY_SIZE(states);
  // Serial.println(gCurrentStateNumber);
  gCurrentStateHueNumber = state_colors[gCurrentStateNumber];
  // Serial.println(gCurrentStateHueNumber);
  EEPROM.write(0, gCurrentStateNumber);
}

// Modes
void nextMode()
{
  gCurrentModeNumber = random_order ? random(num_modes) : (gCurrentModeNumber + 1) % ARRAY_SIZE(gModes);
  // Serial.println(gCurrentModeNumber);
  EEPROM.write(1, gCurrentModeNumber);
}
void nextPartyMode()
{
  gCurrentPartyModeNumber = random_order ? random(num_party_modes) : (gCurrentPartyModeNumber + 1) % ARRAY_SIZE(gPartyModes);
  // Serial.println(gCurrentPartyModeNumber);
  EEPROM.write(2, gCurrentPartyModeNumber);
}
void nextAllMode()
{
  gCurrentAllModeNumber = random(num_all_modes) % ARRAY_SIZE(gAllModes);
  // Serial.println(gCurrentAllModeNumber);
  EEPROM.write(3, gCurrentAllModeNumber);
}

// Colors
void nextHue()
{
  gCurrentHueNumber = (gCurrentHueNumber + 15) % 255;
  // Serial.println(gCurrentHueNumber);
  EEPROM.write(4, gCurrentHueNumber);
}

void nextSaturation()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentSaturationNumber = (gCurrentSaturationNumber - 51) % 255;
  // Serial.println(gCurrentSaturationNumber);
  EEPROM.write(5, gCurrentSaturationNumber);
}

void nextValue()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentValueNumber = (gCurrentValueNumber - 51) % 255;
  // Serial.println(gCurrentValueNumber);
  EEPROM.write(6, gCurrentValueNumber);
}

// Settings
void nextSetting()
{
  gCurrentSettingNumber = (gCurrentSettingNumber + 1) % ARRAY_SIZE(settings);
  // Serial.println(gCurrentSettingNumber);
  gCurrentSettingHueNumber = setting_colors[gCurrentSettingNumber];
  // Serial.println(gCurrentSettingHueNumber);
}

void nextInterval()
{
  gCurrentIntervalNumber = (gCurrentIntervalNumber + 1) % ARRAY_SIZE(intervals);
  // Serial.println(gCurrentIntervalNumber);
  gCurrentIntervalValueNumber = interval_colors[gCurrentIntervalNumber];
  // Serial.println(gCurrentIntervalValueNumber);
}

// Decisions
void decide_autoplay()
{
  if (autoplay)
  {
    autoplay = 0;
    // Serial.println("Autoplay Off");
    EEPROM.write(7, 0);
    flash(160, 255, 255);
  }
  else
  {
    autoplay = 1;
    // Serial.println("Autoplay On");
    EEPROM.write(7, 1);
    flash(96, 255, 255);
  }
}
void decide_random_order()
{
  if (random_order)
  {
    random_order = 0;
    // Serial.println("Random Order Off");
    EEPROM.write(8, 0);
    flash(160, 255, 255);
  }
  else
  {
    random_order = 1;
    // Serial.println("Random Order On");
    EEPROM.write(8, 1);
    flash(96, 255, 255);
  }
}
void decide_random_interval()
{
  if (random_interval)
  {
    random_interval = 0;
    // Serial.println("Random Intverval Off");
    EEPROM.write(9, 0);
    flash(160, 255, 255);
  }
  else
  {
    random_interval = 1;
    // if (!autoplay)
    // {
    //   autoplay = 1;
    // Serial.println("Autoplay Off");
    //   EEPROM.write(7, 0);
    // }
    // Serial.println("Random Intverval On");
    EEPROM.write(9, 1);
    flash(96, 255, 255);
  }
}

void decide_interval()
{
  if (interval == 60)
  {
    interval = 5;
    // Serial.println("Interval Off");
    EEPROM.write(10, 5);
    flash(160, 255, 255);
  }
  else
  {
    interval = 60;
    // Serial.println("Interval On");
    EEPROM.write(10, 60);
    flash(96, 255, 255);
  }
}

void update_state()
{
  EEPROM.write(0, gCurrentStateNumber);
  if (gCurrentStateNumber == 0)
  {
    state = "modes";
  }
  else if (gCurrentStateNumber == 1)
  {
    // if (random_interval = 0)
    // {
    //   random_interval = 1;
    // }
    // if (autoplay = 0)
    // {
    //   autoplay = 1;
    // }
    state = "party_modes";
  }
  else if (gCurrentStateNumber == 2)
  {
    state = "colors";
  }
  else if (gCurrentStateNumber == 3)
  {
    // if (random_order = 0)
    // {
    //   random_order = 1;
    // }
    // if (autoplay = 0)
    // {
    //   autoplay = 1;
    // }
    state = "all_modes";
  }
}

void update_setting()
{
  if (gCurrentSettingNumber == 0)
  {
    decide_autoplay();
    state = last_state;
  }
  else if (gCurrentSettingNumber == 1)
  {
    // decide_interval();
    // state = last_state;
    state = "interval_select";
  }
  else if (gCurrentSettingNumber == 2)
  {
    decide_random_order();
    state = last_state;
  }
  else if (gCurrentSettingNumber == 3)
  {
    decide_random_interval();
    state = last_state;
  }
  else if (gCurrentSettingNumber == 4)
  {
    // decide_save_settings();
    state = last_state;
  }
  gCurrentSettingNumber = 0;
}

void update_interval()
{
  if (gCurrentIntervalNumber == 0)
  {
    interval = 60;
    flash(255, 0, 255);
  }
  else if (gCurrentIntervalNumber == 1)
  {
    interval = 30;
    flash(255, 0, 170);
  }
  else if (gCurrentIntervalNumber == 2)
  {
    interval = 10;
    flash(255, 0, 85);
  }
  // Serial.print("Interval Number ");
  // Serial.println(gCurrentIntervalNumber);
  // Serial.print("Interval ");
  // Serial.println(interval);
  // else
  // {
  //   interval = 5;
  //   flash(255, 100, 255);
  // }
  state = last_state;
}

// void decide_save_settings()
// {
//   if (save_settings)
//   {
//     save_settings = 0;
// Serial.println("Save Settings Off");
//     EEPROM.write(11, 0);
//     flash(160, 255, 255);
//   }
//   else
//   {
//     save_settings = 1;
// Serial.println("Save Settings On");
//     EEPROM.write(11, 1);
//     flash(96, 255, 255);
//   }
// }