#include "Zadatak2v2.hpp"

Robot::Robot(bool Par, bool Nepar) {
	this->Par = Par;
	this->Nepar = Nepar;
}
Human::Human(bool Par, bool Nepar) {
	this->Par = Par;
	this->Nepar = Nepar;
}
int Human::move() {
	int broj;
	cout << "Odigrajte broj u rasponu 0-5" << endl;
	while (1) {
		cin >> broj;
		if (broj < 0 || broj>5) {
			cout << "Neispravan unos , broj mora biti u rasponu 1-5" << endl;
			cout << "Unesite ponovno" << endl;
		}
		else {
			Human_move = broj;
			return Human_move;
			system("cls");	
		}
	}
}
int Robot::move() {
	int a = rand() % 6;
	Robot_move=a;
	return Robot_move;
}
Game::Game(Player* P1, Player* P2){
	this->P1 = P1;
	this->P2 = P2;
}
int Game::Game_Over() {
	if (P1->get_points() == goal) {
		return 2;
	}
	else if (P2->get_points() == goal) {
		return 1;
	}
	else
		return 0;
}
void Game::GameType() {
	while (1) {
		int a = P1->move();
		int b = P2->move();
		Check_Result();
		Print_Status();
		system("pause");
		system("cls");
		if (Game_Over() == 2) {
			cout << "Cestitam pobijedili ste" << endl;
			return;
		}
		else if (Game_Over() == 1) {
			cout << "Zao nam je , izgubili ste" << endl;
			return;
		}
	}
	

}
void Game::Check_Result() {
	if ((P1->get_move() + P2->get_move()) % 2 == 0 && P1->get_color())
		P1->increment_point();
	else if ((P1->get_move() + P2->get_move()) % 2 != 0 && !(P1->get_color()))
		P1->increment_point();
	else
		P2->increment_point();

}
void Game::Print_Status() {
	cout << "Odigrali ste broj " << P1->get_move() << endl;
	cout << "Racunalo je odigralo broj " << P2->get_move() << endl;
	if ((P1->get_move() + P2->get_move()) % 2 == 0 && P1->get_color()){
		cout<< "Zbroj brojeva je paran" << endl;
		cout<<"Osvojili ste bod" << endl;

	}
	else if ((P1->get_move() + P2->get_move()) % 2 != 0 && !(P1->get_color())) {
		cout << "Zbroj brojeva je neparan" << endl;
		cout << "Osvojili ste bod" << endl;
	}
	else if ((P1->get_move() + P2->get_move()) % 2 == 0) {
		cout << "Zbroj brojeva je paran" << endl;
		cout << "Racunalo osvaja bod" << endl;
	}
	else {
		cout << "Zbroj brojeva je neparan" << endl;
		cout << "Racunalo osvaja bod" << endl;
	}
	cout << endl;
	cout << endl;
	cout << "Imate " << P1->get_points() << "bodova" << endl;
	cout << "Racunalo ima " << P2->get_points() << "bodova" << endl;
}
Game::~Game() {
	delete P1;
	delete P2;
}
