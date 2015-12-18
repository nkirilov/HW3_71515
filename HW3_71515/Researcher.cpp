#include<iostream>
#include"Researcher.h"


void Researcher::MergeSort(char** names, unsigned size)
{
	char** buffer = new char*[size];
	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = new char[9];
	}
	mergeBuffer(names, size, buffer);
	for (size_t i = 0; i < size; i++)
	{
		delete[]buffer[i];
	}
	delete[]buffer;
}

void Researcher::mergeBuffer(char** data, unsigned size, char** buffer)
{
	if (size <= 1)
	{
		return;
	}
	int middle = size / 2;
	mergeBuffer(data, middle, buffer);
	mergeBuffer(data + middle, size - middle, buffer + middle);
	mergeSortArr(data, middle, data + middle, size - middle, buffer);
	for (size_t i = 0; i < size; i++)
	{
		strcpy(data[i], buffer[i]);
	}
}

void Researcher::mergeSortArr(char** first, unsigned firstSize, char** second, unsigned secondSize, char** buffer)
{
	int fSize = 0, sSize = 0, bSize = 0;
	while (fSize<firstSize && sSize<secondSize)
	{
		if (strcmp(first[fSize], second[sSize])<0)
		{
			strcpy(buffer[bSize], first[fSize]);
			++fSize;
			++bSize;
		}
		else
		{
			strcpy(buffer[bSize], second[sSize]);
			++sSize;
			++bSize;
		}
	}
	while (fSize<firstSize)
	{
		strcpy(buffer[bSize], first[fSize]);
		++fSize;
		++bSize;
	}
	while (sSize<secondSize)
	{
		strcpy(buffer[bSize], second[sSize]);
		++sSize;
		++bSize;
	}
}

void Researcher::Research()
{
	for (size_t i = 0; i < numberOfTests; i++)
	{
		//input parameters
		do
		{
			std::cin >> numberOfNames >> numberOfOperations;
			if (numberOfNames > 1000000 || numberOfOperations>500000)
			{
				std::cout << "Wrong Parameters!Enter again!" << std::endl;
			}
		} while (numberOfNames > 1000000 || numberOfOperations>500000);

		//create names
		Names = new char*[numberOfNames];
		for (size_t j = 0; j < numberOfNames; j++)
		{
			Names[j] = new char[9];
		}
		//input names
		for (size_t j = 0; j < numberOfNames; j++)
		{
			std::cin >> Names[j];
			
		}

		//sort
		MergeSort(Names, numberOfNames);
		unsigned startRange = 0, endRange = numberOfNames - 1;
		//input and run operations
		for (size_t j = 0; j < numberOfOperations; j++)
		{
			char buffer[6];
			
			std::cin >> buffer;
			//input ranges
			if (strcmp(buffer, "ENTER") == 0)
			{
				std::cin >> startRange;
				std::cin >> endRange; 
			}
			else if (strcmp(buffer, "QUERY") == 0)//execute query
			{
				char compare[9];
				unsigned count = 0;
				std::cin >> compare;
				for (size_t k = startRange; k <= endRange; k++)
				{
					if (strncmp(Names[k],compare,strlen(compare))==0)
					{
						count++;
					}
				}
				std::cout << count << std::endl;
				count = 0;
			}
			else//incase of wrong input
			{
				std::cout << "Wrong operation!" << std::endl;
			}

		}





		//delete names
		for (size_t j = 0; j <  numberOfNames; j++)
		{
			delete[]Names[j];
		}
		delete[]Names;
	}

}

