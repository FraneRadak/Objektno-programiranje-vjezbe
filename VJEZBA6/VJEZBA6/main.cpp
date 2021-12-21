#include "funkcije.hpp"


int main() {
	Tarantula t1;
	Vrabac v1;
	Zohar z1;
	Animal* p1 = &t1;
	Animal* p2 = &v1;
	Animal* p3 = &z1;
	Count c;
	c.add(p1);
	c.add(p2);
	c.add(p3);
	int broj = c.sum();
	return 0;

}