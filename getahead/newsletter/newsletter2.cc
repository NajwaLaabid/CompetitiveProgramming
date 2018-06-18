#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(void){

	string s = ") ( ( ) ) ) ) ) ( ( ( ( ( )";
	vector<char> st;
	int best = 0, current = 0;

	for(int i = 0; i < s.size(); i++){

		if(s[i] == '(') {

			st.push_back(s[i]);

		}else if(s[i] == ')') {

			if(st.empty()) // pop fails
				current = 0;
			else{
				current += 2;
				st.pop_back();

				if(st.empty() && best < current)
					best = current;
			}
		}

	}

	if( best < current )
		best = current;

	cout << best << endl;

	return 0;
}