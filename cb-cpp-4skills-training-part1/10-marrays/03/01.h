#include<iostream>
using namespace std;

int exec10marrays0301h()  {
	// d, r, u, l
	int di[] = {1, 0, -1, 0};
	int dj[] = {0, 1, 0, -1};

	int i = 4, j = 7;

	for (int d = 0; d < 4; ++d) {
		int ni = i + di[d];
		int nj = j + dj[d];
		cout<<ni<<" "<<nj<<"\n";
	}
	/*
	 5 7
	 4 8
	 3 7
	 4 6

	 */



	return 0;
}
