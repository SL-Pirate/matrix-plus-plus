#pragma once
#include <vector>

#include "cell.h"

class Column {
    int index;
    int length;
    bool is_blank = true;
    int height;

public:
    explicit Column(int height);

    /*
     * Call next to seek the stream and fill the buffer
     */
    void next();

    /*
     * buffer containing items until it fills the screen
     */
    std::vector<Cell> buffer;
};
