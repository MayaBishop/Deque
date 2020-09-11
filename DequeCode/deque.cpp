//
//  deque.cpp
//  dequedriver
//
//  Created by Maya Bishop on 2020-01-26.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#include "deque.h"

//Constructor that creates an empty deque
Deque::Deque(){
    totalSize = 0;
    p_front = nullptr;
    p_back = nullptr;
}

//calls the clear function to deallocate the deque
Deque::~Deque(){
    clear();
}

//takes in a value for the new node, create a node and add it to the front of the deque
string Deque::enqueue_front(int i){
    Node* temp = new Node(i, nullptr, p_front);
    if (p_front != nullptr){
        p_front->setP_prev(temp);
    }
    p_front = temp;
    if (p_back == nullptr){
        p_back = p_front;
    }
    totalSize++;
    return "success";
}

//takes in a value for the new node, create a node and add it to the back of the deque
string Deque::enqueue_back(int i){
    Node* temp = new Node(i, p_back, nullptr);
    if (p_back != nullptr){
        p_back->setP_next(temp);
    }
    p_back = temp;
    if (p_front == nullptr){
        p_front = p_back;
    }
    totalSize++;
    return "success";
}

//removes the node from the front of the deque and deallocate the node
string Deque::dequeue_front(){
    if(totalSize == 0){
        throw Deque_Empty();
    }
    Node* temp = p_front;
    if(p_back == p_front){
        p_back = p_back->getP_prev();
    }
    p_front = p_front->getP_next();
    delete temp;
    temp = nullptr;
    
    totalSize --;
    return "success";
}

//removes the node from the back of the deque and deallocate the node
string Deque::dequeue_back(){
    if(totalSize == 0){
        throw Deque_Empty();
    }
    Node* temp = p_back;
    if(p_back == p_front){
        p_front = p_front->getP_next();
    }
    p_back = p_back->getP_prev();
    delete temp;
    temp = nullptr;
    totalSize --;
    return "success";
}

//removes each node from the deque all the way through if there are still nodes in the deque
string Deque::clear(){
    Node* temp = p_back;
    for(int i=totalSize; i>0; i--){
        if(p_back == p_front){
            p_front = p_front->getP_next();
        }
        p_back = p_back->getP_prev();
        delete temp;
        temp = p_back;
        totalSize--;
    }
    return "success";
}

//compares the value passed into the method to the value in the first node in the deque
string Deque::front(int i){
    if (p_front == nullptr){
        throw Deque_Empty();
    }
    if (p_front->getValue() != i){
        throw Deque_Empty();
    }
    return "success";
}

//compares the value passed into the method to the value in the last node in the deque
string Deque::back(int i){
    if (p_back == nullptr){
        throw Deque_Empty();
    }
    if (p_back->getValue() != i){
        throw Deque_Empty();
    }
    return "success";
}

//checks if the deque is empty based off the total size and returns whether it is empty or not
string Deque::empty(){
    if(totalSize==0){
        return "success";
    }else{
        return "failure";
    }
}

//returns the size of the deque
int Deque::size(){
    return totalSize;
}

//prints the deque in order from front to back and then back to front
void Deque::print(){
    Node* temp = p_front;
    if (p_front != nullptr){
        for(int i = 0; i < totalSize; i++){
            cout<<temp->getValue();
            if (i != totalSize-1){
                cout<<" ";
            }
            temp = temp->getP_next();
        }
        cout<<endl;
        temp = p_back;
        for(int i = totalSize-1; i >= 0; i--){
            cout<<temp->getValue();
            if (i != 0){
                cout<<" ";
            }
            temp = temp->getP_prev();
        }
        cout<<endl;
    }
}
