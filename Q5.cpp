#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(string m, string mod, int y) 
        : make(m), model(mod), year(y) {}

    // Display basic vehicle info
    virtual void display() const {
        cout << "=== Vehicle Details ===" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }

    virtual ~Vehicle() {}
};


class Car : public Vehicle {
protected:
    int doors;
    float fuelEfficiency; 

public:
    
    Car(string m, string mod, int y, int d, float fe)
        : Vehicle(m, mod, y), doors(d), fuelEfficiency(fe) {}

    // Display car info
    void display() const override {
        cout << "\n=== Car Details ===" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Doors: " << doors << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << " MPG" << endl;
    }
};

class ElectricCar : public Car {
private:
    float batteryLife; 

public:
    
    ElectricCar(string m, string mod, int y, int d, float fe, float bl)
        : Car(m, mod, y, d, fe), batteryLife(bl) {}

    // Display electric car info
    void display() const override {
        cout << "\n=== Electric Car Details ===" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Doors: " << doors << endl;
        cout << "Fuel Efficiency: " << fuelEfficiency << " MPGe (Miles Per Gallon equivalent)" << endl;
        cout << "Battery Life: " << batteryLife << " miles per charge" << endl;
    }

    // Special method for electric cars
    void estimateRange(float currentBattery) const {
        float range = (currentBattery / 100.0f) * batteryLife;
        cout << "Estimated range at current battery: " << range << " miles" << endl;
    }
};

int main() {
    // Create an ElectricCar object
    ElectricCar tesla("Tesla", "Model 3", 2024, 4, 24.5f, 350.0f);
    tesla.display();

    // Show range estimation
    cout << "\nAt 80% battery:" << endl;
    tesla.estimateRange(80);

    cout << "\nVehicle management system ready! " << endl;

    return 0;
}
