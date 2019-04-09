//
// Created by student on 23.11.2018.
//

#include "Graph.h"

Graph::Graph(int numberOfVertices) {
    this->numberOfVertices = numberOfVertices;
    headNodes = new Node*[this->numberOfVertices];
    for(int i=0;i<numberOfVertices;i++){
        headNodes[i] = new Node(i+1);
    }
}

void Graph::addEdge(Node& source, Node& destination) {
    source.adjacencyList.push_front(&destination);
    source.numberOfEdges++;
    if(source.piggyBankNumber != destination.piggyBankNumber){
        destination.indegree++;
    }
}

void Graph::buildSCC() {
    int index = 0;
    stack<Node*> S;
    for(int i=0;i<numberOfVertices;i++){
        Node* v = headNodes[i];
        if(v->index == -1){
            DFS(v,index,S);
        }
    }
}

void Graph::DFS(Node* v, int& index,stack<Node*> &S){
//    cout << "DFS Started with node: " << v->piggyBankNumber << " with index: " << index<<endl;
    v->index = index;
    v->lowlink = index;
    index++;
    v->onStack = true;
    S.push(v);

    for(list<Node*>::iterator itr = v->adjacencyList.begin(); itr != v->adjacencyList.end(); ++itr){
        Node* w = *itr;
        if(w->index == -1){
            //Successor w has not yet been visited, recurse on it.
            DFS(w,index,S);
            v->lowlink = min(v->lowlink,w->lowlink);
        }else if(w->piggyBankNumber != v->piggyBankNumber && w->onStack){
            // Successor w is in stack S and hence in the current SCC
            // If w is not on stack, then (v, w) is a cross-edge in the DFS tree and must be ignored
            v->lowlink = min(v->lowlink,w->index);
        }
    }
    // If v is a root node, pop the stack and generate an SCC
    if(v->lowlink == v->index){
        //Start a new SCC
        SCC newSCC;
        Node* w;
        do{
            w = S.top();
            w->onStack = false;
            S.pop();
            newSCC.addComponent(w->piggyBankNumber);
            if(w->piggyBankNumber == v->piggyBankNumber){
                newSCC.setRoot(w->piggyBankNumber);
            }
        }while(w->index != v->index);
        //Add this new SCC to the SCCList
        SCCList.push_front(newSCC);
        //Output the SCC.
//      newSCC.printSCC();
    }
}

void Graph::calculatePiggyBanksToBreak() {
    for(list<SCC>::iterator itr = SCCList.begin(); itr != SCCList.end();++itr){
        SCC* next = &(*itr);
        int rootIndex = next->root-1;
        Node* root = this->headNodes[rootIndex];
        if(root->indegree == 0){
            piggyBanksToBreak.push(next->root);
            numToBreak++;
        }
    }
}
