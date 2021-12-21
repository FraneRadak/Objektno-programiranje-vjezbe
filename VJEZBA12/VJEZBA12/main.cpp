#include "funkcije.hpp"



int main() {
	ifstream file;
	file.open("wimbledon_double_faults.txt");
	if (!(file.is_open())) {
		cout << "ERROR OPENNING FILE" << endl;
		return 1;
	}
	vector<Red> container = napuni(file);
	print(container);
	
	remove(container);
	vector<Red>::iterator it=najmanje(container);
	sortiraj(container);
	formatirani_ispis(container);
	
	/* zadatak 2
	ostream_iterator<short> os(std::cout, " ");
	polje<short, 10> a(4);
	a[0] = a[2] += 5;
	copy(a.begin(), a.end(), os);
	*/
	/*zadatak 3
	ifstream file("zadatak3.txt");
	if (!(file.is_open())) {
		cout << "ERROR OPENNING FILE" << endl;
	}
	try {
		vector<double>prirodni = ucitaj(file);
		int n = prebroji(prirodni);
		izbrisi(prirodni);
		sortiraj_vektor(prirodni);
		print(prirodni);
	}
	catch (int) {
		cout << "Uneseni brojevi moraju biti prirodni" << endl;
	}
	*/
}