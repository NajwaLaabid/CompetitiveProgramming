// http://codeforces.com/contest/472/problem/A

#include <iostream>

using namespace std;

int main (void) {

	int n, x , y;

	cin >> n;

	if( n % 2 == 0) {

		x = n - 4;
		y = n - x;

	} else {

		x = n - 9;
		y = n - x;

	}

	cout << x << " " << y << endl;

	return 0;
}