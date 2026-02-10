#include <mutex>
#include <iostream>
using namespace std;
class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() {
        cout << "Singleton Constructor Called!" << endl;
    }

public:
    static Singleton* getInstance() {
      if (instance == nullptr) {
        lock_guard<mutex> lock(mtx); // Double-checked locking
        if(instance == nullptr){
          instance = new Singleton();
        }
      }
      return instance;
    }
};

// Static member definitions
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    cout << (s1 == s2) << endl;
}
