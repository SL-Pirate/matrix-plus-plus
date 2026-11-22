//
// Created by isira.h on 11/22/26.
//

#pragma once

class Cell {
    bool is_visible;
    char i;

public:
    bool is_head = false;

    Cell(char i, bool is_visible);

    void set_is_visible(bool visible);

    [[nodiscard]] char draw() const;

    [[nodiscard]] bool get_is_visible() const;
};
