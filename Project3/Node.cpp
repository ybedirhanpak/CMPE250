//
// Created by student on 23.11.2018.
//

#include "Node.h"

Node::Node(int piggyBankNumber) {
    this->piggyBankNumber = piggyBankNumber;
    this->index = -1; //-1 means undefined
    this->lowlink = 0;
    this->numberOfEdges = 0; // There are no edges initially
    this->onStack = false;
    this->indegree = 0;
}