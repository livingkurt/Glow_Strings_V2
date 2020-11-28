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
int random_interval = true;

long state = "modes"; // Current state of the light
long last_state = ""; // Current state of the light

uint8_t gCurrentModeNumber = 0;
uint8_t gCurrentStateNumber = 0;
uint8_t gCurrentPartyModeNumber = 0;
uint8_t gCurrentAllModeNumber = 0;
uint8_t gCurrentHueNumber = 0;
uint8_t gCurrentSaturationNumber = 255;
uint8_t gCurrentValueNumber = 255;
// unsigned long current_millis;
// unsigned long previous_press_duration;
// unsigned long previous_button_millis;
// unsigned long pressed_millis;

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

const char *states[4] = {
    "modes",
    "party_modes",
    "colors",
    "all_modes",
};

int num_states = (sizeof(states) / sizeof(states[0]));
// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimpleStateColorsList[])();

const int *state_colors[4] = {
    0,
    32,
    64,
    96
    // 160,
    // 224,
    // 64,
    // 255,
};
int num_state_colors = (sizeof(state_colors) / sizeof(state_colors[0]));

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();

SimplePatternList gModes = {
    rainbow_cycle,
    sparkle_white,
    split_rainbow_2,
    shooting_star_white_bnf,
    sparkle_rainbow_all_fade,
    juggle,
    pulse_white,
    split_rainbow_4,
    sparkle_white_rainbow_all_fade,
    all_rainbow,
    juggle_white,
    bpm,
    sparkle_rainbow_saturation,
    shooting_star_rainbow_bnf,
    sparkle_rainbow_random,
    pulse_rainbow,
};
int num_modes = (sizeof(gModes) / sizeof(gModes[0]));

typedef void (*SimplePartyModeList[])();

SimplePartyModeList gPartyModes = {
    // wave_rainbow_shooting_star,
    // wave_white_shooting_star,
    // wave_white_shooting_star_split_2,
    // wave_rainbow_shooting_star_split_2,
    // wave_rainbow_split_2,
    // wave_white_split_2,
    // wave_rainbow,
    // shooting_star_mirror_white_bnf,
    // wave_white,
    section_flash_random,
    flash_red,
    section_flash,
    section_flash_all_fade,
    flash_red,
    section_flash_all_rainbow,
    flash_white,
    section_flash_rainbow_cycle,
    flash_rainbow,
    section_flash_rainbow_cycle_split,
};

int num_party_modes = (sizeof(gPartyModes) / sizeof(gPartyModes[0]));

typedef void (*SimpleAllModeList[])();

SimpleAllModeList gAllModes = {
    rainbow_cycle,
    sparkle_white,
    split_rainbow_2,
    shooting_star_white_bnf,
    sparkle_rainbow_all_fade,
    juggle,
    pulse_white,
    split_rainbow_4,
    sparkle_white_rainbow_all_fade,
    all_rainbow,
    juggle_white,
    bpm,
    sparkle_rainbow_saturation,
    shooting_star_rainbow_bnf,
    sparkle_rainbow_random,
    pulse_rainbow,
    section_flash_random,
    flash_red,
    section_flash,
    section_flash_all_fade,
    flash_red,
    section_flash_all_rainbow,
    flash_white,
    section_flash_rainbow_cycle,
    flash_rainbow,
    section_flash_rainbow_cycle_split,
};

int num_all_modes = (sizeof(gAllModes) / sizeof(gAllModes[0]));

void loop()
{
  // current_millis = millis() / 10;
  // Serial.println(current_millis);
  Serial.println(state);
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
  if (state == "state_select")
  {
    color_selection();
  }
  if (state == "all_modes")
  {
    handle_all_mode_change();
  }
  if (state == "enter_sleep")
  {
    enter_sleep();
  }
  handle_button();
}
