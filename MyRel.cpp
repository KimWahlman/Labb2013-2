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
	mPairs.insert(PSet.begin, PSet.end);
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
