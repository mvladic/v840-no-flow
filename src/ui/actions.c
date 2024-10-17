#include "actions.h"
#include "screens.h"
#include "ui.h"

void action_show_screen2(lv_event_t * e) {
    loadScreen(SCREEN_ID_SCREEN2);
}

void action_show_main(lv_event_t * e) {
    loadScreen(SCREEN_ID_MAIN);
}