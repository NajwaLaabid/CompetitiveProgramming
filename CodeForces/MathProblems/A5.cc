// link : http://codeforces.com/contest/318/problem/A

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	long long n, k, x, g; // g is number of odd elements

	cin >> n >> k;

	if ( n % 2 == 0 ) g = n/2;
	else g = n/2 + 1;

	if ( k <= g ) x = 2 * ( k - 1 ) + 1;
	else x = 2 * ( k - g );

	cout << x << endl;

	return 0;
}