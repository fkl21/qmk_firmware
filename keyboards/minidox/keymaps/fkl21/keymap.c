// fkl21' Minidox keymap (adapted from dustypomerleau)

// Links:
// - [KeyCodes and More](https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes)
// - [KEYCODES](https://docs.qmk.fm/#/keycodes)
// - [FAQs w/ ANSI/ISO etc. graphics and codes](https://docs.qmk.fm/#/faq_keymap)
// - https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum my_layers {
  _CMK_DHM,
  _NEO2,
  _QWERTY,
  _GAMING,
  _GAMING2,
  _SYS,
  _NAV,
  _NUM_E,
  _NUM_N,
  _SYM,
  _SYM_NEO
};

enum my_keycodes {
  CMK_DHM = SAFE_RANGE,
  NEO2,
  QWERTY,
  GAMING,
  GAMING2,
  SYS,
  NAV,
  NUM_E,
  NUM_N,
  SYM
};

enum td_keycodes {
  ALT_LP,
  CTL_RCB,
  GUI_RP,
  SFT_LCB,
  SFT_PLS
};

typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

static td_state_t td_state;
int cur_dance (qk_tap_dance_state_t *state);
void altlp_finished (qk_tap_dance_state_t *state, void *user_data);
void altlp_reset (qk_tap_dance_state_t *state, void *user_data);
void ctlrcb_finished (qk_tap_dance_state_t *state, void *user_data);
void ctlrcb_reset (qk_tap_dance_state_t *state, void *user_data);
void guirp_finished (qk_tap_dance_state_t *state, void *user_data);
void guirp_reset (qk_tap_dance_state_t *state, void *user_data);
void sftlcb_finished (qk_tap_dance_state_t *state, void *user_data);
void sftlcb_reset (qk_tap_dance_state_t *state, void *user_data);
void sftpls_finished (qk_tap_dance_state_t *state, void *user_data);
void sftpls_reset (qk_tap_dance_state_t *state, void *user_data);

enum unicode_names {
     AE_L,
     AE_U,
     UE_L,
     UE_U,
     OE_L,
     OE_U,
     SS_L,
     SS_U,
};

