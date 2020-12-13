#include "SLList.h"

int SLList::getData() const {
    return this->m_data;
}

void SLList::setData(int data) {
    this->m_data = data;
}

SLList* SLList::next() {
    return this->m_nextElem;
}

bool SLList::hasNext() {
    return this->m_nextElem != nullptr;
}

SLList* SLList::beginList(int data) {
    return new SLList(data);
}

SLList* SLList::addElement(int data) {
    if (!this->hasNext()) {
        auto newElem = new SLList(data);
        this->m_nextElem = newElem;
        return newElem;
    }
    return nullptr;
}

void SLList::removeNext() {
    delete this->m_nextElem;
    this->m_nextElem = nullptr;
}

SLList::SLList(int data) {
    this->m_data = data;
    this->m_nextElem = nullptr;
}

SLList::~SLList() {
    this->m_nextElem = nullptr;
    delete this;
}

SLList::SLList() {
    this->m_nextElem = nullptr;
    this->m_data = 0;
}