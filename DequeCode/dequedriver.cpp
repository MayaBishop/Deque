//
//  main.cpp
//  dequedriver
//
//  Created by Maya Bishop on 2020-01-26.
//  Copyright © 2020 Maya Bishop. All rights reserved.
//

#include <iostream>
#include <string>
#include "deque.h"
using namespace std;

int main(int argc, const char * argv[]) {
    //initialize variables used for parsing commands
    Deque deque;
    string line;
    string command;
    int param;
    int divider;
    while(!cin.eof()){
        //get the line from the file and find the divider
        getline(cin, line);
        divider = line.find(" ");
        command = line.substr(0,divider);
        try{//check the command entered and call the correct method from deque in response
            if(command == "enqueue_front"){
                param = stoi(line.substr(divider));
                cout << deque.enqueue_front(param) << endl;
                
            }else if(command == "enqueue_back"){
                param = stoi(line.substr(divider));
                cout << deque.enqueue_back(param) << endl;
                
            }else if(command == "dequeue_front"){
                cout << deque.dequeue_front() << endl;
                
            }else if(command == "dequeue_back"){
                cout << deque.dequeue_back() << endl;
                
            }else if(command == "clear"){
                cout << deque.clear() << endl;
                
            }else if(command == "front"){
                param = stoi(line.substr(divider));
                cout << deque.front(param) << endl;
                
            }else if(command == "back"){
                param = stoi(line.substr(divider));
                cout << deque.back(param) << endl;
                
            }else if(command == "empty"){
                cout << deque.empty() << endl;
                
            }else if(command == "size"){
                cout << "size is "<< deque.size() << endl;
                
            }else if(command == "print"){
                deque.print();
            }
        }
        catch(Deque_Empty e){// if there is a error called Deque_Empty that results from any of the commands output failure
            cout << "failure" << endl;
        }
    }
    
    return 0;
}