const uint32_t PROGMEM unicode_map[] = {
     [AE_L]  = 0x00E4,  // ä
     [AE_U]  = 0x00C4,  // Ä
     [UE_L]  = 0xC3BC,  // ü
     [UE_U]  = 0xC39C,  // Ü
     [OE_L]  = 0xC3B6,  // ö
     [OE_U]  = 0xC396,  // Ö
     [SS_L]  = 0xC39F,  // ß
     [SS_U]  = 0x1E9E   // ẞ
};
// TODO use alt preprocessor function instead of individual definitions
#define ALT(x) LALT_T(x)
#define ALT_2 LALT_T(KC_2)
#define ALT_3 LALT_T(KC_3)
#define ALT_8 LALT_T(KC_8)
#define ALT_D LALT_T(KC_D)
#define ALT_E LALT_T(KC_E)
#define ALT_K LALT_T(KC_K)
#define ALT_LB LALT_T(KC_LBRC)
#define ALT_S LALT_T(KC_S)
#define CTRL_2 LCTL_T(KC_2)
#define CTRL_4 LCTL_T(KC_4)
#define CTRL_5 LCTL_T(KC_5)
#define CTRL_9 LCTL_T(KC_9)
#define CTRL_EQ LCTL_T(KC_EQL)
#define CTRL_I LCTL_T(KC_I)
#define CTRL_L LCTL_T(KC_L)
#define CTRL_R LCTL_T(KC_R)
#define CTRL_S LCTL_T(KC_S)
#define GUI_0 LGUI_T(KC_0)
#define GUI_1 LGUI_T(KC_1)
#define GUI_4 LGUI_T(KC_4)
#define GUI_7 LGUI_T(KC_7)
#define GUI_RB LGUI_T(KC_RBRC)
#define GUI_F LGUI_T(KC_F)
#define GUI_J LGUI_T(KC_J)
#define GUI_N LGUI_T(KC_N)
#define GUI_TEA LGUI_T(KC_T)
#define MAC_EM S(LALT(KC_MINS))
#define MAC_EN LALT(KC_MINS)
#define NAV_BK LT(_NAV, KC_BSPC)
#define NAV_LK TG(_NAV)
#define NUME_SPC LT(_NUM_E, KC_SPC)
#define NUMLK_E TG(_NUM_E)
#define NUMLK_N TG(_NUM_N)
#define NUMN_SPC LT(_NUM_N, KC_SPC)
#define SFT_0 LSFT_T(KC_0)
#define SFT_1 LSFT_T(KC_1)
#define SFT_6 LSFT_T(KC_6)
#define SFT_7 LSFT_T(KC_7)
#define SFT_A LSFT_T(KC_A)
#define SFT_O LSFT_T(KC_O)
#define SFT_OS OSM(MOD_LSFT)
#define SFT_QOT LSFT_T(KC_QUOT)
#define SFT_SCLN LSFT_T(KC_SCLN)
#define SYM_OS OSL(_SYM)
#define SYM_NEO_OS OSL(_SYM_NEO)
#define GAMING2_OS OSL(_GAMING2)
#define SYS_Z LT(_SYS, KC_Z)
#define SYS_Y LT(_SYS, KC_Y)
#define VOL_DN S(LALT(KC__VOLDOWN))
#define VOL_UP S(LALT(KC__VOLUP))
/* SFT_U,   CTRL_I,  ALT_D,   GUI_E, KC_O,        KC_S,    GUI_N,    ALT_R,   CTRL_T,  SFT_D,   \ */
#define SFT_U LSFT_T(KC_U)
#define CTRL_I LCTL_T(KC_I)
#define ALT_A LALT_T(KC_A)
#define GUI_E LGUI_T(KC_E)
/* #define HYPER_O */
/* #define HYPER_S */
#define GUI_N LGUI_T(KC_N)
#define ALT_R LALT_T(KC_R)
#define CTRL_T LCTL_T(KC_T)
#define SFT_D LSFT_T(KC_D)
/* TODO #define SYS_UE LT(_SYS, KC_XXX) */
#define KC_AE XP(AE_L, AE_U)
#define KC_OE XP(OE_L, OE_U)
#define KC_UE XP(UE_L, UE_U)
#define SYS_UE LT(_SYS, KC_UE)

/* #define SLT_LT  LSFT_T(S(KC_LT)) */
#define SLT_LT  LSFT_T(KC_LT)
#define CTRL_LCBR LCTL_T(KC_LCBR)
#define ALT_LBRC LALT_T(KC_LBRC)
#define GUI_LPRN LGUI_T(KC_LPRN)
//#define XXX_XXX KC_QUOT
//#define XXX_XXX KC_AT
#define GUI_RPRN LGUI_T(KC_RPRN)
#define ALT_RBRC LALT_T(KC_RBRC)
#define CTRL_RCBR LCTL_T(KC_RCBR)
#define SLT_GT LSFT_T(KC_GT)

