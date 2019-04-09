//
// Created by student on 23.11.2018.
//

#ifndef SCC_GRAPH_H
#define SCC_GRAPH_H

#include <iostream>
#include <list>
#include "Node.h"
#include <iterator>
#include "SCC.h"
#include <stack>
#include <queue>

using namespace std;

class Graph {
public:
    int numberOfVertices;
    //An array that holds Node pointers
    Node* *headNodes;
    //List of SCC
    list<SCC> SCCList;
    //Number of piggy banks to break
    int numToBreak = 0;
    //List of piggy banks to break
    stack<int> piggyBanksToBreak;
    //Constructor
    Graph(int numberOfVertices);
    //Add edge from source node to destination node
    void addEdge(Node& source, Node& destination);
    void buildSCC();
    void DFS(Node* v,int& index,stack<Node*> &S);
    void calculatePiggyBanksToBreak();

    void printAdjLists(){
        for(int i=0;i<numberOfVertices;i++){
            cout << "Head:" << i+1;
            Node* headNode = headNodes[i];
            for(list<Node*>::iterator itr = headNode->adjacencyList.begin();itr != headNode->adjacencyList.end(); ++itr){
                cout << " -> " << (*itr)->piggyBankNumber;
            }
            cout << endl;
        }
    }
};

#endif //SCC_GRAPH_H
