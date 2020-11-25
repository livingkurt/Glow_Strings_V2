#include <FastLED.h>
#include <EEPROM.h>

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

#define PIN_BUTTON 2 // Pin for the button
int autoplay = true;

long state = "modes"; // Current state of the light
long last_state = ""; // Current state of the light

uint8_t gCurrentModeNumber = 0;
uint8_t gCurrentPartyModeNumber = 0;
uint8_t gCurrentHueNumber = 0;
uint8_t gCurrentSaturationNumber = 255;
uint8_t gCurrentValueNumber = 255;

CRGB leds[NUM_LEDS];
// Button myButton(2, true, true, 50); // Declare the button

#define BRIGHTNESS 255
#define FRAMES_PER_SECOND 120
#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

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

SimplePatternList gModes = {
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
    pulse_rainbow,
};
int num_modes = (sizeof(gModes) / sizeof(gModes[0]));

typedef void (*SimplePartyModeList[])();

SimplePartyModeList gPartyModes = {
    section_flash_all_rainbow,
    flash_rainbow,
    section_flash,
    section_flash_rainbow_cycle,
    section_flash_rainbow_cycle_split,

    // shooting_star_white_end_to_end,
};

int num_party_modes = (sizeof(gPartyModes) / sizeof(gPartyModes[0]));

void loop()
{
  // readbutton();
  if (state == "modes")
  {
    handle_mode_change();
  }
  if (state == "party_modes")
  {
    handle_party_mode_change();
  }
  if (state == "colors")
  {
    color_selection();
  }
  if (state == "off")
  {
    off();
  }
  handle_button();
}
