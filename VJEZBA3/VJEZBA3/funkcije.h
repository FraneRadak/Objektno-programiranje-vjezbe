#include <iostream>
#include <cmath>
#include <cstdbool>
#include <time.h>
using namespace std;

class VEKTOR {
private:
	double* niz;
	int lv;
	int fv;
public:
	void vector_new(int n);
	void vector_delete();
	void vector_pop_back();
	double vector_front();
	double vector_back();
	void vector_push_back(int n);
	double* realociraj(double* niz);
	void print();
};
class TOCKA {
private:
	double x=0;
	double y=0;
	double z=0;
public:
	void set_value(double x1, double y1, double z1);
	void set_random_value(int dg, int gg);
	void get_value(double& x1, double& y1, double& z1);
	int distance1(TOCKA&tocka);
	int distance2(TOCKA&tocka);
};
class META {
private:
	TOCKA t1;
	TOCKA t2;
	bool pogodena;
public:
	void set_target(TOCKA& t1, TOCKA& t2);
	bool isshot(double z);
};
class ORUZJE {
private:
	TOCKA polozaj;
	int spremnik_max;
	int spremnik_stanje;
public:
	void shoot();
	void reload();
	void set_weapon(int n, TOCKA& t);
	double get_position();
	int shooting(META*& target, int n);
};
