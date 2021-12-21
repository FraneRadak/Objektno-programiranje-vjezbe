#include "zadatak2.hpp"


Point::Point(double a, double b) {
	x =a;
	y =b;
}
float Point::distance(Point& t2) {
	return sqrt((x - t2.x) * (x - t2.x) + (y - t2.y) * (y - t2.y));
}
void Point::zaokruzi() {
	if (x - (int)x > 0.49)
		x++;
	if (y - (int)y > 0.49)
		y++;
	x = (double)((int)x);
	y = (double)((int)y);
}
Board::Board() {
	height = 10;
	width = 10;
	stupac = new char* [height];
	for (int i = height-1;i >= 0;i--) {
		stupac[i] = new char[10];
		for (int j = 0;j < width;j++) {
			if (j == 0 || j == 9 || i == 0 || i == 9)
				stupac[i][j] = '#';
			else
				stupac[i][j] = ' ';
		}
		cout << endl;
	}
}
Board::Board(int x, int y) {
	height = x;
	width = y;
	stupac = new char* [height];
	if (!stupac)
		cout << "ERROR" << endl;
	for (int i = height - 1;i >= 0;i--) {
		stupac[i] = new char[width];
		for (int j = 0;j < width;j++) {
			if (j == 0 || j == width-1 || i == 0 || i == height-1)
				stupac[i][j] = '#';
			else
				stupac[i][j] = ' ';
		}
		cout << endl;
	}
}
Board::Board(const Board& other) {
	height = other.height;
	width = other.width;
	stupac= new char* [height];
	if (!stupac)
		cout << "ERROR" << endl;
	for (int i = height - 1;i >= 0;i--) {
		stupac[i] = new char[width];
		for (int j = 0;j < width;j++) {
			stupac[i][j] = other.stupac[i][j];
		}
	}
}
void Board::print_board() {
	for (int i = height-1;i >= 0;i--) {
		for (int j =0;j < width;j++) {
			cout <<" "<<stupac[i][j];
		}
		cout << endl;
	}
}
void Board::draw_char(Point p, char ch) {
	p.zaokruzi();
	if (p.x == 0 || p.y == 0 || p.x>=width-1 || p.y>=height-1) {
		cout << "Koordinate moraju biti pozitivne , te manje od dimenzija ploce" << endl;
		return;
	}
	stupac[(int)p.y][(int)p.x] = ch;
}
void Board::draw_up_line(Point p, char ch) {

	p.zaokruzi();
	if (p.x <= 0 || p.y <= 0 || p.x >= width - 1 || p.y >= height - 1) {
		cout << "Koordinate moraju biti pozitivne , te manje od dimenzija ploce" << endl;
		return;
	}
	for (int i = p.y;i < height - 1;i++)
		stupac[i][(int)p.x] = ch;
}
void Board::draw_line(Point &t1,Point &t2,char ch) {
	if (t1.x == 0 || t1.y == 0 || t1.x >= width - 1 || t1.y >= height - 1) {
		cout << "Koordinate moraju biti pozitivne , te manje od dimenzija ploce" << endl;
		return;
	}
	if (t2.x == 0 || t2.y == 0 || t2.x >= width - 1 || t2.y >= height - 1) {
		cout << "Koordinate moraju biti pozitivne , te manje od dimenzija ploce" << endl;
		return;
	}
	double x = (t1.x + t2.x) / 2;
	double y = (t1.y + t2.y) / 2;
	Point poloviste(x,y);
	if (t1.distance(t2) < 1) {
		poloviste.zaokruzi();
		stupac[(int)(poloviste.y)][(int)(poloviste.x)] = ch;
		return;
	}
	draw_line(t1, poloviste,ch);
	draw_line(poloviste, t2,ch);
}

void Board::Clear_board() {
	for (int i = height - 2;i >= 1;i--) {
		for (int j = 1;j < width-1;j++) {
			stupac[i][j]=' ';
		}
		cout << endl;
	}
}
Board::~Board() {
	for (int i = 0;i<height;i++) {
		delete[] stupac[i];
	}
	delete[] stupac;
}

