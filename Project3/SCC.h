//
// Created by student on 24.11.2018.
//

#ifndef SCC_SCC_H
#define SCC_SCC_H

#include "Node.h"

class SCC {
public:
    int root;
    list<int> components;
    SCC();
    void addComponent(int& component);
    void setRoot(int& root);

    void printSCC(){
        cout << "Root: ";
        for(list<int>::iterator itr = components.begin();itr != components.end();++itr){
            cout << *itr << " ";
        }
        cout << endl;
    }
};


#endif //SCC_SCC_H
