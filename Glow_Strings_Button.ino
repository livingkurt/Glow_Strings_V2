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

#define PIN_BUTTON 2 // Pin for the button

long state = "modes"; // Current state of the light
long last_state = ""; // Current state of the light

uint8_t gCurrentStateNumber = 0;        // EPPROM 0
uint8_t gCurrentStateHueNumber = 0;     // EPPROM 0
uint8_t gCurrentModeNumber = 0;         // EPPROM 1
uint8_t gCurrentPartyModeNumber = 0;    // EPPROM 2
uint8_t gCurrentAllModeNumber = 0;      // EPPROM 3
uint8_t autoplay = 1;                   // EPPROM 4
uint8_t random_interval = 1;            // EPPROM 5
uint8_t gCurrentHueNumber = 0;          // EPPROM 6
uint8_t gCurrentSaturationNumber = 255; // EPPROM 7
uint8_t gCurrentValueNumber = 255;      // EPPROM 8
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
  load_setting();
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
    96};
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
    section_flash_random,
    wave_white,
    section_flash,
    wave_rainbow,
    section_flash_all_fade,
    flash_red,
    wave_rainbow_mirror,
    section_flash_all_rainbow,
    wave_rainbow_shooting_star,
    flash_white,
    wave_white_mirror_shooting_star,
    section_flash_rainbow_cycle,
    wave_white_mirror,
    flash_rainbow,
    wave_rainbow_mirror_shooting_star,
    wave_white_shooting_star,
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
    wave_white,
    section_flash,
    wave_rainbow,
    section_flash_all_fade,
    flash_red,
    wave_rainbow_mirror,
    section_flash_all_rainbow,
    wave_rainbow_shooting_star,
    flash_white,
    wave_white_mirror_shooting_star,
    section_flash_rainbow_cycle,
    wave_white_mirror,
    flash_rainbow,
    wave_rainbow_mirror_shooting_star,
    wave_white_shooting_star,
    section_flash_rainbow_cycle_split,
};

int num_all_modes = (sizeof(gAllModes) / sizeof(gAllModes[0]));

uint32_t since_press = 0; // Tracks how long since last button press
bool was_pressed = false; // Tracks if the button was pressed in previous frame

void loop()
{
  // current_millis = millis() / 10;
  // Serial.println(current_millis);
  bool pressed = digitalRead(PIN_BUTTON) == HIGH; // Button is pressed when pin is low
  bool changed = pressed != was_pressed;          // If pressed state has changed, we might need to act

  if (!pressed)
  {
    if (state == "modes")
    {
      handle_mode_change();
    }
    if (state == "party_modes")
    {
      handle_party_mode_change();
    }
    if (state == "colors" || state == "value" || state == "saturation")
    {
      color_selection();
    }
    if (state == "state_select")
    {
      state_selection();
    }
    if (state == "all_modes")
    {
      handle_all_mode_change();
    }
    if (state == "enter_sleep")
    {
      enter_sleep();
    }
  }
  handle_button(pressed, changed);
}
