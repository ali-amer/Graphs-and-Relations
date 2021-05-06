#pragma once
#ifndef _TESTTEMP_H_
#define _TESTTEMP_H_
#include <iostream>
#include <cmath>
using namespace std;
template <typename T1>
class Relations
{
private:
	T1* myArray;
	int Pos;
	int size;
	void noOfReflexiveSymmetricRelations();
	void noOfAntisymmetricRelations();
	void noOfSymmetricRelations();
	void noOfReflexiveRelationss();
	void insertInRelations(T1 i);
	void print();
public:
	Relations(int size);
	void input();
	void noOfRelationss(Relations R);
	void seeAllRelationFunctions();

};
#endif