#include <iostream>
#include <cstdlib>
#include <string.h>
class Animal {
protected:
	char vrsta[15] = "zivotinja";
public:
	virtual int legs() = 0;
	virtual char* name() = 0;
};
class Kukac : public Animal {
protected:
	char vrsta[15] = "Kukac";
public:
};
 
class Pauk : public Animal {
protected:
	char vrsta[15] ="Pauk";
public:
};
class Ptica : public Animal {
private:
	char vrsta[15] = "Ptica";
public:
};
class Tarantula :public Pauk {
private:
	int num_leg = 8;
	char ime[15] = "Tarantula";
public:
	int legs();
	char* name();
};
class Zohar :public Kukac {
private:
	int num_leg = 6;
	char ime[15] = "Zohar";
public:
	int legs();
	char* name();
};
class Vrabac :public Ptica {
private:
	int num_leg = 2;
	char ime[15] = "Vrabac";
public:
	int legs();
	char* name();
};
class Count {
private:
	Animal** niz;
	int lv = 0;
	int broj = 0;
public:
	Count();
	void add(Animal* A1);
	int sum();
};