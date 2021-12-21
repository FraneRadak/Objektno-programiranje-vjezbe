#include "funkcije.hpp"


int main() {
	Counter c;
	Vehcile* v[] = { new Catamaran(30), new Ferry(10, 5, 3), new Seaplane(5)};
	for (unsigned i = 0; i < 3; ++i)
		c.add(v[i]);
	std::cout << "ukupno " << c.total() << " putnika" << std::endl;
	for (int i = 0;i < 3;i++)
		delete v[i];
}