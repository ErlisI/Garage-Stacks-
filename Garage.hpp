//
//  Garage.hpp
//  test
//
//  Created on 10.3.22.
//

#ifndef Garage_hpp
#define Garage_hpp

#include "Stack.hpp"

class Garage{
private:
    Car defaultC;
    
    Stack lane1;
    Stack lane2;
    Stack street;
    
public:
    void addCar(string);
    void removeCar(string);
    void displayCar();
};

void readData(ifstream&, Garage&);

#endif
