#include <iostream>
#include <cstdlib>
using namespace std;
struct Point {
public:
	double x;
	double y;
	Point(double a, double b);
	float distance(Point &t2);
	void zaokruzi();
};
class Board {
private:
	char** stupac;
	int width;
	int height;
public:
	Board();
	Board(int x, int y);
	Board(const Board& other);
	~Board();
	void print_board();
	void draw_char(Point p,char ch);
	void draw_up_line(Point p, char ch);
	void draw_line(Point &p1,Point &p2,char ch);
	void Clear_board();
};
