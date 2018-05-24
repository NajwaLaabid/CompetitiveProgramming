// Link: http://codeforces.com/problemset/problem/559/A

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(void) {

	long long number, sideLarge;
	int sides[6];

	for( int i = 0; i < 6; i++) 
		cin >> sides[i]; 
	
	sideLarge = sides[0] + sides[1] + sides[2];

	number = pow( sideLarge, 2 ) - pow(sides[2], 2) - pow(sides[4], 2) - pow(sides[0], 2);

	cout << number << endl;

	return 0;
}

/*
	Tutorial:

	Imagine hexagon inside a regular triangle. 
	Divide triangle into N regular triangles with side 1, using lines parallel to the side of the large triangle.
	Find total number of those triangles:
		- The area of the large triangle is: sqt(3)/4 * pow(A, 2)
		- The area of the small triangles is: sqt(3)/4 * pow(a, 2) = sqt(3)/4
		- The number of triangles deduced: pow(A, 2)
		- A = a1 + a2 + a3 
			* one side of the large triangle can be seen as the sum of the 3 first sides of the hexagon (clockwise order)

	Remove the excess triangles (the ones that are not part of hexagon):
		- Comparing the shapes of hexagon and outer triangle, 3 'tringular masses' are found to be of excess:
			* The one next to side 1 (bottom left)
			* the one next to side 3 (top)
			* the one next to side 5 (bottom right)

		- The number of triangles in each of these masses can be found using the same method adopted earlier:
		- The total number to be removed is hence: pow(a1, 2), pow(a3, 2), pow(a5, 2)


	Final number of inner triangles: pow( (a1 + a2 + a3), 2 ) - pow( a1, 2 ) - pow( a3, 2 ) - pow( a5, 2 )

*/