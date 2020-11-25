// uint8_t state = STATE_PLAY; // Current state of the light
uint32_t since_press = 0; // Tracks how long since last button press
bool was_pressed = false; // Tracks if the button was pressed in previous frame

void handle_button()
{
  bool pressed = digitalRead(PIN_BUTTON) == HIGH; // Button is pressed when pin is low
  bool changed = pressed != was_pressed;          // If pressed state has changed, we might need to act
  Serial.println(since_press);
  // Serial.println("Hello");

  if (state == "modes")
  { // If playing

    if (pressed)
    { // and pressed
      if (since_press == 1000)
      {
        Serial.println(1000);
        if (autoplay)
        {
          flash(255, 255, 255);
        }
        else
        {
          flash(96, 255, 255);
        }
      }
      else if (since_press == 2000)
      {
        Serial.println(2000);
        flash(224, 255, 255);
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
        decide_autoplay();
      }
      else if (since_press < 3000 && since_press > 2000)
      { // if less than 4s, toggle conjure
        Serial.println("Entering Hue Menu");
        FastLED.show();
        state = "hue";
      }
    }
  }
  else if (state == "hue")
  { // If playing
    // state

    if (pressed)
    { // and pressed
      if (since_press == 1000)
      {
        Serial.println(1000);
        // flash(32, 32, 32); // Flash white when chip will sleep (500ms)
        flash(255, 255, 100);
      }
      // if (since_press == 2000)
      // {
      //   Serial.println(2000);
      //   // flash(0, 0, 128); // Flash blue when conjure will toggle (2s)
      //   flash(96, 0, 255);
      // }

      // else if (since_press == 3000)
      // {
      //   Serial.println(3000);
      //   // flash(128, 0, 0); // Flash red when chip will lock and sleep (4s)
      //   flash(160, 255, 255);
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
      // else if (since_press < 2000)
      // { // if less than 2s, sleep
      //   Serial.println("Entering Value Menu");
      //   state = "value";
      // }
      // else if (since_press < 3000)
      // { // if less than 4s, toggle conjure
      //   Serial.println("Entering Saturation Menu");
      //   state = "saturation";
      // }
      else if (since_press < 2000)
      { // if less than 4s, toggle conjure
        Serial.println("Entering Modes Menu");
        state = "modes";
      }
    }
  }
  // else if (state == "value")
  // { // If playing
  //   if (pressed)
  //   { // and pressed
  //     if (since_press == 1000)
  //     {
  //       Serial.println(1000);
  //       // flash(32, 32, 32); // Flash white when chip will sleep (500ms)

  //       flash(224, 255, 255);
  //     }
  //     if (since_press == 2000)
  //     {
  //       Serial.println(2000);
  //       // flash(0, 0, 128); // Flash blue when conjure will toggle (2s)
  //       flash(255, 0, 255);
  //     }

  //     else if (since_press == 3000)
  //     {
  //       Serial.println(3000);
  //       // flash(128, 0, 0); // Flash red when chip will lock and sleep (4s)
  //       flash(160, 255, 255);
  //     }
  //   }
  //   else if (changed)
  //   { // if not pressed and changed (just released)

  //     if (since_press < 1000 && since_press != 0)
  //     { // if less than 500ms, sleep if conjuring and change mode if not
  //       Serial.println("Next Color");
  //       nextValue();
  //       since_press = 0;
  //       return;
  //     }
  //     else if (since_press < 2000)
  //     { // if less than 2s, sleep
  //       Serial.println("Change States");
  //       state = "hue";
  //     }
  //     else if (since_press < 3000)
  //     { // if less than 4s, toggle conjure
  //       Serial.println("Change States");
  //       state = "saturation";
  //     }
  //     else if (since_press < 4000)
  //     { // if less than 4s, toggle conjure
  //       Serial.println("Change States");
  //       state = "modes";
  //     }
  //   }
  // }
  // else if (state == "saturation")
  // { // If playing
  //   if (pressed)
  //   { // and pressed
  //     if (since_press == 1000)
  //     {
  //       Serial.println(1000);
  //       // flash(32, 32, 32); // Flash white when chip will sleep (500ms)

  //       flash(224, 255, 255);
  //     }
  //     if (since_press == 2000)
  //     {
  //       Serial.println(2000);
  //       // flash(0, 0, 128); // Flash blue when conjure will toggle (2s)
  //       flash(255, 255, 100);
  //     }

  //     else if (since_press == 3000)
  //     {
  //       Serial.println(3000);
  //       // flash(128, 0, 0); // Flash red when chip will lock and sleep (4s)
  //       flash(255, 255, 255);
  //     }
  //   }
  //   else if (changed)
  //   { // if not pressed and changed (just released)

  //     if (since_press < 1000 && since_press != 0)
  //     { // if less than 500ms, sleep if conjuring and change mode if not
  //       Serial.println("Next Color");
  //       nextSaturation();
  //       since_press = 0;
  //       return;
  //     }
  //     else if (since_press < 2000)
  //     { // if less than 2s, sleep
  //       Serial.println("Change States");
  //       state = "hue";
  //     }
  //     else if (since_press < 3000)
  //     { // if less than 4s, toggle conjure
  //       Serial.println("Change States");
  //       state = "value";
  //     }
  //     else if (since_press < 4000)
  //     { // if less than 4s, toggle conjure
  //       Serial.println("Change States");
  //       state = "modes";
  //     }
  //   }
  // }
  since_press += 20;
  if (changed)
    since_press = 0;     // If state changed we need to reset since_press
  was_pressed = pressed; // Update was_pressed to this frame's button status
}