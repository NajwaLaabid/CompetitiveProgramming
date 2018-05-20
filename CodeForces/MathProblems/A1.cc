// link: http://codeforces.com/contest/4/problem/A

#include <iostream>

using namespace std;

int main(void) {

	int w;

	cin >> w;

	if( w > 2 && w % 2 == 0 )
		cout << "YES" << endl;

	else 
		cout << "NO" << endl;

	return 0;
} 