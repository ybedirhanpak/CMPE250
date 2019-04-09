//
// Created by student on 24.11.2018.
//

#include "SCC.h"

SCC::SCC() {
    root = 0;
}

void SCC::addComponent(int& component) {
    this->components.push_front(component);
}

void SCC::setRoot(int& root) {
    this->root = root;
}
