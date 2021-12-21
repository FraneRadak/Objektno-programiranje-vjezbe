#include "funkcije.h"
void zad1(int niz[], int& najmanji, int& najveci, int n) {
	najmanji = niz[0];
	najveci = niz[0];
	for (int i = 0;i < n;i++) {
		if (niz[i] > najveci)
			najveci = niz[i];
		else if (niz[i] < najmanji)
			najmanji = niz[i];
	}
}
int zad2(PRAVOKUTNIK*& niz, const KRUZNICA& krug,int n){
	int manji = 0;
	int counter=0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < 4;j++) {
			if (lenght(niz[i].tocke[j].x, niz[i].tocke[j].y, krug.ishodiste.x, krug.ishodiste.y) < krug.radius) {
				manji++;
			}
		}
		if (manji && manji < 4) {
			counter++;
		}
		manji = 0;
	}
	return counter;
}
int& zad3(int (&niz)[6],int n) {
	return niz[rand()%6]; // vraca referencu na  jedan element niza
}

int* zad4(int n) {
	int* p = new int[n];
	p[0] = 1;
	p[1] = 1;
	for (int i = 2;i < 10;i++) {
		p[i] = p[i - 1] + p[i - 2];
	}
	return p;
}
int* zad5(int*& niz, int indeks,int broj,int& n) {
	niz[indeks] = broj;
	if (indeks  == n-1) {
		n = 2 * n;
		int *novi = new int[n];
		for (int i = 0;i < n / 2;i++)
			novi[i] = niz[i];
		delete[] niz;
		niz = NULL;
		return novi;
	}
	return niz;
}
PRAVOKUTNIK* novi(int n) {
	PRAVOKUTNIK* niz;
	niz = new PRAVOKUTNIK[n];
	return niz;
}
int lenght(int t1x,int t1y,int t2x,int t2y){
	int d= sqrt((t1x - t2x) * (t1x - t2x) + (t1y - t2y) * (t1y - t2y));
	return d;
}
void vector_new(VEKTOR& vektor) {
	vektor.niz = new int[vektor.fv];
	vektor.lv = 0;
}
void vector_push_back(VEKTOR& vektor, int broj) {
	vektor.niz[vektor.lv] = broj;
	if (vektor.lv == vektor.fv-1) {
		int* temp = vektor.niz;
		vektor.niz = realociraj(vektor);
		delete[] temp;
		temp = NULL;
	}
	vektor.lv++;
}
int* realociraj(VEKTOR& vektor) {
	vektor.fv *= 2;
	int* niz = new int[vektor.fv];
	for (int i = 0;i < vektor.fv / 2;i++) {
		niz[i] = vektor.niz[i];
	}
	return niz;
}
void print_vector(VEKTOR& vektor) {
	for (int i = 0;i < vektor.lv;i++) {
		cout << vektor.niz[i]<<" ";
	}
}
void vector_pop_back(VEKTOR& vektor){
	if (vektor.lv)
		vektor.lv -= 1;
}
int vector_front(VEKTOR& vektor) {
	if (vektor.lv)
		return vektor.niz[0];
}
int vector_back(VEKTOR& vektor) {
	if(vektor.lv)
		return vektor.niz[vektor.lv - 1];
}
int vector_size(VEKTOR& vektor) {
	return vektor.lv;
}
void delete_vector(VEKTOR& vektor) {
	delete[] vektor.niz;
	vektor.niz = NULL;
}

