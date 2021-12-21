#include "funkcije.h"
#include <time.h>

void VEKTOR::vector_new(int n) {
	niz = new double[n];
	lv = 0;
	fv = n;
}
void VEKTOR::vector_delete() {
	delete[] niz;
	niz = NULL;
}
void VEKTOR::vector_push_back(int broj) {
	niz[lv] = broj;
	if (lv == fv - 1) {
		double* temp = niz;
		niz = realociraj(niz);
		delete[] temp;
		temp = NULL;
	}
	lv++;
}
double*VEKTOR:: realociraj(double*niz) {
	fv *= 2;
	double* niz1 = new double[fv];
	for (int i = 0;i <fv/2;i++) {
		niz1[i] = niz[i];
	}
	return niz1;
}
void VEKTOR::vector_pop_back() {
	if (lv)
		lv--;
}
double VEKTOR::vector_front() {
	if (lv) {
		return niz[0];
	}
	else
	{
		cout << "Niz je prazan" << endl;
		return 0;
	}

}
double VEKTOR::vector_back() {
	if (lv) {
		return niz[lv-1];
	}
}
void VEKTOR::print() {
	for (int i = 0;i < this->lv;i++) {
		cout << this->niz[i] << " ";
	}
}
void TOCKA::set_value(const double a, const double b, double c) {
	x = a;
	y = b;
	z = c;
}
void TOCKA::set_random_value(const int a, const int b) {
	x = a + rand() % (b - a + 1);
	y = a + rand() % (b - a + 1);
	z = a + rand() % (b - a + 1);
}
 void TOCKA::get_value(double& a, double& b, double& c) {
	a = x;
	b = y;
	c = z;
}
int TOCKA::distance1(TOCKA&tocka) {
	return sqrt((x - tocka.x) * (x - tocka.x) + (y - tocka.y) * (y - tocka.y));
}
int TOCKA::distance2(TOCKA& tocka) {
	return sqrt((x - tocka.x) * (x - tocka.x) + (y - tocka.y) * (y - tocka.y)+(z-tocka.z)*(z-tocka.z));
}
void ORUZJE::shoot() {
	if (spremnik_stanje)
		spremnik_stanje--;
	else {
		reload();
		spremnik_stanje--;
	}
}
void ORUZJE::reload() {
	spremnik_stanje = spremnik_max;
}
void ORUZJE::set_weapon(const int n,TOCKA&t) {
	polozaj = t;
	spremnik_max = n;
}
double ORUZJE::get_position() {
	double x, y, z;
	polozaj.get_value(x, y, z);
	return z;
}

void META::set_target(TOCKA& tocka1, TOCKA& tocka2) {
	t1 = tocka1;
	t2 = tocka2;
}

bool META::isshot(double z) {
	double niz[3];
	t1.get_value(niz[0], niz[1], niz[2]);
	double niz1[3];
	t2.get_value(niz1[0], niz1[1], niz1[2]);
	if (niz1[2] < niz[2]) {
		double temp=niz[2];
		niz[2] = niz1[2];
		niz1[2] = temp;
	}
	if (z >= niz[2] && z <= niz1[2]) {
		pogodena = true;
		return true;
	}
	pogodena = false;
	return false;
}
int ORUZJE::shooting(META*& target,const int n) {
	int counter = 0;
	double niz[3];
	polozaj.get_value(niz[0], niz[1], niz[2]);
	for (int i = 0;i < n;i++) {
		if (target[i].isshot(niz[2])) {
			counter++;
		}
		shoot();
	}
	return counter;
}



