#include"RELATIONS.h"

template <typename T1>
Relations<T1>::Relations(int size)
{
	myArray = new T1[size];
	this->size = size;
	Pos = 0;
}
template <class T1>
void Relations<T1>::input()
{
	T1 i;
	cout << "ENTER  " << this->size << " ELEMENTS :";
	while (Pos != size)
	{
		cin >> i;
		insertInRelations(i);
	}cout << endl << endl;
}
template <class T1>
void Relations<T1>::noOfRelationss(Relations R)
{
	cout << "TOTAL RelationsS ARE BETWEEN TWO : " << pow(2, this->size * R.size) << endl;
}
template <class T1>
void Relations<T1>::seeAllRelationFunctions()
{
	cout << "\t\t=================================" << endl;
	this->print();
	cout << "\t\t=================================" << endl;
	this->noOfRelationss(*this);
	this->noOfSymmetricRelations();
	this->noOfReflexiveRelationss();
	this->noOfReflexiveSymmetricRelations();
	cout << "\t\t=================================";
	cout << endl << endl;
}
template <class T1>
void Relations<T1>::noOfReflexiveSymmetricRelations()
{
	cout << "TOTAL REFLEXIVE AND SYMMETRIC RELATIONS ARE: " << pow(2, this->size * this->size - this->size / 2) << endl;
}
template <class T1>
void Relations<T1>::noOfAntisymmetricRelations()
{
	cout << "TOTAL ANTISYMMETRIC RELATIONS ARE: " << pow(2, this->size) * pow(3, ((this->size * this->size) - this->size) / 2) << endl;
}
template <class T1>
void Relations<T1>::noOfSymmetricRelations()
{
	cout << "TOTAL SYMMETRIC RELATIONS ARE: " << pow(2, ((this->size * this->size) + this->size) / 2) << endl;
}
template <class T1>
void Relations<T1>::noOfReflexiveRelationss()
{
	cout << "TOTAL REFLEXIVE RELATIONS ARE: " << pow(2, ((this->size * this->size) - this->size)) << endl;
}
template <class T1>
void Relations<T1>::insertInRelations(T1 i)
{
	myArray[Pos++] = i;
}
template <class T1>
void Relations<T1>::print()
{
	cout << "GIVEN RELATION :  { ";
	for (int i = 0; i < this->size; i++)
	{
		if (i == this->size - 1)
			cout << this->myArray[i] << " }";
		else
			cout << this->myArray[i] << " , ";
	}cout << endl;
}


