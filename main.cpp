#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
    string name;
    string model;
    int batteryLife;

public:
    Robot(string n, string m, int b) : name(n), model(m), batteryLife(b) {}// Constructor


    string getName() {return name;}
    string getModel() {return model;}
    int getBatteryLife() {return batteryLife;}// Getter Methods


    void setName(string n){name = n;}
    void setModel(string m){model = m;}
    void setBatteryLife(int b){batteryLife = b;}// Setter Methods


    // Display function
    void displayRobot() {
        cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
    }
};

// Step 2: Function to modify robot (pass by value)
void modifyRobotByValue(Robot r) {
    // set new batter life for Robot object
    r.setBatteryLife(50);
    // print new battery life for Robot object
    cout << "Inside function using pass by value: " << r.getBatteryLife() << endl;

}

// Step 3: Function to modify robot (pass by reference)
void modifyRobotByReference(Robot &r) {
    // set new battery life for Robot object
    r.setBatteryLife(100);
    // print new battery life for Robot object
    cout << "Inside function using pass by reference: " << r.getBatteryLife() << endl;
}


// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>
class Fleet {
private:
    T* robots;
    int capacity;
    int count;

public:
    // Constructor: Allocates space for 'capacity' robots
    Fleet(int cap) {
        capacity = cap;
        count = 0;
        robots = new T[capacity];
    }

    // Add robot to fleet
    void addRobot(T robot) {
        if (count < capacity) {
            robots[count] = robot;
            count++;
        } else {
            cout << "Fleet is full!\n";
        }
    }

    // Display all robots
    void showFleet() {
        cout << "Fleet contains:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << robots[i] << "\n";
        }
    }

    // Destructor: Free allocated memory
    ~Fleet() {
        delete[] robots;
    }
};

int main() {
    // Step 5: Create a Robot object
    Robot myRobot("Rob", "model1",72);

    // Step 6: Use pointers to access Robot object
    Robot* robotPtr = &myRobot;
    // update battery life using pointer
    robotPtr->setBatteryLife(20);

   cout << "Updated Battery Life (using pointer): " << robotPtr->getBatteryLife() << "%\n";

    // Step 7: Pass by value (no change outside function)
    modifyRobotByValue(myRobot);
    // print battery life: there should be no change
    cout << "After modifyRobotByValue, Battery Life: " << myRobot.getBatteryLife() << "%\n";

    // Step 8: Pass by reference (changes persist)
    modifyRobotByReference(myRobot);
    // print battery life: it should change
    cout << "After modifyRobotByReference, Battery Life: " << myRobot.getBatteryLife() << "%\n";

    // Step 9: Use the Fleet template class
    Fleet<string> myFleet(3);
    myFleet.addRobot("Autobot-X");
    myFleet.addRobot("Cybertron-7");
    myFleet.addRobot("NanoDroid-3");

    myFleet.showFleet();

    return 0;
}