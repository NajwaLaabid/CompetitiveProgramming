// link : http://codeforces.com/problemset/problem/577/A
#include <bits/stdc++.h>

using namespace std; 

int main (void) {

	long long x, y;
	int n, sum = 0;
	int square = 0;

	cin >> n >> x; 

	if( x <= n )
		sum = 1;

	for ( int i = 2; i <= n; i++ ) {
		y = x / i;

		if ( i <= x && x % i == 0 ) 
			sum++;
		
		if ( y == i && square ) {
			square = 0;
			sum--;
		} else if ( y == i ) {
			// cout << "yes" << endl;
			square = 1;
		}

	}

	cout << sum << endl;

	return 0;
}