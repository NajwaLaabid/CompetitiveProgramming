#include<bits/stdc++.h>

using namespace std;

int main(void) {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	vector<long long> sticks, output, numbers;
	long long n, t, m, max, add, size, flag, j;
	string s;

	sticks.push_back(6);
	sticks.push_back(2);
	sticks.push_back(5);
	sticks.push_back(5);
	sticks.push_back(4);
	sticks.push_back(5);
	sticks.push_back(6);
	sticks.push_back(3);
	sticks.push_back(7);
	sticks.push_back(6);

	for(int i = 0; i < 10; i++)
		numbers.push_back(0);
	
	numbers[2] = 1;
	numbers[3] = 7;
	numbers[4] = 4;
	numbers[5] = 5;
	numbers[6] = 9;
	numbers[7] = 8;
	
	// cin >> t;

	// while(t--) {
		output.clear();
		max = 6;
		add = 0;

		cin >> n;
		cin >> s;

		for(int i = 0; i < s.size(); i++)
			output.push_back(sticks[s[i] - '0']); // initial number with sticks
		
		sort(output.rbegin(), output.rend());

		for(int i = 0; i < output.size(); i++) {
			// cout << "checking" << output[i] << endl;
			m = max - output[i] - add;

			if( m == 0 ) {
				// add is what we needed
				output[i] += add;
				add = 0;
			} 
			else if( m < 0 ) {
				// we have more than we need
				add = 0 - m; // change m to positive
				output[i] = max;
			} 
			else {
				flag = 0;
				// try to borrow from the others
				j = i+1;
				if(j < output.size() && output[j] - m >= 2) {
					output[i] += add + m;
					output[j] -= m;
					flag = 1;
					max = 6;
					add = 0;
				}

				// couldnt borrow, see if can move to the next max
				if( flag == 0 && max != 3 ) {
					max = 3;
					i -= 1; // revisit the same number with a different max
				} else
					max = 6;

			}  
		}

		// check if have any add left
		if(add > 0) {
			size = output.size() - 1;
			for(int i = size; i >= 0; i--) {
				// add from end
				if( add <= 7 - output[i] ) {
					output[i] += add;
					add = 0;
				} else {
					add -= 7 - output[i];
					output[i] += add;
				}
			}
		}
		
		// print output
		for(int i = 0; i < output.size(); i++)
			cout << numbers[output[i]];

		cout << endl;
	// }

	return 0;
}