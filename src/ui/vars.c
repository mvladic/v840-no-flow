#include "vars.h"
#include "screens.h"

int32_t selected_theme_index = 0;

int32_t get_var_selected_theme_index() {
    return selected_theme_index;
}

void set_var_selected_theme_index(int32_t value) {
    selected_theme_index = value;

    change_color_theme(value);
}