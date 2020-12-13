#include <iostream>
#include "SLList.h"
using namespace std;


void printSLList(SLList* list)
{
    while ((SLList*)list->hasNext())
    {
        cout << list->getData() << ", ";
        list = list->next();
    }
    cout << list->getData() << endl;
}

bool contains(int element, const int* array, int size)
{
    for (int i = 0; i < size; i++)
        if (element == array[i]) return true;
    return false;
}

SLList* deleteDuplicates(const SLList* listHead, const int listLength)
{
    auto list = (SLList*)listHead;
    int* duplicates = new int[listLength];
    SLList* newList = SLList::beginList(list->getData());
    SLList* newListHead = newList;

    if (((SLList*)list)->hasNext())
    {
        list = list->next();
        int i = 0;
        while (list->hasNext())
        {
            if (!contains(list->getData(), duplicates, listLength))
            {
                duplicates[i] = list->getData();
                newList = newList->addElement(list->getData());
                i++;
            }
            list = list->next();
        }
    }
    return newListHead;
}

SLList* findKElement(int k, const SLList* listHead)
{
    int c = 1;
    auto list = (SLList*)listHead;
    while (list->hasNext())
    {
        list = list->next();
        c++;
    }

    list = (SLList*)listHead;

    c -= k;
    k = 0;
    while (k != c)
    {
        k++;
        list = list->next();
    }

    return list;
}

int main() {
    SLList* list = SLList::beginList(rand() % 5);
    SLList* listHead = list;
    int listLength = 10;
    for (int i = 0; i < listLength - 1; i++)
    {
        list = list->addElement(rand() % 5);
    }

    cout << "Original list:" << endl;

    printSLList(listHead);

    cout << "List without duplicates:" << endl;

    SLList* listWithoutDuplicates = deleteDuplicates(listHead, listLength);

    printSLList(listWithoutDuplicates);

    cout << "---> Countdown start with 1, not 0 <---" << endl;
    cout << "2nd from the end in original list: " << findKElement(2, listHead)->getData() << endl;
    cout << "1th from the end in list without duplicates: " << findKElement(1, listWithoutDuplicates)->getData() << endl;
    return 0;
}