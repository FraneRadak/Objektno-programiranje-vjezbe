#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cmath>
using namespace std;


class Book {
protected:
	char* autor;
	char* naslov;
	int godina_izdanja;
public:
	Book();
	~Book();
	void GetData(char(&autor)[1024], char(&naslov)[1024]);
	virtual float data() = 0;
};
class EBook : public Book {
private:
	float size=0;
	char* enaslov;
public:
	EBook();
	~EBook();
	void LoadEBook(char(&autor)[1024], char(&naslov)[1024], float broj);
	float data() { return size; }
};
class HardCopyBook : public Book {
private:
	int pages=0;
public:
	void LoadBook(char(&autor)[1024], char(&naslov)[1024], float broj);
	float data() { return 0;}
};
class Library {
protected:
	Book** niz;
	int n;
	int lv = 0;
public:
	Library(int n);
	Library();
	~Library();
	void get_Library(char*buffer);
	char** GetTitles(char(&buffer)[1024],int&size);
	Book** GetPartTitle(char(&buffer)[1024], int& size);
	float Get_size();
};
void readfile(char(&buffer1)[1024], char(&autor)[1024], char(&naslov)[1024], char(&enaslov)[1024], float& broj);