#define GB_PIPE LSFT(KC_NUBS)
#define GB_AT LSFT(KC_QUOT)
#define GB_TILDE KC_PIPE
#define GB_DQUOT KC_AT
#define GB_HASH KC_NUHS
#define GB_BSLS KC_NUBS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* NEO2 layout
 *
 * w/o additional modifier keys
 * ,----------------------------------.           ,----------------------------------.
 * |   X  |   V  |   L  |   C  |   W  |           |   K  |   H  |   G  |   F  |   Q  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   U  |   I  |   A  |   E  |   O  |           |   S  |   N  |   R  |   T  |   D  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Ü  |   Ö  |   Y  |   P  |   Z  |           |   B  |   M  |   ,  |   .  |   J  |
 * `----------------------------------'           `----------------------------------'
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   X  |   V  |   L  |   C  |   W  |           |   K  |   H  |   G  |   F  |   Q  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/U| CTL/I| ALT/A| GUI/E|   O  |           |   S  | GUI/N| ALT/R| CTL/T| SFT/D|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SYS/Ü|   Ö  |   Y  |   P  |   Z  |           |   B  |   M  |   ,  |   .  |   J  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |SFT/OS|SYM/OS|      |    |      |SYM/OS|SFT/OS|
 *                  `------+------|NAV/BK|    |NUM/SP|------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 * TODO rename _CMK_DHM to NEO2
 * TODO add umlaute ue, oe, (and ae when a position is found)
 * TODO change SYS_Z to SYS_UE
 * TODO fix issue with UE and OE unicode
 */
[_NEO2] = LAYOUT( \
  KC_X,     KC_V,     KC_L,    KC_C,    KC_W,         KC_K,    KC_H,     KC_G,    KC_F,    KC_Q, \
  SFT_U,    CTRL_I,   ALT_A,   GUI_E,   KC_O,         KC_S,    GUI_N,    ALT_R,   CTRL_T,  SFT_D,   \
  SYS_UE,    X(OE_L),  KC_Y,    KC_P,    KC_Z,         KC_B,    KC_M,     KC_COMM, KC_DOT,  KC_J, \
  /* SYS_Z,   KC_Y,  KC_Y,    KC_P,    KC_Z,         KC_B,    KC_M,     KC_COMM, KC_DOT,  KC_J, \ */
                 SFT_OS,  SYM_NEO_OS,  NAV_BK,       NUME_SPC,  SYM_NEO_OS, SFT_OS                     \
),
/* SFT_OS,  NAV_BK,  SYM_OS,       SYM_OS,  NUME_SPC, SFT_OS                     \ */
/* Colemak Mod-DH
 * src: https://colemakmods.github.io/mod-dh/ ; https://colemakmods.github.io/mod-dh/keyboards.html
 * update to rev2 (swap k and m)
 * plus use semicolon and slash in layer0
 *
 * w/o additional modifier keys
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/A| CTL/R| ALT/S| GUI/T|   G  |           |   M  | GUI/N| ALT/E| CTL/I| SFT/O|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SYS/Z|   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |SFT/OS|SYM/OS|      |    |      |SYM/OS|SFT/OS|
 *                  `------+------|NAV/BK|    |NUM/SP|------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_CMK_DHM] = LAYOUT( \
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,         KC_J,    KC_L,     KC_U,    KC_Y,    KC_SCLN, \
  SFT_A,   CTRL_R,  ALT(KC_S),   GUI_TEA, KC_G,         KC_M,    GUI_N,    ALT_E,   CTRL_I,  SFT_O, \
  SYS_Z,   KC_X,    KC_C,    KC_D,    KC_V,         KC_K,    KC_H,     KC_COMM, KC_DOT,  KC_SLSH, \
                    SFT_OS,  SYM_OS,  NAV_BK,       NUME_SPC,  SYM_OS, SFT_OS                     \
),
/* SFT_OS,  NAV_BK,  SYM_OS,       SYM_OS,  NUME_SPC, SFT_OS                     \ */

/* QWERTY
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/A| CTL/S| ALT/D| GUI/F|   G  |           |   H  | GUI/J| ALT/K| CTL/L| SFT/;|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SYS/Z|   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |SFT/OS|SYM/OS|      |    |      |SYM/OS|SFT/OS|
 *                  `------+------|NAV/BK|    |NUM/SP|------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    \
  SFT_A,   CTRL_S,  ALT_D,   GUI_F,   KC_G,         KC_H,    GUI_J,    ALT_K,   CTRL_L,  SFT_SCLN, \
  SYS_Z,   KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, \
                    SFT_OS,  SYM_OS,  NAV_BK,       NUME_SPC,  SYM_OS, SFT_OS                     \
),
/* SFT_OS,  NAV_BK,  SYM_OS,       SYM_OS,  NUMN_SPC, SFT_OS                     \ */


