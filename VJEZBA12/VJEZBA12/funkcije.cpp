#include "funkcije.hpp"


istream& operator>>(istream& os, Red& r) {
	os >> r.redni_br >> r.Ime >>r.drzava>> r.greske >> r.mecevi;
	return os;
}
ostream& operator<<(ostream& os, Red& r) {
	os << r.redni_br<<"  " << r.Ime<<"  " << r.drzava<<"  " << r.greske<<"  " << r.mecevi;
	return os;
}


vector<Red>napuni(ifstream& file) {
	vector<Red>v;
	istream_iterator<Red>it(file);
	istream_iterator<Red>eof;
	copy(it, eof, back_inserter(v));
	return v;
}
void print(vector<Red>& container) {
	for (int i = 0;i < container.size();i++) {
		cout<<container[i]<<endl;
	}
}
void remove(vector<Red>& r) {
	vector<Red>::iterator it;
	it = r.begin();
	while(it!=r.end()){
		if ((*it).greske > 4) {
			it = r.erase(it);
		}
		else {
			it++;
		}
	}
}
vector<Red>::iterator najmanje(vector<Red>& r) {
	vector<Red>::iterator it=r.begin();
	vector<Red>::iterator temp=it;
	while (it != r.end()) {
		if ((*it).greske < (*temp).greske) {
			temp = it;
		}
		it++;
	}
	return temp;
}
bool usporedi(const Red& r1, const Red& r2) {
	return (r1.greske < r2.greske);
}
void sortiraj(vector<Red>& r) {
	sort(r.begin(), r.end(), usporedi);
}
void formatirani_ispis(vector<Red>& r) {
	vector<Red>::iterator it=r.begin();
	while (it != r.end()) {
		cout << (*it).redni_br <<" "<< (*it).Ime <<" "<< (*it).greske << endl;
		it++;
	}

}
vector<double>ucitaj(ifstream& file) {
	istream_iterator<double> it(file);
	istream_iterator<double> eof;
	vector<double>temp;
	copy(it, eof, back_inserter(temp));
	try {
		provjeri(temp);
	}
	catch (int) {
		throw int();
	}
	return temp;
}
void provjeri(vector<double>& v) {
	for (vector<double>::iterator it = v.begin();it != v.end();it++) {
		if (((*it) - (int)(*it) != 0) || ((*it) <= 0)) {
			throw int();
		}
	}
}
int prebroji(vector<double>& v) {
	int counter = 0;
	for (vector<double>::iterator it = v.begin();it != v.end();it++) {
		if ((*it) > 100) {
			counter++;
		}
	}
	return counter;
}
void izbrisi(vector<double>& v) {
	vector<double>::iterator it=v.begin();
	while (it != v.end()) {
		if ((*it) < 100) {
			it = v.erase(it);
		}
		else {
			it++;
		}
	}
}
bool compare_function(const double& a, const double& b) {
	return (a > b);
}
void sortiraj_vektor(vector<double>& v) {
	sort(v.begin(), v.end(), compare_function);
}
void print(vector<double>& container) {
	for (int i = 0;i < container.size();i++) {
		cout << container[i] << endl;;
	}
}
