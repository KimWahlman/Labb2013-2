#include "MyRel.h"
#include <iostream>
#include <string>

int main()
{
	// Domänermängder
	std::set<int> ints;

	int arrays[] = { 1, 2, 3, 4, 5, 6 };
	ints.insert(arrays, arrays+6);
	
	MyRel R(ints);
	R.add(std::pair<int, int>(R.domain[0], R.domain[5]));

	
	return 0;
}
