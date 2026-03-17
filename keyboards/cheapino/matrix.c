#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "util.h"
#include "matrix.h"
#include "config.h"
#include "quantum.h"
#include "debounce.h"
#include "encoder.h"
#include "ghosting.h"
#include "print.h"

#define MATRIX_IO_DELAY 25

#define COL_SHIFTER ((uint16_t)1)

static const pin_t row_pins[] = MATRIX_ROW_PINS;
static const pin_t col_pins[] = MATRIX_COL_PINS;
static matrix_row_t previous_matrix[MATRIX_ROWS];

static void select_row(uint8_t row) {
    setPinOutput(row_pins[row]);
    writePinLow(row_pins[row]);
}

static void unselect_row(uint8_t row) { setPinInputHigh(row_pins[row]); }

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
}

static void select_col(uint8_t col) {
    setPinOutput(col_pins[col]);
    writePinLow(col_pins[col]);
}

static void unselect_col(uint8_t col) {
    setPinInputHigh(col_pins[col]);
}

static void unselect_cols(void) {
    for (uint8_t x = 0; x < MATRIX_COLS/2; x++) {
        setPinInputHigh(col_pins[x*2]);
    }
}

static void read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    select_row(current_row);
    wait_us(MATRIX_IO_DELAY);

    for (uint8_t col_index = 0; col_index < MATRIX_COLS / 2; col_index++) {
        uint16_t column_index_bitmask = COL_SHIFTER << ((col_index * 2) + 1);
        if (readPin(col_pins[col_index*2])) {
            current_matrix[current_row] &= ~column_index_bitmask;
        } else {
            current_matrix[current_row] |= column_index_bitmask;
        }
    }

    unselect_row(current_row);
}

static void read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    select_col(current_col*2);
    wait_us(MATRIX_IO_DELAY);

    uint16_t column_index_bitmask = COL_SHIFTER << (current_col * 2);
    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        if (readPin(row_pins[row_index])) {
            current_matrix[row_index] &= ~column_index_bitmask;
        } else {
            current_matrix[row_index] |= column_index_bitmask;
        }
    }
    unselect_col(current_col*2);
}


void matrix_init_custom(void) {
    unselect_cols();
    unselect_rows();
    debounce_init(MATRIX_ROWS);
}

void store_old_matrix(matrix_row_t current_matrix[]) {
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        previous_matrix[i] = current_matrix[i];
    }
}

bool has_matrix_changed(matrix_row_t current_matrix[]) {
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        if (previous_matrix[i] != current_matrix[i]) return true;
    }
    return false;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    store_old_matrix(current_matrix);
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        read_cols_on_row(current_matrix, current_row);
    }
    for (uint8_t current_col = 0; current_col < MATRIX_COLS/2; current_col++) {
        read_rows_on_col(current_matrix, current_col);
    }

    fix_encoder_action(current_matrix);
    fix_ghosting(current_matrix);

    return has_matrix_changed(current_matrix);
}
