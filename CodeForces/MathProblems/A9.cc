#include <iostream>

using namespace std;


int main(void) {

	int n, k = 1, ans = 0;
	vector<int> p;

	cin >> n;

	// Ys
	for( int i = 2; i < n - 1 ;  i++ ) {
		k = 1;
		while ( pow(i, k) <= n ) {
			p.push_back( pow(i, k) );
			k++;
			ans++;
		}
		
	}

	// number of Ys
	cout << ans << endl;

	for( int i = 0; i < p.size() - 1; i++ ) 
		cout << p[i] << " ";
	

	// Print Ys
	cout << p[i] << endl;

	return 0;
}