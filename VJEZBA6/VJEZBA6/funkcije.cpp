#include "funkcije.hpp"

int Tarantula::legs() {
	return num_leg;
}
int Vrabac::legs() {
	return num_leg;
}
int Zohar::legs() {
	return num_leg;
}
char* Tarantula::name() {
	char* ime1 =_strdup(ime);
	return ime1;
}
char* Zohar::name() {
	char* ime1 = _strdup(ime);
	return ime1;
}
char* Vrabac::name() {
	char* ime1 = _strdup(ime);
	return ime1;
}
Count::Count() {
	niz = new Animal* [10];
}
void Count::add(Animal* A1) {
	niz[lv] = A1;
	lv++;
}
int Count::sum() {
	for (int i = 0;i < lv;i++) {
		puts(niz[i]->name());
		broj += niz[i]->legs();
	}
	return broj;
}