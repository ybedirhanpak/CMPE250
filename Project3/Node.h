//
// Created by student on 23.11.2018.
//

#ifndef SCC_NODE_H
#define SCC_NODE_H

#include <iostream>
#include <list>

using namespace std;

class Node {
public:
    int piggyBankNumber;
    int index;//-1 means undefined
    int lowlink;
    int numberOfEdges;
    int indegree;
    bool onStack;
    //List of nodes
    list<Node*> adjacencyList;
    //Constructor
    Node(int piggyBankNumber);
};


#endif //SCC_NODE_H
