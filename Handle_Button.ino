uint32_t since_press = 0; // Tracks how long since last button press
bool was_pressed = false; // Tracks if the button was pressed in previous frame

void handle_button()
{
  bool pressed = digitalRead(PIN_BUTTON) == HIGH; // Button is pressed when pin is low
  bool changed = pressed != was_pressed;          // If pressed state has changed, we might need to act
  Serial.println(since_press);
  if (state == "modes")
  {
    modes(pressed, changed);
  }
  else if (state == "party_modes")
  {
    party_modes(pressed, changed);
  }
  else if (state == "colors")
  {
    colors(pressed, changed);
  }
  else if (state == "off")
  {
    off(pressed, changed);
  }
  since_press += 20;
  if (changed)
    since_press = 0;     // If state changed we need to reset since_press
  was_pressed = pressed; // Update was_pressed to this frame's button status
}

void modes(bool pressed, bool changed)
{
  if (pressed)
  { // and pressed
    if (since_press == 1000)
    {
      flash(255, 255);
    }
    else if (since_press == 2000)
    {
      if (autoplay)
      {
        flash(160, 255);
      }
      else
      {
        flash(96, 255);
      }
    }
    else if (since_press == 3000)
    {
      flash(64, 255);
    }
    else if (since_press == 4000)
    {
      flash(224, 255);
    }
  }
  else if (changed)
  { // if not pressed and changed (just released)
    if (since_press < 1000 && since_press != 0)
    { // if less than 500ms, sleep if conjuring and change mode if not
      Serial.println("Next pattern");
      nextMode(); // Change to the next pattern
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    { // if less than 2s, sleep
      // Turn Off Lights
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
      state = "off";
      last_state = "modes";
      EEPROM.write(0, 3);
    }
    else if (since_press < 3000 && since_press > 2000)
    { // if less than 4s, toggle conjure
      decide_autoplay();
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "party_modes";
      EEPROM.write(0, 1);
    }
    else if (since_press < 5000 && since_press > 4000)
    {
      state = "colors";
      EEPROM.write(0, 2);
    }
    else
    {
    }
  }
}
void party_modes(bool pressed, bool changed)
{
  if (pressed)
  { // and pressed
    if (since_press == 1000)
    {
      flash(255, 255);
    }
    else if (since_press == 2000)
    {
      if (random_interval)
      {
        flash(160, 255);
      }
      else
      {
        flash(96, 255);
      }
    }
    else if (since_press == 3000)
    {
      flash(224, 255);
    }
  }
  else if (changed)
  { // if not pressed and changed (just released)
    if (since_press < 1000 && since_press != 0)
    { // if less than 5000ms, sleep if conjuring and change mode if not
      Serial.println("Next Party Mode");
      nextPartyMode(); // Change to the next pattern
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    { // if less than 2s, sleep
      // Turn Off Lights
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
      state = "off";
      last_state = "modes";
      EEPROM.write(0, 2);
    }
    else if (since_press < 3000 && since_press > 2000)
    { // if less than 4s, toggle conjure
      decide_autoplay();
    }
    else if (since_press < 4000 && since_press > 3000)
    {
      state = "modes";
      EEPROM.write(0, 0);
    }
    else
    {
    }
  }
}
void colors(bool pressed, bool changed)
{
  if (pressed)
  { // and pressed
    if (since_press == 1000)
    {
      Serial.println(1000);
      // flash(32, 32, 32); // Flash white when chip will sleep (5000ms)
      flash(255, 255);
    }
    else if (since_press == 2000)
    {
      Serial.println(1000);
      // flash(32, 32, 32); // Flash white when chip will sleep (5000ms)
      flash(224, 255);
    }
  }
  else if (changed)
  { // if not pressed and changed (just released)

    if (since_press < 1000 && since_press != 0)
    { // if less than 5000ms, sleep if conjuring and change mode if not
      Serial.println("Next Color");
      nextHue();
      since_press = 0;
      return;
    }
    else if (since_press < 2000 && since_press > 1000)
    { // if less than 2s, sleep

      // Turn Off Lights
      fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
      FastLED.show();
      state = "off";
      last_state = "colors";
      EEPROM.write(0, 3);
    }
    else if (since_press < 3000 && since_press > 2000)
    { // if less than 2s, sleep
      Serial.println("Change States");
      state = "modes";
      EEPROM.write(0, 0);
    }
    else
    { // if more than 4s, lock light
    }
  }
}
void off(bool pressed, bool changed)
{
  if (pressed)
  { // and pressed
    if (since_press == 1000)
    {
      Serial.println(1000);
      flash(255, 0);
    }
  }
  else if (changed)
  { // if not pressed and changed (just released)
    if (since_press < 2000 && since_press > 1000)
    { // if less than 2s, sleep
      Serial.println("Change States");
      state = last_state;
      EEPROM.write(0, 0);
    }
    else
    { // if more than 4s, lock light
    }
  }
}