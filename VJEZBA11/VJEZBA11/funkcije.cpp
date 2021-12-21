#include "funkcije.hpp"

vector<int> generiraj(int n) {
	vector<int> temp(n);
	return temp;
}
void unos(vector<int>& v) {
	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
		cin >> *it;
	}
}
void ispis(vector<int>& v) {

	for (vector<int>::iterator it = v.begin();it != v.end();it++) {
		cout << *it << " ";
	}
}
vector <int>filter(vector<int>& v1, vector<int>& v2) {
	vector<int>temp;
	for (vector<int>::iterator it = v1.begin();it != v1.end();it++) {
		if (!(count(v2.begin(), v2.end(), *it))) {
			temp.push_back(*it);
		}
	}
	return temp;
}
void change(string& str) {
	for (int i = 0;i < str.length();i++) {
		if (str[i] == ' ' && (str[i + 1] == '.' || str[i + 1] == ',' || str[i + 1] == ':')) {
			str.erase(str.begin() + i);
			if (str[i+1] != ' ') {
				str.insert(i+1, string(1, ' '));
			}
		}
	}
}
int ukupnozn(list<string>&str){
	int counter = 0;
	for (list<string>::iterator it = str.begin();it != str.end();it++){
		counter += (*it).length();
	}
	return counter;
}
double prosjek(list<string>& str) {
	int a = 0;
	for (list<string>::iterator it = str.begin();it != str.end();it++){
		for (int j = 0;j < (*it).length()-1;j++) {
			if ((*it)[j] == ' ') {
				a++;
			}
		}
	}
	return (double)ukupnozn(str) / a;
}
void izbrisi(list<string>& str) {
	string temp="";
	for (list<string>::iterator it = str.begin();it != str.end();it++) {
		if ((*it).length() > temp.length()) {
			temp = *it;
		}
	}
	str.remove(temp);
}
void Triangle::unos(int n) {
	Trokut temp;
	for (int i = 0;i < n;i++) {
		cout << "TROKUT BROJ" << i + 1<<endl;
		cout << "Unesite x koordinatu prve tocke" << endl;
		cin >> temp.p1.x;
		cout << "Unesite y koordinatu prve tocke" << endl;
		cin >> temp.p1.y;
		cout << "Unesite z koordinatu prve tocke" << endl;
		cin >> temp.p1.z;
		cout << "----------------------------------------" << endl;
		cout << "Unesite x koordinatu druge tocke" << endl;
		cin >> temp.p2.x;
		cout << "Unesite y koordinatu druge tocke" << endl;
		cin >> temp.p2.y;
		cout << "Unesite z koordinatu druge tocke" << endl;
		cin >> temp.p2.z;
		cout << "----------------------------------------" << endl;
		cout << "Unesite x koordinatu trece tocke" << endl;
		cin >> temp.p3.x;
		cout << "Unesite y koordinatu trece tocke" << endl;
		cin >> temp.p3.y;
		cout << "Unesite z koordinatu trece tocke" << endl;
		cin >> temp.p3.z;
		cout << "----------------------------------------" << endl;
		cout << "********************************************************";
		niz.push_back(temp);
	}
}
void Triangle::ispis() {
	for (int i = 0;i < niz.size();i++) {
		Trokut temp = niz[i];
		cout << "TROKUT BROJ" << i + 1 << endl;
		cout << "X koordinata prve tocke:" << temp.p1.x<< endl;
		cout << "Y koordinata prve tocke:" << temp.p1.y<< endl;
		cout << "Z koordinata prve tocke:" << temp.p1.z<< endl;
		cout << "----------------------------------------" << endl;
		cout << "X koordinata druge tocke:" << temp.p2.x << endl;
		cout << "Y koordinata druge tocke:" << temp.p2.y << endl;
		cout << "Z koordinata druge tocke:" << temp.p2.z << endl;
		cout << "----------------------------------------" << endl;
		cout << "X koordinata trece tocke:" << temp.p3.x << endl;
		cout << "Y koordinata trece tocke:" << temp.p3.y << endl;
		cout << "Z koordinata trece tocke:" << temp.p3.z << endl;
		cout << "----------------------------------------" << endl;
		cout << "********************************************************";
	}
}
double Triangle::povrsina(Trokut& t) {
	double s = abs((t.p1.x * t.p2.y + t.p2.x * t.p3.y + t.p3.x * t.p1.y - t.p1.y * t.p2.x - t.p2.y * t.p3.x - t.p3.y * t.p1.x) / 2);
	return s;
}
Trokut Triangle::najveci() {
	int maksind = 0;
	double maksp = 0;
	for (int i = 0;i<niz.size();i++) {
		if (povrsina(niz[i]) > maksp) {
			maksp = povrsina(niz[i]);
			maksind = i;
		}
	}
	return niz[maksind];
}