#include "MyRel.h"
#include <iostream>
#include <string>

int main()
{
	// Domänermängder
	std::set<int> ints;

	int arrays[] = { 1, 2, 3, 4, 5, 6 };
	ints.insert(arrays, arrays+6);
	
	MyRel Bas(ints);
	
	Bas.add( std::pair<int, int>( ( *Bas.domain( ).find( 1 ) ), ( *Bas.domain( ).find( 2 ) ) ) );
	Bas.add( std::pair<int, int>( ( *Bas.domain( ).find( 3 ) ), ( *Bas.domain( ).find( 4 ) ) ) );
	Bas.add( std::pair<int, int>( ( *Bas.domain( ).find( 5 ) ), ( *Bas.domain( ).find( 6 ) ) ) );
	Bas.add( std::pair<int, int>( ( *Bas.domain( ).find( 2 ) ), ( *Bas.domain( ).find( 3 ) ) ) );
	
	MyRel Refl = Bas.refl_closure();
	MyRel Trans = Bas.trans_closure();
	MyRel Append = Bas;
		  Append.append(trans);
	MyRel Comp = Bas.comp(trans);
	return 0;
}
