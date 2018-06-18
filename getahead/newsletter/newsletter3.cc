#include<iostream>
#include<vector>
#include<map>
#include<pair>

using namespace std;

int main(void) {

	map< int, vector<int> > tree;
	map< int, int> paths;
	vector< int > stack, count;
	int n, head, node, best = 0, parent;
	char c;

	cin >> n >> head;

	for( int i = 0; i < n; i++ ) {
		node = cin.get();
		paths[node] = 1;

		c = cin.get(); // space
		tree[node] = vector<int>(); // initialize to empty vector

		while (c != "\n") {
			if ( c != " ")
				tree[node].push_back ( (int)c );
			c = cin.get();
		}
	}

	// get head 
	stack.insert( stack.end(), tree[head].begin(), tree[head].end() );

	while( !stack.empty() ) {
		node = stack.front();
		if(node - head == 1) 
			paths[node] = paths[head] + 1;
		
		stack.pop_front();

		if( !tree[node].empty() ) {
			head = node;
			stack.insert( stack.end(), tree[node].begin(), tree[node].end() );
		}

		if( best < paths[node] ) 
			best = paths[node];
		
	}

	cout << best << endl;


	return 0;
}