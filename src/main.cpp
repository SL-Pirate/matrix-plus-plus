//
// Created by isira.h on 11/19/26.
//

#include <curses.h>
#include <iostream>
#include <algorithm>

#include "matrix.h"

#include <bits/this_thread_sleep.h>

#include "col.h"
#include "main.h"

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    keypad(stdscr, TRUE);

    if (has_colors() == FALSE) {
        endwin();
        std::cerr << "Curses does not support colors" << std::endl;
        return EXIT_FAILURE;
    }

    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    int y, x;
    getmaxyx(stdscr, y, x);
    auto grid = std::vector<std::shared_ptr<Column> >();
    for (int i = 0; i < x; i++) {
        grid.push_back(std::make_shared<Column>(y));
    }

    while (true) {
        for (int i = 0; i < x; i++) {
            const auto &col = grid[i];
            col->next();
            for (int j = 0; j < y; j++) {
                mvwprintw(stdscr, j, i, "%c", col->buffer[j].draw());
            }
        }
        refresh();

        // falling down
        std::this_thread::sleep_for(DELAY);
    }
}

std::unique_ptr<char> gen_random_char() {
    if (chance(gen) <= 0)
        return std::make_unique<char>(' ');

    return std::make_unique<char>(characters[letterOrDigit(gen)]);

    // return std::make_unique<char>(dist(rd));
}

int gen_random_int(const int min, const int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(rd);
}
