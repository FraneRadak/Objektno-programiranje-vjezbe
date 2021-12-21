#include <iostream>
using namespace std;

class Money {
private:
	int kune;
	int lipe;
public:
	Money();
	Money(int x, int y=0);
	Money& operator+=(const Money& m);
	Money& operator-=(const Money& m);
	Money& operator+(const Money& m);
	Money& operator-(const Money& m);
	operator double();
	friend ostream& operator<<(ostream&os,const Money& m);
	void round_high();
	void round_low();
};
