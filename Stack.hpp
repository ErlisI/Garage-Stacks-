//
//  Stack.hpp
//  test
//
//  Created on 10.3.22.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Car{
    
    string plate;
    int count = 0;
    
};

class Node {
public:
    Car data;
    Node* next = NULL;
    Node(Car d):data(d){};
};

class Stack{
private:
    Node* head = NULL;
    
public:
    void push(Car);
    void pop();
    Car peek();
    bool search(string);
    int stackSize();
    void display();
    
    bool isFull(){
        if(stackSize() == 10)
            return true;
        return false;
    }
};

#endif
