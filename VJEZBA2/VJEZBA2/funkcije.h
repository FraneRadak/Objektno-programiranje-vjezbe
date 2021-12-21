#include <cmath>
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#ifndef TOCKA
typedef struct{
	int x;
	int y;
}TOCKA;
#endif // !TOCKA


#ifndef PRAVOKUTNIK
typedef struct{
	TOCKA tocke[4];
	int niz[8];
}PRAVOKUTNIK;
#endif // !PRAVOKUTNIK


#ifndef KRUZNICA
typedef struct {
	TOCKA ishodiste;
	int radius;
}KRUZNICA;
#endif // !KRUZNICA


#ifndef VEKTOR
typedef struct {
	int* niz;
	int fv;
	int lv;
}VEKTOR;
#endif // !VEKTOR
 

void zad1(int niz[], int& najmanji, int& najveci,int n);
int& zad3(int(&niz)[6], int n);
int* zad4(int n);
int* zad5(int*& niz, int indeks, int broj, int& n);
PRAVOKUTNIK* novi(int n);
int zad2(PRAVOKUTNIK*& niz, const KRUZNICA& krug, int n);
void vector_new(VEKTOR& vektor);
void vector_push_back(VEKTOR& vektor, int broj);
void vector_pop_back(VEKTOR& vektor);
int vector_front(VEKTOR& vektor);
int vector_back(VEKTOR& vektor);
int vector_size(VEKTOR& vektor);
void delete_vector(VEKTOR& vektor);
int* realociraj(VEKTOR& vektor);
void print_vector(VEKTOR& vektor);
int lenght(int t1x, int t1y, int t2x, int t2y);



