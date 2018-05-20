// link: http://codeforces.com/contest/546/problem/A

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	long long k, n, w, totalCost, needed;

	cin >> k >> n >> w;

	totalCost = k * w * ( 1 + w )/ 2;

	needed =  totalCost - n;

	if ( needed > 0 )
		cout << needed << endl;
	else 
		cout << 0 << endl;

	return 0;
}