#include<iostream>
using namespace std;


int e = 100;
class text {
private:
	int* _elem;
	int data;
	int _size;

public:
	text( int e,int s) {
		_elem = new int[e];
		_size = 0;
		for ( ; _size <s-1; ) {
			_elem[_size++] = 0;
		}
	}
	~text() {
		delete []_elem;
	}

	void insert( int e) {
		_elem[_size] = e;
		_size++;
	}
	void init() {
		for (int i = 0; i < _size; i++) {
			_elem[i] = rand();
		}
	}

	void swap(int& n, int& m) {
		int* temp = new int;
		*temp = n;
		n = m;
		m = *temp;
		delete temp;
	}



	bool sorted() {
		bool sorted = true;
		for (int i = 0; i < _size-1; i++) {
			if (_elem[i] > _elem[i + 1])
			{
				sorted = false;
				swap(_elem[i], _elem[i + 1]);
			}
		}
		return sorted;
	}
	void bubbleSort() {
		while (!sorted());
	}










	void print() {
		for (int i = 0; i < _size; i++) {
			printf("%c ", _elem[i]);

		}
	}
};


int main()
{
	text tet(15,10);
	tet.init();
	tet.bubbleSort();
	tet.print();
	return 0;
}