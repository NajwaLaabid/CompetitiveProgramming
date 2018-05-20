// link: http://codeforces.com/problemset/problem/313/A

#include <iostream>
#include <cmath> 

using namespace std;

int main (void) {

	int n, r, k;

	cin >> n;

	if ( n > 0 ) 
		cout << n << endl;
	else {

		r = abs(n)%10;
		k = abs(n)/100;

		if ( k * 10 + r < abs(n)/10 ) 
			cout << - (k * 10 + r) << endl;
		else
			cout << n/10;

	}

	return 0;
}