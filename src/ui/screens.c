#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

groups_t groups;
static bool groups_created = false;

objects_t objects;
lv_obj_t *tick_value_change_obj;

static lv_meter_scale_t * scale0;
static lv_meter_indicator_t * indicator1;
static lv_meter_indicator_t * indicator2;
static lv_meter_indicator_t * indicator3;

static void event_handler_cb_main_main(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        // group: encoder_group
        lv_group_remove_all_objs(groups.encoder_group);
    }
}

static void event_handler_cb_main_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_selected_theme_index(value);
        }
    }
}

static void event_handler_cb_screen2_screen2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_SCREEN_LOAD_START) {
        // group: encoder_group
        lv_group_remove_all_objs(groups.encoder_group);
    }
}

static void event_handler_cb_screen2_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    if (event == LV_EVENT_VALUE_CHANGED) {
        lv_obj_t *ta = lv_event_get_target(e);
        if (tick_value_change_obj != ta) {
            int32_t value = lv_dropdown_get_selected(ta);
            set_var_selected_theme_index(value);
        }
    }
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_main_main, LV_EVENT_ALL, 0);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 668, 17);
            lv_obj_set_size(obj, 109, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "Light\nDark");
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj0, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 456, 224);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Text");
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 605, 30);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Theme:");
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 339, 392);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_show_screen2, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Screen 2");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 524, 216);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(theme_colors[0][2]));
            lv_led_set_brightness(obj, 255);
        }
        {
            lv_obj_t *obj = lv_meter_create(parent_obj);
            lv_obj_set_pos(obj, 32, 30);
            lv_obj_set_size(obj, 180, 180);
            {
                lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                scale0 = scale;
                lv_meter_set_scale_ticks(obj, scale, 41, 1, 5, lv_color_hex(theme_colors[0][3]));
                lv_meter_set_scale_major_ticks(obj, scale, 8, 3, 10, lv_color_hex(theme_colors[0][2]), 10);
                lv_meter_set_scale_range(obj, scale, 0, 100, 300, 120);
                {
                    lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 3, lv_color_hex(theme_colors[0][3]), -28);
                    indicator1 = indicator;
                    lv_meter_set_indicator_value(obj, indicator, 30);
                }
                {
                    lv_meter_indicator_t *indicator = lv_meter_add_scale_lines(obj, scale, lv_color_hex(theme_colors[0][2]), lv_color_hex(theme_colors[0][3]), false, 0);
                    indicator2 = indicator;
                    lv_meter_set_indicator_start_value(obj, indicator, 0);
                    lv_meter_set_indicator_end_value(obj, indicator, 80);
                }
                {
                    lv_meter_indicator_t *indicator = lv_meter_add_arc(obj, scale, 2, lv_color_hex(theme_colors[0][3]), 0);
                    indicator3 = indicator;
                    lv_meter_set_indicator_start_value(obj, indicator, 0);
                    lv_meter_set_indicator_end_value(obj, indicator, 90);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 501, 305);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Styled Text");
            add_style_styled_text(obj);
        }
    }
}

void tick_screen_main() {
    {
        if (!(lv_obj_get_state(objects.obj0) & LV_STATE_EDITED)) {
            int32_t new_val = get_var_selected_theme_index();
            int32_t cur_val = lv_dropdown_get_selected(objects.obj0);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj0;
                lv_dropdown_set_selected(objects.obj0, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void create_screen_screen2() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_add_event_cb(obj, event_handler_cb_screen2_screen2, LV_EVENT_ALL, 0);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 347, 354);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_show_main, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 386, 233);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Screen 2");
            lv_obj_set_style_text_color(obj, lv_color_hex(theme_colors[0][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_dropdown_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 672, 20);
            lv_obj_set_size(obj, 109, LV_SIZE_CONTENT);
            lv_dropdown_set_options(obj, "Light\nDark");
            lv_obj_add_event_cb(obj, event_handler_cb_screen2_obj1, LV_EVENT_ALL, 0);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 609, 33);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Theme:");
        }
        {
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 130, 146);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(theme_colors[0][2]));
            lv_led_set_brightness(obj, 255);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 570, 308);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Styled Text");
            add_style_styled_text(obj);
        }
    }
}

void tick_screen_screen2() {
    {
        if (!(lv_obj_get_state(objects.obj1) & LV_STATE_EDITED)) {
            int32_t new_val = get_var_selected_theme_index();
            int32_t cur_val = lv_dropdown_get_selected(objects.obj1);
            if (new_val != cur_val) {
                tick_value_change_obj = objects.obj1;
                lv_dropdown_set_selected(objects.obj1, new_val);
                tick_value_change_obj = NULL;
            }
        }
    }
}

void change_color_theme(uint32_t theme_index) {
    lv_style_set_text_color(get_style_styled_text_MAIN_DEFAULT(), lv_color_hex(theme_colors[theme_index][2]));
    
    lv_obj_set_style_text_color(objects.obj2, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_led_set_color(objects.obj3, lv_color_hex(theme_colors[theme_index][2]));
    
    scale0->tick_color = lv_color_hex(theme_colors[theme_index][3]);
    scale0->tick_major_color = lv_color_hex(theme_colors[theme_index][2]);
    
    indicator1->type_data.needle_line.color = lv_color_hex(theme_colors[theme_index][3]);
    
    indicator2->type_data.scale_lines.color_start = lv_color_hex(theme_colors[theme_index][2]);
    indicator2->type_data.scale_lines.color_end = lv_color_hex(theme_colors[theme_index][3]);
    
    indicator3->type_data.arc.color = lv_color_hex(theme_colors[theme_index][3]);
    
    lv_obj_set_style_text_color(objects.obj4, lv_color_hex(theme_colors[theme_index][2]), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_led_set_color(objects.obj5, lv_color_hex(theme_colors[theme_index][2]));
    
    lv_obj_invalidate(objects.main);
    lv_obj_invalidate(objects.screen2);
}

void ui_create_groups() {
    if (!groups_created) {
        groups.encoder_group = lv_group_create();
        groups_created = true;
    }
}

uint32_t theme_colors[2][4] = {
    { 0xffffffff, 0xff404040, 0xffd70f0f, 0xffccd917 },
    { 0xff000000, 0xff000000, 0xff1ae0b8, 0xff5014db },
};

void create_screens() {
    ui_create_groups();
    
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_screen2();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_screen2,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
