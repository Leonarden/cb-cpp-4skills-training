#include<iostream>
using namespace std;

void print_triangle1(int levels) {
	if (levels == 0)
		return;

	print_triangle(levels - 1);

	for (int i = 0; i < levels; ++i)
		cout << "*";
	cout << "\n";
}

int exec12recfunc042h()  {
	print_triangle1(5);
	return 0;
}

