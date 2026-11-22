//
// Created by isira.h on 11/21/26.
//

#include "col.h"

#include <algorithm>

#include "main.h"
#include "matrix.h"

Column::Column(const int height) {
    this->height = height;
    this->buffer = std::vector<Cell>();

    for (int i = 0; i < this->height; i++) {
        buffer.emplace_back(*gen_random_char(), false);
    }

    index = gen_random_int(0, height);
    length = gen_random_int(std::min(MIN_SEQ_LEN, height - 1), height - 1);
}

void Column::next() {
    if (index == height) {
        index = 0;
    }
    const int tail = (index - length + height) % height;
    buffer[tail].set_is_visible(false);
    buffer[index].set_is_visible(true);
    buffer[index].is_head = true;
    if (index > 0) {
        buffer[index - 1].is_head = false;
    }
    index++;
}
