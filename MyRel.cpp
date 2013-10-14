#include "MyRel.h"
#include <iostream>

MyRel::MyRel()
{
	
}

MyRel::MyRel(std::set<int> A)
{
	mDomainSet = A;
}

MyRel::~MyRel()
{
	mDomainSet.clear();
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
