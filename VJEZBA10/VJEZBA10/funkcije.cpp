#include "funkcije.hpp"

void Devide_by_zero::write_error(fstream&f) {
	cout << "Zabranjneno je dijeliti s 0!!" << endl;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	f << ltm->tm_mday<<"."<< 1 + ltm->tm_mon<<"."<< 1900 + ltm->tm_year<<","<< ltm->tm_hour << ":"<< ltm->tm_min << ":"<< ltm->tm_sec << endl;
	f << error << endl;
	f << "----------------------" << endl;
}
void Not_digit::write_error(fstream& f) {
	cout << "Uneseni znak mora biti znamenka!!" << endl;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	f << ltm->tm_mday << "." << 1 + ltm->tm_mon << "." << 1900 + ltm->tm_year << "," << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
	f << error << endl;
	f << "----------------------" << endl;
}
void Invalid_operation::write_error(fstream& f) {
	cout << "Nepoznata operacija!!" << endl;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	f << ltm->tm_mday << "." << 1 + ltm->tm_mon << "." << 1900 + ltm->tm_year << "," << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
	f << error << endl;
	f << "----------------------" << endl;
}