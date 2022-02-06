#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton* getInstance();

	void setData(int value) {
		data = value;
	}

	void display() {
		cout << "data = " << data << endl;
	}
	
private:
	// Private constructor so that no objects can be created.
	Singleton() {}

	//Singletons should not be cloneable.
	Singleton(Singleton &other) = delete; //C++11 delete keyword tells the compiler to make the function noncallable

	//Singletons should not be assignable.
	Singleton& operator=(const Singleton &) { return *this; }

	int data;

	static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance() {
	if (instance == nullptr) {
		instance = new Singleton();
	}

	return instance;
}

//Driver Function
int main() {
	Singleton* s1 = Singleton::getInstance();
	Singleton* s2 = Singleton::getInstance();

	//Since copy constructor is private below line will give compilation error
	//Singleton copy = *s1;

	//Since assignment operator is private below line will give compilation error
	//*s1 = *s2;

	//set "100" for one instance
	s1->setData(100);

	//Value "100" will be displayed for both
	s1->display();
	s2->display();

	return 0;
}