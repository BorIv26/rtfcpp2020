#ifndef TASK_7_TASK_7_H
#define TASK_7_TASK_7_H
class SLList
{
public:
	int getData()const;
	void setData(int data);
	SLList* next();
	bool hasNext();
	static SLList* beginList(int data);
	SLList* addElement(int data);
	void removeNext();
	~SLList();
private:
	SLList* m_nextElem;
	int m_data;
	explicit SLList(int);
	SLList();
};
#endif