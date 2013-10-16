#include "MyRel.h"
#include <iostream>

MyRel::MyRel()
{
	
}

// Sätt mDomainSet till A
MyRel::MyRel(std::set<int> A)
{
	mDomainSet = A;
}

// Töm våra std::set<...>
MyRel::~MyRel()
{
	mDomainSet.clear();
	mPairs.clear();
}

// Metod som retunerar relations domänmängder
std::set<int> MyRel::domain()
{
	return mDomainSet;
}

void MyRel::add(std::pair<int,int> P)
{
	if(!q(P))
		mPairs.insert(P);
}

void MyRel::add(std::set<std::pair<int,int>> PSet)
{
	mPairs.insert(PSet.begin(), PSet.end());
}

bool MyRel::q(std::pair<int, int> P)
{
	for(std::set<std::pair<int, int>>::iterator i = mPairs.begin(); i != mPairs.end(); i++)
	{
		if((*i).first == P.first && (*i).second == P.second)
			return true;
	}
	return false;
}

std::set<std::pair<int, int>> MyRel::pairSet()
{
	return mPairs;
}

MyRel MyRel::refl_closure()
{
	MyRel refl(domain());
	refl.add(pairSet());
	for(std::set<std::pair<int, int>>::iterator i = refl.mPairs.begin(); i != refl.mPairs.end(); i++)
	{
		if((*i).first != (*i).second)
		{
			std::pair<int, int> x((*i).first, (*i).first), y((*i).second, (*i).second);
			if(!q(x))
				refl.mPairs.insert(x);

			if(!q(y))
				refl.mPairs.insert(y);
		}
	}
	return refl;
}

MyRel MyRel::symm_closure()
{
	MyRel symm(domain());
	symm.add(pairSet());
	for(std::set<std::pair<int, int>>::iterator i = symm.mPairs.begin(); i != symm.mPairs.end(); i++)
	{
		if((*i).first != (*i).second)
		{
			std::pair<int, int> x((*i).second, (*i).first);
			if(!q(x))
				symm.mPairs.insert(x);
		}
	}
	return symm; // Lovar Inge, ingen copy paste!
}

MyRel MyRel::comp(MyRel S)
{
	std::set<int> newSet;
	
	newSet = mDomainSet;
	newSet.insert(S.mDomainSet.begin(), S.mDomainSet.end());
	
	MyRel _comp(newSet);

	_comp.add(mPairs);
	_comp.add(S.mPairs);

	return _comp;
}

void MyRel::append(MyRel S)
{
	add(S.mPairs);
}

MyRel MyRel::trans_closure()
{
	MyRel trans(domain());
		  trans.add(pairSet());
	
	std::pair<int, int> transPair;
	std::set<std::pair<int, int>> temp = trans.mPairs;

	for(std::set<std::pair<int, int>>::iterator i = temp.begin(); i != temp.end(); i++)
	{
	
		for(std::set<std::pair<int, int>>::iterator j = temp.begin(); j != temp.end(); j++)
		{
			if ( (*i).second == (*j).first )
			{
				transPair.first = (*i).first;
				transPair.second = (*j).second;
				trans.add(transPair);
			}
			
		}
	}
	return trans;
}

void MyRel::printSet()
{
	std::cout << "Set: ";
	for(std::set<int>::iterator i = mDomainSet.begin(); i != mDomainSet.end(); i++)
	{
		std::cout << (*i) << " ";
	}
	std::cout << std::endl;
}

void MyRel::printPairs()
{
	std::cout << "Pairs: ";
	for(std::set<std::pair<int, int>>::iterator i = mPairs.begin(); i != mPairs.end(); i++)
	{
		std::cout << "{" << (*i).first << ", " << (*i).second << "} ";
	}
	std::cout << std::endl;
}
