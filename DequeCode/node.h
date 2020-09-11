//
//  node.h
//  dequedriver
//
//  Created by Maya Bishop on 2020-01-26.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#ifndef node_h
#define node_h

#include <stdio.h>
using namespace std;
class Node;

class Node{
private:
    //class variables
    int value;
    Node* p_prev;
    Node* p_next;
public:
    //condtructors and deconstructors
    Node();
    Node(int v, Node* prev, Node* next);
    ~Node();
    //get and set functions for all class variables
    void setValue(int v);
    int getValue();
    void setP_prev(Node* prev);
    Node* getP_prev();
    void setP_next(Node* next);
    Node* getP_next();
    

};
#endif /* node_h */
