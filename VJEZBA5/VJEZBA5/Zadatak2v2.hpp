#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
using namespace std;

class Player {
protected:
	bool Par;
	bool Nepar;
	int points = 0;
public:
	virtual int move() = 0;
	virtual int get_move() = 0;
	void increment_point() {points++;};
	int get_points() { return points;}
	bool get_color() { return Par;}
};
class Robot : public Player {
private:
	int Robot_move;
public:
	Robot(bool Par, bool Nepar);
	int move();
	int get_move() { return Robot_move; };
};
class Human : public Player {
private:
	int Human_move;
public:
	Human(bool Par, bool Nepar);
	int move();
	int get_move() { return Human_move; };
};
class Game {
private:
	Player* P1;
	Player* P2;
	int goal = 5;
public:
	Game(Player* P1, Player* P2);
	int Game_Over();
	void Print_Status();
	void GameType();
	void Check_Result();
	~Game();
	
};