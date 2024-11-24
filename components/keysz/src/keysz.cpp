#include "keysz.hpp"

// main constructor 
keysz::keysz(gpio_num_t rows[ROWS], gpio_num_t cols[COLS]){
  for (int i=0; i<ROWS; i++){
    row_pins[i] = rows[i];
  }
  for (int i=0; i<COLS; i++){
    col_pins[i] = cols[i];
  }
}

// setup method
void keysz::setup(){
  // init gpio
  for (int i=0; i<ROWS; i++){
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << row_pins[i]);
    gpio_config(&io_conf);
  }

  for (int i=0; i<COLS; i++){
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = (1ULL << col_pins[i]);
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
  }
}

// scan method 
void keysz::scan(){
  for (int row=0; row<ROWS; row++){
    // activate the current row 
    for (int r=0; r<ROWS; r++){
      if (r==row){
        gpio_set_level(row_pins[r], 0);
      }else{
        gpio_set_level(row_pins[r], 1);
      }
    }

    // read column state 
    for (int col=0; col<COLS; col++){
      // active low 
      bool pressed = (gpio_get_level(col_pins[col])==0);

      if (pressed!=button_states[row][col]){
        button_states[row][col]=pressed;
        if (pressed){
          // debug 
          ESP_LOGI(TAG, "%d, %d pressed", row, col);
        }else{
          // debug 
          ESP_LOGI(TAG, "%d, %d released", row, col);
        }
      }
    }

    // small delay to prevent ghosting 
    vTaskDelay(pdMS_TO_TICKS(5));
  }

  // delay before next scan cycle 
  vTaskDelay(pdMS_TO_TICKS(20));
}

