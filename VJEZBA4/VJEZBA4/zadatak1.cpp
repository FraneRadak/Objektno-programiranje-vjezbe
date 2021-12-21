#include "zadatak1.hpp"
vektor::vektor() {
	niz = new double[10];
	fv = 10;
	lv = 0;
}
vektor::vektor(int n, double k) {
	niz = new double[n];
	for (int i = 0;i < n;i++) {
		niz[i] = k;
	}
	fv = n;
	lv = n - 1;
}
vektor::vektor(const vektor& other) {
	niz = new double[other.fv];
	fv = other.fv;
	lv = other.lv;
	for (int i = 0;i < lv;i++) {
		niz[i] = other.niz[i];
	}
}
void vektor::vector_new(int n) {
	niz = new double[n];
	lv = 0;
	fv = n;
}
void vektor::vector_delete() {
	delete[] niz;
	niz = NULL;
}
void vektor::vector_push_back(int broj) {
	if (lv == fv - 1) {
		double* temp = niz;
		niz = realociraj(niz);
		delete[] temp;
		temp = NULL;
	}
	niz[lv] = broj;
	lv++;
}
double* vektor::realociraj(double* niz) {
	fv *= 2;
	double* niz1 = new double[fv];
	for (int i = 0;i < fv / 2;i++) {
		niz1[i] = niz[i];
	}
	return niz1;
}
void vektor::vector_pop_back() {
	if (lv)
		lv--;
}
double vektor::vector_front() {
	if (lv) {
		return niz[0];
	}
	else
	{
		cout << "Niz je prazan" << endl;
		return 0;
	}

}
double vektor::vector_back() {
	if (lv) {
		return niz[lv - 1];
	}
}
void vektor::print() {
	for (int i = 0;i < this->lv;i++) {
		cout << this->niz[i] << " ";
	}
}
vektor::~vektor() {
	delete[] niz;
	niz = NULL;
}