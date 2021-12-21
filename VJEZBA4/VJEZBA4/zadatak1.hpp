#include <iostream>
#include <cstdlib>
using namespace std;

class vektor {
private:
	double* niz;
	int lv;
	int fv;
public:
	vektor();
	vektor(int n, double k=0);
	vektor(const vektor& other);
	void vector_new(int n);
	void vector_delete();
	void vector_pop_back();
	double vector_front();
	double vector_back();
	void vector_push_back(int n);
	double* realociraj(double* niz);
	void print();
	~vektor();
};


