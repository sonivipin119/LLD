#include <mutex>
#include <iostream>
using namespace std;
class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton Constructor Called!" << endl;
    }

public:
    static Singleton* getInstance() {
      return instance;
    }
};

// Static member definitions
// waste memory if instance is never used when heavy work needed, but thread safe without locks
Singleton* Singleton::instance = new Singleton(); // Eager initialization

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl;
}
