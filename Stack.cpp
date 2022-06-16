//
//  Stack.cpp
//  test
//
//  Created on 10.3.22.
//

#include "Stack.hpp"

//This method pushes the Car to the Stack
void Stack::push(Car c){
    
    Node* newNode = new Node(c);
    
        if (!newNode)
            return;
    
        //head is empty
        if (this->head == NULL) {
            this->head = newNode;
            
        }else {//head is not empty
            newNode->next = this->head;
            this->head = newNode;
        }
}

//This method pops the Car from the Stack
void Stack::pop(){
    
    Node* cur = this->head;
    
    //list is empty
    if (this->head == NULL) {
        return;
        
    //list is not empty
    }
    this->head = cur->next;
    delete cur;
}

//This method returns the data (includes the Cars plate and the number of times it moved) at the top of the Stack
Car Stack::peek(){
    
    //head is empty
    if (this->head == NULL) {
        cout<<"The Parking Lot Is Empty, Nothing To Look At Here :("<<endl;
        exit(0);
    }
    
    return this->head->data;
}

//This method just searches the Stack to see if the Car is in the Stack or not
bool Stack::search(string c){
    
    Node* temp = this->head;
    
    while (temp != NULL) {
        
        if (temp->data.plate == c)
            return true;
        
        temp = temp->next;
    }
    return false; // not found
}

//This method returns the size of the stack
int Stack::stackSize(){
    
    Node* temp = this->head;
    int i = 0;
    
    while(temp != NULL){
        i++;
        temp = temp->next;
    }
    
    return i;
}

//This method displays all the Cars plates (its just used for the final result)
void Stack::display(){
    
    Node* temp = head;
    
    while(temp != NULL){
        
        cout<<temp->data.plate<<" ";
        temp = temp->next;
    }
}
