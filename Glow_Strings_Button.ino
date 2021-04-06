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
#define NUM_LEDS 250
// The Order of RGB was wired on the chip
#define COLOR_ORDER RGB

#define PIN_BUTTON 2 // Pin for the button

long state = "modes"; // Current state of the light
long last_state = ""; // Current state of the light

// State
uint8_t gCurrentStateNumber = 0;    // EPPROM 0
uint8_t gCurrentStateHueNumber = 0; // EPPROM 0
// Modes
uint8_t gCurrentModeNumber = 0;      // EPPROM 1
uint8_t gCurrentPartyModeNumber = 0; // EPPROM 2
uint8_t gCurrentAllModeNumber = 0;   // EPPROM 3
// Colors
uint8_t gCurrentHueNumber = 0;          // EPPROM 6
uint8_t gCurrentSaturationNumber = 255; // EPPROM 7
uint8_t gCurrentValueNumber = 255;      // EPPROM 8
// Settings Menu
uint8_t gCurrentSettingNumber = 0;
uint8_t gCurrentSettingHueNumber = 110;
// Interval
uint8_t gCurrentIntervalNumber = 0;
uint8_t gCurrentIntervalValueNumber = 255;
// Settings
uint8_t autoplay = 1;        // EPPROM 4
uint8_t random_order = 0;    // EPPROM 9
uint8_t random_interval = 0; // EPPROM 5
int interval = 60;           // EPPROM 10
uint8_t save_settings = 0;   // EPPROM 9

int DCgap = 250;           // max ms between clicks for a double click event
boolean DCwaiting = false; // whether we're waiting for a double click (down)
boolean DConUp = false;    // whether to register a double click on next release, or whether to wait and click

int short_press = 1000;
int menu_1_length = 2000;
int menu_2_length = 3000;
int menu_3_length = 4000;
int menu_4_length = 5000;
int menu_5_length = 6000;
int menu_6_length = 7000;

int color_2 = random(255);
int color_3 = random(255);
int color_4 = random(255);
int color_5 = random(255);
int color_6 = random(255);
int color_7 = random(255);
int color_8 = random(255);
int color_9 = random(255);
int color_10 = random(255);

// const int *random_colors[10] = {
//     random(255),
//     random(255),
//     random(255),
//     random(255),
//     random(255),
//     random(255),
//     random(255),
//     random(255),
//     random(255),
//     random(255),
// };

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
  // if (save_settings)
  // {
  //   load_setting();
  // }
}

const char *states[4] = {
    "modes",
    "party_modes",
    "colors",
    "all_modes",
};

int num_states = (sizeof(states) / sizeof(states[0]));

const int *state_colors[4] = {
    0,
    32,
    64,
    96};
int num_state_colors = (sizeof(state_colors) / sizeof(state_colors[0]));

const char *settings[5] = {
    "autoplay",
    "interval_length",
    "random_order",
    "random_interval",
    "back_to_modes",
    // "save_settings",
};

int num_settings = (sizeof(settings) / sizeof(settings[0]));

const int *setting_colors[5] = {
    110,
    130,
    150,
    170,
    190};

int num_setting_colors = (sizeof(setting_colors) / sizeof(setting_colors[0]));

const char *intervals[3] = {
    "long",
    "mid",
    "short",
};

int num_intervals = (sizeof(intervals) / sizeof(intervals[0]));

const int *interval_colors[3] = {
    255,
    170,
    85};

int num_interval_colors = (sizeof(interval_colors) / sizeof(interval_colors[0]));

// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();

SimplePatternList gModes = {
    // cycle_rainbow_and_black,
    // split_cycle_red_and_blue,
    // pulse_rainbow_speed,
    // wave_white_shooting_star,
    // cycle_rainbow_ramp,
    // juggle_all_rainbow_one_way,
    // wave_rainbow_mirror_shooting_star,
    // wave_white_mirror,
    // wave_rainbow_mirror,
    // wave_white_mirror_shooting_star,
    // wave_rainbow_mirror_shooting_star,
    // wave_white,
    // wave_all_rainbow,
    // wave_white_shooting_star,
    // wave_rainbow_shooting_star,
    // flash_white,
    // flash_red,
    // flash_random_color,
    // flash_red_and_blue,
    // flash_rainbow,
    // flash_white_ramp,
    // flash_all_rainbow_ramp,
    // flash_rainbow_ramp,
    // flash_colors,
    cycle_rainbow,
    sparkle_white,
    split_cycle_rainbow_2,
    shooting_star_white_bnf,
    juggle_rainbow,
    sparkle_rainbow_all_fade,
    juggle_white_one_way,
    cycle_all_rainbow_and_black,
    pulse_white,
    shooting_star_rainbow,
    cycle_color_and_black,
    sparkle_white_rainbow_all_fade,
    all_rainbow,
    shooting_star_white_mirror,
    split_shooting_star_rainbow,
    bpm,
    pulse_desaturated_rainbow,
    juggle_rainbow_one_way,
    shooting_star_white,
    sparkle_rainbow_saturation,
    juggle_white,
    shooting_star_rainbow_bnf,
    sparkle_rainbow_random,
    shooting_star_rainbow_mirror,
    pulse_rainbow,
    split_shooting_star_white,
};
int num_modes = (sizeof(gModes) / sizeof(gModes[0]));