/* GAMING:
 * * Notes:
 *   * Right half of keyboard should not be needed, as this would increase mouse space
 *   * Left-Hand-Side keys are shifted one to the right to place tab, shift and ctrl on qwerty's q a and z.
 *   * Right-hand-Side: keys are kept as in qwerty (for now, at least)
 * * TODOs:
 *   * [ ] add GMG2 (modifier for gaming layer2 to cover some more keycodes)
 *   * [ ] add layoutswitch to System Layer i.e. on qwerty's t position
 *
 * ,------------------------------.           ,----------------------------------.
 * | TAB  |  Q  |  W  |  E  |  R  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+----------+------+-----|           |------+------+------+------+------|
 * | SHIFT|  A  |  S  |  D  |  F  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+----------+------+-----|           |------+------+------+------+------|
 * | CTRL |  Z  |  X  |  C  |  V  |           |   N  |   M  |   ,  |   .  |   /  |
 * `------------------------------'           `----------------------------------'
 *
 *                  ,--------------------.    ,--------------------.
 *                  | ALT  | GMG2 |      |    |      |SYM/OS|SFT/OS|
 *                  `------+------|  SP  |    |NUM/SP|------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_GAMING] = LAYOUT( \
   KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,         SYS_Y,    KC_U,     KC_I,    KC_O,    KC_P,    \
   KC_LSFT,   KC_A,    KC_S,    KC_D,    KC_F,         KC_H,    GUI_J,    ALT_K,   CTRL_L,  SFT_SCLN, \
   KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,         KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, \
                 KC_LALT, GAMING2_OS,  KC_SPC,         NUME_SPC,  SYM_OS, SFT_OS      \
    ),

/* GAMING2:
 *
 * TODO test restored config (1, 2, keys, additional g, h, j)
 *
 * ,------------------------------.           ,----------------------------------.
 * |   1  |  2  |  W  |  3  |  4  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+----------+------+-----|           |------+------+------+------+------|
 * |   G  |  A  |  S  |  D  |  5  |           |   H  |   J  |   K  |   L  |   ;  |
 * |------+----------+------+-----|           |------+------+------+------+------|
 * |   H  |  Y  |  J  |  N  |  M  |           |   N  |   M  |   ,  |   .  |   /  |
 * `------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | ALT  | GMG2 |      |    |      |SYM/OS|SFT/OS|
 *                  `------+------|  SP  |    |NUM/SP|------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_GAMING2] = LAYOUT( \
                      KC_1,      KC_2,    KC_W,    KC_3,    KC_4,         SYS_Y,    KC_U,     KC_I,    KC_O,    KC_P,    \
                      KC_G,   KC_A,    KC_S,    KC_D,    KC_5,         KC_H,    GUI_J,    ALT_K,   CTRL_L,  SFT_SCLN, \
                      KC_H,   KC_Y,    KC_J,    KC_N,    KC_M,         KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, \
                                       KC_LALT, _______, KC_SPC,         NUME_SPC,  SYM_OS, SFT_OS            \
    ),

/* System, media, and layer lock keys
 * If you use QWERTY + the Vanilla numbers primarily, change NUMLK_E to NUMLK_N here.
 * NOTES:
 *
 * what is:
 * --------
 * - AU_ON: Turn on Audio Features
 * - AU_OFF: Turn off Audio Features
 * - AU_TOG: Turn off Audio Features
 * - KC_MPLY: musik player on/off
 * - KC_MFFD: Next Track
 * - KC_MRWD: Previous Track
 * - EEPROM_RESET:: Reinitializes the keyboard's EEPROM (persistent memory)
 *
 * TODO What to try out:
 * TODO KC_LOCK 	Hold down the next key pressed, until the key is pressed again
 * - Ä - AE - 00C4 unicode
 * - Ë -   unicode
 * -  -  unicode
 * -  -  unicode
 * DONE reimplement this layout
 * DONE swap reset for eeprom reset
 * TODO find locks and put them in LOCK slots
 * TODO list all LOCKS
 * DONE add INSERT
 * - KC_NUM LK: LOCK number layer
 * - KC_NAV LKA: LOCK navigation layer
 * - NAV_LK
 * - NUMLK_N
 * -
 * what to do with these?
 * - KC_WSTP  does not work properly
 * - KC_WREF  does not work properly
 * -
 * ,--------------------------------------------.   ,-----------------------------------------.
 * | EERESET | DEBUG | QWERTY | CMKDHM | GAMING |   | PAUSE | BW_FWD  | BRITE+ | VOL+ | MNEXT |
 * |---------+-------+--------+--------+--------+   +-------+---------+--------+------+-------|
 * | SHIFT   | CTRL  | ALT    | GUI    | HYPER  |   | PRINT | BW_STOP | BW_REL | MUTE | MPLY  |
 * |---------+-------+--------+--------+--------+   +-------+---------+--------+------+-------|
 * |         | DEBUG | LOCK   | AU_TOG | INSERT |   | POWER | BW_BWD  | BRITE- | VOL- | MPREV |
 * `--------------------------------------------'   `-----------------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYS] = LAYOUT( \
                EEPROM_RESET,   NEO2,   QWERTY,  CMK_DHM, GAMING,         KC_PAUSE,  KC_WFWD,  KC_BRIU,   KC_VOLU,  KC_MNXT, \
                KC_LSFT,        KC_LCTL, KC_LALT, KC_LGUI, KC_HYPR,        KC_PSCR , KC_WSTP,  KC_WREF,   KC_MUTE,  KC_MPLY, \
                _______,        DEBUG, _______, AU_TOG,  KC_INS,         KC_POWER, KC_WBAK,  KC_BRID,   KC_VOLD,  KC_MPRV, \
                                         _______, _______,   _______,      _______,  _______,  _______                     \
),

/* Navigation + mouse keys
   what is
   - DONE: add mousescroll left and right
   - TODO: add mouse acceleration
     - ACL0, ACL1, ACL2: Set mouse acceleration to x
   - NUME_LK
   - TODO: find useful functions for empty slots min 8x
 *
 * ,----------------------------------.           ,----------------------------------.
 * | TAB  |      | WH U | WH D | BSPC |           | HOME | PGDN | PGUP | END  |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | ESC  | CTRL |  ALT |  GUI |NAV LK|           | LEFT | DOWN |  UP  | RIGHT|      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | CAPS |      |      | BTN2 | BTN1 |           | MS L | MS D | MS U | MS R |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      |  DEL |      |
 *                  `------+------|  ESC |    | ENTER|------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NAV] = LAYOUT( \
  KC_TAB, _______, KC_WH_U, KC_WH_D, KC_BSPC,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,  \
  KC_ESC, _______, _______, KC_BSPC, KC_DEL,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,  \
  KC_CAPS, _______, _______, KC_BTN2, KC_BTN1,       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,  \
                    _______, _______, KC_ESC,        KC_ENT,  KC_DEL,  _______                     \
),

/* my NumberBlock + function keys (NumBlock instead of numbers in a row - default pairing with Colemak)
 * Number + function keys (ergonomic number order - default pairing with Colemak)
 * TODO: try to implement NAV key sequence to switch numpad layer util squence is repeated.
 * TODO update for NEO2 layout i.e. rearrange maybe a bit; neo's layer4 is a bist suboptimal for minidox
 * - 0
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |   +  |   7  |   8  |   9  |   *  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F6  |  F7  |  F8  |  F9  |  F10 |           |   0  |   4  |   5  |   6  | ENTER|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |      |NUM_LK|           |   -  |   1  |   2  |   3  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | TAB  |      |    |      |      |      |
 *                  `------+------|  ESC |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM_E] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         LSFT(KC_EQL),   KC_7,   KC_8,   KC_9,   LSFT(KC_8), \
  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_0,           KC_4,   KC_5,   KC_6,   KC_ENT,     \
  KC_F11,  KC_F12,  _______, _______, _______,       KC_MINS,        KC_1,   KC_2,   KC_3,   KC_SLSH,    \
                    _______, KC_TAB,  KC_ESC,        _______, _______, _______                           \
),

/* Number + function keys (numeric number order - default pairing with QWERTY)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/1| CTL/2| ALT/3| GUI/4|   5  |           |   6  | GUI/7| ALT/8| CTL/9| SFT/0|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |   -  | SPACE| BSPC |           |  DEL |NUM LK|      |      |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | TAB  |      |    |      |      |      |
 *                  `------+------|  ESC |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
/* [_NUM_N] = LAYOUT( \ */
/*   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  \ */
/*   SFT_1,   CTRL_2,  ALT_3,   GUI_4,   KC_5,          KC_6,    GUI_7,   ALT_8,   CTRL_9,  SFT_0,   \ */
/*   KC_F11,  KC_F12,  KC_MINS, KC_SPC,  KC_BSPC,       KC_DEL,  NUMLK_N, _______, _______, KC_SLSH, \ */
/*                     _______, KC_TAB,  KC_ESC,        _______, _______, _______                    \ */
/* ), */

