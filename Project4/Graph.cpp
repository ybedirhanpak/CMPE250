//
// Created by student on 30.11.2018.
//

#include "Graph.h"

Graph::Graph(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;

    this->nodeMatrix = new Node**[rows];
}

void Graph::createRows(int r) {
    this->nodeMatrix[r] = new Node*[columns];
}

void Graph::addNode(int r, int c, int height) {
    this->nodeMatrix[r][c] = new Node(r,c);
    this->nodeMatrix[r][c]->height = height;
    this->nodeMatrix[r][c]->minLadder = INF;
    this->nodeMatrix[r][c]->marked = false;
}

void Graph::calculateLadder(int r1, int c1, int rX, int cX) {
    //Since array starts from 0 index, subtract 1 from coordinates.
    int r0 = r1-1;
    int c0 = c1-1;

    min_heap<Ladder> pQueue;

    Node* current = nodeMatrix[r0][c0];
    current->minLadder = 0;
    current->marked = true;

    int nodeCount = 1;
    do{

        //If nextNode is our target, we don't have to look further.
        //Subtract 1 from coordinates to arrange array indices.
        if(current->r == (rX-1) && current->c == (cX)-1){
            break;
        }

        //Traverse neighbor coordinates
        //Left neighbor
        if(current->c-1 >= 0){
            Node* neighbor = nodeMatrix[current->r][current->c-1];
            if(!neighbor->marked)
                addToPriorityQueue(current,neighbor,pQueue);
        }
        //Top neighbor
        if(current->r-1 >= 0){
            Node* neighbor = nodeMatrix[current->r-1][current->c];
            if(!neighbor->marked)
                addToPriorityQueue(current,neighbor,pQueue);
        }
        //Right neighbor
        if(current->c+1 < columns){
            Node* neighbor = nodeMatrix[current->r][current->c+1];
            if(!neighbor->marked)
                addToPriorityQueue(current,neighbor,pQueue);
        }
        //Bottom neighbor
        if(current->r+1 < rows){
            Node* neighbor = nodeMatrix[current->r+1][current->c];
            if(!neighbor->marked)
                addToPriorityQueue(current,neighbor,pQueue);
        }

        current = nodeMatrix[pQueue.top().r][pQueue.top().c];
        pQueue.pop();

        if(!current->marked){
            current->marked = true;
            nodeCount++;
        }

    }while(!pQueue.empty());

}

void Graph::addToPriorityQueue(Node*& current, Node*& neighbor, min_heap<Ladder>& pQueue) {
    int adjLadderLength = abs(current->height - neighbor->height);
    if(max(current->minLadder,adjLadderLength) < neighbor->minLadder){
        int newLadderLength = max(current->minLadder,adjLadderLength);
        neighbor->minLadder = newLadderLength;
        Ladder l(newLadderLength,neighbor->r,neighbor->c);
        pQueue.push(l);
    }
}

//Since array starts from index 0, subtract 1 from the coordinates to reach the value in the matrix.
int Graph::getLadder(int r, int c) {
    return nodeMatrix[r-1][c-1]->minLadder;
}

void Graph::resetLadder() {
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            nodeMatrix[i][j]->marked = false;
            nodeMatrix[i][j]->minLadder = INF;
        }
    }
}

Graph::~Graph() {
    for(int i=0;i<rows;i++){
        delete this->nodeMatrix[i];
    }
    delete this->nodeMatrix;
}
