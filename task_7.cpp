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
