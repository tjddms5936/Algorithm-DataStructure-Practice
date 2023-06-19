#pragma once
#include <stdio.h>

class C_QUEUE
{
private:
	struct S_NODE
	{
		int nData;
		S_NODE* pBefore;
		S_NODE* pAfter;
	};

private:
	S_NODE m_pFrontDummy;
	S_NODE m_pBackDummy;
	S_NODE* m_pFront;
	S_NODE* m_pBack;
	int m_nSize;
private:
	S_NODE* createNode(int nData);
	void printNode(S_NODE* pNode);
	void linkNode(S_NODE* pPivotNode, S_NODE* pNewNode);
public:
	C_QUEUE();
	~C_QUEUE() = default;
	C_QUEUE(const C_QUEUE&) = delete;
	C_QUEUE& operator=(const C_QUEUE&) = delete;

	void push(int nData);
	int pop(); // ���� ������ ������ -1 ��ȯ
	int size();
	bool empty(); // ��������� true, �ƴϸ� false
	bool front(int& nResult); 
	bool back(int& nResult); 
	void printQueue();
};