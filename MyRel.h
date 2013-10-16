#ifndef MYREL_H
#define MYREL_H

#include <set>
#include <utility>
#include <vector>

class MyRel
{
public:
	MyRel();
	MyRel(std::set<int> A);
	~MyRel();

	std::set<int> domain();
	
	void add(std::pair<int, int> P);
	void add(std::set<std::pair<int,int>> PSet);
	void append(MyRel S);
	void printPairs();
	void printSet();

	bool q(std::pair<int, int> P);
	
	//Pairset
	std::set<std::pair<int, int>> pairSet();

	MyRel  refl_closure();
	MyRel  symm_closure();
	MyRel   comp(MyRel S); // Skapar sammansättningen av en relation med en annan relation.
	MyRel trans_closure();

	
private:
	std::set<int> mDomainSet;
	std::set<std::pair<int, int>> mPairs;
};

#endif // MYREL_H
