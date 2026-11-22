//
// Created by isira.h on 11/21/26.
//

#pragma once
#include <memory>
#include <random>

#include "matrix.h"

static std::uniform_int_distribution<> dist('a', 'z');
static std::mt19937 gen(rd());
static std::uniform_int_distribution chance(1, 100);
static std::uniform_int_distribution letterOrDigit(0, 76);
static constexpr char characters[] =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "~!@#$%^&-=*+\\/?";


char gen_random_char();

int gen_random_int(int min, int max);
