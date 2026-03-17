#include "wait.h"
#include "quantum.h"

uint8_t _hue_countdown = 50;
uint8_t _hue;
uint8_t _saturation;
uint8_t _value;

uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
    rgblight_sethsv(_hue_countdown * 5, 230, 70);
    _hue_countdown--;
    if (_hue_countdown == 0) {
        rgblight_sethsv(_hue, _saturation, _value);
        return 0;
    } else {
        return 50;
    }
}

void keyboard_post_init_user(void) {
    _hue = rgblight_get_hue();
    _saturation = rgblight_get_sat();
    _value = rgblight_get_val();
    defer_exec(50, flash_led, NULL);
}
