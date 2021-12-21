#include "zadatak1.hpp"
#include "zadatak2.hpp"

int main(void) {
	/*
	vektor v(10,5);
	v.vector_push_back(1);
	v.vector_push_back(2);
	v.vector_push_back(3);
	v.vector_push_back(4);
	v.vector_push_back(5);
	v.print();
	vektor v2 = v;
	cout << endl;
	v2.print();
	*/
	Board b;
	Point t1(2,2);
	Point t2(8, 8);
	b.draw_char(t1, 'X');
	b.draw_char(t2, 'X');
	b.print_board();
	cout << "------------------" << endl;
	b.draw_line(t1, t2, 'X');
	b.print_board();


	
}