// uint8_t op_state = STATE_PLAY; // Current state of the light
uint32_t since_press = 0; // Tracks how long since last button press
bool was_pressed = false; // Tracks if the button was pressed in previous frame

void handle_button()
{
  bool pressed = digitalRead(PIN_BUTTON) == HIGH; // Button is pressed when pin is low
  bool changed = pressed != was_pressed;          // If pressed state has changed, we might need to act
  Serial.println(since_press);
  // Serial.println("Hello");

  if (op_state == "modes")
  { // If playing

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
        flash(224, 255);
      }
    }
    else if (changed)
    { // if not pressed and changed (just released)
      if (since_press < 1000 && since_press != 0)
      { // if less than 500ms, sleep if conjuring and change mode if not
        Serial.println("Next pattern");
        nextPattern(); // Change to the next pattern
        since_press = 0;
        return;
      }
      else if (since_press < 2000 && since_press > 1000)
      { // if less than 2s, sleep
        // Turn Off Lights
        fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0));
        FastLED.show();
        op_state = "off";
        last_state = "modes";
        EEPROM.write(0, 2);
      }
      else if (since_press < 3000 && since_press > 2000)
      { // if less than 4s, toggle conjure
        decide_autoplay();
      }
      else if (since_press < 4000 && since_press > 3000)
      {
        op_state = "colors";
        EEPROM.write(0, 1);
      }
      else
      {
      }
    }
  }
  else if (op_state == "colors")
  { // If playing
    // op_state

    if (pressed)
    { // and pressed
      if (since_press == 1000)
      {
        Serial.println(1000);
        // flash(32, 32, 32); // Flash white when chip will sleep (500ms)
        flash(255, 255);
      }
      else if (since_press == 2000)
      {
        Serial.println(1000);
        // flash(32, 32, 32); // Flash white when chip will sleep (500ms)
        flash(224, 255);
      }
    }
    else if (changed)
    { // if not pressed and changed (just released)

      if (since_press < 1000 && since_press != 0)
      { // if less than 500ms, sleep if conjuring and change mode if not
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
        op_state = "off";
        last_state = "colors";
        EEPROM.write(0, 2);
      }
      else if (since_press < 3000 && since_press > 2000)
      { // if less than 2s, sleep
        Serial.println("Change States");
        op_state = "modes";
        EEPROM.write(0, 0);
      }
      else
      { // if more than 4s, lock light
      }
    }
  }
  else if (op_state == "off")
  { // If playing
    // op_state
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
        op_state = last_state;
        EEPROM.write(0, 0);
      }
      else
      { // if more than 4s, lock light
      }
    }
  }
  since_press += 20;
  if (changed)
    since_press = 0;     // If state changed we need to reset since_press
  was_pressed = pressed; // Update was_pressed to this frame's button status
}