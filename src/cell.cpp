//
// Created by isira.h on 11/22/26.
//

#include "cell.h"

#include "main.h"

Cell::Cell(char i, const bool is_visible) {
    this->i = i;
    this->is_visible = is_visible;
}

char Cell::draw() const {
    if (is_visible) { return i; }

    return ' ';
}

void Cell::set_is_visible(const bool visible) {
    if (this->is_visible != visible) {
        // generating new characters for new lines
        if (is_visible == false && visible == true) {
            i = *gen_random_char();
        }

        this->is_visible = visible;
    }
}

bool Cell::get_is_visible() const {
    return is_visible;
}
