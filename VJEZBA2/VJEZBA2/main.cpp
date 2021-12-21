
#include "funkcije.h"
using namespace std;

void main() {
	srand(time(NULL));
	//
	//zadatak1
	/*
	int niz[6] = { 1,3,5,6,9,11 };
	int najmanji;
	int najveci;
	int n = sizeof(niz) / sizeof(int);
	zad1(niz, najmanji, najveci,n);
	cout << "Najmanji broj niza je " << najmanji << ", a najveci broj niza je " << najveci;
	*/
	//Zadatak2
	/*
	int n=2;
	PRAVOKUTNIK* niz = novi(n);
	niz[0].tocke[0].x = 7;
	niz[0].tocke[0].y = 5;
	niz[0].tocke[1].x = 3;
	niz[0].tocke[1].y = -5;
	niz[0].tocke[2].x = 0;
	niz[0].tocke[2].y = 13;
	niz[0].tocke[3].x = -2;
	niz[0].tocke[3].y = 4;
	//----------------------------
	niz[1].tocke[0].x = 17;
	niz[1].tocke[0].y = -6;
	niz[1].tocke[1].x = -13;
	niz[1].tocke[1].y = 4;
	niz[1].tocke[2].x = 21;
	niz[1].tocke[2].y = 8;
	niz[1].tocke[3].x = -15;
	niz[1].tocke[3].y = -2;
	KRUZNICA krug;
	krug.ishodiste.x = -15;
	krug.ishodiste.y = 4;
	krug.radius = 25;
	int ukupno = zad2(niz, krug, n);
	cout << "Kruznicu ukupno sijece " << ukupno << " pravokutnika";
	delete[] niz;
	niz = NULL;
	*/
	
	//zadatak3
	
	int niz[6] = { 1,3,5,6,9,11 };
	int& element = zad3(niz, 6);
	element += 1;
	cout << "Broj je " << element << endl;

	//zadatak4
	/*
	int n = 10;
	int* pointer = zad4(n);
	for (int i = 0;i < n;i++) {
		cout << pointer[i] <<" ";
	}
	delete[] pointer;
	*/

	//zadatak5
	/*
	int broj;
	int indeks = 0;
	int n=10;
	int* niz = new int[n];
	while (1) {
		cout << "Unesite pozitivan cijeli broj:" << endl;
		cin >> broj;
		if (!broj)
			break;
		else if (broj > 0) {
			niz = zad5(niz, indeks, broj, n);
		}
		else
			cout<<"Pogresan unos" <<endl;
		indeks++;
	}
	for (int i = 0;i < indeks;i++) {
		cout << niz[i] << " ";
	}
	delete[] niz;
	niz = NULL;
	*/
	//zadatak6
	/*
	VEKTOR vektor;
	cout << "Unesite velicinu vektora:" << endl;
	cin >> vektor.fv;
	vector_new(vektor);
	vector_push_back(vektor, 1);
	vector_push_back(vektor, 2);
	vector_push_back(vektor, 3);
	vector_push_back(vektor, 4);
	vector_push_back(vektor, 5);
	vector_pop_back(vektor);
	cout << vector_front(vektor) << endl;
	cout << vector_back(vektor) << endl;
	cout << vector_size(vektor) << endl;
	print_vector(vektor);
	delete_vector(vektor);
	*/
}