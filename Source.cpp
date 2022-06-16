//
//  Source.cpp
//  test
//
//  Created on 10.3.22.
//

#include "Garage.hpp"

int main() {
    
    //Declaring the Object
    Garage garage;
    
    ifstream inFile;
    
    //Reading the data to the Stack
    readData(inFile, garage);
    
    cout<<endl;
    
    //Displaying the Final Result
    garage.displayCar();
    
    cout<<endl;
    
    return 0;
}
