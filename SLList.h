#ifndef LW7_SLLIST_H
#define LW7_SLLIST_H

class SLList
{
public:
    int getData() const;
    void setData(int);
    SLList* next();
    bool hasNext();
    static SLList* beginList(int);
    SLList* addElement(int);
    void removeNext();

    ~SLList();

private:
    SLList* m_nextElem;
    int m_data;

    explicit SLList(int);
    SLList();
};

#endif //LW7_SLLIST_H