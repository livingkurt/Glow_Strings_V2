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
        Serial.println(1000);
        if (autoplay)
        {
          flash(255, 255);
        }
        else
        {
          flash(96, 255);
        }
      }
      else if (since_press == 2000)
      {
        Serial.println(2000);
        flash(224, 255);
      }

      // else if (since_press == 3000)
      // {
      //   Serial.println(3000);
      //   flash(224, 0);
      // }
      // since_press += 20;
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
        decide_autoplay();
      }
      else if (since_press < 3000 && since_press > 2000)
      { // if less than 4s, toggle conjure
        Serial.println("Color Choice");
        autoplay = false;
        Serial.println("Autoplay Off");
        // fill_solid(leds, NUM_LEDS, CHSV(255, 255, 255)); // Set all to red.
        gPatterns[15]();
        FastLED.show();
        op_state = "colors";
        EEPROM.write(0, 1);
        // EEPROM.commit();
        // since_press = 0;
      }
      else
      { // if more than 4s, lock light
        // settings.locked = 1; // set locked bit
        // enter_sleep();       // go to sleep
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

      // if (since_press == 2000)
      // {
      //   Serial.println(2000);
      //   // flash(0, 0, 128); // Flash blue when conjure will toggle (2s)
      //   flash(96, 255);
      // }

      // else if (since_press == 3000)
      // {
      //   Serial.println(3000);
      //   // flash(128, 0, 0); // Flash red when chip will lock and sleep (4s)
      //   flash(255, 0);
      // }
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
        Serial.println("Change States");
        op_state = "modes";
        EEPROM.write(0, 0);
      }
      // else if (since_press < 3000)
      // { // if less than 4s, toggle conjure

      // }
      // else
      // { // if more than 4s, lock light
      //   // settings.locked = 1; // set locked bit
      //   // enter_sleep();       // go to sleep
      // }
      // since_press = 0;
    }

    // if (settings.locked)
    // { // and locked
    //   if (pressed)
    //   { // and pressed
    //     if (since_press == 4000)
    //       flash(0, 128, 0); // Flash green when light will wake (2s)
    //     else if (since_press == 8000)
    //       flash(128, 0, 0); // Flash red when light will stay locked (4s)
    //   }
    //   else if (changed)
    //   { // if not pressed and changed (just released)
    //     if (since_press < 4000)
    //     {                   // if less than 2s, stay locked
    //       flash(128, 0, 0); // flash red
    //       enter_sleep();    // go to sleep
    //     }
    //     else if (since_press < 8000)
    //     {                        // if less than 4s, unlock
    //       settings.locked = 0;   // unset locked bit
    //       op_state = STATE_PLAY; // wake up and play
    //     }
    //     else
    //     {                   // if more than 4s, stay locked
    //       flash(128, 0, 0); // flash red
    //       enter_sleep();    // go to sleep
    //     }
    //   }
    // }
    // else
    // { // if not locked
    //   // if (pressed)
    //   // { // and pressed
    //   //   if (since_press == 4000)
    //   //     flash(56, 0, 56); // flash magenta after 2s (bundle switch)
    //   //   else if (since_press == 8000)
    //   //     flash(128, 0, 0); // flash red after 4s (lock light)
    //   // }
    //   // else if (changed)
    //   // { // if not pressed and changed (just released)
    //   //   if (since_press < 4000)
    //   //   { // if less than 2s, wake up and play
    //   //     op_state = STATE_PLAY;
    //   //   }
    //   //   else if (since_press < 8000)
    //   //   {                                                   // if less than 4s, switch bundles
    //   //     settings.bundle = (settings.bundle == 0) ? 1 : 0; // toggle bundle 1/2
    //   //     settings.conjure = 0;                             // deactivate conjure
    //   //     settings.mode = 0;                                // reset mode
    //   //     change_mode(0);                                   // change to mode 0
    //   //     op_state = STATE_PLAY;
    //   //   }
    //   //   else
    //   //   {                      // if more than 4s, lock light
    //   //     settings.locked = 1; // set lock bit
    //   //     enter_sleep();       // go to sleep
    //   //   }
    //   // }
    // }
  }
  since_press += 20;
  if (changed)
    since_press = 0;     // If state changed we need to reset since_press
  was_pressed = pressed; // Update was_pressed to this frame's button status
}