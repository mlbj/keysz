#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "keysz.hpp"

// example esp8266 (D1 mini) pinout 
#define R1_PIN GPIO_NUM_3   // RX                                     - R1
#define C4_PIN GPIO_NUM_16  // D0 NEEDS EXTERNAL PULLUP RESISTOR      - C4
#define R2_PIN GPIO_NUM_5   // D1                                     - R2
#define R3_PIN GPIO_NUM_4   // D2                                     - R3
#define R4_PIN GPIO_NUM_0   // D3                                     - R4
#define C3_PIN GPIO_NUM_14  // D5                                     - C3
#define C2_PIN GPIO_NUM_12  // D6                                     - C2
#define C1_PIN GPIO_NUM_13  // D7                                     - C1
 
const gpio_num_t row_pins[4] = {R1_PIN, R2_PIN, R3_PIN, R4_PIN};
const gpio_num_t col_pins[4] = {C1_PIN, C2_PIN, C3_PIN, C4_PIN};

extern "C" void app_main() {
    gpio_num_t rows[] = {GPIO_NUM_3, GPIO_NUM_5, GPIO_NUM_4, GPIO_NUM_0};
    gpio_num_t cols[] = {GPIO_NUM_13, GPIO_NUM_12, GPIO_NUM_14, GPIO_NUM_16};

    keysz keyboard(rows, cols);
    keyboard.setup();

    while (true) {
        keyboard.scan(); 
    }
}