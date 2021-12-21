#include "funkcije.hpp"

void fun1() {
	throw Devide_by_zero();
}
void input_number(int&a) {
	char broj;
	cout << "Unesite cijeli broj:" << endl;
	cin>>broj;
	
	if (!(isdigit(broj))) {
		throw Not_digit();
	}
	else {
		a = (int)broj - 48;
	}
}
char input_simbol() {
	char temp;
	cout << "Unesite simbol:" << endl;
	cin >> temp;
	return temp;
}
double count(int a, int b,char operation) {
	if (operation == '/') {
		if (b == 0) {
			throw Devide_by_zero();
		}
		return a / b;
	}
	else if (operation == '+') {
		return a + b;
	}
	else if (operation == '-') {
		return a - b;
	}
	else if (operation == '*') {
		return a * b;
	}
	else {
		throw Invalid_operation();
	}
}
int main() {
	fstream file;
	file.open("errors.log", ios::out | ios::app);
	while (1) {
		try{
			int a;
			int b;
			input_number(a);
			input_number(b);
			char operation =input_simbol();
			double c = count(a, b, operation);
			cout << "Rezultat je " << c << endl;
		}
		catch (Error& e) {
			e.write_error(file);
			break;
		}
	}
	file.close();
}



