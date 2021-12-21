#include "Zadatak1.hpp"
//Konstruktori / Destruktori
Book::Book() {
	autor = NULL;
	naslov = NULL;
	godina_izdanja = 0;
}
Book::~Book() {
	if (autor != NULL && naslov != NULL) {
		delete[] autor;
		delete[] naslov;
	}
}
EBook::EBook() {
	enaslov = NULL;
}
EBook::~EBook() {
	if (enaslov != NULL) {
		delete[] enaslov;
	}
}
Library::Library() {
	n = 10;
	niz = new Book* [n];
}
Library::~Library() {
	delete[] niz;
}
Library::Library(int n) {
	this->n = n;
	niz = new Book* [n];
}
//-------------------------------------------------
void Book::GetData(char(&autor)[1024], char(&naslov)[1024]) {
	strcpy(autor, this->autor);
	strcpy(naslov, this->naslov);
}

void HardCopyBook:: LoadBook(char(&autor)[1024], char(&naslov)[1024], float broj) {
	this->autor = _strdup(autor);
	this->naslov = _strdup(naslov);
	pages = broj;
}
void EBook::LoadEBook(char(&autor)[1024], char(&enaslov)[1024], float broj) {
	this->autor =_strdup(autor);
	this->naslov =_strdup(enaslov);
	size = broj;
}
char** Library::GetTitles(char(&buffer)[1024],int &size) {
	char** naslovi = new char* [lv];
	char autor[1024];
	char naslov[1024];
	for (int i = 0;i < lv;i++) {
		niz[i]->GetData(autor, naslov);
		if (!strcmp(autor, buffer)) {
			naslovi[size] = _strdup(naslov);
			size++;
		}
	}
	return naslovi;
}
float Library::Get_size() {
	float suma = 0;
	char buffer[1024];
	for (int i = 0;i < lv;i++) {
		suma+=niz[i]->data();
	}
	return suma;
}
Book** Library::GetPartTitle(char(&buffer)[1024], int& size) {
	Book** knjige = new Book * [lv];
	char autor[1024];
	char naslov[1024];
	for (int i = 0;i < lv;i++) {
		niz[i]->GetData(autor, naslov);
		if (strstr(naslov, buffer)) {
			knjige[size] = niz[i];
			size++;
		}
	}
	return knjige;
}
void Library::get_Library(char *buffer) {
	FILE* fp = fopen(buffer, "r");
	char buffer1[1024];
	char autor[1024];
	char naslov[1024];
	char enaslov[1024];
	if (!fp)
	{
		cout << "ERROR OPENING FILE" << endl;
		return;
	}
	while (fgets(buffer1, 1024, fp) != NULL) {
		float broj = 0;
		readfile(buffer1, autor, naslov, enaslov, broj);
		if (enaslov[0] != '\0') {
			HardCopyBook* b = new HardCopyBook;
			b->LoadBook(autor, naslov, 0);
			niz[lv] = b;
			lv++;
			EBook* b1 = new EBook;
			b1->LoadEBook(autor, enaslov, broj);
			niz[lv] = b1;
			lv++;
		}
		else {
			HardCopyBook* b = new HardCopyBook;
			b->LoadBook(autor, naslov, broj);
			niz[lv] = b;
			lv++;
		}
	}
}
void readfile(char (&buffer1)[1024],char(&autor)[1024], char(&naslov)[1024], char(&enaslov)[1024], float& broj) {
	int i = 0, j = 0, k = 0, t = 0;
	int counter = 0;
	bool flag = false;
	int lenght = strlen(buffer1);
	for (int z = 0;buffer1[z] != '\0';z++) {
		if (buffer1[z] == ';') {
			counter++;
		}
		else if (counter == 0) {
			autor[i] = buffer1[z];
			i++;
		}
		else if (counter == 1 && buffer1[z] != ';') {
			naslov[j] = buffer1[z];
			j++;
		}
		else if (counter == 2) {
			if (buffer1[z] != ' ' && (isalpha(buffer1[z]) || buffer1[z] == '_' || buffer1[z] == '.')) {
				enaslov[t] = buffer1[z];
				t++;
			}
			else if (buffer1[z] != ' ' && isdigit(buffer1[z])) {
				if (!(isdigit(buffer1[z])) && buffer1[z] != '.') {
					break;
				}
				broj = float(broj * 10 + ((int)buffer1[z] - 48));
			}
		}
		else if (counter == 3) {
			if (!(isdigit(buffer1[z])) && buffer1[z] != '.' && buffer1[z] != ' ') {
				break;
			}
			if (buffer1[z] == '.') {
				flag = true;
			}
			else if (isdigit(buffer1[z])) {
				if (flag == true) {
					int potencija = -1;
					broj = broj + ((float)(((int)buffer1[z] - 48) * pow(10, potencija)));
					potencija--;
				}
				else
					broj = float(broj * 10 + ((int)buffer1[z] - 48));
			}
		}
	}
	enaslov[t] = '\0';
	autor[i] = '\0';
	naslov[j] = '\0';
}
