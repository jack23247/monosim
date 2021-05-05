#pragma once

#include "monosim.h"

cell_t board[CELLS] = {
    {GO,            NONE,   -1,     +20000,  "Via"},
    {LAND,          PINK,   6000,   -200,   "Vicolo Corto"},
    {CHEST,         NONE,   -1,     +0,     "Probabilità"},
    {LAND,          PINK,   6000,   -400,   "Vicolo Stretto"},
    {TAX,           NONE,   -1,     -20000, "Tassa Patrimoniale"},
    {STATION,       NONE,   20000,  -2500,  "Stazione SUD"},
    {LAND,          BLUE,   10000,  -600,   "Bastioni Gran Sasso"},
    {CHANCE,        NONE,   -1,     +0,     "Imprevisti"},
    {LAND,          BLUE,   10000,  -600,   "Viale Monterosa"},
    {LAND,          BLUE,   12000,  -800,   "Viale Vesuvio"},
    {JUST_VISITING, NONE,   -1,     +0,     "Transito / Prigione"},
    {LAND,          ORANGE, 14000,  -1000,  "Via Accademia"},
    {COMPANY,       NONE,   15000,  -2000,  "Società Elettrica"},
    {LAND,          ORANGE, 14000,  -1000,  "Corso Ateneo"},
    {LAND,          ORANGE, 16000,  -1200,  "Piazza Università"},
    {STATION,       NONE,   20000,  -2500,  "Stazione OVEST"},
    {LAND,          BROWN,  18000,  -1400,  "Via Verdi"},
    {CHEST,         NONE,   -1,     +0,     "Probabilità"},
    {LAND,          BROWN,  18000,  -1400,  "Corso Raffaello"},
    {LAND,          BROWN,  20000,  -1600,  "Piazza Dante"},
    {FREE_PARKING,  NONE,   -1,     +0,     "Posteggio Gratuito"},
    {LAND,          RED,    22000,  -1800,  "Via Marco Polo"},
    {CHANCE,        NONE,   -1,     +0,     "Imprevisti"},
    {LAND,          RED,    22000,  -1800,  "Corso Magellano"},
    {LAND,          RED,    24000,  -2000,  "Largo Colombo"},
    {STATION,       NONE,   20000,  -2500,  "Stazione NORD"},
    {LAND,          YELLOW, 26000,  -2200,  "Viale Costantino"},
    {LAND,          YELLOW, 26000,  -2200,  "Viale Traiano"},
    {COMPANY,       NONE,   15000,  -2000,  "Società Acqua Potabile"},
    {LAND,          YELLOW, 28000,  -2400,  "Piazza Giulio Cesare"},
    {GO_TO_JAIL,    NONE,   -1,     +0,     "In prigione!"},
    {LAND,          GREEN,  30000,  -2600,  "Via Roma"},
    {LAND,          GREEN,  30000,  -2600,  "Corso Impero"},
    {CHEST,         NONE,   -1,     +0,     "Probabilità"},
    {LAND,          GREEN,  32000,  -2800,  "Largo Augusto"},
    {STATION,       NONE,   20000,  -2500,  "Stazione EST"},
    {CHANCE,        NONE,   -1,     +0,     "Imprevisti"},
    {LAND,          PURPLE, 35000,  -3500,  "Viale dei Giardini"},
    {TAX,           NONE,   -1,     -10000, "Tassa di Lusso"},
    {LAND,          PURPLE, 40000,  -5000,  "Parco della Vittoria"},
};