/*
	algo:
	scan nb
	in set? 
	 - get elt from set iterator, compute area, compare to areabest and update
	 :
	 - add pair<val, indx> to set
*/
#include<bits/stdc++.h>

int main(void) {

	pair<int, int> point;
	set<pair<int, int>> plot;
	int bestArea = 0, area;
	vector<int> values = {1, 2, 5, 2, 4, 1};

	for(int i = 0; i < values.size(); i++) {
		point = plot.find(make_pair(values[i], i));

		if( point != plot.end ) 
			// compute area
			bestArea = max( bestArea, ( i - point->second ) * values[i] );
		else
			plot.insert(make_pair(values[i], i));
	}


	return 0;
}