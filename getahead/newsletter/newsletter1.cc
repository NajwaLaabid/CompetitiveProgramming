#include<bits/stdc++.h>

using namespace std;

class flattenedIterator {
	private:
		vector< vector<int> > origirnalList;
		vector<int> flattenedList;
		int size, head, maxInnerSize, innerHead;

	public:

		void flattenedIterator(vector<vector<int>> list) {
			origirnalList = list;
			size = list.size();
			head = 0;
			maxInnerSize = 0;
			innerHead = 0;

			for(int i = 0; i < size; i++) {
				if( list[i].size() > maxInnerSize ) {
					maxInnerSize = list[i].size();
				}
			}
		}

		bool hasNextFlat() {
			return head < size;
		}

		vector<int> nextFlat() {
			return origirnalList[head++];
		}

		bool hasNext() {
			return innerHead < originalList[head].size();
		}

		int next() {
			return originalList[head][innerHead];
		}

		vector<int> interleave() {
			vector<int> innerList;
			int iterations = size * maxInnerSize;

			while( iterations-- ) {
				while( hasNextFlat() ) {
					innerList = nextFlat();

					if( hasNext() ) {
						flattenedList.push_back( next() );
					}
				
				}

				head = 0;	
			}
			
		}



};

int main(void) {



	return 0;
}