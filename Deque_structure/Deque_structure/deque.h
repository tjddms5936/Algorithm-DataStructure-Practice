#pragma once
#include <stdio.h>

class C_DEQUE
{
private:
	struct S_NODE
	{
		int nData;
		S_NODE* pL;
		S_NODE* pR;
	};

private:
	S_NODE m_BeginDummy;
	S_NODE m_EndDummy;
	S_NODE* m_pBegin;
	S_NODE* m_pEnd;
	int m_nSize;

private:
	S_NODE* createNode(int nData);
	void linkNode(S_NODE* pLeft, S_NODE* pRight);
	void printNode(S_NODE* pNode);
public:
	C_DEQUE();
	~C_DEQUE() = default;
	C_DEQUE(const C_DEQUE&) = delete;
	C_DEQUE& operator =(const C_DEQUE&) = delete;

	void push_front(int nData);
	void push_back(int nData);
	bool pop_front(int& popData);
	bool pop_back(int& popData);
	int size();
	bool empty();
	bool front(int& nResult);
	bool back(int& nResult);
	void printData();
};