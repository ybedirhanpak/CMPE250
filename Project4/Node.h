//
// Created by student on 30.11.2018.
//

#ifndef SHORTEST_PATH_NODE_H
#define SHORTEST_PATH_NODE_H

#include <iostream>
#include <list>

using namespace std;

class Node {
public:
    int height;
    int r;
    int c;
    int minLadder;
    bool marked;

    Node(int r, int c);

    bool operator<(const Node& other) const;
    bool operator>(const Node& other) const;
};


#endif //SHORTEST_PATH_NODE_H
