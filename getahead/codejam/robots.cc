#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<map>

using namespace std;

int main(void) {

	vector<long long> a, b, c, d, x, y;
	long long k, temp, count;
	int n, t;
	map<long long, long long> occurence;

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> t;

	for(int i = 1; i <= t; i++) {
		count = 0;
		cin >> n >> k;
		occurence.clear();
		a.clear();
		b.clear();
		c.clear();
		d.clear();
		y.clear();
		x.clear();

		for(int j = 0; j < n; j++) {
			cin >> temp;
			a.push_back(temp);
		}

		for(int j = 0; j < n; j++) {
			cin >> temp;
			b.push_back(temp);
		}

		for(int j = 0; j < n; j++) {
			cin >> temp;
			c.push_back(temp);
		}

		for(int j = 0; j < n; j++) {
			cin >> temp;
			d.push_back(temp);
		}

		//compute x and y
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				temp = a[j] ^ b[k];
				x.push_back( a[j] ^ b[k] );
				temp = c[j] ^ d[k];
				y.push_back( temp );
				if( occurence.find(temp) != occurence.end() ) 
					occurence[temp]++;
				else
					occurence[temp] = 1;
			}
		}


		sort( y.begin(), y.end() );

		for(int j = 0; j < x.size(); j++) {
			x[j] = x[j] ^ k;
		}
		
		for(int j = 0; j < x.size(); j++) {
			if( binary_search(y.begin(), y.end(), x[j]) ){
				count += occurence[x[j]];
			}
		}

		cout << "Case #" << i << ": " << count << endl;
	}


	return 0;
}