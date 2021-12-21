#include "funkcije.h"

void main() {
	srand(time(NULL));

	VEKTOR vektor;
	vektor.vector_new(5);
	vektor.vector_push_back(1);
	vektor.vector_push_back(2);
	vektor.vector_push_back(3);
	vektor.vector_push_back(4);
	vektor.vector_push_back(5);
	vektor.vector_push_back(6);
	//double a = vektor.vector_back();
	//cout << a << endl;
	vektor.print();
	//zad2
	/*
	TOCKA tocka1;
	TOCKA tocka2;
	tocka1.set_value(6, 8, 9);
	tocka2.set_value(15, 6, 87);
	int d = tocka1.distance1(tocka2);
	cout << "Dvodimenzionalna udaljenost tocaka je " << d << endl;
	d = tocka1.distance2(tocka2);
	cout << "Trodimenzionalna udaljenost tocaka je " << d << endl;
	tocka1.set_random_value(5, 60);
	tocka2.set_random_value(4,78);
	d = tocka1.distance1(tocka2);
	cout << "Dvodimenzionalna udaljenost tocaka je " << d << endl;
	d = tocka1.distance2(tocka2);
	cout << "Trodimenzionalna udaljenost tocaka je " << d << endl;
	*/
	//zadatak5
	cout << endl;
	int n = 700;
	META* mete = new META[n];
	for (int i = 0;i < n;i++) {
		TOCKA t1;
		TOCKA t2;
		t1.set_random_value(1, 10);
		t2.set_random_value(1, 10);
		mete[i].set_target(t1, t2);
	
	}
	ORUZJE oruzje;
	TOCKA t;
	t.set_random_value(1, 10);
	oruzje.set_weapon(15, t);
	cout << "Ukupno je pogodeno " << oruzje.shooting(mete,n) <<"od "<<n<<" meta"<< endl;
	delete[] mete;
}