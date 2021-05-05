#include "monosim.h"

void rnd_test() {
    for (int i = 0; i < 100000; i++) {
        printf("%u,%u\n", roll_die(), roll_die());
    }
}

void validate_board(void) {
    cell_t* current_cell;
    for (int i = 0; i < CELLS; i++) {
        current_cell = &board[i];
        switch (current_cell->type) {  // Check for cell data consistency
            case GO:
                assert(current_cell->color == NONE);
                assert(current_cell->offset == 20000);
                assert(current_cell->value == -1);
                break;
            case LAND:
                assert(current_cell->color != NONE);
                assert(current_cell->offset < 0);
                assert(current_cell->value > 0);
                assert(current_cell->value <= 40000);
                break;
            case CHEST:
            case CHANCE:
            case JUST_VISITING:
            case FREE_PARKING:
            case GO_TO_JAIL:
                assert(current_cell->color == NONE);
                assert(current_cell->offset == 0);
                assert(current_cell->value == -1);
                break;
            case TAX:
                assert(current_cell->color == NONE);
                assert(current_cell->offset == -20000 ||
                       current_cell->offset == -10000);
                assert(current_cell->value == -1);
                break;
            case STATION:
                assert(current_cell->color == NONE);
                assert(current_cell->offset == -2500);
                assert(current_cell->value == 20000);
                break;
            case COMPANY:
                assert(current_cell->color == NONE);
                assert(current_cell->offset == -2000);
                assert(current_cell->value == 15000);
                break;
            default:
                assert(0);
                break;
        }
        switch (current_cell->type) {  // Check for cell placement correctness
            case GO:
                assert(i == 0);
                break;
            case LAND:
                // Everything else
                break;
            case CHEST:
                assert(i == 2 || i == 17 || i == 33);
                break;
            case TAX:
                assert(i == 4 || i == 38);
                break;
            case STATION:
                assert(i == 5 || i == 15 || i == 25 || i == 35);
                break;
            case CHANCE:
                assert(i == 7 || i == 22 || i == 36);
                break;
            case JUST_VISITING:
                assert(i == 10);
                break;
            case COMPANY:
                assert(i == 12 || i == 28);
                break;
            case FREE_PARKING:
                assert(i == 20);
                break;
            case GO_TO_JAIL:
                assert(i == 30);
                break;
            default:
                assert(0);
                break;
        }
    }
    return;
}

void simulate_balance(int initial_balance, unsigned int turns) {
    unsigned int cur_pos = 0;
    unsigned int limit = -1;  // Force negative overflow to get max
    unsigned int d1 = 0;
    unsigned int d2 = 0;
    int cur_balance = initial_balance;
    if (turns) limit = turns;
    for (unsigned int i = 0; i < limit; i++) {
        d1 = roll_die();
        d2 = roll_die();
        cur_pos = cur_pos + d1 + d2;
        if (cur_pos >= 40) cur_pos -= 39;
        cur_balance += board[cur_pos].offset;
        printf("%u,%u,%u,%u,%s,%i\n", i + 1, d1, d2, cur_pos,
               board[cur_pos].name, cur_balance);
        if (!turns && cur_balance < 0) {
            return;
        }
    }
    return;
}

void simulate(unsigned int turns) {
    unsigned int cur_pos = 0;
    unsigned int d1 = 0;
    unsigned int d2 = 0;
    unsigned int total_laps = 0;
    for (unsigned int i = 0; i < turns; i++) {
        // Phase 1 - roll
        d1 = roll_die();
        d2 = roll_die();
        // Phase 2 - advance
        cur_pos += (d1 + d2);
        if (cur_pos >= 40) {
            cur_pos -= 40;
            total_laps++;
        }
        // Print roll results
        /*printf("%u,%u,%u,%u,%2u - %s\n", i + 1, total_laps, d1, d2, cur_pos,
               board[cur_pos].name);*/
        printf("%02u - %s\n", cur_pos, board[cur_pos].name);
        // Phase 3 - play
        check_conditions(&cur_pos);
    }
    return;
}

void check_conditions(unsigned int* cur_pos) {
    switch (board[*cur_pos].type) {
        case GO_TO_JAIL:
            *cur_pos = 10;
            break;
        default:
            break;
    }
    return;
}

int main() {
    validate_board();
    // rnd_test();
    simulate(200000);
    return 0;
}
