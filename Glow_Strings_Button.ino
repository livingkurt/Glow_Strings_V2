#include <FastLED.h>
#include <JC_Button.h>

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

// Data Pin on Arduino
#define LED_PIN 5
// LED Chip Type
#define LED_TYPE WS2811
// Number of LEDs Used
#define NUM_LEDS 50
// The Order of RGB was wired on the chip
#define COLOR_ORDER RGB
// Interval Between Mode Changes
#define INTERVAL 15
// Choose Random or Not Random Mode Changes
#define RANDOM "Not Random"
// Choose Random or Not Random Mode Changes
int autoplay = true;

CRGB leds[NUM_LEDS];
Button myButton(2, true, true, 50); // Declare the button

#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 120

TBlendType blendingType; //tBlendType is a type of value like int/char/uint8_t etc., use to choose LINERBLEND and NOBLEND

void setup()
{
  delay(3000); // 3 second delay for recovery
  Serial.begin(9600);
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}
// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();

SimplePatternList gPatterns = {
    // section_flash,
    // section_flash_rainbow_cycle,
    // section_flash_rainbow_cycle_split,
    // section_flash_all_rainbow,
    // shooting_star_white_end_to_end,
    // wave_rainbow_shooting_star,
    // wave_white_shooting_star,
    // wave_white_shooting_star_split_2,
    // wave_rainbow_shooting_star_split_2,
    // wave_rainbow_split_2,
    // wave_white_split_2,
    // wave_white,
    // wave_rainbow,

    //    rainbow_cycle,
    //    sparkle_white,
    //    split_rainbow_2,
    //    shooting_star_white,
    //    sparkle_rainbow_all_fade,
    //    juggle,
    //    pulse_white,
    //    split_rainbow_4,
    //    sparkle_white_rainbow_all_fade,
    //    split_shooting_star_white_4,
    //    all_rainbow,
    //    juggle_white,
    //    bpm,
    //    sparkle_rainbow_saturation,
    //    shooting_star_rainbow,
    //    sparkle_rainbow_random,
    //    pulse_rainbow,
    pulse_rainbow,
    rainbow_cycle,
    sparkle_white,
    split_rainbow_2,
    // shooting_star_white,
    shooting_star_white_bnf,
    sparkle_rainbow_all_fade,
    juggle,
    pulse_white,
    split_rainbow_4,
    sparkle_white_rainbow_all_fade,
    //    split_shooting_star_white_4,
    all_rainbow,
    juggle_white,
    bpm,
    sparkle_rainbow_saturation,
    //    shooting_star_rainbow,
    shooting_star_rainbow_bnf,
    sparkle_rainbow_random,

};

int num_modes = (sizeof(gPatterns) / sizeof(gPatterns[0]));

uint8_t gCurrentPatternNumber = 0;

void loop()
{
  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();
  // gPatterns[random(num_modes)]();
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);
  if (autoplay)
  {
    EVERY_N_SECONDS(INTERVAL)
    {
      nextPattern(); // change patterns periodically
    }
  }

  readbutton();
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

// void nextPattern()
// {
//   // add one to the current pattern number, and wrap around at the end
//   if (RANDOM == "Random")
//   {
//     gCurrentPatternNumber = random(num_modes) % ARRAY_SIZE(gPatterns);
//   }
//   else
//   {
//     Serial.println(random(num_modes));
//     gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
//   }
// }
void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE(gPatterns);
  Serial.println({gCurrentPatternNumber});
}

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

boolean held;

void readbutton()
{
  myButton.read();

  if (myButton.isReleased())
  {
    held = myButton.releasedFor(1000);
    if (held)
    {
      // button has been pressed for one second
      Serial.println("Button Held 2000!  Stop Autoplay...   ");

      if (autoplay)
      {
        autoplay = false;
        flash(255);
      }
      else
      {
        autoplay = true;
        flash(160);
      }
      Serial.println(autoplay);
      // hold(2000);
      return;
    }
    return;
  }
  else if (myButton.wasPressed())
  {
    if (!held)
    {
      Serial.println("Button pressed!  Next pattern...   ");
      nextPattern(); // Change to the next pattern
      return;
    }
  }

  // else if (myButton.releasedFor(2000))
  // {
  //   // button has been pressed for one second
  //   Serial.println("Button Held 4000!  Stop Autoplay...   ");
  //   Serial.println(autoplay);
  //   if (autoplay)
  //   {
  //     autoplay = false;
  //     flash();
  //   }
  //   return;
  // }
} //end_readbutton

void flash(int color)
{
  int gap = 300;
  fill_solid(leds, NUM_LEDS, CHSV(color, 255, 255)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, 255, 255)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(color, 255, 255)); // Set all to red.
  hold(gap);
  FastLED.show();
  fill_solid(leds, NUM_LEDS, CHSV(0, 0, 0)); // Set all to red.
  hold(gap);
  FastLED.show();
  return;
}