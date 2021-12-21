using namespace std;
#include <iostream>
template<typename T>
void sort(T* niz, int n) {
	bool flag = 0;
	while (1){
		flag = 0;
		for (int i = 0;i < n-1;i++) {
			if (niz[i] > niz[i + 1]) {
				swap(niz[i], niz[i + 1]);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
}
template<>
void sort(char* niz , int n) {
	bool flag = 0;
	for (int i = 0;i < n;i++) {
		if (isalpha(niz[i])) {
			niz[i] = tolower(niz[i]);
		}
	}
	while (1) {
		flag = 0;
		for (int i = 0;i < n - 1;i++) {
			if (niz[i] > niz[i + 1]) {
				swap(niz[i], niz[i + 1]);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
}
void swap(char t1, char t2) {
	char temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}

template<typename T>
void swap(T& t1, T& t2) {
	T temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}
template <typename Stek>
class Stack {
private:
	Stek* niz;
	int lv ;
	int fv;
public:
	
	Stack() {
		fv = 10;
		lv = 0;
		niz = new Stek[fv];
	}
	
	void pop() {
		if (lv) {
			lv--;
		}
	}
	
	void push(Stek t) {
		niz[lv] = t;
		lv++;
	}
	
	bool is_empty(){
		if (lv)
			return false;
	return true;
	}
};