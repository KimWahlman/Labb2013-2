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

	std::cout << "Grund settet\n";
	Bas.printSet();
	Bas.printPairs();

	MyRel Refl = Bas.refl_closure();
	std::cout << "\n\nReflektiva settet\n";
	Refl.printSet();
	Refl.printPairs();

	MyRel  Symm = Bas.symm_closure();
	std::cout << "\n\nSymmetriska settet\n";
	Symm.printSet();
	Symm.printPairs();

	MyRel Trans = Bas.trans_closure();
	std::cout << "\n\nTransitiva settet\n";
	Trans.printSet();
	Trans.printPairs();
	
	MyRel Append = Bas;
		  Append.append(Trans);
	std::cout << "\n\nAlla par fran MyRel Trans laggs i Append\n";
	Append.printSet();
	Append.printPairs();
	
	MyRel Comp = Symm.comp(Refl);
	std::cout << "\n\nSammansattning mellan Symm och Refl\n";
	Comp.printSet();
	Comp.printPairs();

	int x;
	std::cin >> x;

	return 0;
}
