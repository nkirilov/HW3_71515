#pragma once


class Researcher
{
public:
	Researcher(int numOT = 0) :numberOfTests(numOT)
	{
		numberOfTests = numOT;
	}
	~Researcher();


	void Research();
	void empty();
	void setNumberOfTests(int);
	void setNumberOfNames();
	void setNumberOfOperations();

	int getNumberOfTests();
	int getNumberOfNames();
	int getNumberOfOperations();




private:
	int numberOfTests;
	int numberOfNames;
	int numberOfOperations;
	char** Names;

};



Researcher::~Researcher()
{
}