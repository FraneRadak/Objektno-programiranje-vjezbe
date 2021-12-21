#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <istream>
#include <string>
#include <iterator>
#include<algorithm>
using namespace std;
typedef struct  {
	int redni_br;
	string Ime;
	string drzava;
	int mecevi;
	int greske;
}Red;
template<typename T,int n>
class polje {
private:
	T niz[n];
public:
	polje(int x) {
		fill(niz, niz + n, x);
	}
	T& operator[](int x) {
		if (x < n) {
			return niz[x];
		}
	}
	T* begin() {
		return niz;
	}
	T* end() {
		return niz+n;
	}
};

vector<Red>napuni(ifstream& f);
void print(vector<Red>& container);
void remove(vector<Red>& r);
vector<Red>::iterator najmanje(vector<Red>& r);
void sortiraj(vector<Red>& r);
void formatirani_ispis(vector<Red>& r);
vector<double>ucitaj(ifstream& file);
void provjeri(vector<double>& v);
int prebroji(vector<double>& v);
void izbrisi(vector<double>& v);
bool compare_function(const double& a, const double& b);
void sortiraj_vektor(vector<double>& v);
void print(vector<double>& container);


