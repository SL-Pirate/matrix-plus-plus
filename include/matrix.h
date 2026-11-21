//
// Created by isira.h on 11/19/26.
//

#pragma once

#include <random>

#define DELAY std::chrono::milliseconds(50)
// minimum length of a character/space sequence
#define MIN_SEQ_LEN 10

static auto rd = std::random_device();
