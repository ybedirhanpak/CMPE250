//
// Created by student on 30.11.2018.
//

#ifndef SHORTEST_PATH_GRAPH_H
#define SHORTEST_PATH_GRAPH_H

#include "Node.h"
#include "Ladder.h"
#include <iomanip>
#include <cmath>
#include <math.h>
#include <queue>
#include <iterator>

using namespace std;

#define INF (int) pow(10,9) - 1

template<class T> using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;

class Graph {
    int rows;
    int columns;
    Node ***nodeMatrix;

    void addToPriorityQueue(Node*& current, Node*& neighbor, min_heap<Ladder>& pQueue);

public:
    Graph(int rows, int columns);
    ~Graph();

    void createRows(int r);

    void addNode(int r, int c, int height);

    void calculateLadder(int r1, int c1, int rX, int cX);

    void resetLadder();

    int getLadder(int r,int c);

};


#endif //SHORTEST_PATH_GRAPH_H
