//
//  Garage.cpp
//  test
//
//  Created on 10.3.22.
//

#include "Garage.hpp"

//This method adds cars to the stack
void Garage::addCar(string car){
    
    Car c;
    c.plate = car;
    
    //Checking if the car already exists in the Stack
    if(this->lane1.search(car) || this->lane2.search(car)){
        cout<<"The car was already there"<<endl;
        return;
    }
    
    //Checks if there's space to add the car to Lane 1 and if so it adds it
    if(!this->lane1.isFull()){
        
        cout<<"Car "<<c.plate<<" Was Parked in Lane 1!"<<endl;
        this->lane1.push(c);
        return;
        
    //Checks if there's space to add the car to Lane 2 and if so it adds it
    }else if(!this->lane2.isFull()) {
        
        cout<<"Car "<<c.plate<<" Was Parked in Lane 2!"<<endl;
        this->lane2.push(c);
        return;
        
    //If both lanes are full...well too bad lol
    }else
        cout<<"The Parking Lot is Full! Come Another Day :)"<<endl;
}

//This method departs(or removes) cars from the Stack
void Garage::removeCar(string car){
    
    Car topC;
    
    int counterLane1 = 0, counterLane2 = 0, counterStreet = 0;
    
    //Checks if the car is in neither lanes
    if(!this->lane1.search(car) && !this->lane2.search(car)){
        cout<<"The Car You Are Looking For Is Not Here!"<<endl;
        return;
    }
    
    //Setting the car as the top car of the Stack (hence the variable declaration topC lol)
    topC = this->lane1.peek();
    
    //Depart the car from Lane 1
    if(this->lane1.search(car)){
        
        while(car != topC.plate){
            
            topC.count++;
            
            if(!this->lane2.isFull()){
                this->lane2.push(topC);
                this->lane1.pop();
                topC = this->lane1.peek();
                counterLane2++;
                
            }else {
                this->street.push(topC);
                this->lane1.pop();
                topC = this->lane1.peek();
                counterStreet++;
            }
        }
        
        //Departing the car we want and showing if it made any moves
        cout<<"Car "<<topC.plate<<" Has Departed, And Was moved "<<topC.count<<" Time(s)!"<<endl;
        this->lane1.pop();
        
        //Adding the cars back to their original Lane
        for(int i = 0; i < counterStreet; i++){
            topC = this->street.peek();
            topC.count++;
            this->lane1.push(topC);
            this->street.pop();
        }
        
        for(int i = 0; i < counterLane2; i++){
            topC = this->lane2.peek();
            topC.count++;
            this->lane1.push(topC);
            this->lane2.pop();
        }
            
    //Depart the car from Lane 2
    }else if(this->lane2.search(car)){
        
        topC = this->lane2.peek();
        
        while(car != topC.plate){
            
            topC.count++;
            
            if(!this->lane1.isFull()){
                this->lane1.push(topC);
                this->lane2.pop();
                topC = this->lane2.peek();
                counterLane1++;
                
            }else {
                this->street.push(topC);
                this->lane2.pop();
                topC = this->lane2.peek();
                counterStreet++;
            }
        }
        
        //Departing the car we want and showing if it made any moves
        cout<<"Car "<<topC.plate<<" Has Departed, And Was moved "<<topC.count<<" Times!"<<endl;
        this->lane2.pop();
        
        //Adding the cars back to their original Lane
        for(int i = 0; i < counterStreet; i++){
            topC = this->street.peek();
            topC.count++;
            this->lane2.push(topC);
            this->street.pop();
        }
        
        for(int i = 0; i < counterLane1; i++){
            topC = this->lane1.peek();
            topC.count++;
            this->lane2.push(topC);
            this->lane1.pop();
        }
    }
}

//Just a method to display the final result
void Garage::displayCar(){
    
    cout<<"Final Result: "<<endl;
    
    cout<<"Lane 1: ";
    this->lane1.display();
    
    cout<<endl;
    
    cout<<"Lane 2: ";
    this->lane2.display();
    
    cout<<endl;
}

//This function reads the data from the text file and adds the data to the Stack
void readData(ifstream& inFile, Garage& garage){
    
    string readCar;
    char rCar;

    inFile.open("PUT YOUR FILE HERE TO TEST THE PROGRAM"); // Open file

    if (!inFile) { //check if file was opened correctly
        cout << "File can't be opened" << endl;
        exit(1);
    }

    //Getting the data and adding it to the Stack
    while (inFile>>rCar>>readCar) {
        
        if(rCar == 'A')
            garage.addCar(readCar);
        
        else if(rCar == 'D')
            garage.removeCar(readCar);
    }

    inFile.close();
}
