#include "Zadatak2v2.hpp"
#include "Zadatak1.hpp"

int main(void) {
	/*
	int size = 0;
	Library L1(100);
	char buffer[50] = "Knjige.txt";
	L1.get_Library(buffer);
	float suma = L1.Get_size();
	cout << (float)suma;
	*/
	
	Player* P1 = new Human(true,false);
	Player* P2 = new Robot(false, true);
	Game G1(P1,P2);
	G1.GameType();
}



