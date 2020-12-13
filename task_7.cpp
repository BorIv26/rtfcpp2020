#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "task_7.h"
using namespace std;

SLList::SLList()
{
    this->m_data = 0;
    this->m_nextElem = nullptr;    
}

SLList::SLList(int data)
{
    this->m_data = data;
    this->m_nextElem = nullptr;
}

SLList::~SLList() 
{
    this->m_nextElem = nullptr;
    delete this;
}

int SLList::getData()const
{
	return this->m_data;
}

SLList* SLList::beginList(int data) 
{
    return new SLList(data);
}

void SLList::setData(int data)
{
	this->m_data = data;
}
SLList* SLList::next()
{
	return this->m_nextElem;
}
bool SLList::hasNext()
{
    return this->m_nextElem != nullptr;
}

SLList* SLList::addElement(int data) 
{
    if (!this->hasNext()) 
    {
        auto newElem = new SLList(data);
        this->m_nextElem = newElem;
        return newElem;
    }
    return nullptr;
}

void SLList::removeNext() 
{
    delete this->m_nextElem;
    this->m_nextElem = nullptr;
}

void printSLList(SLList* list)
{
	while ((SLList*)list->hasNext())
	{
		cout << list->getData() << " ";
		list = list->next();
	}
	cout << list->getData() << endl;
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