/* Number + function keys (numeric number order - default pairing with QWERTY)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/1| CTL/2| ALT/3| GUI/4|   5  |           |   6  | GUI/7| ALT/8| CTL/9| SFT/0|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |   -  | SPACE| BSPC |           |  DEL |NUM LK|      |      |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      | TAB  |      |    |      |      |      |
 *                  `------+------|  ESC |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM_N] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  \
  SFT_1,   CTRL_2,  ALT_3,   GUI_4,   KC_5,          KC_6,    GUI_7,   ALT_8,   CTRL_9,  SFT_0,   \
  KC_F11,  KC_F12,  KC_MINS, KC_SPC,  KC_BSPC,       KC_DEL,  NUMLK_N, _______, _______, KC_SLSH, \
                    _______, KC_TAB,  KC_ESC,        _______, _______, _______                    \
),


/* Symbols
 *
 * ORIGINAL w/ sft, ctl, alt, gui annotations
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   ?  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SFT/+| CTL/=| ALT/(| GUI/)|   "  |           |   :  | GUI/]| ALT/[| CTL/}| SFT/{|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   <  |   |  |   -  |   >  |   \  |           |   `  |   _  |   /  |   ~  |   ;  |
 * `----------------------------------'           `----------------------------------'
 * ORIGINAL w/o TapDance for modifier keys.
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   ?  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   +  |   =  |   (  |   )  |   "  |           |   :  |     ]|   [  |   }  |   {  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   <  |   |  |   -  |   >  |   \  |           |   `  |   _  |   /  |   ~  |   ;  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |ENDASH|      |    |      |EMDASH|      |
 *                  `------+------|      |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 * [_SYM] = LAYOUT( \ */
