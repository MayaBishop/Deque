//
//  node.cpp
//  dequedriver
//
//  Created by Maya Bishop on 2020-01-26.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#include "node.h"

//creates an empty node
Node::Node(){
    value = 0;
    p_prev = nullptr;
    p_next = nullptr;
}

//creates a node based off the values passed into the constructor
Node::Node(int v, Node* prev, Node* next){
    value = v;
    p_prev = prev;
    p_next = next;
}

//Deconstructor - restructs the neighbouring nodes as well as helps to dealocate the current one
Node::~Node(){
    if (p_prev != nullptr){
        p_prev->setP_next(p_next);
    }
    if (p_next != nullptr){
        p_next->setP_prev(p_prev);
    }
    p_prev = nullptr;
    p_next = nullptr;
}

//set value for the node based off of the input
void Node::setValue(int v){
    value = v;
}

//return the value stored in the node
int Node::getValue(){
    return value;
}

//set the pointer for the previous node to the node address passed into the function
void Node::setP_prev(Node* prev){
    p_prev = prev;
}

//return the pointer recorded at the previous node variable
Node* Node::getP_prev(){
    return p_prev;
}

//set the pointer for the next node to the node address passed into the function
void Node::setP_next(Node* next){
    p_next = next;
}

//return the pointer recorded at the next node variable
Node* Node::getP_next(){
    return p_next;
}

