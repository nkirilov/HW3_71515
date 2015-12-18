#pragma once
#include<iostream>


class Researcher
{
public:
	Researcher(int numOT = 0) :numberOfTests(numOT)
	{
		numberOfTests = numOT;
		numberOfNames = 0;
		numberOfOperations = 0;
		Names = NULL;
	}
	


	void Research();
	void MergeSort(char** names, unsigned size);
	void mergeBuffer(char** data, unsigned size, char** buffer);
	void mergeSortArr(char** first, unsigned firstSize, char** second, unsigned secondSize, char** buffer);
	



private:
	unsigned numberOfTests;//t
	unsigned numberOfNames;//n
	unsigned numberOfOperations;//q
	char** Names;

};



