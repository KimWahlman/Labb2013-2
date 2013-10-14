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
	R.add( std::pair<int, int>( ( *R.domain( ).find( 1 ) ), ( *R.domain( ).find( 2 ) ) ) );
	R.add( std::pair<int, int>( ( *R.domain( ).find( 3 ) ), ( *R.domain( ).find( 4 ) ) ) );
	R.add( std::pair<int, int>( ( *R.domain( ).find( 5 ) ), ( *R.domain( ).find( 6 ) ) ) );
	//MyRel T = R.refl_closure();
	MyRel S = R.symm_closure();
	S = S.refl_closure();
	return 0;
}
