#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctime>
using namespace std;

class Error{
private:
public:
	virtual void write_error( fstream&f)=0;
};
class Devide_by_zero :public Error {
private:
	string error = "Dijeljenje s 0";
public:
	void write_error(fstream& f);
};
class Not_digit :public Error {
private:
	string error = "Uneseni znak nije broj!";
public:
	void write_error(fstream& f);
};
class Invalid_operation :public Error {
private:
	string error = "Nepoznata operacija!!";
public:
	void write_error(fstream& f);
};

