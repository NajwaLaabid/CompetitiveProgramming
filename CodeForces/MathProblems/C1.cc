#include<iostream>
#include<cmath>


using namespace std;

int main(void) {
	int n;
	long long solution;

	cin >> n;

	solution = pow(2, n+1) - 2;

	cout << solution << endl;

	return 0;
}
