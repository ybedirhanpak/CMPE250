//
// Created by student on 13.12.2018.
//

#include "Ladder.h"

Ladder::Ladder(int height, int r, int c) {
    this->height = height;
    this->r = r;
    this->c = c;
}

bool Ladder::operator<(const Ladder &other) const {
    return this->height < other.height;
}

bool Ladder::operator>(const Ladder &other) const {
    return this->height > other.height;
}