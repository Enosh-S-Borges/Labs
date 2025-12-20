/*9 Suppose we have three classes Vehicle, FourWheeler, and Car. The class Vehicle is the base class, the class FourWheeler is 
derived from it and the class Car is derived from the class FourWheeler. Class Vehicle has a method 'vehicle' that prints 'I am a 
vehicle', class FourWheeler has a method 'fourWheeler' that prints 'I have four wheels', and class Car has a method 'car' that 
prints 'I am a car'. So, as this is a multi-level inheritance; we can have access to all the other classes methods from the 
object of the class Car. We invoke all the methods from a Car object and print the corresponding outputs of the methods. 
So, if we invoke the methods in this order, car(), fourWheeler(), and vehicle(), then the output will be, 
• I am a car  
• I have four wheels  
• I am a vehicle  
Write a C++ program to demonstrate multilevel inheritance using the above.  */

#include <iostream>
using namespace std;

class Vehicle {
public:
    void vehicle() {
        cout << "I am a vehicle" << endl;
    }
};

class FourWheeler : public Vehicle {
public:
    void fourWheeler() {
        cout << "I have four wheels" << endl;
    }
};

class Car : public FourWheeler {
public:
    void car() {
        cout << "I am a car" << endl;
    }
};

int main() {
    Car c;
    c.car();
    c.fourWheeler();
    c.vehicle();
    return 0;
}