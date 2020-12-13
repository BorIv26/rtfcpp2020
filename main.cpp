#include <iostream>
#include "SLList.h"
using namespace std;

void printSLList(SLList* list)
{
	while ((SLList*)list->hasNext())
	{
		cout << list->getData() << " ";
		list = list->next();
	}
	cout << list->getData() << endl;
}

bool hasSame(int element, int* array, int size)
{
	for (int i = 0; i < size; i++)
		if (element == array[i]) return true;
	return false;
}

SLList* deleteDuplicates(const SLList* first, const int listLength)
{
	SLList* list = (SLList*)first;
	int* duplicates = new int[listLength];
	SLList* noDuplList = SLList::beginList(list->getData());
	SLList* noDuplListBegin = noDuplList;
	int i = 0;

	if ((list)->hasNext())
	{
		list = list->next();
		while (list->hasNext())
		{
			if (!hasSame(list->getData(), duplicates, listLength))
			{
				noDuplList = noDuplList->addElement(list->getData());
				duplicates[i] = list->getData();
				i++;
			}
			list = list->next();
		}
	}
	return noDuplListBegin;
}

SLList* findKFromEnd(const SLList* list1, int k)
{
	int i = 1;
	SLList* list = (SLList*)list1;
	while (list->hasNext())
	{
		i++;
		list = list->next();
	}
	list = (SLList*)list1;
	while (int j = 0 <= i - k - 1)
	{
		k++;
		list = list->next();
	}
	return list;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	SLList* list = SLList::beginList(rand() % 5);
	SLList* listBegin = list;
	int length = 10;
	for (int i = 0; i < length - 1; i++)
	{
		list = list->addElement(rand() % 5);
	}
	int k = 7;
	int k1 = 3;
	SLList* noDuplList = deleteDuplicates(listBegin, length);
	SLList* kInMainList = findKFromEnd(listBegin, k);
	SLList* k1InNoDuplList = findKFromEnd(noDuplList, k1);
	cout << "SLList обычный" << endl;
	printSLList(listBegin);
	cout << "SLList без дубликатов" << endl;
	printSLList(noDuplList);
	cout << "k-атый с конца обычного(седьмой)=";
	cout << kInMainList->getData() << endl;
	cout << "k1-атый с конца обычного(четвертый)=";
	cout << k1InNoDuplList->getData() << endl;
}