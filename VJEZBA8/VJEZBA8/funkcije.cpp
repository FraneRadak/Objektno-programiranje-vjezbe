#include "funkcije.hpp"

Money::Money() {
	kune = 0;
	lipe = 0;
}
Money::Money(int x, int y) {
	kune = x;
	lipe = y;
}
Money& Money::operator+=(const Money& m) {
	kune += m.kune;
	lipe += m.lipe;
	round_high();
	return *this;
}
Money& Money::operator+(const Money& m) {
	kune += m.kune;
	lipe += m.lipe;
	round_high();
	return *this;
}
Money& Money::operator-(const Money& m) {
	if (kune > 0) {
		kune -= m.kune;
		lipe -= m.lipe;
		round_low();
	}
	return *this;
}
Money& Money::operator-=(const Money& m) {
	if (kune > 0) {
		kune -= m.kune;
		lipe -= m.lipe;
		round_low();
	}
	return *this;
}
void Money::round_high() {
	if (lipe >= 100) {
		kune++;
		lipe -= 100;
	}
}
void Money::round_low() {
	if (lipe < 0) {
		kune--;
		lipe = 100 - abs(lipe);
	}
}
ostream& operator<<(ostream& os, const Money& m) {
	return os << "Ukupan racun iznosi " << m.kune << " kuna i " << m.lipe << " lipa" << endl;
}
Money::operator double() {
	return double(kune);
}