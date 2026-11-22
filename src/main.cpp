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
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    int y, x;
    getmaxyx(stdscr, y, x);
    auto grid = std::vector<std::unique_ptr<Column> >();
    for (int i = 0; i < x; i++) {
        if (i % 2 == 1) {
            grid.push_back(nullptr);
        } else {
            grid.push_back(std::make_unique<Column>(y));
        }
    }

    while (true) {
        for (int i = 0; i < x; i++) {
            if (i % 2 == 1) continue;

            const auto &col = grid[i];
            col->next();
            for (int j = 0; j < y; j++) {
                if (const auto item = col->buffer[j]; item.is_head) {
                    attroff(COLOR_PAIR(1));
                    attron(COLOR_PAIR(2));
                } else {
                    attroff(COLOR_PAIR(2));
                    attron(COLOR_PAIR(1));
                }

                mvwprintw(stdscr, j, i, "%c", col->buffer[j].draw());
            }
        }
        refresh();

        // falling down
        std::this_thread::sleep_for(DELAY);
    }
}

char gen_random_char() {
    if (chance(gen) <= 0)
        return ' ';

    return characters[letterOrDigit(gen)];
}

int gen_random_int(const int min, const int max) {
    std::uniform_int_distribution distribution(min, max);
    return distribution(rd);
}
