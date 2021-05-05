#pragma once

#include <assert.h>
#include <immintrin.h>
#include <stdint.h>
#include <stdio.h>

#define CELLS 40
#define DIE_SIZE 6
#define DIES 2

typedef enum color color_t;
typedef enum type type_t;
typedef struct cell cell_t;

enum color { NONE, PINK, BLUE, ORANGE, BROWN, RED, YELLOW, GREEN, PURPLE };

enum type {
    GO = 1,
    LAND,
    CHEST,
    TAX,
    STATION,
    CHANCE,
    JUST_VISITING,
    COMPANY,
    FREE_PARKING,
    GO_TO_JAIL
};

struct cell {
    type_t type;
    color_t color;
    int value;
    int offset;
    char name[32];
};

#include "boarddef.h"

static inline unsigned int roll_die() {
    static unsigned int randomness = 0;
    int rc = 1;
    rc &= _rdrand32_step(&randomness);
    assert(rc != 0);
    return((randomness % 6)+1);
}

void validate_board(void);
void rnd_test(void);
void simulate_balance(int initial_balance, unsigned int turns);
void simulate(unsigned int turns);
void check_conditions(unsigned int* cur_pos);