/*   KC_EXLM,     KC_AT,   KC_HASH,    KC_DLR,     KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_QUES,     KC_QUOT,     \ */
/*   TD(SFT_PLS), CTRL_EQ, TD(ALT_LP), TD(GUI_RP), KC_DQT,        KC_COLN, GUI_RB,  ALT_LB,  TD(CTL_RCB), TD(SFT_LCB), \ */
/*   KC_LT,       KC_PIPE, KC_MINS,    KC_GT,      KC_BSLS,       KC_GRV,  KC_UNDS, KC_SLSH, KC_TILD,     KC_SCLN,     \ */
/*                         _______,    MAC_EN,     _______,       _______, MAC_EM,  _______                            \ */
/* )
 *
 *
 * My Version (Symbols specified below are should-be's; OS layout is GB!):
 * TODO:
 *   - [ ] find and add "°" to layout
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   "  |   £  |   $  |   %  |           |   ^  |   &  |   *  |   -  |   =  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   <  |   {  |   [  |   (  |   '  |           |   "  |   )  |   ]  |   }  |   >  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   \  |   |  |   ¬  |   @  |   `  |           |   °  |   _  |   ~  |   #  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |ENDASH|      |    |      |EMDASH|      |
 *                  `------+------|      |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
 *
 * TODOs:
 * - [ ] What to do with MAC_EN? ; probably just delete it?
 * - [ ] add ° to symbol layer
 * NOTES:
 * Because of GB-Layout some KC result in different symbol:
 * (- "\" -> "#")
 * - KC_TILD -> "¬"
 * - KC_PIPE -> "~"
 * - KC_AT -> """
 * - KC_NUHS -> "#"
 * - KC_NUBS -> "\"
 * - KC_TILD -> "¬"
 *
 * TODO: modifier do not work properly -> rollback and solve later...
 */
