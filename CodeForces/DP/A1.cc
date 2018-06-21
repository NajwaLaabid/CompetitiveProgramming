#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main (void) {

	int n, x, score = 0;
	vector<int> a, occ;

	// freopen("in.in", "r", stdin);
	// freopen("out.out", "w", stdout);

	cin >> n;

	for(int i = 0; i <= 100002; i++) {
		occ.push_back(0);
	}

	for(int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
		occ[x]++;
	}

	sort(a.begin(), a.end(), greater<int>());

	for(int i = 0; i < n; i++){
		x = a[i];

		if ( x * occ[x] > ( (x-1) * occ[x-1] + (x+1) * occ[x+1] ) ) {
			score += x * occ[x];
			// cout << "adding : " << x * occ[x] << endl;
			occ[x] = 0;
			occ[x - 1] = 0;
			occ[x + 1] = 0;
		} else {
			score += ( (x-1) * occ[x - 1] + ( x + 1 ) * occ[x+1] );
			// cout << "adding in else. Nb: " << x << "Occ: " << occ[x] << endl;
			occ[x-2 >= 0 ? x-2 : 0] = 0;
			occ[x-1] = 0;
			occ[x] = 0;
			occ[x+1] = 0;
			occ[x+2] = 0;
		}
	}

	cout << score << endl;

	return 0;
}