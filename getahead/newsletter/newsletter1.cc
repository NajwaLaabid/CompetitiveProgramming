#include<bits/stdc++.h>

using namespace std;

class flattenedIterator {
	private:
		vector< vector<int> > originalList;
		vector<int> flattenedList;
		int size, head, maxInnerSize, innerHead;

	public:

		flattenedIterator(vector<vector<int>> list) {
			originalList = list;
			size = list.size();
			head = 0;
			maxInnerSize = 0;
			innerHead = 0;

			for(int i = 0; i < size; i++) 
				if( list[i].size() > maxInnerSize ) 
					maxInnerSize = list[i].size();
		}

		bool hasNext() {
			return head < size;
		}

		int next() {
			if( hasNext() ) return head++;
			return -1;
		}

		bool hasNextInner(int innerListIdx) {
			return innerHead <  originalList[innerListIdx].size();
		}

		int nextInner(int innerListIdx) {
			if( hasNextInner(innerListIdx) ) return originalList[innerListIdx][innerHead];
			return -1;
		}

		vector<int> interleave() {
			int innerListIdx;
			int iterations = size * maxInnerSize;
			innerHead = 0;

			while( iterations-- ) {
				while( hasNext() ) {
					innerListIdx = next();

					if( hasNextInner(innerListIdx) ) 
						flattenedList.push_back( nextInner(innerListIdx) );
				}

				innerHead++;
				head = 0;	
			}

			return flattenedList;
		}
};

int main(void) {
	vector<vector<int>> list;
	vector<int> interleavedList;
	int i;

	interleavedList.push_back(1);
	interleavedList.push_back(2);
	interleavedList.push_back(3);

	list.push_back(interleavedList);
	interleavedList.clear();

	interleavedList.push_back(4);
	interleavedList.push_back(5);
	interleavedList.push_back(6);
	interleavedList.push_back(7);

	list.push_back(interleavedList);
	interleavedList.clear();

	interleavedList.push_back(11);
	interleavedList.push_back(9);
	interleavedList.push_back(52);

	list.push_back(interleavedList);
	interleavedList.clear();

	flattenedIterator FI = flattenedIterator(list);
	interleavedList = FI.interleave();

	cout << "{ ";
	for(i = 0; i < interleavedList.size() - 1; i++) 
		cout << interleavedList[i] << " ";
	
	cout << interleavedList[i] << "}" << endl;

	return 0;
}