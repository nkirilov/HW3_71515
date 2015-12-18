//Николай Здравков Кирилов 
//ФН 71515
//Visual Studio 2015 Enterprise
//Windows 8.1 Pro 64bit
#include<iostream>
#include"Researcher.h"

int main()
{
	unsigned tests;
	std::cin >> tests;
	Researcher r(tests);
	r.Research();
	system("pause");
	return 0;
}