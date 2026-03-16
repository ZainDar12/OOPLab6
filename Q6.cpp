#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string brand;
    string model;

public:

    Device(string b = "Unknown", string m = "Unknown") 
        : brand(b), model(m) {}

    virtual void display() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
    }

    virtual ~Device() {}
};

class Smartphone : virtual public Device {
protected:
    int simSlotCount;

public:

    Smartphone(string b = "Unknown", string m = "Unknown", int sim = 1)
        : Device(b, m), simSlotCount(sim) {}

    void display() const override {
        cout << "\n=== Smartphone Details ===" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "SIM Slots: " << simSlotCount << endl;
    }
};

class Tablet : virtual public Device {
protected:
    bool stylusSupport;

public:
    
    Tablet(string b = "Unknown", string m = "Unknown", bool stylus = false)
        : Device(b, m), stylusSupport(stylus) {}

    // Display tablet info
    void display() const override {
        cout << "\n=== Tablet Details ===" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Stylus Support: " << (stylusSupport ? "Yes" : "No") << endl;
    }
};

class HybridDevice : public Smartphone, public Tablet {
private:
    float screenSize;
    string folding_type;

public:
   
    HybridDevice(string b = "Unknown", string m = "Unknown", int sim = 1, 
                 bool stylus = false, float screen = 6.5f, string fold = "None")
        : Device(b, m), Smartphone(b, m, sim), Tablet(b, m, stylus), 
          screenSize(screen), folding_type(fold) {}

    // Display hybrid device info
    void display() const override {
        cout << "  HYBRID DEVICE SPECIFICATIONS  " << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "SIM Slots: " << simSlotCount << endl;
        cout << "Stylus Support: " << (stylusSupport ? "Yes" : "No") << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Folding Type: " << folding_type << endl;
    }

    // Special method for hybrid devices
    void toggleMode() const {
        cout << "\n Switching between Smartphone and Tablet mode..." << endl;
        cout << " Mode switched successfully!" << endl;
    }
};

int main() {
    cout << "       HYBRID DEVICE MANAGEMENT SYSTEM            " << endl;
   
 

    // Create a HybridDevice object
    HybridDevice flagship("Samsung", "Galaxy Z Fold 6", 2, true, 7.6f, "Folding");
    
    // Display the hybrid device details
    flagship.display();

    // Use hybrid device features
    flagship.toggleMode();

    cout << "\n Virtual inheritance resolved the Diamond Problem!" << endl;
    cout << " Only ONE instance of Device base class exists!" << endl;
    cout << " HybridDevice combines Smartphone and Tablet seamlessly!" << endl;

    cout << "\n WITHOUT Virtual Inheritance (The Problem):" << endl;
    cout << "   - HybridDevice would have TWO separate copies of Device" << endl;
    cout << "   - Accessing 'brand' would be ambiguous" << endl;
    cout << "   - Compiler error: member is ambiguous" << endl;

    cout << "\n WITH Virtual Inheritance (The Solution):" << endl;
    cout << "   - HybridDevice has ONLY ONE copy of Device" << endl;
    cout << "   - No ambiguity when accessing inherited members" << endl;
    cout << "   - Clean, efficient multiple inheritance!" << endl;

    return 0;
}
