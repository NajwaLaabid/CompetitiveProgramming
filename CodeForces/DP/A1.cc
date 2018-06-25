#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;
vector<int> occ;


int count(int start, int rem, int score) {
	int first = 0, second = 0, newIdx;

	if( start >= a.size() )
		return score;

	else {
		newIdx = start + occ[a[start]];

		if( rem - 1 != a[start] )
			first = a[start] * occ[a[start]] + count(newIdx, a[start], score);
		else
			first = count(newIdx, a[start], score);

		if( newIdx < a.size() )
			second = a[newIdx] * occ[a[newIdx]] + count(newIdx + occ[a[newIdx]], a[newIdx], score);

		return score + max(first, second);
	}
}

int main (void) {

	int n, x, score = 0;

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

	cout << count(0, 0, 0) << endl;

	return 0;
}