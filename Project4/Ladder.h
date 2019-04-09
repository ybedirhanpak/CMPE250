//
// Created by student on 13.12.2018.
//

#ifndef PROJECT4_LADDER_H
#define PROJECT4_LADDER_H

#include "Node.h"

class Ladder {
public:
    int r;
    int c;
    int height;

    Ladder(int height, int r, int c);

    bool operator<(const Ladder& other) const;
    bool operator>(const Ladder& other) const;
};


#endif //PROJECT4_LADDER_H
