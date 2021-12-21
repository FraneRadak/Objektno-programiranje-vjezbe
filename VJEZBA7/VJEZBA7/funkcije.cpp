#include "funkcije.hpp"

Ferry::Ferry(int a,int b,int c) {
	people = a;
	bikes = b;
	cars = c;
}
Catamaran::Catamaran(int n) {
	num = n;
}

Seaplane::Seaplane(int n){
	num = n;
}

char* Aircraft::type() {
	char* tip1 = _strdup(tip);
	return tip1;
}
char* Watercraft::type() {
	char* tip1 = _strdup(tip);
	return tip1;
}
unsigned int Ferry::passangers() {
	return people;
}
unsigned int Catamaran::passangers() {
	return num;
}
unsigned int Seaplane::passangers() {
	return num;
}
char* Seaplane::type() {
	char*tip=new char[50];
	int brojac = 0;
	char* sluc = Aircraft::type();
	for (int i = 0;sluc[i]!='\0';i++) {
		tip[brojac] = sluc[i];
		brojac++;
	}
	delete[]sluc;
	tip[brojac] = '-';
	brojac++;
	char* temp2 = Watercraft::type();
	for (int i = 0;i < strlen(temp2);i++) {
		tip[brojac] = temp2[i];
		brojac++;
	}
	delete[]temp2;
	tip[brojac] = '\0';
	return tip;
}
void Counter::add(Vehcile* v) {
	char* str = v->type();
	puts(str);
	delete[] str;
	counter += v->passangers();
}
int Counter::total() {
	return counter;
}


