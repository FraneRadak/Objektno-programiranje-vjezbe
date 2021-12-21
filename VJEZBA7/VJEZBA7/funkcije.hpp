#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;

class Vehcile {
protected:
public:
	virtual char* type() = 0;
	virtual unsigned int passangers()=0;
	virtual ~Vehcile(){}
};
class Watercraft :public virtual Vehcile {
protected:
	char tip[10] = "water";
public:
	char* type();
};
class Aircraft :public virtual Vehcile {
protected:
	char tip[10] = "air";
public:
	char* type();
};
class Ferry :public Watercraft {
protected:
	int people;
	int bikes;
	int cars;
public:
	Ferry(int a , int b , int c);
	unsigned int passangers();

};
class Catamaran :public Watercraft {
protected:
	int num;
public:
	Catamaran(int n);
	unsigned int passangers();
	
};
class Seaplane :public Watercraft, public Aircraft {
protected:
	int num;
public:
	Seaplane(int n);
	unsigned int passangers();
	char* type() override;

	
};
class Counter {
private:
	unsigned int counter = 0;
public:
	void add(Vehcile* v);
	int total();
};