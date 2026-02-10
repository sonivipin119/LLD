#include<iostream>
// Singleton Design
// 1. Private constructor to prevent instantiation from outside the class.
// 2. Static member variable to hold the single instance of the class.
// 3. Create a static instance (getinstance) method that returns the single instance of the class, creating it if it doesn't already exist.
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton Constructor called" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}