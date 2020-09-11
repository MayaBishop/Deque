//
//  deque.hpp
//  dequedriver
//
//  Created by Maya Bishop on 2020-01-26.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#ifndef deque_h
#define deque_h

#include <stdio.h>
#include "node.h"
#include <string>
#include <iostream>
using namespace std;
class Deque;

class Deque{
    private:
        int totalSize;//contains totalSize of Deque
        Node* p_front;//pointer to first node in deque
        Node* p_back;//pointer to last node in deque
    public:
        //constructor and deconstructor
        Deque();
        ~Deque();
        //methods for commands involving adding and removing from the dequeue
        string enqueue_front(int i);
        string enqueue_back(int i);
        string dequeue_front();
        string dequeue_back();
        string clear();
        //methods for comparison and info about deque
        string front(int i);
        string back(int i);
        string empty();
        int size();
        void print();
};

class Deque_Empty{};
#endif /* deque_h */
