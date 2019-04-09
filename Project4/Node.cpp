//
// Created by student on 30.11.2018.
//

#include "Node.h"

Node::Node(int r, int c) {
    this->r = r;
    this->c = c;
}

bool Node::operator<(const Node &other) const {
    return this->minLadder < other.minLadder;
}

bool Node::operator>(const Node &other) const {
    return this->minLadder > other.minLadder;
}