[_SYM] = LAYOUT( \
   KC_EXLM,     KC_AT,           KC_HASH,    KC_DLR,           KC_PERC,         KC_CIRC,   KC_AMPR,     KC_ASTR,    KC_MINS,     KC_EQL,   \
   KC_LT,       KC_LCBR,         KC_LBRC,    KC_LPRN,          KC_QUOT,         KC_AT,     KC_RPRN,     KC_RBRC,    KC_RCBR,     KC_GT,    \
   KC_NUBS,     LSFT(KC_NUBS),   KC_TILD,    LSFT(KC_QUOT),    KC_GRV,          _______,   KC_UNDS,     KC_PIPE,    KC_NUHS,     _______,  \
                                 _______,    MAC_EN,     _______,         _______,   MAC_EM,      _______                          \
                 ),

/*
 * My Version NEO Layout == Layer3
 * TODO add missing symbols
 * - @
 * -
 * -
 * -
 * ,----------------------------------.           ,----------------------------------.
 * |   @  |   _  |   [  |   ]  |   ^  |           |   !  |   <  |   >  |   =  |   &  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   \  |   /  |   {  |   }  |   *  |           |   ?  |   (  |   )  |   -  |   :  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   #  |   $  |   |  |   ~  |   `  |           |   +  |   %  |   "  |   '  |   ;  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |ENDASH|      |    |      |EMDASH|      |
 *                  `------+------|      |    |      |------+------'
 *                                |      |    |      |
 *                                `------'    `------'
*/

[_SYM_NEO] = LAYOUT( \
                    GB_AT,     KC_UNDS,     KC_LBRC,    KC_RBRC,     KC_CIRC,                 KC_EXLM,   KC_LT,       KC_GT,      KC_EQL,      KC_AMPR,  \
                    GB_BSLS,   KC_SLSH,     KC_LCBR,    KC_RCBR,     KC_ASTR,                 KC_QUES,   KC_LPRN,     KC_RPRN,    KC_MINS,     KC_COLN, \
                    GB_HASH,   KC_DLR,      GB_PIPE,    GB_TILDE,    KC_GRV,                  KC_PLUS,   KC_PERC,     GB_DQUOT,   KC_QUOT,     KC_SCLN,  \
                                                     _______,    MAC_EN,     _______,                    _______,   MAC_EM,      _______                          \
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NEO2:
      if (record->event.pressed) {
          set_single_persistent_default_layer(_NEO2);
      }
      return false;
    case CMK_DHM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_CMK_DHM);
      }
      return false;
    case QWERTY:
      if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
    default:
      return true;
  }
};

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  if (state->count == 2) return DOUBLE_SINGLE_TAP;
  else return 3;
}

void altlp_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_LPRN);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LALT));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(KC_LPRN);
      register_code16(KC_LPRN);
  }
}

void altlp_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_LPRN);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LALT));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(KC_LPRN);
  }
}

void ctlrcb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_RCBR);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LCTL));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(KC_RCBR);
      register_code16(KC_RCBR);
  }
}

void ctlrcb_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_RCBR);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LCTL));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(KC_RCBR);
  }
}

void guirp_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_RPRN);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LGUI));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(KC_RPRN);
      register_code16(KC_RPRN);
  }
}

void guirp_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_RPRN);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LGUI));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(KC_RPRN);
  }
}

void sftlcb_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_LCBR);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(KC_LCBR);
      register_code16(KC_LCBR);
  }
}

void sftlcb_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_LCBR);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(KC_LCBR);
  }
}

void sftpls_finished (qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
    case SINGLE_TAP:
      register_code16(KC_PLUS);
      break;
    case SINGLE_HOLD:
      register_mods(MOD_BIT(KC_LSFT));
      break;
    case DOUBLE_SINGLE_TAP:
      tap_code16(KC_PLUS);
      register_code16(KC_PLUS);
  }
}

void sftpls_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
    case SINGLE_TAP:
      unregister_code16(KC_PLUS);
      break;
    case SINGLE_HOLD:
      unregister_mods(MOD_BIT(KC_LSFT));
      break;
    case DOUBLE_SINGLE_TAP:
      unregister_code16(KC_PLUS);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [ALT_LP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, altlp_finished, altlp_reset),
  [CTL_RCB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctlrcb_finished, ctlrcb_reset),
  [GUI_RP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, guirp_finished, guirp_reset),
  [SFT_LCB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftlcb_finished, sftlcb_reset),
  [SFT_PLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftpls_finished, sftpls_reset)
};
