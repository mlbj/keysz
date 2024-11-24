#ifndef KEYSZ_HPP
#define KEYSZ_HPP

#include <cstring>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"


class keysz{
private:
    static const int ROWS = 4;
    static const int COLS = 4;

    gpio_num_t row_pins[ROWS];
    gpio_num_t col_pins[COLS];
    bool button_states[ROWS][COLS];

    static constexpr const char *TAG = "keysz";
    
public:
    // main constructor 
    keysz(gpio_num_t rows[ROWS], gpio_num_t cols[COLS]);

    // main methods 
    void setup();
    void scan();
}; 


#endif // KEYSZ_HPP

