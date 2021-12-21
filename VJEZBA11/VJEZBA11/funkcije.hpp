#include <iostream>
#include<cstdlib>
#include <vector>
#include <cmath>
#include <math.h>
#include <list>
using namespace std;

typedef struct {
	double x;
	double y;
	double z;
}Point;
typedef struct {
	Point p1;
	Point p2;
	Point p3;
}Trokut;

class Triangle {
private:
	vector<Trokut>niz;
	double povrsina(Trokut& t);
public:
	void unos(int n);
	void ispis();
	Trokut najveci();
};

vector<int> generiraj(int n);
void unos(vector<int>& v);
void ispis(vector<int>& v);
vector <int>filter(vector<int>& v1, vector<int>& v2);
void change(string& str);
int ukupnozn(list<string>& str);
double prosjek(list<string>& str);
void izbrisi(list<string>& str);