typedef void (*SimplePartyModeList[])();

SimplePartyModeList gPartyModes = {
    flash_rainbow,
    // wave_white_mirror,
    section_flash_rainbow_cycle,
    wave_all_rainbow,
    cycle_red_and_blue_speed,
    flash_white_ramp,
    section_flash,
    juggle_rainbow_one_way,
    flash_rainbow_ramp,
    wave_white_shooting_star,
    flash_red,
    // wave_rainbow_mirror_shooting_star,
    section_flash_random,
    flash_white,
    // wave_rainbow_mirror,
    cycle_rainbow_speed,
    flash_all_rainbow_ramp,
    // wave_white_mirror_shooting_star,
    section_flash_all_rainbow,
    flash_red_and_blue,
    juggle_white_one_way,
    wave_rainbow_shooting_star,
    section_flash_all_fade,
    flash_random_color,
    wave_white,
    section_flash_rainbow_cycle_split,
};

int num_party_modes = (sizeof(gPartyModes) / sizeof(gPartyModes[0]));

typedef void (*SimpleAllModeList[])();

SimpleAllModeList gAllModes = {
    cycle_rainbow,
    sparkle_white,
    split_cycle_rainbow_2,
    shooting_star_white_bnf,
    juggle_rainbow,
    sparkle_rainbow_all_fade,
    juggle_white_one_way,
    cycle_all_rainbow_and_black,
    pulse_white,
    shooting_star_rainbow,
    cycle_color_and_black,
    sparkle_white_rainbow_all_fade,
    all_rainbow,
    shooting_star_white_mirror,
    split_shooting_star_rainbow,
    bpm,
    pulse_desaturated_rainbow,
    juggle_rainbow_one_way,
    shooting_star_white,
    sparkle_rainbow_saturation,
    juggle_white,
    shooting_star_rainbow_bnf,
    sparkle_rainbow_random,
    shooting_star_rainbow_mirror,
    pulse_rainbow,
    split_shooting_star_white,
    flash_rainbow,
    // wave_white_mirror,
    section_flash_rainbow_cycle,
    wave_all_rainbow,
    cycle_red_and_blue_speed,
    flash_white_ramp,
    section_flash,
    juggle_rainbow_one_way,
    flash_rainbow_ramp,
    wave_white_shooting_star,
    flash_red,
    // wave_rainbow_mirror_shooting_star,
    section_flash_random,
    flash_white,
    // wave_rainbow_mirror,
    cycle_rainbow_speed,
    flash_all_rainbow_ramp,
    // wave_white_mirror_shooting_star,
    section_flash_all_rainbow,
    flash_red_and_blue,
    juggle_white_one_way,
    wave_rainbow_shooting_star,
    section_flash_all_fade,
    flash_random_color,
    wave_white,
    section_flash_rainbow_cycle_split,

};
int num_all_modes = (sizeof(gAllModes) / sizeof(gAllModes[0]));

uint32_t since_press = 0; // Tracks how long since last button press
bool was_pressed = false; // Tracks if the button was pressed in previous frame

void loop()
{
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
    if (state == "setting_select")
    {
      setting_selection();
    }
    if (state == "interval_select")
    {
      interval_selection();
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
  FastLED.show();
}

// uint32_t since_press = 0;   // Tracks how long since last button press
// bool was_pressed = false;   // Tracks if the button was pressed in previous frame
// int buttonState;            // the current reading from the input pin
// int lastButtonState = HIGH; // the previous reading from the input pin

// // the following variables are unsigned longs because the time, measured in
// // milliseconds, will quickly become a bigger number than can be stored in an int.
// unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
// unsigned long debounceDelay = 10;   // the debounce time; increase if the output flickers

// void loop()
// {
//   bool reading = digitalRead(PIN_BUTTON) == HIGH;
//   bool changed = reading != was_pressed; // If pressed state has changed, we might need to act
//                                          // If the switch changed, due to noise or pressing:
//   if (reading != lastButtonState)
//   {
//     // reset the debouncing timer
//     lastDebounceTime = millis();
//   }
//   if ((millis() - lastDebounceTime) > debounceDelay)
//   {
//     // whatever the reading is at, it's been there for longer than the debounce
//     // delay, so take it as the actual current state:

//     // if the button state has changed:
//     if (reading != buttonState)
//     {
//       buttonState = reading;

//       // // only toggle the LED if the new button state is HIGH
//       // if (buttonState == HIGH) {
//       //   ledState = !ledState;
//       // }
//       if (!reading)
//       {
//         if (state == "modes")
//         {
//           handle_mode_change();
//         }
//         if (state == "party_modes")
//         {
//           handle_party_mode_change();
//         }
//         if (state == "colors" || state == "value" || state == "saturation")
//         {
//           color_selection();
//         }
//         if (state == "state_select")
//         {
//           state_selection();
//         }
//         if (state == "setting_select")
//         {
//           setting_selection();
//         }
//         if (state == "interval_select")
//         {
//           interval_selection();
//         }
//         if (state == "all_modes")
//         {
//           handle_all_mode_change();
//         }
//         if (state == "enter_sleep")
//         {
//           enter_sleep();
//         }
//       }
//     }
//     lastButtonState = reading;
//     handle_button(reading, changed);
//     FastLED.show();
//   }
// }
