#include <iostream>

// Base class
class Vehicle {
   protected:
    float fuelCapacity;
    float currentFuel;

    void consumeFuel(float amount) {
        if (amount <= currentFuel) {
            currentFuel -= amount;
        } else {
            std::cout << "Not enough fuel!\n";
        }
    }

   public:
    Vehicle(float fuelCapacity) : fuelCapacity(fuelCapacity), currentFuel(0) {}

    void refuel(float amount) {
        if (amount + currentFuel <= fuelCapacity) {
            currentFuel += amount;
            std::cout << "Refueled to " << currentFuel << " liters.\n";
        } else {
            std::cout << "Cannot refuel beyond capacity!\n";
        }
    }

    virtual void drive(float km) = 0;  // Pure virtual function, making Vehicle
                                       // an abstract class
};

// Derived class
class Car : public Vehicle {
   public:
    Car(float fuelCapacity) : Vehicle(fuelCapacity) {}

    void drive(float km) override {
        float fuelNeeded = km * 0.1;  // Suppose 1 km needs 0.1 liters of fuel
        consumeFuel(fuelNeeded);
        std::cout << "Driven " << km << " km, remaining fuel: " << currentFuel
                  << " liters.\n";
    }
};

int main() {
    Car myCar(50);     // Car with a fuel capacity of 50 liters
    myCar.refuel(30);  // Refuel the car with 30 liters
    // Note: doesn't allow access to protected members consumeFuel and
    // currentFuel
    myCar.drive(100);  // Attempt to drive 100 km
    myCar.drive(50);   // Attempt to drive another 50 km
    return 0;
}
